/**
 * @file Paises.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief 
 * @date 2023-12-04
 * 
 */

#include "Pais.cpp"
#include <set>

class Paises{

	private:
		set<Pais> datos;

	public:

			
		Paises(){}

		// Métodos de la clase Paises

		void Insertar(const Pais &p){
			datos.insert(p);
		}

		void Borrar(const Pais &p){
			datos.erase(p);
		}

		// Métodos de la clase iterator
		class iterator{
			private:
				set<Pais>::iterator p;

			public:

				const Pais & operator*() const{
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

				friend class Paises;
		};
		// Métodos de la clase const_iterator

		class const_iterator{

			private:

				set<Pais>::const_iterator p;

			public:

				const Pais & operator*() const{
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

				friend class Paises;
		};

		// Resto de métodos de la clase Paises

		friend istream & operator>>(istream & is, Paises & R){
			Paises rlocal;
			//leemos el comentario
			if (is.peek()=='#'){
				string a;
				getline(is,a);
			}	
				
			Pais P;
			while (is>>P){
				rlocal.Insertar(P);
				
			}
			R=rlocal;
			return is;
		}

		iterator begin(){
			iterator it;
			it.p = datos.begin();
			return it;
		}

		const_iterator begin() const{
			const_iterator it;
			it.p = datos.begin();
			return it;
		}

		iterator end(){
			iterator it;
			it.p = datos.end();
			return it;
		}

		const_iterator end() const{
			const_iterator it;
			it.p = datos.end();
			return it;
		}

		iterator find(const Pais &p){
			iterator it;
			it.p = datos.find(p);
			return it;
		}

		const_iterator find(const Punto &p){
			const_iterator it;
			for (it.p=datos.begin(); it.p!=datos.end(); ++it.p){
				if ((it.p)->GetPunto() == p)
					return it;
			}
			const_iterator fin;
			fin.p=datos.end();
			return fin; 
		}


		friend ostream & operator<<(ostream & os, const Paises &R){
			
			Paises::const_iterator it;
			for (it=R.begin(); it!=R.end(); ++it){
				os<<*it<<"\t";
			}
			return os;
		}
};

