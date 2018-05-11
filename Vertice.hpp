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

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Vertice dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Vertice
class Vertice{
	
	private:
		double _vectorCoordenas[2];
		int _i=0;
	
	public:
		//! Observadores públicos de la clase Vertice
		inline double getDataX(){return _vectorCoordenas[0];}

		inline double getDataY(){return _vectorCoordenas[1];}

		int getLabel(double vector);

		//! Modificadores públicos de la clase Vertice

		inline void setDataX(double vector){
			_vectorCoordenas[0]=vector;	

			#ifndef NDEBUG
				assert(std::abs(getDataX()-vector)<COTA_ERROR);
			#endif
		}

		inline void setDataY(double vector){
			_vectorCoordenas[1]=vector;
			
			#ifndef NDEBUG
				assert(std::abs(getDataY()-vector)<COTA_ERROR);
			#endif
		}

		inline void setData(double x, double y){
			setDataX(x);
			setDataY(y);
		//	t++;
		//	aumentarEtiqueta(t);
		}
/*
		inline void aumentarEtiqueta(int t){
			_i=t;
		}
*/
	}; //Se cierra la clase Vertice
} //Se cierra el espacio de nombres de la asignatura ED
#endif