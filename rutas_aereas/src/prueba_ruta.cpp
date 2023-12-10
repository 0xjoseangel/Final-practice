/**
 * @file prueba_ruta.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-10
 * 
 */

#include "Almacen_Rutas.cpp"
#include <iostream>
using namespace std;


int main(){

    cout << "Esto es una prueba de la clase Ruta. " << endl;

    cout << "Introduzca una Ruta (codigo nºpuntos puntos): ";
    Ruta r;
    cin >> r;

    cout << endl << "La ruta es: " << r << endl;

    cout << "Nº de puntos: " << r.GetSize() << endl;
    cout << "Código: " << r.GetCode() << endl;

    cout << "Borrar el punto (7.406652727545182,12.344585699999925)" << endl;
    Punto p(7.406652727545182,12.344585699999925, "");
    r.Borrar(p);
    cout << "Ruta con el punto borrado: " << r << endl;
    
    Ruta::iterator it;
    cout << "Búsqueda del punto (-0.18659558628491132,-78.4305382): ";
    it=r.find(Punto(-0.18659558628491132,-78.4305382, ""));

    cout << endl << *it << endl;

    cout << "Introduce otra ruta: ";
    Ruta r2;
    cin >> r2;
    cout << endl << "¿Son iguales? ";
    if (r==r2)
        cout << "Sí" << endl;
    else    
        cout << "No" << endl;

    return 0;
}