/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2012 OpenFOAM Foundation
     \\/     M anipulation  |
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

Description
    Mixture instantiation

\*---------------------------------------------------------------------------*/

#include "error.H"

#include "basicMixture.H"
#include "makeBasicMixture.H"

#include "perfectGas.H"
#include "incompressible.H"
#include "isobaricPerfectGas.H"

#include "eConstThermo.H"

#include "hConstThermo.H"
#include "janafThermo.H"
#include "specieThermo.H"

#include "constTransport.H"
#include "sutherlandTransport.H"

#include "icoPolynomial.H"
#include "hPolynomialThermo.H"
#include "polynomialTransport.H"

#include "redlichKwong.H"
#include "pengRobinson.H"
#include "aungierRedlichKwong.H"
#include "soaveRedlichKwong.H"
#include "realGasSpecieThermo.H"
#include "nasaHeatCapacityPolynomial.H"
#include "constantHeatCapacity.H"

#include "pureMixture.H"


#include "binaryMixture.H"
#include "mixtureRedlichKwong.H"
#include "mixturePengRobinson.H"
#include "mixtureSoaveRedlichKwong.H"
#include "mixtureAungierRedlichKwong.H"

#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/* * * * * * * * * * * * * * * private static data * * * * * * * * * * * * * */

makeBasicMixture
(
    pureMixture,
    constTransport,
    eConstThermo,
    perfectGas
);

makeBasicMixture
(
    pureMixture,
    sutherlandTransport,
    eConstThermo,
    perfectGas
);


makeBasicMixture
(
    pureMixture,
    constTransport,
    hConstThermo,
    perfectGas
);

makeBasicMixture
(
    pureMixture,
    sutherlandTransport,
    hConstThermo,
    perfectGas
);

makeBasicMixture
(
    pureMixture,
    sutherlandTransport,
    janafThermo,
    perfectGas
);

makeBasicMixture
(
    pureMixture,
    constTransport,
    hConstThermo,
    incompressible
);

makeBasicPolyMixture
(
    pureMixture,
    3
);

makeBasicPolyMixture
(
    pureMixture,
    8
);


makeBasicMixture
(
    pureMixture,
    constTransport,
    hConstThermo,
    isobaricPerfectGas
);

makeBasicMixture
(
    pureMixture,
    sutherlandTransport,
    hConstThermo,
    isobaricPerfectGas
);

makeBasicMixture
(
    pureMixture,
    sutherlandTransport,
    janafThermo,
    isobaricPerfectGas
);


//CL: Real Gas Mixtures
makeBasicRealFluidMixture
(
    pureMixture,
    sutherlandTransport,
    realGasSpecieThermo,
    nasaHeatCapacityPolynomial,
    redlichKwong
);


makeBasicRealFluidMixture
(
    pureMixture,
    sutherlandTransport,
    realGasSpecieThermo,
    nasaHeatCapacityPolynomial,
    pengRobinson
);


makeBasicRealFluidMixture
(
    pureMixture,
    sutherlandTransport,
    realGasSpecieThermo,
    nasaHeatCapacityPolynomial,
    aungierRedlichKwong
);


makeBasicRealFluidMixture
(
    pureMixture,
    sutherlandTransport,
    realGasSpecieThermo,
    nasaHeatCapacityPolynomial,
    soaveRedlichKwong
);



makeBasicRealFluidMixture
(
    pureMixture,
    constTransport,
    realGasSpecieThermo,
    nasaHeatCapacityPolynomial,
    redlichKwong
);


makeBasicRealFluidMixture
(
    pureMixture,
    constTransport,
    realGasSpecieThermo,
    nasaHeatCapacityPolynomial,
    pengRobinson
);


makeBasicRealFluidMixture
(
    pureMixture,
    constTransport,
    realGasSpecieThermo,
    nasaHeatCapacityPolynomial,
    aungierRedlichKwong
);


makeBasicRealFluidMixture
(
    pureMixture,
    constTransport,
    realGasSpecieThermo,
    nasaHeatCapacityPolynomial,
    soaveRedlichKwong
);

makeBasicRealFluidMixture
(
    pureMixture,
    sutherlandTransport,
    realGasSpecieThermo,
    constantHeatCapacity,
    redlichKwong
);


makeBasicRealFluidMixture
(
    pureMixture,
    sutherlandTransport,
    realGasSpecieThermo,
    constantHeatCapacity,
    pengRobinson
);


makeBasicRealFluidMixture
(
    pureMixture,
    sutherlandTransport,
    realGasSpecieThermo,
    constantHeatCapacity,
    aungierRedlichKwong
);


makeBasicRealFluidMixture
(
    pureMixture,
    sutherlandTransport,
    realGasSpecieThermo,
    constantHeatCapacity,
    soaveRedlichKwong
);



makeBasicRealFluidMixture
(
    pureMixture,
    constTransport,
    realGasSpecieThermo,
    constantHeatCapacity,
    redlichKwong
);


makeBasicRealFluidMixture
(
    pureMixture,
    constTransport,
    realGasSpecieThermo,
    constantHeatCapacity,
    pengRobinson
);


makeBasicRealFluidMixture
(
    pureMixture,
    constTransport,
    realGasSpecieThermo,
    constantHeatCapacity,
    aungierRedlichKwong
);


makeBasicRealFluidMixture
(
    pureMixture,
    constTransport,
    realGasSpecieThermo,
    constantHeatCapacity,
    soaveRedlichKwong
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
