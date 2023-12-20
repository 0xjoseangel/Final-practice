/**
 * @file pruebapegado.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief Este programa utiliza la clase Imagen para cargar una imagen desde un archivo, rota la imagen
 * alrededor de su centro según un ángulo especificado y guarda la imagen resultante en un nuevo archivo.
 * 
 * @date 2023-12-20
 * 
 */

#include "imagen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char * argv[]){
  if (argc!=8){
    cout<<"Los parametros son :"<<endl;
    cout<<"1.-La imagen de fondo"<<endl;
    cout<<"2.-La imagen a pegar"<<endl;
    cout<<"3.-La máscara de la imagen a pegar"<<endl;
    cout<<"4.-El nombre de la imagen de salida"<<endl;
    cout<<"5.-La fila donde pegar"<<endl;
    cout<<"6.-La columna donde pegar"<<endl;
    cout<<"7.- 0: Pegado Opaco 1: Pegado Blending"<<endl;
    return 0;
  }
  Imagen I,Ip;
  I.LeerImagen(argv[1]);
  Ip.LeerImagen(argv[2],argv[3]);
  int i,j;
  i=atoi(argv[5]); j=atoi(argv[6]);
  
  Tipo_Pegado tp=OPACO; //variable de tipo Tipo_Pegado que es un enumerado con los valores OPACO y 	BLENDING
  int au= atoi(argv[7]);
  if (au!=0)
    tp=BLENDING;
  
    
  I.PutImagen(i,j,Ip,tp);
  I.EscribirImagen(argv[4]);
  
}  