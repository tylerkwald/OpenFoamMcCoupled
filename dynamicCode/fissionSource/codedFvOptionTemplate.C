/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2019-2021 OpenCFD Ltd.
    Copyright (C) YEAR AUTHOR, AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "codedFvOptionTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
#include "fvMatrix.H"

//{{{ begin codeInclude

//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace fv
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = ce6fa4aaedb989991b44cb4816b801a9b064a99d
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void fissionSource_ce6fa4aaedb989991b44cb4816b801a9b064a99d(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}


// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(fissionSourceFvOptionscalarSource, 0);
addRemovableToRunTimeSelectionTable
(
    option,
    fissionSourceFvOptionscalarSource,
    dictionary
);

} // End namespace fv
} // End namespace Foam


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::fv::
fissionSourceFvOptionscalarSource::
fissionSourceFvOptionscalarSource
(
    const word& name,
    const word& modelType,
    const dictionary& dict,
    const fvMesh& mesh
)
:
    fv::cellSetOption(name, modelType, dict, mesh)
{
    if (false)
    {
        printMessage("Construct fissionSource fvOption from dictionary");
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::fv::
fissionSourceFvOptionscalarSource::
~fissionSourceFvOptionscalarSource()
{
    if (false)
    {
        printMessage("Destroy fissionSource");
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void
Foam::fv::
fissionSourceFvOptionscalarSource::correct
(
    GeometricField<scalar, fvPatchField, volMesh>& fld
)
{
    if (false)
    {
        Info<< "fissionSourceFvOptionscalarSource::correct()\n";
    }

//{{{ begin code
    
//}}} end code
}


void
Foam::fv::
fissionSourceFvOptionscalarSource::addSup
(
    fvMatrix<scalar>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<< "fissionSourceFvOptionscalarSource::addSup()\n";
    }

//{{{ begin code - warn/fatal if not implemented?
    NotImplemented
//}}} end code
}


void
Foam::fv::
fissionSourceFvOptionscalarSource::addSup
(
    const volScalarField& rho,
    fvMatrix<scalar>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<< "fissionSourceFvOptionscalarSource::addSup(rho)\n";
    }

//{{{ begin code - warn/fatal if not implemented?
    #line 28 "/home/tyler/OpenFOAM/tyler-v2412/run/MultiFuelPin/system/fuelZone/fvOptions/codedSource"
const scalarField& V = mesh_.V();
        scalarField& hSource = eqn.source();

        // Retrieve the x component of the cell centres
        // const scalarField& cellx = mesh_.C().component(0);
        // const scalarField& celly = mesh_.C().component(1);
        const scalarField& cellz = mesh_.C().component(2);
        // const scalarField& cellr = sqrt(fuelZone.C().component(0)^2 + fuelZone.C().component(1)^2);

        forAll(cellz, i)
        {
            // Only apply in the region with internal heat generation
            hSource[i] += - cos(M_PI * (cellz[i]-1.8)/4)/2.515 * 66600.0/0.00018*V[i];
            // hSource[i] += - cos(M_PI * (cellz[i]-1.8)/4)/2.515 * 66600/246560 /V[i]/10970;

            // TSource[i] += - cos(M_PI * (cellz[i]-1.8)/4)/2.515 * 66600/246560 /V[i]/300/10970;
        }
//}}} end code
}


void
Foam::fv::
fissionSourceFvOptionscalarSource::constrain
(
    fvMatrix<scalar>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<< "fissionSourceFvOptionscalarSource::constrain()\n";
    }

//{{{ begin code
    
//}}} end code
}


// ************************************************************************* //

