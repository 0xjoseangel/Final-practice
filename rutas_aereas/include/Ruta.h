#ifndef __RUTA__
#define __RUTA__

#include <string>
#include <list>
#include "Punto.h"

/**
 * @file Ruta.h
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief __T.D.A. Ruta__
 * 
 * La clase _Ruta_ representa una ruta, la cual queda representada
 * por una lista de objetos de la clase _Punto_ y un string con el 
 * código que identifica dicha ruta. A la hora de mostrar una instancia
 * del T.D.A. Ruta se hace escribiendo el código de la ruta, el número de
 * puntos de dicha ruta y los puntos que la componen:
 * 
 * Un ejemplo podría ser:
 * 
 * R1 5 (34.5204,69.2008) (52.5079,13.4261) (7.40665,12.3446) (-0.186596,-78.4305) (40.4005,-3.59165) 
 * 
 * @date 2023-12-06
 * 
 */

/**
 * @brief  __T.D.A. Ruta__
 * 
 * La clase _Ruta_ representa una ruta, la cual queda representada
 * por una lista de objetos de la clase _Punto_ y un string con el 
 * código que identifica dicha ruta. A la hora de mostrar una instancia
 * del T.D.A. Ruta se hace escribiendo el código de la ruta, el número de
 * puntos de dicha ruta y los puntos que la componen:
 * 
 * Un ejemplo podría ser:
 * 
 * R1 5 (34.5204,69.2008) (52.5079,13.4261) (7.40665,12.3446) (-0.186596,-78.4305) (40.4005,-3.59165) 
 * 
 * 
 */
class Ruta{

    private:

        list<Punto> puntos;
        string code;

    public:

        /**
         * @brief Constructor por defecto del tipo Ruta.
         * 
         */
        Ruta();

        /**
         * @brief Método para insertar un nuevo Punto a nuestra Ruta.
         * 
         * @param n objeto tipo Punto a insertar.
         * @post El nuevo Punto es insertado al final de la Ruta.
         */
        void Insertar(const Punto &n);

        /**
         * @brief Método para eliminar un punto de nuestra Ruta.
         * 
         * @param n objeto tipo Punto a borrar.
         */
        void Borrar(const Punto &n);

        /**
         * @brief Método para consultar el tamaño de la Ruta.
         * 
         * @return int número de Puntos de la ruta.
         */
        int GetSize() const;

        /**
         * @brief Método para consultar el código de una Ruta.
         * 
         * @return string código de la Ruta.
         */
        string GetCode() const;

        /**
         * @brief Método para establecer el código de una Ruta.
         * 
         * @param cod nuevo código de la Ruta.
         */
        void SetCode(const string &cod);
        
        /**
         * @brief Clase iteradora para la clase Ruta
         * 
         * Permite iterar sobre sobre los distintos puntos de la ruta.
         * 
         */
        class iterator{
           
            private:

                list<Punto>::iterator p;
            
            public:
                
                /**
                 * @brief Sobrecarga del operador * para el tipo iterator.
                 * 
                 * @return const Punto& referencia al objeto al que apunta el iterador.
                 */
                const Punto & operator*() const;

                /**
                 * @brief Sobrecarga del operador ++ para el tipo iterator.
                 * 
                 * @return iterator& iterador que apunta al siguiente objeto tipo Punto
                 * de la lista.
                 */
                iterator & operator++();

                /**
                 * @brief Sobrecarga del operador -- para el tipo iterator.
                 * 
                 * @return iterator& iterador que apunta al anterior objeto tipo Punto
                 * de la lista.
                 */
                iterator & operator--();

                /**
                 * @brief Sobrecarga del operador == para el tipo iterator.
                 * 
                 * @param it iterador con el que se compara.
                 * @return true si apuntan al mismo elemento.
                 * @return false si no lo hacen.
                 */
                bool operator==(const iterator &it) const;

                /**
                 * @brief Sobrecarga del operador != para el tipo iterator.
                 * 
                 * @param it iterador con el que se compara.
                 * @return true si no apuntan al mismo elemento.
                 * @return false si lo hacen.
                 */
                bool operator!=(const iterator &it) const;

