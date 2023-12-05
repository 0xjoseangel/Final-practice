/**
 * @file imagen.cpp
 * @brief Fichero con definiciones para los métodos primitivos de la clase Imagen
 *
 */

#include <cstring>
#include <cassert>
#include <iostream>

#include <imagen.h>
#include <imagenES.h>

using namespace std;

/********************************
      FUNCIONES PRIVADAS
********************************/
void Imagen::Allocate(int f, int c){
    if ((f == 0) || (c == 0)){
        nf = nc = 0;
        data = 0;
    } else {
        nf = f;
        nc = c;
        data = new Pixel*[nf];
        for (int i=0;i<nf;i++){
            data[i]=new Pixel[nc];
            for (int j=0;j<nc;j++){
                // Inicializamos una imagen en blanco
	            data[i][j].r=255;
	            data[i][j].g=255;
	            data[i][j].b=255;
	            data[i][j].transp=255;
            }
        } 
    }
}

void Copiar(const Imagen &I);  

void Imagen::Copiar(const Imagen &I) {
    Allocate(I.nf, I.nc);
    
} 

/********************************
      FUNCIONES PUBLICAS
********************************/
Imagen::Imagen() {
    Allocate();
}


/********************************
            ITERADOR
********************************/
Imagen::iterador::iterador() : ptr(0), currentRow(0), currentCol(0) {}
Imagen::iterador::iterador(const iterador &v) : ptr(v.ptr), currentRow(v.currentRow), currentCol(v.currentCol), imagen(v.imagen) {}
Imagen::iterador::~iterador() {}
Imagen::iterador & Imagen::iterador::operator=(const iterador& orig) {
    ptr = orig.ptr;
    currentRow = orig.currentRow;
    currentCol = orig.currentCol;
    imagen = orig.imagen;
    return *this;
}
Pixel & Imagen::iterador::operator*() const {
    assert(ptr!=0);
    return *ptr;
}
Imagen::iterador & Imagen::iterador::operator++() {
    currentCol++;
        if (currentCol == imagen.num_cols()) {
            currentCol = 0;
            currentRow++;
        }
        return *this;
}
Imagen::iterador & Imagen::iterador::operator--() {
    // Revisar
    return *this;
}
bool Imagen::iterador::operator!=(const iterador& v) const {
    return ptr != v.ptr;
}
bool Imagen::iterador::operator==(const iterador& v) const {
    return ptr == v.ptr;
}