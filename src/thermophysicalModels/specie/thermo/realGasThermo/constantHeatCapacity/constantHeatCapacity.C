/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | 
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Author
Christian Lucas
Institut für Thermodynamik
Technische Universität Braunschweig 
Germany

\*---------------------------------------------------------------------------*/

#include "constantHeatCapacity.H"
#include "IOstreams.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class equationOfState>
Foam::constantHeatCapacity<equationOfState>::constantHeatCapacity(Istream& is)
:
    equationOfState(is),
    Cp0_(readScalar(is)),
    cp0_(Cp0_*this->W()),
    //values for some need terms at std
        e0_std(e0(this->Tstd)),
	s0_std(s0(this->Tstd)),
        integral_p_dv_std(this->integral_p_dv(this->rhostd(),this->Tstd)),
        integral_dpdT_dv_std(this->integral_dpdT_dv(this->rhostd(),this->Tstd)),
    // cp @ STD (needed to limit cp for stability
        cp_std(this->cp_nonLimited(this->rhostd(),this->Tstd)) 	
{
    is.check("constantHeatCapacity::constantHeatCapacity(Istream& is)"); 	
}

template<class equationOfState>
Foam::constantHeatCapacity<equationOfState>::constantHeatCapacity(const dictionary& dict)
:
    equationOfState(dict),
    //CL:perfect gas heat capacity 
    Cp0_(readScalar(dict.subDict("thermodynamics").lookup("cp"))),
    cp0_(Cp0_*this->W()),
    //values for some need terms at std
        e0_std(e0(this->Tstd)),
	s0_std(s0(this->Tstd)),
        integral_p_dv_std(this->integral_p_dv(this->rhostd(),this->Tstd)),
        integral_dpdT_dv_std(this->integral_dpdT_dv(this->rhostd(),this->Tstd)),
    // cp @ STD (needed to limit cp for stability
        cp_std(this->cp_nonLimited(this->rhostd(),this->Tstd)) 
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class equationOfState>
void Foam::constantHeatCapacity<equationOfState>::write(Ostream& os) const
{
    equationOfState::write(os);

    dictionary dict("thermodynamics");
    dict.add("cp", Cp0_);

    os  << indent << dict.dictName() << dict;
}


// * * * * * * * * * * * * * * * Ostream Operator  * * * * * * * * * * * * * //

template<class equationOfState>
Foam::Ostream& Foam::operator<<
(
    Ostream& os,
    const constantHeatCapacity<equationOfState>& np
)
{
    os  << static_cast<const equationOfState&>(np) << tab
        << np.Cp0_;
    os.check("Ostream& operator<<(Ostream& os, const constantHeatCapacity& np)");
    return os;
}


// ************************************************************************* //
