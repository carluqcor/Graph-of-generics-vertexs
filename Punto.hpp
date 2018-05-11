/*! 
   \file Punto.hpp
   \brief Fichero de la clase Punto
   \author Carlos Luque Córdoba
   \date   anywhere
*/

#ifndef _PUNTO_HPP_
#define _PUNTO_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Grafo
class Punto{
	
	private:
		double _x //!Atributo para la posición x del punto
		double _y //!Atributo para la posición y del punto

	public:
		//!Constructores de la clase Grafo
		inline Punto(double x, double y){
			_x=x;
			_y=y;
		}
		//!Observadores públicos de la clase Grafo

		//!Modificadores públicos de la clase Grafo

	}; //Se cierra la clase Grafo
} //Se cierra el espacio de nombres de la asignatura ED
#endif