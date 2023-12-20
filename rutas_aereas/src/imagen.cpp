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
       MÉTODOS PRIVADOS
********************************/
void Imagen::Allocate(int f, int c){
    if ((f == 0) || (c == 0)){
        nf = nc = 0;
        data = nullptr;
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
void Imagen::Copiar(const Imagen &I) {
    Allocate(I.nf, I.nc);
    for (const_iteradorImagen it = I.begin(); it != I.end(); ++it) {
        // Obtener las coordenadas actuales del iterador
        int fila = it.getCurrentRow();
        int col = it.getCurrentCol();
        // Copiar el píxel de la imagen original a la imagen actual
        data[fila][col] = *it;
    }
}

void Imagen::Borrar() {
    for(int i=0;i<nf;++i)
    	delete[] data[i];
    delete[] data;  
}
/********************************
       MÉTODOS PUBLICOS
********************************/
Imagen::Imagen() {
    Allocate();
}
Imagen::Imagen(int f, int c) {
    Allocate(f, c);
} 
Imagen::Imagen(const Imagen & I) {
    assert (this != &I);
    Copiar(I);
}

Imagen & Imagen::operator=(const Imagen & I){
    if (this != &I){
        Borrar();
        Copiar(I);
    }
    return *this;
}
Imagen::~Imagen() {
    Borrar();
}
// Set get
Pixel & Imagen::operator()(int i,int j){
  assert(i>=0 && i<nf && j>=0 && j<nc);
  return data[i][j];
}
const Pixel & Imagen::operator()(int i,int j) const{
  assert(i>=0 && i<nf && j>=0 && j<nc);
  return data[i][j];
}
// E/S
void Imagen::EscribirImagen(const char * nombre){
      unsigned char * aux = new unsigned char [nf*nc*3];
      unsigned char * m = new unsigned char [nf*nc];
      
      int total = nf*nc*3;
      for (int i=0;i<total;i+=3){
	    int posi = i /(nc*3);
	   int posj = (i%(nc*3))/3;
	    
	    aux[i]=data[posi][posj].r;
	    aux[i+1]=data[posi][posj].g;
	    aux[i+2]=data[posi][posj].b;
	    m[i/3]=data[posi][posj].transp;
	     
	 }    
	
      if (!EscribirImagenPPM (nombre, aux,nf,nc)){
	  cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
      }	  
      delete[]aux;
      string n_aux = "mascara_";
      n_aux =n_aux+nombre;
      std::size_t found =n_aux.find(".ppm");
      if (found!=std::string::npos){
	n_aux =n_aux.substr(0,found);
      }
      n_aux =n_aux+".pgm";

      
      if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
	  cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
      }	    
      delete []m;
}
void Imagen::LeerImagen(const char * nombre,const string &nombremascara){
      int f,c;
      unsigned char * aux,*aux_mask ;
      
      LeerTipoImagen(nombre, f, c);
      aux = new unsigned char [f*c*3];
      LeerImagenPPM (nombre, f,c,aux);
      if (nombremascara!=""){
        int fm,cm;
        LeerTipoImagen(nombremascara.c_str(), fm, cm);
        aux_mask = new unsigned char [fm*cm];
        LeerImagenPGM(nombremascara.c_str(), fm,cm,aux_mask);
      }
      else{
	    aux_mask=0;
      }	
      
      
      Imagen I(f,c);
      int total = f*c*3;
      for (int i=0;i<total;i+=3){
        int posi = i /(c*3);
        int posj = (i%(c*3))/3;
	//   cout<<posi<<" " <<posj<<endl;
	     I.data[posi][posj].r=aux[i];
	     I.data[posi][posj].g=aux[i+1];
	     I.data[posi][posj].b=aux[i+2];
	     if (aux_mask!=0)
	      I.data[posi][posj].transp=aux_mask[i/3];
	     else  
	       I.data[posi][posj].transp=255;
	 }    
	  
      *this = I;   
      if (aux_mask!=0) delete[]aux_mask;
      delete []aux;
      
}
void Imagen::PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado){
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);
    
    for (int i=0;i<I.nf;i++)
        for (int j=0;j<I.nc;j++) {
            if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
                if (I.data[i][j].transp!=0){
                    if (tippegado==OPACO)
                      data[i+posi][j+posj]=I.data[i][j];
                    else{
                      data[i+posi][j+posj].r=(data[i+posi][j+posj].r+I.data[i][j].r)/2;
                      data[i+posi][j+posj].g=(data[i+posi][j+posj].r+I.data[i][j].g)/2;
                      data[i+posi][j+posj].b=(data[i+posi][j+posj].r+I.data[i][j].b)/2;
                    }  
    
                }  
            }
    }    
}
// Métodos para el iterador
Imagen::iteradorImagen Imagen::begin(){
    return iteradorImagen(*this);
}
Imagen::iteradorImagen Imagen::end(){
    return iteradorImagen(*this, &data[num_filas()-1][num_cols()-1], num_cols()-1, num_filas()-1);
}
// Métodos para el iterador constante
Imagen::const_iteradorImagen Imagen::begin() const{
    return const_iteradorImagen(*this);
}
Imagen::const_iteradorImagen Imagen::end() const{
    return const_iteradorImagen(*this, &data[num_filas()-1][num_cols()-1], num_cols()-1, num_filas()-1);
}

