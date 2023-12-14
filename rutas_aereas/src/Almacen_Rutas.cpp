/**
 * @file Almacen_Rutas.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-06
 * 
 */

#include "Almacen_Rutas.h"

// Métodos de la clase Almacen_Rutas
Almacen_Rutas::Almacen_Rutas() {}

void Almacen_Rutas::Insertar(const Ruta &R){
    pair<string, Ruta> pair;
    pair.first=R.GetCode();
    pair.second=R;
    rutas.insert(pair);
}

void Almacen_Rutas::Borrar(const Ruta &R){
    rutas.erase(R.GetCode());
}

Ruta Almacen_Rutas::GetRuta(const string &a){
    return rutas[a];
}

// Métodos de la clase iterator

const pair<string, Ruta> Almacen_Rutas::iterator::operator*() const{
	return *p;
}

Almacen_Rutas::iterator & Almacen_Rutas::iterator::operator++(){
	++p;
	return *this;
}

Almacen_Rutas::iterator & Almacen_Rutas::iterator::operator--(){
	--p;
	return *this;
}

bool Almacen_Rutas::iterator::operator==(const iterator &it) const{
	return (this->p == it.p);
}

bool Almacen_Rutas::iterator::operator!=(const iterator &it) const{
	return (this->p != it.p);
}

// Métodos de la clase const_iterator

const pair<string, Ruta> Almacen_Rutas::const_iterator::operator*() const{
	return *p;
}

Almacen_Rutas::const_iterator & Almacen_Rutas::const_iterator::operator++(){
	++p;
	return *this;
}

Almacen_Rutas::const_iterator & Almacen_Rutas::const_iterator::operator--(){
	--p;
	return *this;
}

bool Almacen_Rutas::const_iterator::operator==(const const_iterator &it) const{
	return this->p == it.p;
}

bool Almacen_Rutas::const_iterator::operator!=(const const_iterator &it) const{
	return this->p != it.p;
}

// Resto de métodos de la clase Almacen_Rutas

Almacen_Rutas::iterator Almacen_Rutas::begin(){
    iterator it;
    it.p=rutas.begin();
    return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::begin() const{
    const_iterator it;
    it.p=rutas.begin();
    return it;
}


Almacen_Rutas::iterator Almacen_Rutas::end(){
    iterator it;
    it.p=rutas.end();
    return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::end() const{
    const_iterator it;
    it.p=rutas.end();
    return it;
}

ostream & operator<<(ostream &os, const Almacen_Rutas &AR){
    os << "#Rutas" << endl;
    Almacen_Rutas::const_iterator it;
    for(it = AR.begin() ; it != AR.end() ; ++it)
        os << (*it).second;
    os << endl;
    return os;
}
istream & operator>>(istream &is, Almacen_Rutas &AR){
    Almacen_Rutas aux;
	if (is.peek()=='#'){
      string a;
      getline(is,a);
    }
	
	Ruta r;
	while (is>>r){
	  aux.Insertar(r);
	}
    AR=aux;
	return is;
	}

