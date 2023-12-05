#ifndef __PUNTO__
#define __PUNTO__

/**
 * @file Punto.h
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include <iostream>
#include "Pais.h"
using namespace std;

class Punto{
    private:
        double latitud, longitud;

    public:

        /**
         * @brief Constructor por defecto de la clase Punto.
         * 
         */
        Punto();

        /**
         * @brief Constructor de un objeto Punto a partir de sus coordenadas.
         * 
         * @param l Latitud del punto.
         * @param L Longitud del punto.
         * @param d 
         * @pre -90<=l<=90 && -180<=L<=180
         */
        Punto(double l, double L, const string &d);

        /**
         * @brief Método de consulta de la latitud de un objeto tipo Punto.
         * 
         * @return double con el valor de la latitud.
         */
        double GetLatitud() const;


        /**
         * @brief Método de consulta de la longitud de un objeto tipo Punto.
         * 
         * @return double con el valor de la longitud.
         */
        double GetLongitud() const;

        /**
         * @brief Método para asignar una nueva latitud a un objeto tipo Punto.
         * 
         * @param l Nuevo valor de la latitud.
         * @pre -90<=l<=90
         */
        void SetLatitud(double l);


        /**
         * @brief Método para asignar una nueva longitud a un objeto tipo Punto.
         * 
         * @param L Nuevo valor de la longitud.
         * @pre -180<=L<=180
         */
        void SetLongitud(double L);

        /**
         * @brief Sobrecarga del operador < para el tipo Punto.
         * 
         * Un objeto tipo Punto será menor que otro si su longitud
         * es menor.
         * 
         * @param p Objeto tipo punto con el que se compara. 
         * @return true si la longitud es menor que la de p.
         * @return false si no es menor.
         */
        bool operator<(const Punto &p) const;

            /**
         * @brief Sobrecarga del operador == para el tipo Punto.
         * 
         * Un objeto tipo Punto será igual que otro si su latitud 
         * y longitud son iguales.
         * 
         * @param p Objeto tipo punto con el que se compara. 
         * @return true si latitud y longitud coinciden.
         * @return false si no coinciden.
         */
        bool operator==(const Punto &p) const;

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
        friend ostream & operator<<(ostream &os, const Pais &P);
};

/**
 * @brief Sobrecarga del operador << para el tipo Punto.
 * 
 * @param os Flujo de salida.
 * @param p Objeto tipo Punto a escribir.
 * @return ostream& Flujo de salida.
 */
ostream & operator<<(ostream &os, const Punto &p);

#endif