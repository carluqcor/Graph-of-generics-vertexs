/*! 
   \file Vertice.hpp
   \brief Fichero de la clase Vertice
   \author Carlos Luque Córdoba
   \date   anywhere
*/

#ifndef _Vertice_HPP_
#define _Vertice_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Vertice
class Vertice{
	
	private:
		double _vectorCoordenas[2];
	
	public:
		//! Observadores públicos de la clase Vertice
		double getData();

		int getLabel(double vector);

		//! Modificadores públicos de la clase Vertice

		void setData(double vector);

	}; //Se cierra la clase Vertice
} //Se cierra el espacio de nombres de la asignatura ED
#endif