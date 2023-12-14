/**
 * @file prueba_pais.cpp
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
    if (p == p2)
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