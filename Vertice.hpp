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

// Abs para cotas de error de numeros reales positivos
#include <cmath>

#include "Punto.hpp"


#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Vertice dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Vertice
class Vertice{
	
	private:
		Punto<float> _punto;
		unsigned int _label;
	
	public:
		//! Constructores públicos de la clase Vertice
		inline Vertice(Punto<float> punto, unsigned int label=-1){
			setPunto(punto);
			setLabel(label);
		}
/*
		inline Vertice(Vertice &vertice){
			setVertice(vertice);
		}
*/
		//! Observadores públicos de la clase Vertice
		inline Punto<float> const getPunto() const {return _punto;} //Controlar asertos

		inline int getLabel() const {return _label;}

		//! Modificadores públicos de la clase Vertice
		inline void setPunto(Punto<float> &punto){
			_punto=punto;
		}

		inline void setLabel(int label){
			_label=label;
		}


		/*inline void setVertice(Vertice &vertice){
			_vertex=vertice;
		}*/

		inline Vertice &operator=(Vertice const &u){
			return (*(this)=u);
		}



	}; //Se cierra la clase Vertice
} //Se cierra el espacio de nombres de la asignatura ED
#endif