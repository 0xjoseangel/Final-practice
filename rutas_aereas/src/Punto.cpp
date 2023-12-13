/**
 * @file Punto.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include "Punto.h"
#include <cassert>
using namespace std;

Punto::Punto():latitud(0), longitud(0){}

Punto::Punto(double l, double L, const string &d){
    assert(-90<=l<=90 && -180<=L<=180);
    this->latitud=l;
    this->longitud=L;
}

double Punto::GetLatitud() const{
    return this->latitud;
}

double Punto::GetLongitud() const{
    return this->longitud;
}

void Punto::SetLatitud(double l){
    assert(-90<=l<=90);
    this->latitud=l;
}

void Punto::SetLongitud(double L){
    assert(-180<=L<=180);
    this->longitud=L;
}

bool Punto::operator<(const Punto &p) const{
    return (this->GetLongitud()) < (p.GetLongitud());
}

bool Punto::operator==(const Punto &p) const{
    return ((this->GetLatitud() == p.GetLatitud()) &&
     (this->GetLongitud() == p.GetLongitud()));
}

bool Punto::operator!=(const Punto &p) const{
    return ((this->GetLatitud() != p.GetLatitud()) ||
     (this->GetLongitud() != p.GetLongitud()));
}

istream & operator>>(istream &is, Punto &p){
    char aux;
    // Leemos omitiendo los paréntesis y la coma
    is >> aux >> p.latitud >> aux >> p.longitud >> aux;
    return is;
}

ostream & operator<<(ostream &os, const Punto &p){
    os << "(" << p.GetLatitud() << "," << p.GetLongitud() << ")";
    return os;
}