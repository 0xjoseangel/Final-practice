#ifndef __PAISES__
#define __PAISES__

/**
 * @file Paises.h
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include "Pais.h"
#include <set>

class Paises{

    private:
        set<Pais> datos;

    public:
        /**
         * @brief Constructor por defecto de un objeto tipo Paises.
         * 
         */
        Paises();

        /**
         * @brief Método para insertar un objeto de tipo Pais en nuestro objeto
         * de tipo Paises.
         * 
         * @param p objeto de tipo Pais a insertar.
         */
        void Insertar(const Pais &p);

        /**
         * @brief Método para borrar un país de nuestros Paises.
         * 
         * @param p objeto de tipo Pais a borrar.
         */
        void Borrar(const Pais &p);

        class iterator{
           
            private:
                set<Pais>::iterator p;
            
            public:
                
                /**
                 * @brief Sobrecarga del operador * para el tipo iterator.
                 * 
                 * @return const Pais& referencia al objeto al que apunta el iterador.
                 */
                const Pais & operator*() const;

                /**
                 * @brief Sobrecarga del operador ++ para el tipo iterator.
                 * 
                 * @return iterator& iterador que apunta al siguiente objeto tipo Pais
                 * del set.
                 */
                iterator & operator++();

                /**
                 * @brief Sobrecarga del operador -- para el tipo iterator.
                 * 
                 * @return iterator& iterador que apunta al anterior objeto tipo Pais
                 * del set.
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

                friend class Paises;

        };

        class const_iterator{
           
            private:
                set<Pais>::const_iterator p;
            
            public:
                /**
                 * @brief Sobrecarga del operador * para el tipo const_iterator.
                 * 
                 * @return const Pais& referencia constante al objeto al que apunta el iterador.
                 */
                const Pais & operator*() const;

                /**
                 * @brief Sobrecarga del operador ++ para el tipo const_iterator.
                 * 
                 * @return const_iterator& iterador que apunta al siguiente objeto tipo Pais
                 * del set.
                 */
                const_iterator & operator++();

                /**
                 * @brief Sobrecarga del operador -- para el tipo const_iterator.
                 * 
                 * @return const_iterator& iterador que apunta al anterior objeto tipo Pais
                 * del set.
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

                friend class Paises;
        };

        /**
         * @brief Método para obtener el inicio de los países.
         * 
         * @return iterator que apunta al primer elemento del set<Pais>.
         */
        iterator begin();

        /**
         * @brief Método para obtener el inicio de los países.
         * 
         * @return const_iterator que apunta al primer elemento del set<Pais>.
         */
        const_iterator begin() const;

        /**
         * @brief Método para obtener el fin de los países.
         * 
         * @return iterator que apunta al siguiente al último de todos los países.
         */
        iterator end();

          /**
         * @brief Método para obtener el fin de los países.
         * 
         * @return const_iterator que apunta al siguiente al último de todos los países.
         */
        const_iterator end() const;

        /**
         * @brief Método para buscar un país en nuestro set<Paises>.
         * 
         * @param p Pais a buscar.
         * @return iterator que apunta al país encontrado o end() si no 
         * se encuentra.
         */
        iterator find(const Pais &p);

        /**
         * @brief Método para buscar un punto en nuestro set<Paises>.
         * 
         * @param p Punto a buscar.
         * @return const_iterator que apunta al país del punto encontrado o 
         * end() si no se encuentra.
         */
        const_iterator find(const Punto &p);

        /**
         * @brief Sobrecarga del operador >> para el tipo Paises.
         * 
         * @param is Flujo de entrada.
         * @param R Objeto de tipo Paises a leer.
         * @return istream& Flujo de entrada.
         */
        friend istream & operator>>(istream & is, Paises & R);

        /**
         * @brief Sobrecarga del operador << para el tipo Paises.
         * 
         * @param os Flujo de salida.
         * @param R Objeto de tipo Paises a escribir.
         * @return ostream& Flujo de salida.
         */
        friend ostream & operator<<(ostream & os, const Paises &R);
};

#endif