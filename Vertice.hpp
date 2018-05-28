/*! 
   \file Vertice.hpp
   \brief Fichero de la clase Vertice
   \author Carlos Luque Córdoba
   \date   anywhere
*/

#ifndef _VERTICE_HPP_
#define _VERTICE_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

#include "Punto.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Vertice dentro del espacio de nombres de la asigantura: ed
namespace ed{
//!  Definición de la plantilla de la clase Punto
template < class T > 

//!  Definición de la clase Vertice
class Vertice{
	
	private:
		T _punto;
		int _label;
	
	public:
		//! Constructores públicos de la clase Vertice
		inline Vertice(T punto, int label){
			setPunto(punto);
			setLabel(label);
		}

		inline Vertice(int label){
			setLabel(label);
		}

	//	inline Vertice(Vertice<T> const &vertice){
	//		setPunto(vertice.getPunto());
	//		setLabel(vertice.getLabel());
	//	}

		//! Observadores públicos de la clase Vertice
		inline T getPunto() const {return _punto;} //Controlar asertos

		inline int const getLabel() const {return _label;}

		//! Modificadores públicos de la clase Vertice
		inline void setPunto(T const &punto){
			_punto=punto;
		}

		inline void setLabel(int const label){
			_label=label;
		}

		inline void imprimirVertice(){
			getPunto().escribirPunto();
			std::cout<<" "<<getLabel()<<RESET<<std::endl;
		}

		inline Vertice<T> &operator=(Vertice<T> const &u){
			return (*(this)=u);
		}
	}; //Se cierra la clase Vertice
} //Se cierra el espacio de nombres de la asignatura ED
#endif