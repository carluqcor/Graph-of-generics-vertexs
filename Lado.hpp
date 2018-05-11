/*! 
   \file Lado.hpp
   \brief Fichero de la clase Lado
   \author Carlos Luque Córdoba
   \date   anywhere
*/

#ifndef _Lado_HPP_
#define _Lado_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

#include "Vertice.hpp"

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Lado
class Lado{

	public:
		//!Observadores públicos de la clase Lado
		inline Lado const getLado(Lado const &Lado) const {return Lado;}

		bool has(Vertice const &u);

		Vertice const other(Vertice const &u);

		Vertice first();

		Vertice second();

		//!Modificadores públicos de la clase Lado
		inline void setLado(Lado &lado, double x, double y){lado(x,y);}

	}; //Se cierra la clase Lado
} //Se cierra el espacio de nombres de la asignatura ED
#endif