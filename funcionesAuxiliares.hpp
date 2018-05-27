/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 4
  \author Carlos Luque Córdoba
  \date   Anywhere
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "macros.hpp"
#include "distancia.hpp"
#include "Punto.hpp"
#include "Vertice.hpp"
#include "Lado.hpp"
#include "Grafo.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
 	int menu();

	void anadirVertices(std::string const & nombreFichero, Grafo <Punto<float> > graph);

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FuncionesAuxiliares_HPP_

#endif