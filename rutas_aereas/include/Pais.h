#ifndef __PAIS__
#define __PAIS__

/**
 * @file Pais.h
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include "Punto.h"
using namespace std;

class Pais{

    private:
        Punto p;
        string pais;
        string bandera;
    public:

    /**
     * @brief Constructor por defecto de un objeto tipo Pais.
     * 
     */
    Pais();

    /**
     * @brief Constructor de un objeto Pais a partir de un punto,
     * el nombre del país y su bandera.
     * 
     * @param punto Punto donde se sitúa del país.
     * @param Pais Nombre del país.
     * @param Bandera Nombre del archivo .ppm con la bandera del país.
     */
    Pais(const Punto &punto, string Pais, string Bandera);

    /**
     * @brief Método para consultar el punto donde se encuentra un país.
     * 
     * @return Punto objeto con la latitud y longitud del país.
     */
    Punto GetPunto() const;

    /**
     * @brief Método para consultar el nombre de un país.
     * 
     * @return string con el nombre del país.
     */
    string GetPais() const;

    /**
     * @brief Método para consultar la bandera de un país.
     * 
     * @return string con el nombre del archivo .ppm donde se almacena
     * la bandera del país.
     */
    string GetBandera() const;

    /**
     * @brief Sobrecarga del operador < para el tipo Pais
     * 
     * Se dirá que un país es menor que otro si alfabéticamente su nombre
     * está por debajo, es decir, si letra a letra se encuentra por debajo
     * en el abecedario (por orden alfabético).
     * 
     * @param P país con el que se compara.
     * @return true si el nombre del país del objeto que llama al método
     *  es menor si se ordena alfabéticamente que el nombre del país
     *  que se pasa como argumento.
     * @return false si no lo es.
     */
    bool operator<(const Pais &P) const;

    /**
     * @brief Sobrecarga del operador == que compara dos objetos de tipo Pais.
     * 
     * Dos países serán iguales si tienen igual punto, nombre y bandera.
     * 
     * @param P país con el que se compara.
     * @return true si coinciden el punto, el nombre del país y la bandera.
     * @return false si alguno de ellos no coincide.
     */
    bool operator==(const Pais &P) const;
    
    /**
     * @brief Sobrecarga del operador == que compara un objeto de tipo Pais con
     * otro de tipo Punto.
     * 
     * Un país será igual a un punto si el punto del país es igual al punto con el
     * que se compara.
     * 
     * @param P punto con el que se compara.
     * @return true si el punto del país y el que se pasa como argumento coinciden.
     * @return false si no coinciden.
     */
    bool operator==(const Punto &P) const;

    /**
     * @brief Sobrecarga del operador >> para el tipo Pais.
     * 
     * @param is Flujo de entrada.
     * @param p Objeto tipo Pais a leer.
     * @return istream& Flujo de entrada.
     */
    friend istream & operator>>(istream &is, Pais &P);
    
    /**
     * @brief Sobrecarga del operador << para el tipo Pais.
     * 
     * @param os Flujo de salida.
     * @param p Objeto tipo Pais a escribir.
     * @return ostream& Flujo de salida.
     */
    friend ostream & operator <<(ostream &os, const Pais &P);
};

#endif