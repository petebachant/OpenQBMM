/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2015 Alberto Passalacqua
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
    Foam::populationBalanceSubModels::aggregationKernels::constantAggregation

Description
    Constant aggregation kernel. The value of the kernel is read from dictionary
    or assumed equal to 1.

SourceFiles
    constantAggregation.C

\*---------------------------------------------------------------------------*/

#ifndef constantAggregation_H
#define constantAggregation_H

#include "aggregationKernel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace populationBalanceSubModels
{
namespace aggregationKernels
{

/*---------------------------------------------------------------------------*\
                    Class constantAggregation Declaration
\*---------------------------------------------------------------------------*/

class constantAggregation
:
    public aggregationKernel
{
public:

        //- Runtime type information
        TypeName("constant");


    // Constructors

        //- Construct from components
        constantAggregation(const dictionary& dict);


    //- Destructor
    virtual ~constantAggregation();


    // Member Functions

        //- Aggregation kernel
        virtual tmp<volScalarField> Ka
        (
            const volScalarField& abscissa1,
            const volScalarField& abscissa2
        ) const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace aggregationKernels
} // End namespace populationBalanceSubModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
