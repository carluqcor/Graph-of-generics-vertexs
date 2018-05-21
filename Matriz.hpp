/*! 
   \file Matriz.hpp
   \brief Fichero de la clase Matriz
   \author Carlos Luque Córdoba
   \date   anywhere
*/

#ifndef _Matriz_HPP_
#define _Matriz_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

#include <vector>

#include "Vertice.hpp"
#include "MatrizInterfaz.hpp"
#include "Punto.hpp"
#include "Grafo.hpp"

//Librería que incluye el uso de abs para el control de cota de error
#include <cmath>

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

	//!  Definición de la clase Matriz
	class Matriz{
		private:
			std::vector <std::vector<float>> _matriz;
			int _n;
		public:
			inline 

	}; // Se cierra la clase Matriz

} //Se cierra el espacio de nombres ed