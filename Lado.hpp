/*! 
   \file Lado.hpp
   \brief Fichero de la clase Lado
   \author Carlos Luque Córdoba
   \date   29/05/2018
*/

#ifndef _Lado_HPP_
#define _Lado_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

#include "Punto.hpp"
#include "Vertice.hpp"
#include "macros.hpp"

// Abs para cotas de error de numeros reales positivos
#include <cmath>

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales



// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la plantilla de la clase Grafo
template < class T > 

//!  Definición de la clase Lado
class Lado{
	private:
		//! Atributos privados de la clase Punto
		float _coste; //! Atributo privado para el coste del Lado
		int _labelv1; //! Atributo privado para la primera etiqueta del lado
		int _labelv2; //! Atributo privado para la segunda etiqueta del lado

	public:
		//! Constructor públicos de la clase Lado
		/*! 
			\fn        inline Lado(int labelv1, int labelv2, float coste)
			\brief     Constructor que crea un Lado a partir de dos etiquetas de dos vertices y la distancia euclídea entre ellos
			\attention Función sobrecargada        
			\param     labelv1: Label de tipo entero
			\param     labelv2: Label de tipo entero
			\param     coste de tipo float
			\pre       Ninguna
			\post      Los valores de las etiquetas deben ser iguales a las del Punto actual y la resta entre el coste del Punto y el coste pasado por parámetro debe ser menor a la cota de error
			\sa setLadoCoste(), setFirstVertex(), setSecondVertex(), getLadoCoste(), getFirstVertex(), getSecondVertex()
		*/
		inline Lado(int labelv1, int labelv2, float coste){
			setLadoCoste(coste);
			setFirstVertex(labelv1);
			setSecondVertex(labelv2);
			#ifndef NDEBUG
				assert(getFirstVertex()==labelv1);
				assert(getSecondVertex()==labelv2);
				assert(std::abs(getLadoCoste()-coste)<COTA_ERROR);
			#endif
		}
		/*! 
			\fn        inline Lado(int labelv1, int labelv2)
			\brief     Constructor que crea un Lado a partir de dos etiquetas de dos vertices
			\attention Función sobrecargada        
			\param     labelv1: Label de tipo entero
			\param     labelv2: Label de tipo entero
			\pre       Ninguna
			\post      Los valores de las etiquetas deben ser iguales a las del Punto actual
			\sa        setFirstVertex(), setSecondVertex(), getFirstVertex(), getSecondVertex()
		*/
		inline Lado(int labelv1, int labelv2){
			setFirstVertex(labelv1);
			setSecondVertex(labelv2);
			#ifndef NDEBUG
				assert(getFirstVertex()==labelv1);
				assert(getSecondVertex()==labelv2);
			#endif
		}

		/*! 
			\fn        inline Lado(float coste)
			\brief     Constructor que crea un Lado a partir del un coste
			\attention Función sobrecargada        
			\param     coste: Coste de tipo float
			\pre       Ninguna
			\post      La resta entre el coste del Punto y el coste pasado por parámetro debe ser menor a la cota de error
			\sa setLadoCoste(), getLadoCoste()
		*/
		inline Lado(float coste){
			setLadoCoste(coste);
			#ifndef NDEBUG
				assert(std::abs(getLadoCoste()-coste)<COTA_ERROR);
			#endif
		}

		//! Observadores públicos de la clase Lado
		/*! 
			\fn        inline float const getLadoCoste() const 
			\brief     Devuelve el coste del Lado
			\note      Función inline de tipo float
			\return    Coste de tipo float
			\pre       Ninguna
			\post      Ninguna
			\sa        getLadoCoste()
		*/
		inline float const getLadoCoste() const {return _coste;}

		/*! 
			\fn        int const getFirstVertex() const  
			\brief     Devuelve la primera etiqueta del vertice del lado
			\note      Función inline de tipo int
			\return    Coste de tipo int
			\pre       Ninguna
			\post      Ninguna
			\sa        getFirstVertex()
		*/
		inline int const getFirstVertex() const {return _labelv1;}

		/*! 
			\fn        int const getSecondVertex() const  
			\brief     Devuelve la segunda etiqueta del vertice del lado
			\note      Función inline de tipo int
			\return    Coste de tipo int
			\pre       Ninguna
			\post      Ninguna
			\sa        getSecondVertex()
		*/
		inline int const getSecondVertex() const {return _labelv2;}

