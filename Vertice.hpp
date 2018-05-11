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
		double _x,
		double _y;
	
	public:
		//! Observadores públicos de la clase Vertice
		inline double const getDataX()const{return _x;}

		inline double const getDataY()const{return _y;}

		int getLabel(double vector);

		//! Modificadores públicos de la clase Vertice

		inline void setDataX(double vector){
			_x=vector;	

			#ifndef NDEBUG
				assert(std::abs(getDataX()-vector)<COTA_ERROR);
			#endif
		}

		inline void setDataY(double vector){
			_y=vector;
			
			#ifndef NDEBUG
				assert(std::abs(getDataY()-vector)<COTA_ERROR);
			#endif
		}

		inline void setData(double x, double y){
			setDataX(x);
			setDataY(y);
		}
	}; //Se cierra la clase Vertice
} //Se cierra el espacio de nombres de la asignatura ED
#endif