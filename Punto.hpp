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

#include "Vertice.hpp"

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Punto
class Punto{

	public:
		//!Constructores de la clase Punto
		inline Punto(double x=0.0, double y=0.0){
			setDataX(x);
			setDataY(y);
		}
		//!Observadores públicos de la clase Punto
		inline Punto const getPunto(Punto const &punto) const {return punto;} //Controlar asertos

		//!Modificadores públicos de la clase Punto
		inline void setPunto(Punto &punto, double x, double y){Punto(x,y);}

	}; //Se cierra la clase Punto
} //Se cierra el espacio de nombres de la asignatura ED
#endif