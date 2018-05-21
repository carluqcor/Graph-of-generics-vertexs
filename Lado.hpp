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

#include <cmath>

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Lado
class Lado{
		std::string _name;
		double _coste;
		Vertice *_u;
		Vertice *_v;

	public:
		//! Constructor públicos de la clase Vertice
		inline Lado(std::string name, Vertice &u, Vertice &v, double coste){
			setLadoName(name);
			setLadoCoste(coste);
			setFirstVertex(u);
			setSecondVertex(v);
		}

		//! Observadores públicos de la clase Lado
		inline std::string getLadoName() const {return _name;}

		inline double getLadoCoste() const {return _coste;}

		inline Vertice const *getFirstVertex() const {return _u;}

		inline Vertice const *getSecondVertex() const {return _v;}

	//	bool has(Vertice const &u);

	//	Vertice const other(Vertice const &u);

		//! Modificadores públicos de la clase Lado

		inline void setLadoName(std::string name){
			_name=name;
		}

		inline void setLadoCoste(double coste){
			_coste=coste;
			#ifndef NDEBUG
				assert(std::abs(getLadoCoste()-coste)<COTA_ERROR);
			#endif
		}

		inline void setFirstVertex(Vertice &u){
			*_u=u;
		}

		inline void setSecondVertex(Vertice &v){
			*_v=v;
		}

	}; //Se cierra la clase Lado
} //Se cierra el espacio de nombres de la asignatura ED
#endif