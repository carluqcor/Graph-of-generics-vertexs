/*! 
   \file  Vertice.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vertice
   \author Carlos Luque Córdoba
   \date   25/04/2018
*/


// Ficheros de cabecera
#include <iostream>

//Se incluye el fichero hpp
#include "Vertice.hpp"

#include "macros.hpp"

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


//! Modificadores públicos de la clase Vertice
double ed::Vertice::getData(double ){

}

int ed::Vertice::getLabel(double vector){

}

//! Modificadores públicos de la clase Vertice
void ed::Vertice::setData(double vector){

}


namespace ed{

	// Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Vertice const &vertice){

	}

	// Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Vertice &vertice){

	} 

} // Fin del espacio de nombres ed
