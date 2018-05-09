/*! 
   \file Grafo.hpp
   \brief Fichero de la clase Grafo
   \author Carlos Luque Córdoba
   \date   anywhere
*/

#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

#include "Vertice.h"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Grafo
class Grafo{
	
	private:
		Vertice _grafoVector[]; //!Vector de vertices
		int _grafoMatriz [size()] [size()]; //!Matriz cuadrada de adyacencias
	
	public:
		//!Constructores de la clase Grafo
		
		//!Observadores públicos de la clase Grafo

		//!Modificadores públicos de la clase Grafo

	}; //Se cierra la clase Grafo
} //Se cierra el espacio de nombres de la asignatura ED
#endif