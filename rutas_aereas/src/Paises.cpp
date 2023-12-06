/**
 * @file Paises.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include "Paises.h"

Paises::Paises(){}

// Métodos de la clase Paises

void Paises::Insertar(const Pais &p){
    datos.insert(p);
}

void Paises::Borrar(const Pais &p){
    datos.erase(p);
}

// Métodos de la clase iterator

const Pais & Paises::iterator::operator*() const{
	return *p;
}

Paises::iterator & Paises::iterator::operator++(){
	++p;
	return *this;
}

Paises::iterator & Paises::iterator::operator--(){
	--p;
	return *this;
}

bool Paises::iterator::operator==(const iterator &it) const{
	return (this->p == it.p);
}

bool Paises::iterator::operator!=(const iterator &it) const{
	return (this->p != it.p);
}

// Métodos de la clase const_iterator

const Pais & Paises::const_iterator::operator*() const{
	return *p;
}

Paises::const_iterator & Paises::const_iterator::operator++(){
	++p;
	return *this;
}

Paises::const_iterator & Paises::const_iterator::operator--(){
	--p;
	return *this;
}

bool Paises::const_iterator::operator==(const const_iterator &it) const{
	return this->p == it.p;
}

bool Paises::const_iterator::operator!=(const const_iterator &it) const{
	return this->p != it.p;
}

// Resto de métodos de la clase Paises

istream & operator>>(istream & is, Paises & R){
    Paises rlocal;
    //leemos el comentario
	if (is.peek()=='#'){
	    string a;
    	getline(is,a);
	}	
	      
	Pais P;
	while (is>>P){
	     rlocal.Insertar(P);
		
	}
	R=rlocal;
	return is;
}

Paises::iterator Paises::begin(){
	iterator it;
	it.p = datos.begin();
	return it;
}

Paises::const_iterator Paises::begin() const{
	const_iterator it;
	it.p = datos.begin();
	return it;
}

Paises::iterator Paises::end(){
	iterator it;
	it.p = datos.end();
	return it;
}

Paises::const_iterator Paises::end() const{
	const_iterator it;
	it.p = datos.end();
	return it;
}

Paises::iterator Paises::find(const Pais &p){
	iterator it;
	it.p = datos.find(p);
	return it;
}

Paises::const_iterator Paises::find(const Punto &p){
	const_iterator it;
	for (it.p=datos.begin(); it.p!=datos.end(); ++it.p){
		if ((it.p)->GetPunto() == p)
			return it;
	}
	const_iterator fin;
	fin.p=datos.end();
	return fin; 
}


ostream & operator<<(ostream & os, const Paises &R){
	  
	Paises::const_iterator it;
    for (it=R.begin(); it!=R.end(); ++it){
		os<<*it<<"\t";
    }
    return os;
}

