/**
 * @file prueba_punto.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief Este archivo contiene una prueba de la clase _Punto_. 
 * 
 * La prueba comienza leyendo un punto del usuario. El punto se lee como una tupla de dos coordenadas, una latitud y una longitud.
 * 
 * Una vez leído el punto, se imprime en la consola.
 *  
 * A continuación, se cambia la latitud y la longitud del punto. Las nuevas coordenadas se leen del usuario.
 * 
 * El punto modificado se imprime en la consola.
 * 
 * Finalmente, se compara el punto modificado con un punto de coordenadas (1, 1).
 * Si los dos puntos son iguales, se imprime "Si" en la consola. En caso contrario, se imprime "No".
 * 
 * _Ejemplo de uso:_
 * 
 * Introduzca un punto( (latitud, longitud)): (0.0, 0.0)
 * 
 * El punto es el: (0.0, 0.0)
 * 
 * Latitud: 0.0
 * 
 * Longitud: 0.0
 * 
 * Cambia la latitud y longitud.
 * 
 * Nueva latitud: 1.0
 * 
 * Nueva longitud: 1.0
 * 
 * Nuevo Punto: (1.0, 1.0)
 * 
 * ¿Es igual que el punto (1.0, 1.0)?
 * 
 * Si
 * 
 * @date 2023-12-04
 * 
 */

#include "Pais.h"
#include "Paises.h"
#include "Almacen_Rutas.h"
#include <iostream>
using namespace std;


int main(){

    cout << "Esto es una prueba de la clase Punto. " << endl;

    cout << "Introduzca un punto( (latitud, longitud)): ";
    Punto p;
    cin >> p;

    cout << endl << "El punto es el: " << p << endl;

    cout << "Latitud: " << p.GetLatitud() << endl;
    cout << "Longitud: " << p.GetLongitud() << endl;

    double num;
    cout << "Cambia la latitud y longitud." << endl;
    cout << "Nueva latitud: ";
    cin >> num;
    p.SetLatitud(num);
    cout << endl << "Nueva longitud: ";
    cin >> num;
    p.SetLongitud(num);
    cout << endl << "Nuevo Punto: " << p << endl;

    cout << "¿Es igual que el punto (1.0, 1.0)?" << endl;
    Punto p2(1, 1, "");
    if (p == p2)
        cout << "Si" << endl;
    else if (p != p2)
        cout << "No" << endl;

    return 0;
}