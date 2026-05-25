import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from iapws import IAPWS97
import os


def read_openfoam_scalar_field(filepath):
    if not os.path.exists(filepath):
        raise FileNotFoundError(f"Error: Cannot find the file '{filepath}'.")

    # Use errors='ignore' in case the file contains unreadable binary characters
    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()

    # 1. Safety Check: Is the file in binary format?
    for line in lines[:50]:
        if "format" in line and "binary" in line:
            raise ValueError(
                "\n[!] ERROR: This output file is in BINARY format, which Python cannot read as text.\n"
                "--> Open system/controlDict, change 'writeFormat binary;' to 'writeFormat ascii;',\n"
                "--> Then rerun your simulation to output readable text files."
            )

    data = []
    in_internal_field = False
    in_data_list = False

    for line in lines:
        line = line.strip()
        
        # Ignore empty lines
        if not line:
            continue

        # 2. Find the internalField declaration
        if line.startswith("internalField"):
            if "uniform" in line and "nonuniform" not in line:
                # Handle flat initial conditions (e.g. uniform 550;)
                val = float(line.split()[2].strip(';'))
                return np.array([val])
            elif "nonuniform" in line:
                in_internal_field = True
                continue
        
        # 3. Wait for the opening array bracket
        if in_internal_field and not in_data_list:
            if line == "(":
                in_data_list = True
            continue
        
        # 4. Extract data until the closing bracket
        if in_data_list:
            if line == ")" or line == ");":
                break # Stop exactly at the end of the data array
            
            try:
                data.append(float(line))
            except ValueError:
                # Silently skip any weird text anomalies inside the array
                continue

    return np.array(data)

# ==========================================
# Execution Setup
# ==========================================
if __name__ == "__main__":
    time_step = "25"  
    region = "coolantZone"
    variable = "T"
    
    file_path = os.path.join(time_step, region, variable)

    try:
        print(f"Parsing {variable} field from: {file_path}...")
        temperatures = read_openfoam_scalar_field(file_path)
        
        num_cells = len(temperatures)
        print(f"\nExtraction Successful!")
        print(f"----------------------------------")
        print(f"Total Cells: {num_cells}")
        
        if num_cells > 0:
            print(f"Max Temp:    {np.max(temperatures):.2f} K")
            print(f"Min Temp:    {np.min(temperatures):.2f} K")
            print(f"Avg Temp:    {np.mean(temperatures):.2f} K")
        else:
            print("No data was found in the internalField.")
        
    except Exception as e:
        print(e)