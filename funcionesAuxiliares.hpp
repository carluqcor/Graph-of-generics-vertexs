/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 4
  \author Carlos Luque Córdoba
  \date   29/05/2018
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

/*!	(
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
 	int menu();
	
	/*! 
		\fn        vector<vector<float> > prim(Grafo <Punto<float> > &graph, ed::Grafo <ed::Punto<float> > &graph2)
		\brief     Función que genera el arbol abarcador según el algoritmo de Prim
		\note      Función de tipo vector de vectores flotantes
		\param     graph: Grafo de tipo puntos flotantes pasado por referencia
		\param     graph2: Grafo de tipo puntos flotantes pasado por referencia
		\attention El grafo debe ser conexo
		\pre       Ninguna
		\post      Ninguna
		\sa        Ninguna
	*/
 	std::vector<std::vector<float> > prim(Grafo <Punto<float> > &graph, ed::Grafo <ed::Punto<float> > &graph2);
 	
	/*! 
		\fn        vector<vector<float> > kruskal(Grafo <Punto<float> > &graph, ed::Grafo <ed::Punto<float> > &graph2)
		\brief     Función que genera el arbol abarcador según el algoritmo de Kruskal
		\note      Función de tipo vector de vectores flotantes
		\param     graph: Grafo de tipo puntos flotantes pasado por referencia
		\param     graph2: Grafo de tipo puntos flotantes pasado por referencia
		\attention El grafo debe ser conexo
		\pre       Ninguna
		\post      Ninguna
		\sa        Ninguna
	*/
 	std::vector<std::vector<float> > kruskal(Grafo <Punto<float> > &graph, ed::Grafo <ed::Punto<float> > &graph2);

 	/*! 
		\fn        void cargarFichero(ed::Grafo <ed::Punto<float> > &graph, bool directed)
		\brief     Función que permite cargar un fichero con vertices y/o lados
		\note      Función de tipo void
		\param     graph: Grafo de tipo puntos flotantes pasado por referencia
		\param     directed: Booleano que permite conocer el estado del grafo
	*/
 	void cargarFichero(ed::Grafo <ed::Punto<float> > &graph, bool directed);

 	/*! 
		\fn        bool grabarFichero(ed::Grafo <ed::Punto<float> > &graph, bool p, bool k)
		\brief     Función que permite grabar en 3 ficheros diferentes la matriz de adyacencias y las matrices de los caminos míminimos de los arboles abarcadores
		\note      Función de tipo bool
		\return    Nos permite conocer si se ha generado la matriz de adyacencias
		\param     graph: Grafo de tipo puntos flotantes pasado por referencia
		\param     p: Booleano que nos permite conocer si Prim se ha ejecutado
		\param     k: Booleano que nos permite conocer si Kruskal se ha ejecutado
	*/
 	bool grabarFichero(ed::Grafo <ed::Punto<float> > &graph, bool p, bool k);

 	/*! 
		\fn        void generarPNGPrim(char *nombreFichero2, std::vector<float> padre, std::vector<float> hijo, std::vector<float> coste)
		\brief     Función que permite generar el fichero .dot para la creación del PNG del arbol abarcador del algoritmo de Prim
		\note      Función de tipo void
		\param     nombreFichero2: Char para el nombre del fichero, ya que se usan la función fprintf()
		\param     padre: Vector de flotantes donde se guardan los lados visitados
		\param     hijo: Vector de flotantes donde se guardan los lados a visitar
		\param     coste: Vector de flotantes donde se guardan los costes de los lados por los que ha pasado el arbol abarcador
		\attention El grafo debe ser conexo
		\attention El fichero debe tener extensión .dot
	*/
 	void generarPNGPrim(char *nombreFichero2, std::vector<float> padre, std::vector<float> hijo, std::vector<float> coste);

 	/*! 
		\fn        void generarPNGKruskal(char *nombreFichero2, std::vector<float> padre, std::vector<float> hijo, std::vector<float> coste)
		\brief     Función que permite generar el fichero .dot para la creación del PNG del arbol abarcador del algoritmo de Kruskal
		\note      Función de tipo void
		\param     nombreFichero2: Char para el nombre del fichero, ya que se usan la función fprintf()
		\param     padre: Vector de flotantes donde se guardan los lados visitados
		\param     hijo: Vector de flotantes donde se guardan los lados a visitar
		\param     coste: Vector de flotantes donde se guardan los costes de los lados por los que ha pasado el arbol abarcador
		\attention El grafo debe ser conexo
		\attention El fichero debe tener extensión .dot
	*/
 	void generarPNGKruskal(char *nombreFichero2, std::vector<float> padre, std::vector<float> hijo, std::vector<float> coste);

 	/*! 
		\fn        void principio()
		\brief     Función que nos permite elegir entre Dirigido, No dirigido o salir del programa al iniciarlo
		\note      Función de tipo bool
	*/
	bool principio();

	/*! 
		\fn        void borrarVerticeLados(ed::Grafo <ed::Punto<float> > &graph)
		\brief     Función que permite borrar los lados conectados de un vertice en el Grafo
		\note      Función de tipo void
		\param     graph: Grafo de tipo puntos flotantes pasado por referencia
	*/
	void borrarVerticeLados(ed::Grafo <ed::Punto<float> > &graph);

	/*! 
		\fn        void leerLado(ed::Grafo <ed::Punto<float> > &graph)
		\brief     Función que permite añadir un lado por pantalla
		\note      Función de tipo void
		\param     graph: Grafo de tipo puntos flotantes pasado por referencia
	*/
	void leerLado(ed::Grafo <ed::Punto<float> > &graph);

	/*! 
		\fn        void leerVertice(ed::Grafo <ed::Punto<float> > &graph)
		\brief     Función que permite añadir un vertice por pantalla
		\note      Función de tipo void
		\param     graph: Grafo de tipo puntos flotantes pasado por referencia
	*/
	void leerVertice(ed::Grafo <ed::Punto<float> > &graph);
} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FuncionesAuxiliares_HPP_

#endif