/********************************
         iteradorImagen
********************************/
Imagen::iteradorImagen::iteradorImagen(Imagen& img) : ptr(&img.data[0][0]), currentRow(0), currentCol(0), imagen(img) {}
Imagen::iteradorImagen::iteradorImagen(Imagen& img, Pixel* start, int cols, int fils) : ptr(start), currentRow(fils), currentCol(cols), imagen(img) {}
Imagen::iteradorImagen::iteradorImagen(const iteradorImagen &v) : ptr(v.ptr), currentRow(v.currentRow), currentCol(v.currentCol), imagen(v.imagen) {}
Imagen::iteradorImagen & Imagen::iteradorImagen::operator=(const iteradorImagen& orig) {
    ptr = orig.ptr;
    currentRow = orig.currentRow;
    currentCol = orig.currentCol;
    imagen = orig.imagen;
    return *this;
}
Pixel & Imagen::iteradorImagen::operator*() const {
    assert(ptr!=0);
    return *ptr;
}
Imagen::iteradorImagen & Imagen::iteradorImagen::operator++() {
    currentCol++;
    if (currentCol == imagen.num_cols()) {
        currentCol = 0;
        currentRow++;
    }
    ptr = &imagen(currentRow, currentCol);
    return *this;
}
Imagen::iteradorImagen & Imagen::iteradorImagen::operator--() {
    if (currentCol > 0) {
        currentCol--;
    } else {
        if (currentRow > 0) {
            currentRow--;
            currentCol = imagen.num_cols() - 1;
        }   
    }
    ptr = &imagen(currentRow, currentCol);
    return *this;
}
bool Imagen::iteradorImagen::operator!=(const iteradorImagen& v) const {
    return ptr != v.ptr;
}
bool Imagen::iteradorImagen::operator==(const iteradorImagen& v) const {
    return ptr == v.ptr;
}
int Imagen::iteradorImagen::getCurrentRow() const {
    return currentRow;
}
int Imagen::iteradorImagen::getCurrentCol() const {
    return currentCol;
}
/********************************
      const_iteradorImagen
********************************/
Imagen::const_iteradorImagen::const_iteradorImagen(const Imagen& img) : ptr(&img.data[0][0]), currentRow(0), currentCol(0), imagen(img) {}
Imagen::const_iteradorImagen::const_iteradorImagen(const Imagen& img, Pixel* start, int cols, int fils) : ptr(start), currentRow(fils), currentCol(cols), imagen(img) {}
Imagen::const_iteradorImagen::const_iteradorImagen(const const_iteradorImagen &v) : ptr(v.ptr), currentRow(v.currentRow), currentCol(v.currentCol), imagen(v.imagen) {}
const Pixel & Imagen::const_iteradorImagen::operator*() const {
    assert(ptr!=0);
    return *ptr;
}
Imagen::const_iteradorImagen & Imagen::const_iteradorImagen::operator++() {
    currentCol++;
    if (currentCol == imagen.num_cols()) {
        currentCol = 0;
        currentRow++;
    }
    ptr = &imagen(currentRow, currentCol);
    return *this;
}
Imagen::const_iteradorImagen & Imagen::const_iteradorImagen::operator--() {
    if (currentCol > 0) {
        currentCol--;
    } else {
        if (currentRow > 0) {
            currentRow--;
            currentCol = imagen.num_cols() - 1;
        }   
    }
    ptr = &imagen(currentRow, currentCol);
    return *this;
}
bool Imagen::const_iteradorImagen::operator!=(const const_iteradorImagen& v) const {
    return ptr != v.ptr;
}
bool Imagen::const_iteradorImagen::operator==(const const_iteradorImagen& v) const {
    return ptr == v.ptr;
}
int Imagen::const_iteradorImagen::getCurrentRow() const {
    return currentRow;
}
int Imagen::const_iteradorImagen::getCurrentCol() const {
    return currentCol;
}