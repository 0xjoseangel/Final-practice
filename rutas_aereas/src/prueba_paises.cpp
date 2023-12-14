/**
 * @file prueba_paises.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-10
 * 
 */

#include "Pais.h"
#include "Paises.h"
#include "Almacen_Rutas.h"
#include <iostream>
using namespace std;


int main(){

    cout << "Esto es una prueba de la clase Paises. " << endl;

    cout << "Introduzca Paises (formato de paises.txt y EOF al final): ";
    Paises p;
    cin >> p;

    cout << endl << "Los paises son: " << p << endl;

    cout << "Borrado del pais Alemania." << endl << "Paises sin Alemania: ";
    Pais alemania(Punto(52.50786264022465,13.426141949999987, ""), "Alemania", "alemania.ppm");
    p.Borrar(alemania);
    cout << p << endl;

    Paises::iterator it;
    cout << "Búsqueda del país Albania: ";
    Pais albania(Punto(41.332136072796175,19.812877200000003, ""), "Albania", "albania.ppm");
    it=p.find(albania);

    cout << endl << *it << endl;

    return 0;
}