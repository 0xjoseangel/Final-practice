/**
 * @file prueba_pais.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief Este archivo contiene una prueba de la clase _Pais_. 
 * 
 * La prueba comienza leyendo un país del usuario. El país se lee como una tupla de tres datos, una latitud, una longitud y un nombre.
 * 
 * Una vez leído el país, se imprime en la consola.
 * 
 * A continuación, se compara el país con un punto de coordenadas (1, 1).
 * Si los dos puntos son iguales, se imprime "Si" en la consola. En caso contrario, se imprime "No".
 * 
 * Finalmente, se compara el país con un país con parámetros _1.0 1.0 francia francia_.
 * 
 * _Ejemplo de uso:_
 * 
 * Introduzca un pais( latitud longitud nombre bandera): 1.0 1.0 España España 
 *
 * El pais es el: (1,1) España España
 * 
 * Pais: España
 *
 * Bandera: España
 * 
 * ¿Es igual que el punto (1.0, 1.0)?
 * 
 * Sí
 * 
 * ¿Es igual que el país _ 1.0 1.0 francia francia_?
 * 
 * No
 *
 * 
 * @date 2023-12-10
 * 
 */

#include "Pais.h"
#include "Paises.h"
#include "Almacen_Rutas.h"
#include <iostream>
using namespace std;


int main(){

    cout << "Esto es una prueba de la clase Pais. " << endl;

    cout << "Introduzca un pais( latitud longitud nombre bandera): ";
    Pais p;
    cin >> p;

    cout << endl << "El pais es el: " << p << endl;

    cout << "Punto: " << p.GetPunto() << endl;
    cout << "Pais: " << p.GetPais() << endl;
    cout << "Bandera: " << p.GetBandera() << endl;


    cout << "¿Es igual que el punto (1.0, 1.0)?" << endl;
    Punto p2(1, 1, "");
    if (p.GetPunto() == p2)
        cout << "Si" << endl;
    else 
        cout << "No" << endl;

    cout << "¿Es igual que el pais 1.0 1.0 francia francia?" << endl;
    Pais pais2(Punto(1.0,1.0,""), "francia", "francia");
    if (p == pais2)
        cout << "Si" << endl;
    else 
        cout << "No" << endl;

    return 0;
}