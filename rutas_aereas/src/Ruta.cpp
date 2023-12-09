/**
 * @file Ruta.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-06
 * 
 */

#include "Paises.cpp"
#include <list>
#include <algorithm>
using namespace std;

// Métodos de la clase Ruta.

class Ruta{

    private:

        list<Punto> puntos;
        string code;
    
    public:


        Ruta():code("none"){}

        void Insertar(const Punto &n){
            puntos.push_back(n);
        }

        void Borrar(const Punto &n){
            list<Punto>::iterator p = std::find(puntos.begin(), puntos.end(), n);
            if (p != puntos.end())
                puntos.erase(p);    
        }

        int GetSize() const{
            return puntos.size();
        }

        string GetCode() const{
            return this->code;
        }

        void SetCode(const string &cod){
            this->code = cod;
        }

        // Métodos de la clase const_iterator

        class const_iterator{

            private:

                list<Punto>::const_iterator p;

            public:

                const Punto & operator*() const{
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
                    return (this->p == it.p);
                }

                bool operator!=(const const_iterator &it) const{
                    return (this->p != it.p);
                }

                friend class Ruta;
        };

        // Métodos de la clase iterator

        class iterator{

            private:

                list<Punto>::iterator p;

            public:

                const Punto & operator*() const{
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

                friend class Ruta;
            };

        // Resto de métodos de la clase Ruta

        iterator begin(){
            iterator it;
            it.p = puntos.begin();
            return it;
        }

        const_iterator begin() const{
            const_iterator it;
            it.p = puntos.begin();
            return it;
        }

        iterator end(){
            iterator it;
            it.p = puntos.end();
            return it;
        }

        const_iterator end() const{
            const_iterator it;
            it.p = puntos.end();
            return it;
        }

        iterator find(const Punto &p){
            list<Punto>::iterator it;
            it = std::find(puntos.begin(), puntos.end(), p);
            iterator sol;
            sol.p = it;
            return sol;
        }

        bool operator==(const Ruta &R) const{
            if (this->GetSize() != R.GetSize())
                return false;
            else{
                const_iterator p, q;
                p=this->begin();
                q=R.begin();
                for (p=this->begin(); p!=this->end(); ++p, ++q)
                    if (*p != *q)
                        return false;
                return true;
            }
        }

        bool operator<(const Ruta &R) const{
            return (this->GetSize() < R.GetSize());
        }

        friend istream & operator>>(istream &is, Ruta &R){
            Ruta aux;
            Punto p;
            int n_puntos;
            is>>aux.code;
            is>>n_puntos;
            for(int i = 0 ; i < n_puntos ; i++){
                is>>p;
                aux.Insertar(p);
            }
            R = aux;
            return is;
        }

        friend ostream & operator<<(ostream &os, const Ruta &R){
            os<<R.code<<" "<<R.GetSize()<<" ";
            for(Ruta::const_iterator it = R.begin() ; it != R.end() ; ++it)
                os<<*it<<" ";
            os << endl;
            return os;
        }
};








