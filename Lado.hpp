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

#include "Punto.hpp"
#include "Vertice.hpp"


// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la plantilla de la clase Grafo
template < class T > 

//!  Definición de la clase Lado
class Lado{
	private:
		float _coste;
		Vertice<T> *_u;
		Vertice<T> *_v;

	public:
		//! Constructor públicos de la clase Vertice
		inline Lado(Vertice<T> &u, Vertice<T> &v, float coste){
			setLadoCoste(coste);
			setFirstVertex(u);
			setSecondVertex(v);
		}

		//! Observadores públicos de la clase Lado
		inline float getLadoCoste() const {return _coste;}

		inline Vertice<T> const *getFirstVertex() const {return _u;}

		inline Vertice<T> const *getSecondVertex() const {return _v;}

	//	bool has(Vertice const &u);

		inline Vertice<T> const other(Vertice<T> &u){
			if(u==getFirstVertex())
				return getSecondVertex();
			else
				return getFirstVertex();
		}

		//! Modificadores públicos de la clase Lado
		inline void setLadoCoste(float coste){
			_coste=coste;
		}

		inline void setFirstVertex(Vertice<T> &u){
			*_u=u;
		}

		inline void setSecondVertex(Vertice<T> &v){
			*_v=v;
		}

	}; //Se cierra la clase Lado
} //Se cierra el espacio de nombres de la asignatura ED
#endif