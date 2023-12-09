/**
 * @file Pais.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include "Punto.cpp"

class Pais{

	private:

  		Punto p;
        string pais;
        string bandera;

	public:	

		Pais():pais("none"), bandera("none"){}

		Pais(const Punto &punto, string Pais, string Bandera):
			p(punto), pais(Pais), bandera(Bandera) {}

		Punto GetPunto() const {return p;}

		string GetPais() const {return pais;}

		string GetBandera() const {return bandera;}

		bool operator<(const Pais &p) const{
			return this->GetPais() < p.GetPais();
		}

		bool operator==(const Pais &p) const{
			return this->GetPunto() == p.GetPunto() && this->GetPais() == p.GetPais() &&
				this->GetBandera() == p.GetBandera();
		}

		bool operator==(const Punto &P) const{
			return this->GetPunto() == p;
		}

		friend istream & operator>>(istream & is, Pais & P){
			double lat,lng;
			
			is>>lat>>lng>>P.pais>>P.bandera;
			
			P.p=Punto(lat,lng,"");
			return is;
		}

		friend ostream & operator<<(ostream & os, const Pais &P){
			os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
			return os;
		}
};