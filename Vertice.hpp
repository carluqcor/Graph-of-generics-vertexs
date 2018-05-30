/*! 
   \file Vertice.hpp
   \brief Fichero de la clase Vertice
   \author Carlos Luque Córdoba
   \date   29/05/2018
*/

#ifndef _VERTICE_HPP_
#define _VERTICE_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

#include "Punto.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Vertice dentro del espacio de nombres de la asigantura: ed
namespace ed{
//!  Definición de la plantilla de la clase Punto
template < class T > 

//!  Definición de la clase Vertice
class Vertice{
	
	private:
		//! Atributos privados de la clase Vertice
		T _punto; //!Atributo Privado para el punto de tipo genérico
		int _label; //!Atributo Privado para la etiqueta del vertice
	
	public:
		//! Constructores públicos de la clase Vertice
		/*! 
			\fn        inline Vertice(T punto, int label)
			\brief     Constructor que crea un Vertice a partir de un Punto genérico y una etiqueta
			\attention Función sobrecargada      
			\note 	   Constructor inline  
			\param     punto: Objeto de tipo genérico
			\param     label: de tipo entero
			\pre       Ninguna
			\post      El punto pasado por parámetro y la Etiqueta deben ser iguales a las del Vertice
			\sa        setPunto(), setLabel(), getPunto(), getLabel()
		*/
		inline Vertice(T punto, int label){
			setPunto(punto);
			setLabel(label);
			#ifndef NDEBUG
				assert(getLabel()==label);
			#endif
		}

		/*! 
			\fn        inline Vertice(int label)
			\brief     Constructor que crea un Vertice a partir de una etiqueta
			\attention Función sobrecargada
			\note 	   Constructor inline
			\param     label: de tipo entero
			\pre       Ninguna
			\post      La Etiqueta debe ser igual a la del Vertice
			\sa        setLabel(), getLabel()
		*/
		inline Vertice(int label){
			setLabel(label);
			#ifndef NDEBUG
				assert(getLabel()==label);
			#endif
		}

		//! Observadores públicos de la clase Vertice
		/*! 
			\fn        inline T getPunto() const
			\brief     Función que devuelve el punto genérico del Vertice actual     
			\note 	   Función de tipo inline 
			\return    Devuelve el Punto de tipo genérico del Vertice
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline T getPunto() const {return _punto;} //Controlar asertos

		/*! 
			\fn        inline int const getLabel() const
			\brief     Función que devuelve la etiqueta del Vertice actual     
			\note 	   Función de tipo inline 
			\return    Devuelve la etiqueta del Vertice
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline int const getLabel() const {return _label;}

		//! Modificadores públicos de la clase Vertice
		/*! 
			\fn        inline void setPunto(T const &punto)
			\brief     Ajusta el punto del Vertice con el punto pasado por referencia constante
			\note      Función inline de tipo void
			\param     punto: Punto genérico
			\pre       Ninguna
			\post      El punto del Vertice debe ser igual al pasado por referencia constante
			\sa        getLadoCoste()
		*/
		inline void setPunto(T const &punto){
			_punto=punto;
		}

		/*! 
			\fn        inline void setLabel(int const label)
			\brief     Ajusta la etiqueta del Vertice con la etiqueta pasada por referencia constante
			\note      Función inline de tipo void
			\param     label: Etiqueta de tipo entero
			\pre       Ninguna
			\post      La etiqueta del Vertice debe ser igual a la pasada como parámetro constante
			\sa        getLadoCoste()
		*/
		inline void setLabel(int const label){
			_label=label;
			#ifndef NDEBUG
				assert(getLabel()==label);
			#endif
		}

		//! Función de escritura por terminal
		/*! 
			\fn        inline void imprimirVertice()
			\brief     Muestra por pantalla los datos del Vertice actual
			\note      Función inline de tipo void
			\pre       Ninguna
			\post      Ninguna
			\sa        getPunto(), escribirPunto(), getLabel()
		*/
		inline void imprimirVertice(){
			getPunto().escribirPunto();
			std::cout<<" ->    "<<getLabel()<<RESET<<std::endl;
		}

		//! Operador de la clase Vertice
		/*! 
	      	\fn        Vertice<T> &operator=(Vertice <T> const &u)
		    \brief     Operador de asignación: operador que asigna el vertice actual al pasado por referencia constante
		    \attention Se sobrecarga el operador de asignación "="
		    \note      Función inline de tipo Vertice genérico
		    \warning   Se requiere que la funcion de acceso getPunto(), getLabel() tengan el modificador const
		    \param     u: Objeto de la clase Vertice pasado como referencia constante de tipo Genérico
		    \pre       Ninguna
		    \post      Ninguna
		    \sa        Ninguna
	   */
		inline Vertice<T> &operator=(Vertice<T> const &u){
			return (*(this)=u);
		}
	}; //Se cierra la clase Vertice
} //Se cierra el espacio de nombres de la asignatura ED
#endif