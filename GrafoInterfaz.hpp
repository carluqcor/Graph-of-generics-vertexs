/*!
	\file GrafoInterfaz.hpp
	\brief Se define la interfaz del TAD Grafo.
    \author Carlos Luque Córdoba
    \date   anywhere
*/

#ifndef _GRAFO_INTERFAZ_HPP
#define _GRAFO_INTERFAZ_HPP

#include "Grafo.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{
	//!  Definición de la clase MonticuloMedicionesInterfaz
	class GrafoInterfaz{





/*¿SE DEBEN DEFINIR LAS FUNCIONES DE MOVIMIENTO DEL CURSOR?*/








		public:			
		//!Observadores Públicos
		 /*!
        	\brief  Comprueba si el monticulo está vacía
			\note   Función virtual pura, que deberá ser redefinida en la clase heredera
	        \note   Función de tipo "const": no puede modificar al objeto actual
        	\return true, si la lista está vacía; false, en caso contrario
    	*/
		virtual bool isEmpty() const = 0;

		//!Modificadores Públicos
		/*!
	        \brief  Inserta un vertice mediante las componentes x e y
			\note   Función virtual pura, que deberá ser redefinida en la clase heredera
	        \note   Modifica al objeto actual
	        \param  x: Componente x del vertice 
	        \param  y: Componente  del vertice 
    	*/
		virtual void addVertex(double x, double y) = 0;

		/*!
	        \brief  Inserta un lado que conectan 2 vertices
			\note   Función virtual pura, que deberá ser redefinida en la clase heredera
	        \note   Modifica al objeto actual
	        \param  u: Vertice de tipo Vertice 
	        \param  v: Vertice de tipo Vertice
	        \param  lado: Lado de tipo Lado para unir los dos vertices 
    	*/
		virtual void addEdge(Vertice const &u, Vertice const &v, Lado &lado) = 0;

		/*!
	        \brief  Elimina el vertice actual
			\note   Función virtual pura, que deberá ser redefinida en la clase heredera
	        \note   Modificar al objeto actual
    	*/
		virtual void removeVertex() = 0;

		/*!
	        \brief  Elimina el lado actual
			\note   Función virtual pura, que deberá ser redefinida en la clase heredera
	        \note   Modificar al objeto actual
    	*/
		virtual void removeEdge() = 0;

		/*!
	        \brief  Elimina todos los lados y luego los vertices
			\note   Función virtual pura, que deberá ser redefinida en la clase heredera
	        \note   Modificar al objeto actual
    	*/
		virtual void removeAllVertexAndEdges() = 0;

	}; // Clase MonticuloMedicionesInterfaz

} // Espacio de nombres ed

#endif //  _GRAFO_INTERFAZ_HPP
