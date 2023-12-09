/**
 * @file Punto.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include <iostream>
#include <cassert>
using namespace std;

class Punto{
    
    private:
    
        double latitud, longitud;
    
    public:

        Punto():latitud(0), longitud(0){}

        Punto(double l, double L, const string &d){
            assert(-90<=l<=90 && -180<=L<=180);
            this->latitud=l;
            this->longitud=L;
        }

        double GetLatitud() const{
            return this->latitud;
        }

        double GetLongitud() const{
            return this->longitud;
        }

        void SetLatitud(double l){
            assert(-90<=l<=90);
            this->latitud=l;
        }

        void SetLongitud(double L){
            assert(-180<=L<=180);
            this->longitud=L;
        }

        bool operator<(const Punto &p) const{
            return (this->GetLongitud()) < (p.GetLongitud());
        }

        bool operator==(const Punto &p) const{
            return ((this->GetLatitud() == p.GetLatitud()) &&
            (this->GetLongitud() == p.GetLongitud()));
        }

        bool operator!=(const Punto &p) const{
            return ((this->GetLatitud() != p.GetLatitud()) ||
            (this->GetLongitud() != p.GetLongitud()));
        }

        friend istream & operator>>(istream &is, Punto &p){
            char aux;
            // Leemos omitiendo los paréntesis y la coma
            is >> aux >> p.latitud >> aux >> p.longitud >> aux;
            return is;
        }

        friend ostream & operator<<(ostream &os, const Punto &p){
            os << "(" << p.GetLatitud() << "," << p.GetLongitud() << ")";
            return os;
        }
};