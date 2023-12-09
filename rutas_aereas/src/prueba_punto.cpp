/**
 * @file prueba_punto.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include "Almacen_Rutas.cpp"
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
    p.SetLatitud(num);
    cout << endl << "Nuevo Punto: " << p << endl;

    cout << "¿Es igual que el punto (1.0, 1.0)?" << endl;
    Punto p2(1, 1, "");
    if (p == p2)
        cout << "Si" << endl;
    else if (p != p2)
        cout << "No" << endl;

    Pais P;

    return 0;
}