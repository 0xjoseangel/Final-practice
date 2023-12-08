/**
 * @file Ruta.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-06
 * 
 */

#include "Ruta.h"
#include <algorithm>

// Métodos de la clase Ruta.

Ruta::Ruta():code("none"){}

void Ruta::Insertar(const Punto &n){
    puntos.push_back(n);
}

void Ruta::Borrar(const Punto &n){
    list<Punto>::iterator p = std::find(puntos.begin(), puntos.end(), n);
    if (p != puntos.end())
        puntos.erase(p);    
}

int Ruta::GetSize() const{
    return puntos.size();
}

string Ruta::GetCode() const{
    return this->code;
}

void Ruta::SetCode(const string &cod){
    this->code = cod;
}

// Métodos de la clase iterator

const Punto & Ruta::const_iterator::operator*() const{
    return *p;
}

Ruta::const_iterator & Ruta::const_iterator::operator++(){
    ++p;
    return *this;
}

Ruta::const_iterator & Ruta::const_iterator::operator--(){
    --p;
    return *this;
}

bool Ruta::const_iterator::operator==(const const_iterator &it) const{
    return (this->p == it.p);
}

bool Ruta::const_iterator::operator!=(const const_iterator &it) const{
    return (this->p != it.p);
}

// Métodos de la clase const_iterator

const Punto & Ruta::iterator::operator*() const{
    return *p;
}

Ruta::iterator & Ruta::iterator::operator++(){
    ++p;
    return *this;
}

Ruta::iterator & Ruta::iterator::operator--(){
    --p;
    return *this;
}

bool Ruta::iterator::operator==(const iterator &it) const{
    return (this->p == it.p);
}

bool Ruta::iterator::operator!=(const iterator &it) const{
    return (this->p != it.p);
}

// Resto de métodos de la clase Ruta

Ruta::iterator Ruta::begin(){
    iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::const_iterator Ruta::begin() const{
    const_iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::iterator Ruta::end(){
    iterator it;
    it.p = puntos.end();
    return it;
}

Ruta::const_iterator Ruta::end() const{
    const_iterator it;
    it.p = puntos.end();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p){
    list<Punto>::iterator it;
    it = std::find(puntos.begin(), puntos.end(), p);
    iterator sol;
    sol.p = it;
    return sol;
}

bool Ruta::operator==(const Ruta &R) const{
    if (this->GetSize() != R.GetSize())
        return false;
    else{
        const_iterator p, q;
        p=this->begin();
        q=R.begin();
        for (p=this->begin(); p!=this->end(); ++p, ++q)
            if (*p != *q)
                return false;
        return true;
    }
}

bool Ruta::operator<(const Ruta &R) const{
    return (this->GetSize() < R.GetSize());
}

istream & operator>>(istream &is, Ruta &R){
    Ruta aux;
    Punto p;
    int n_puntos;
    is>>aux.code;
    is>>n_puntos;
    for(int i = 0 ; i < n_puntos ; i++){
        is>>p;
        aux.Insertar(p);
    }
    R = aux;
    return is;
}

ostream & operator<<(ostream &os, const Ruta &R){
    os<<R.code<<" "<<R.GetSize()<<" ";
    for(Ruta::const_iterator it = R.begin() ; it != R.end() ; ++it)
        os<<*it<<" ";
    os << endl;
    return os;
}








