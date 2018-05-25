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
		int _labelv1;
		int _labelv2;

	public:
		//! Constructor públicos de la clase Vertice
		inline Lado(int labelv1, int labelv2, float coste){
			setLadoCoste(coste);
			setFirstVertex(labelv1);
			setSecondVertex(labelv2);
		}

		inline Lado(float coste){
			setLadoCoste(coste);
		}

		//! Observadores públicos de la clase Lado
		inline float const getLadoCoste() const {return _coste;}

		inline int const getFirstVertex() const {return _labelv1;}

		inline int const getSecondVertex() const {return _labelv2;}

	//	bool has(Vertice const &u);

		inline int const other(int const labelv1){
			if(labelv1==getFirstVertex())
				return getSecondVertex();
			else
				return getFirstVertex();
		}

		//! Modificadores públicos de la clase Lado
		inline void setLadoCoste(float const coste){
			_coste=coste;
		}

		inline void setFirstVertex(int const label){
			_labelv1=label;
		}

		inline void setSecondVertex(int const label){
			_labelv2=label;
		}

		inline bool const &operator==(Lado<T> const &u){
			if(*this==u)
				return true;
			else
				return false;
		}

		void imprimirLado(){
			std::cout<<*this<<std::endl;
		}

	}; //Se cierra la clase Lado

	//! Sobrecarga del operador de salida
	//!  Definición de la plantilla de la clase Grafo
	template < class T > 
	ostream &operator<<(ostream &stream, Lado<T> const &lado){
		stream << lado.getFirstVertex();
		stream << " ";
		stream << lado.getSecondVertex();
		stream << " ";
		stream << lado.getLadoCoste();
		stream << "\n";

		return stream;
	}

} //Se cierra el espacio de nombres de la asignatura ED
#endif