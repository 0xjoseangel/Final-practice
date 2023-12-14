/**
 * @file Almacen_Rutas.h
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-06
 * 
 */

#ifndef __ALMACEN_RUTAS__
#define __ALMACEN_RUTAS__

#include "Ruta.h"
#include <map>

class Almacen_Rutas{

    private:

        map<string, Ruta> rutas; // Código de ruta y ruta.

    public:

        /**
         * @brief Constructor por defecto del tipo Almacen_Rutas
         * 
         */
        Almacen_Rutas();

        /**
         * @brief Método para insertar una Ruta en nuestro Almacen_Rutas
         * 
         * @param R Ruta a insertar
         */
        void Insertar(const Ruta &R);

        /**
         * @brief Método para borrar una Ruta de nuestro Almacen_Rutas
         * 
         * @param R Ruta a borrar
         */
        void Borrar(const Ruta &R);

        /**
         * @brief Método para consultar una ruta de un Almacen_Rutas
         * 
         * @param a código de la Ruta que se quiere obtener
         * @return Ruta objeto tipo Ruta que se quiere consultar
         */
        Ruta GetRuta(const string &a);

        class iterator{
           
            private:

                map<string, Ruta>::iterator p;
            
            public:
                
                /**
                 * @brief Sobrecarga del operador * para el tipo iterator.
                 * 
                 * @return const pair<string, Ruta> & referencia al objeto al que apunta el iterador.
                 */
                const pair<string, Ruta> operator*() const;

                /**
                 * @brief Sobrecarga del operador ++ para el tipo iterator.
                 * 
                 * @return iterator& iterador que apunta al siguiente objeto 
                 * del map.
                 */
                iterator & operator++();

                /**
                 * @brief Sobrecarga del operador -- para el tipo iterator.
                 * 
                 * @return iterator& iterador que apunta al anterior objeto 
                 * del map.
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

                friend class Almacen_Rutas;

        };

        class const_iterator{
           
            private:

                map<string, Ruta>::const_iterator p;
            
            public:
                /**
                 * @brief Sobrecarga del operador * para el tipo const_iterator.
                 * 
                 * @return const pair<string,Ruta>& referencia constante al objeto
                 *  al que apunta el iterador.
                 */
                const pair<string,Ruta> operator*() const;

                /**
                 * @brief Sobrecarga del operador ++ para el tipo const_iterator.
                 * 
                 * @return const_iterator& iterador que apunta al siguiente objeto
                 * del map.
                 */
                const_iterator & operator++();

                /**
                 * @brief Sobrecarga del operador -- para el tipo const_iterator.
                 * 
                 * @return const_iterator& iterador que apunta al anterior objeto
                 * del map.
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

                friend class Almacen_Rutas;
        };

        /**
         * @brief Método para obtener el inicio del Almacen_Rutas.
         * 
         * @return iterator que apunta la primera Ruta del Almacen_Rutas.
         */
        iterator begin();

        /**
         * @brief Método para obtener el inicio del Almacen_Rutas.
         * 
         * @return const_iterator que apunta la primer Ruta del Almacen_Rutas.
         */
        const_iterator begin() const;

        /**
         * @brief Método para obtener el final del Almacen_Rutas.
         * 
         * @return iterator que apunta a la siguiente a la última Ruta
         * del Almacen_Rutas.
         */
        iterator end();

        /**
         * @brief Método para obtener el final del Almacen_Rutas.
         * 
         * @return const_iterator que apunta a la siguiente a la última Ruta
         * del Almacen_Rutas.
         */
        const_iterator end() const;

        /**
         * @brief Sobrecarga del operador >> para el tipo Almacen_Rutas.
         * 
         * @param is Flujo de entrada.
         * @param AR Almacen_Rutas que se quiere leer.
         * @return istream& Flujo de entrada.
         */
        friend istream & operator>>(istream &is, Almacen_Rutas &AR);

        /**
         * @brief Sobrecarga del operador << para el tipo Almacen_Rutas.
         * 
         * @param os Flujo de salida.
         * @param AR Almacen_Rutas que se quiere escribir.
         * @return ostream& Flujo de salida.
         */
        friend ostream & operator<<(ostream &os, const Almacen_Rutas &AR);

        

};

#endif
