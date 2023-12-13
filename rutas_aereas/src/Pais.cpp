/**
 * @file Pais.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include "Pais.h"

Pais::Pais():pais("none"), bandera("none"){}

Pais::Pais(const Punto &punto, string Pais, string Bandera):
    p(punto), pais(Pais), bandera(Bandera) {}

Punto Pais::GetPunto() const {return p;}

string Pais::GetPais() const {return pais;}

string Pais::GetBandera() const {return bandera;}

bool Pais::operator<(const Pais &p) const{
    return this->GetPais() < p.GetPais();
}

bool Pais::operator==(const Pais &p) const{
    return this->GetPunto() == p.GetPunto() && this->GetPais() == p.GetPais() &&
        this->GetBandera() == p.GetBandera();
}

bool Pais::operator==(const Punto &P) const{
    return this->GetPunto() == p;
}

istream & operator>>(istream & is, Pais & P){
    double lat,lng;
	
	is>>lat>>lng>>P.pais>>P.bandera;
	
	P.p=Punto(lat,lng,"");
	return is;
}

ostream & operator<<(ostream & os, const Pais &P){
	os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
	return os;
}
    