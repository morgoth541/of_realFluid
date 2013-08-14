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

#include "nasaHeatCapacityPolynomial.H"
#include "IOstreams.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class equationOfState>
Foam::nasaHeatCapacityPolynomial<equationOfState>::nasaHeatCapacityPolynomial(Istream& is)
:
    equationOfState(is),
    a1_(readScalar(is)),
    a2_(readScalar(is)),
    a3_(readScalar(is)),
    a4_(readScalar(is)),
    a5_(readScalar(is)),
    a6_(readScalar(is)),
    a7_(readScalar(is)),
    //values for some need terms at std
        e0_std(e0(this->Tstd)),
	s0_std(s0(this->Tstd)),
        integral_p_dv_std(this->integral_p_dv(this->rhostd(),this->Tstd)),
        integral_dpdT_dv_std(this->integral_dpdT_dv(this->rhostd(),this->Tstd)),
    // cp @ STD (needed to limit cp for stability
        cp_std(this->cp_nonLimited(this->rhostd(),this->Tstd)) 	
{
    is.check("nasaHeatCapacityPolynomial::nasaHeatCapacityPolynomial(Istream& is)"); 	
}

template<class equationOfState>
Foam::nasaHeatCapacityPolynomial<equationOfState>::nasaHeatCapacityPolynomial(const dictionary& dict)
:
    equationOfState(dict),
    a1_(readScalar(dict.subDict("thermodynamics").lookup("a1"))),
    a2_(readScalar(dict.subDict("thermodynamics").lookup("a2"))),
    a3_(readScalar(dict.subDict("thermodynamics").lookup("a3"))),
    a4_(readScalar(dict.subDict("thermodynamics").lookup("a4"))),
    a5_(readScalar(dict.subDict("thermodynamics").lookup("a5"))),
    a6_(readScalar(dict.subDict("thermodynamics").lookup("a6"))),
    a7_(readScalar(dict.subDict("thermodynamics").lookup("a7"))),
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
void Foam::nasaHeatCapacityPolynomial<equationOfState>::write(Ostream& os) const
{
    equationOfState::write(os);

    dictionary dict("thermodynamics");
    dict.add("a1", a1_);
    dict.add("a2", a2_);
    dict.add("a3", a3_);
    dict.add("a4", a4_);    
    dict.add("a5", a5_);
    dict.add("a6", a6_);
    dict.add("a7", a7_);

    os  << indent << dict.dictName() << dict;
}


// * * * * * * * * * * * * * * * Ostream Operator  * * * * * * * * * * * * * //

template<class equationOfState>
Foam::Ostream& Foam::operator<<
(
    Ostream& os,
    const nasaHeatCapacityPolynomial<equationOfState>& np
)
{
    os  << static_cast<const equationOfState&>(np) << tab
        << np.a1_ << tab<< np.a2_ << tab << np.a3_ << tab << np.a4_ << tab << np.a5_ << tab << np.a6_ << tab << np.a7_ ;
    os.check("Ostream& operator<<(Ostream& os, const nasaHeatCapacityPolynomial& np)");
    return os;
}


// ************************************************************************* //