                friend class Ruta;

        };

        /**
         * @brief Clase iteradora para la clase Ruta
         * 
         * Permite iterar sobre sobre los distintos puntos de la ruta.
         * 
         */
        class const_iterator{
           
            private:

                list<Punto>::const_iterator p;
            
            public:
                /**
                 * @brief Sobrecarga del operador * para el tipo const_iterator.
                 * 
                 * @return const Punto& referencia constante al objeto al que apunta el iterador.
                 */
                const Punto & operator*() const;

                /**
                 * @brief Sobrecarga del operador ++ para el tipo const_iterator.
                 * 
                 * @return const_iterator& iterador que apunta al siguiente objeto tipo Punto
                 * de la lista.
                 */
                const_iterator & operator++();

                /**
                 * @brief Sobrecarga del operador -- para el tipo const_iterator.
                 * 
                 * @return const_iterator& iterador que apunta al anterior objeto tipo Punto
                 * de la lista.
                 */
                const_iterator & operator--();

                /**
                 * @brief Sobrecarga del operador == para el tipo const_iterator.
                 * 
                 * @param it iterador con el que se compara.
                 * @return true si apuntan al mismo elemento.
                 * @return false si no lo hacen.
                 */
                bool operator==(const const_iterator &it) const;

                /**
                 * @brief Sobrecarga del operador != para el tipo const_iterator.
                 * 
                 * @param it iterador con el que se compara.
                 * @return true si no apuntan al mismo elemento.
                 * @return false si lo hacen.
                 */
                bool operator!=(const const_iterator &it) const;

                friend class Ruta;
        };

        /**
         * @brief Método para obtener el inicio de la Ruta.
         * 
         * @return iterator que apunta al primer Punto de la Ruta.
         */
        iterator begin();

        /**
         * @brief Método para obtener el inicio de la Ruta.
         * 
         * @return const_iterator que apunta al primer Punto de la Ruta.
         */
        const_iterator begin() const;

        /**
         * @brief Método para obtener el final de la Ruta.
         * 
         * @return iterator que apunta al siguiente al último Punto de la Ruta.
         */
        iterator end();

        /**
         * @brief Método para obtener el final de la Ruta.
         * 
         * @return const_iterator que apunta al siguiente al último Punto
         *  de la Ruta.
         */
        const_iterator end() const;

        /**
         * @brief Método para encontrar un punto en una Ruta.
         * 
         * @param p Punto que se quiere buscar.
         * @return iterator que apunta al objeto encontrado o a end() en caso de
         * no encontrarse.
         */
        iterator find(const Punto &p);

        /**
         * @brief Sobrecarga del operador == para el tipo Ruta.
         * 
         * Dos Rutas serán iguales si todos sus puntos lo son.
         * 
         * @param R Ruta con la que se compara.
         * @return true si todos los puntos de ambas rutas coinciden.
         * @return false si hay alguno que no coincide.
         */
        bool operator==(const Ruta &R) const;

        /**
         * @brief Sobrecarga del operador < para el tipo Ruta.
         * 
         * Una Ruta será menor que otra si tiene un menor número de puntos.
         * 
         * @param R Ruta con la que se compara.
         * @return true si la Ruta tiene un menor número de Puntos que la que se
         * pasa como argumento. 
         * @return false si el número de Puntos no es menor.
         */
        bool operator<(const Ruta &R) const;

        /**
         * @brief Sobrecarga del operador >> para el tipo Ruta.
         * 
         * @param is Flujo de entrada.
         * @param R Ruta que se quiere leer.
         * @return istream& Flujo de entrada.
         */
        friend istream & operator>>(istream &is, Ruta &R);

        /**
         * @brief Sobrecarga del operador << para el tipo Ruta
         * 
         * @param os Flujo de salida.
         * @param R Ruta que se quiere escribir.
         * @return ostream& Flujo de salida.
         */
        friend ostream & operator<<(ostream &os, const Ruta &R);

};

#endif 