/**
 * @file prueba_ruta.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief Este archivo contiene una prueba de la clase _Almacen_Rutas_. 
 * 
 * La prueba comienza leyendo un Almacen_Rutas del archivo pasado como argumento con formato _almacen_rutas.txt_.
 * 
 * Una vez leído se imprimen en la consola todas las rutas almacenadas.
 * 
 * A continuación, se pide que se introduzca una ruta por consola, la cual es borrada y el resultado del almacén sin la ruta borrada
 * se muestra por consola.
 * 
 * Finalmente, se pide que se introduzca un código de ruta y se imprime la ruta identificada con dicho código.
 * 
 * _
 * @date 2023-12-10
 * 
 */

#include "Pais.h"
#include "Paises.h"
#include "Almacen_Rutas.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char *argv[]){

    if (argc != 2){
        cerr << "Error de argumentos, debes pasar un fichero formato almacen_rutas.txt." << endl;
        return 1;
    }

    cout << "Esto es una prueba de la clase Almacen_Rutas. " << endl;

    ifstream input;

    input.open(argv[1]);

    Almacen_Rutas r;
    input >> r;

    cout << endl << "Las rutas son: " << r << endl;

    cout << "Introduce una ruta" << endl;
    Ruta ruta;
    cin >> ruta;

    cout << "Borrando la ruta " << endl;
    r.Borrar(ruta);
    cout << "Almacen con la ruta eliminada: " << r;

    cout << "Introduce un codigo de ruta:" << endl;
    string code;
    cin >> code;
    cout << "Ruta con el código introducido: " << r.GetRuta(code) << endl;

    return 0;
}