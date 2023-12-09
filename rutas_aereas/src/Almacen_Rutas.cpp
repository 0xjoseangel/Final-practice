/**
 * @file Almacen_Rutas.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-06
 * 
 */

#include "Ruta.cpp"
#include <map>

using namespace std;

// Métodos de la clase Almacen_Rutas

class Almacen_Rutas{

    private:

        map<string, Ruta> rutas;

    public:

        void Insertar(const Ruta &R){
            pair<string, Ruta> pair;
            pair.first=R.GetCode();
            pair.second=R;
            rutas.insert(pair);
        }

        void Borrar(const Ruta &R){
            rutas.erase(R.GetCode());
        }

        Ruta GetRuta(const string &a){
            return rutas[a];
        }

        // Métodos de la clase iterator

        class iterator{

            private:

                map<string, Ruta>::iterator p;
            
            public:

                const pair<string, Ruta> & operator*() const{
                    return *p;
                }

                iterator & operator++(){
                    ++p;
                    return *this;
                }

                iterator & operator--(){
                    --p;
                    return *this;
                }

                bool operator==(const iterator &it) const{
                    return (this->p == it.p);
                }

                bool operator!=(const iterator &it) const{
                    return (this->p != it.p);
                }

                friend class Almacen_Rutas;
        };

        // Métodos de la clase const_iterator

        class const_iterator{

            private:

                map<string, Ruta>::const_iterator p;

            public:

                const pair<string, Ruta> & operator*() const{
                    return *p;
                }

                const_iterator & operator++(){
                    ++p;
                    return *this;
                }

                const_iterator & operator--(){
                    --p;
                    return *this;
                }

                bool operator==(const const_iterator &it) const{
                    return this->p == it.p;
                }

                bool operator!=(const const_iterator &it) const{
                    return this->p != it.p;
                }

                friend class Almacen_Rutas;
        };

        // Resto de métodos de la clase Almacen_Rutas

        iterator begin(){
            iterator it;
            it.p=rutas.begin();
            return it;
        }

        const_iterator begin() const{
            const_iterator it;
            it.p=rutas.begin();
            return it;
        }


        iterator end(){
            iterator it;
            it.p=rutas.end();
            return it;
        }

        const_iterator end() const{
            const_iterator it;
            it.p=rutas.end();
            return it;
        }

        friend ostream & operator<<(ostream &os, const Almacen_Rutas &AR){
            os << "#Rutas" << endl;
            Almacen_Rutas::const_iterator it;
            for(it = AR.begin() ; it != AR.end() ; ++it)
                os << (*it).second;
            os << endl;
            return os;
        }
};

