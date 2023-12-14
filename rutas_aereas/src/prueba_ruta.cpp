/**
 * @file prueba_ruta.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief Este archivo contiene una prueba de la clase _Ruta_. 
 * 
 * La prueba comienza leyendo una ruta del usuario. El ruta se lee como un código,
 * el número de puntods de la ruta y los puntos de la ruta.
 * 
 * Una vez leídos se imprimen en la consola la ruta, el número de puntos de la misma y su código.
 * 
 * A continuación, se borra el punto (7.406652727545182,12.344585699999925) de la ruta y se muestra
 * la ruta tras el borrado de dicho punto.
 * 
 * Posteriormente, se muestra un ejemplo de búsqueda de un punto, en este caso el (-0.18659558628491132,-78.4305382).
 * 
 * Finalmente se introduce una nueva ruta y se compara con la que ya teníamos para ver si son iguales o no.
 * 
 * _Ejemplo de uso:_
 * 
 * Introduzca una Ruta (codigo nºpuntos puntos): R1 5 (34.520418555522845,69.20082090000005) (52.50786264022465,13.426141949999987) 
 * (7.406652727545182,12.344585699999925) (-0.18659558628491132,-78.4305382) (40.40051528912146	,-3.5916460749999635)
 *
 * La ruta es: R1 5 (34.5204,69.2008) (52.5079,13.4261) (7.40665,12.3446) (-0.186596,-78.4305) (40.4005,-3.59165) 
 *
 * Nº de puntos: 5
 * 
 * Código: R1
 * 
 * Borrar el punto (7.406652727545182,12.344585699999925)
 * 
 * Ruta con el punto borrado: R1 4 (34.5204,69.2008) (52.5079,13.4261) (-0.186596,-78.4305) (40.4005,-3.59165) 
 *
 * Búsqueda del punto (-0.18659558628491132,-78.4305382): (-0.186596,-78.4305)
 *
 * Introduce otra ruta: R3	5	 (17.246400332673307,	-19.670602940234403) (4.283635422564345,-74.22403995000002) (51.528868434293244,	-0.10159864999991441)
 * (62.88647107195116,61.551173617626986) (37.943768420529985,104.13611175000005)
 *
 * ¿Son iguales? No
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