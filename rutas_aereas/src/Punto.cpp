/**
 * @file Punto.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include "Punto.h"

Punto::Punto():latitud(0), longitud(0){}

Punto::Punto(double l, double L, const string &d):latitud(l), longitud(L){}

double Punto::GetLatitud() const{
    return this->latitud;
}

double Punto::GetLongitud() const{
    return this->longitud;
}

void Punto::SetLatitud(double l){
    this->latitud=l;
}


void Punto::SetLongitud(double L){
    this->longitud=L;
}

bool Punto::operator<(const Punto &p) const{
    return (this->GetLatitud()+this->GetLongitud()) < (p.GetLatitud()+p.GetLongitud());
}

bool Punto::operator==(const Punto &p) const{
    return (this->GetLatitud()+this->GetLongitud()) == (p.GetLatitud()+p.GetLongitud());
}

ostream & operator<<(ostream &os, const Punto &p){
    os << "(" << p.GetLatitud() << "," << p.GetLongitud() << ")";
    return os;
}