		/*! 
			\fn        int const other(int const labelv1) 
			\brief     Devuelve la etiqueta contraria a la pasada por parámetro
			\note      Función inline de tipo int
			\param     labelv1: Etiqueta de tipo int
			\pre       Ninguna
			\post      Ninguna
			\sa        getSecondVertex(), getFirstVertex()
		*/
		inline int const other(int const labelv1){
			if(labelv1==getFirstVertex())
				return getSecondVertex();
			else if(labelv1==getSecondVertex())
				return getFirstVertex();
			return 0;
		}

		//! Modificadores públicos de la clase Lado
		/*! 
			\fn        inline float const setLadoCoste(float const coste) const 
			\brief     Ajusta el lado del coste con el coste pasado por parámetro
			\note      Función inline de tipo void
			\param     coste: Coste de tipo float
			\pre       Ninguna
			\post      La resta entre el coste del Punto y el coste pasado por parámetro debe ser menor a la cota de error
			\sa        getLadoCoste()
		*/
		inline void setLadoCoste(float const coste){
			_coste=coste;
			#ifndef NDEBUG
				assert(std::abs(getLadoCoste()-coste)<COTA_ERROR);
			#endif
		}

		/*! 
			\fn        inline float const setFirstVertex(int const label) const 
			\brief     Ajusta la primera etiqueta del lado con el label pasado por parámetro
			\note      Función inline de tipo void
			\param     label: Label de tipo entero
			\pre       Ninguna
			\post      El valor de la primero etiqueta debe ser igual a la del Punto actual 
			\sa        getFirstVertex
		*/
		inline void setFirstVertex(int const label){
			_labelv1=label;
			#ifndef NDEBUG
			assert(getFirstVertex()==label);
			#endif
		}
		
		/*! 
			\fn        inline float const setSecondVertex(int const label) const 
			\brief     Ajusta la segunda etiqueta del lado con el label pasado por parámetro
			\note      Función inline de tipo void
			\param     label: Label de tipo entero
			\pre       Ninguna
			\post      El valor de la segunda etiqueta debe ser igual a la del Punto actual 
			\sa        getFirstVertex
		*/
		inline void setSecondVertex(int const label){
			_labelv2=label;
			#ifndef NDEBUG
			assert(getSecondVertex()==label);
			#endif
		}

		//! Operador de la clase Lado
		/*! 
	      	\fn        bool &operator==(Lado <T> const &u)
		    \brief     Operador de igualdad: operador que comprueba si un lado es igual al pasado por referencia
		    \attention Se sobrecarga el operador de asignación "=="
		    \note      Función inline de tipo bool
		    \warning   Se requiere que la funcion de acceso getLadoCoste(), getFirstVertex(), getSecondVertex() tengan el modificador const
		    \param     u: Objeto de la clase Lado pasado como referencia constante de tipo Genérico
		    \pre       Ninguna
		    \post      Ninguna
		    \sa        Ninguna
	   */
		inline bool const &operator==(Lado<T> const &u){
			if(*(this)==u)
				return true;
			else
				return false;
		}

		//! Función de escritura por pantalla
		/*! 
			\fn        inline void imprimirLado()
			\brief     Muestra por pantalla los datos del Lado actual
			\note      Función inline de tipo void
			\pre       Ninguna
			\post      Ninguna
			\sa        getFirstVertex(), getSecondVertex(), getLadoCoste()
		*/
		inline void imprimirLado(){
			std::cout<<BIGREEN<<" V1: "<< this->getFirstVertex()<<" V2: "<<this->getSecondVertex()<< " coste: "<<this->getLadoCoste()<<" "<<RESET;
		}

	}; //Se cierra la clase Lado

	//! Sobrecarga del operador de salida

	//!  Definición de la plantilla de la clase Grafo
	template < class T > 

	/*!
		\fn        ostream &operator<<(ostream &stream, std::vector<Lado<T> > &lado)
        \brief     Sobrecarga del operador de salida "<<"
        \param     stream: Flujo de entrada
        \param     lado: Objeto de la clase Lado pasado como referencia constante de tipo Genérico 
        \sa        operator<<()
   */
	ostream &operator<<(ostream &stream, std::vector<Lado<T> > &lado){
		stream << "graph A {";
		stream << "\n";
		for(unsigned int i=0; i<lado.size();i++){
			stream << lado[i].getFirstVertex();
			stream << " -- ";
			stream << lado[i].getSecondVertex();
			stream << " [label=\"";
			stream << lado[i].getLadoCoste();
			stream << "\"];\n";
		}
		stream << "}";
		return stream;
	}


} //Se cierra el espacio de nombres de la asignatura ED
#endif