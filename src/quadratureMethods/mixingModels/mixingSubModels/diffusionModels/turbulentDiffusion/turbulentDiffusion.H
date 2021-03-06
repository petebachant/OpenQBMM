/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2015-2016 Alberto Passalacqua
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is derivative work of OpenFOAM.

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

Class
    Foam::mixingSubModels::diffusionModels::turbulentDiffusion

Description
    Turbulent diffusion model.

SourceFiles
    turbulentDiffusion.C

\*---------------------------------------------------------------------------*/

#ifndef turbulentDiffusion_H
#define turbulentDiffusion_H

#include "diffusionModel.H"
#include "fvm.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace mixingSubModels
{
namespace diffusionModels
{

/*---------------------------------------------------------------------------*\
                    Class turbulentDiffusion Declaration
\*---------------------------------------------------------------------------*/

class turbulentDiffusion
:
    public diffusionModel
{
    //- Private member functions
        tmp<volScalarField> turbViscosity(const volScalarField& moment) const;

    //- Private data

        //- Laminar diffusivity
        dimensionedScalar gammaLam_;

        //- Turbulent Schmidt number
        scalar Sc_;

public:

        //- Runtime type information
        TypeName("turbulentDiffusion");


    // Constructors

        //- Construct from components
        turbulentDiffusion(const dictionary& dict);


    //- Destructor
    virtual ~turbulentDiffusion();


    // Member Functions

        //- Moments of the daughter distribution
        virtual tmp<fvScalarMatrix> momentDiff
        (
            const volScalarField& moment
        ) const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace diffusionModels
} // End namespace mixingSubModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
