/*! 
   \file  Punto.hpp
   \brief Fichero que contiene el código de las funciones de la clase Grafo
   \author Carlos Luque Córdoba
   \date   29/05/2018
*/
#ifndef _PUNTO_HPP_
#define _PUNTO_HPP_

// Facilita la entrada y salida 
#include <iostream>
#include <fstream>
// atoi, atof
#include <stdlib.h>

#include "macros.hpp"

// 
using std::ostream;
using std::istream;

namespace ed {

//!  Definición de la plantilla de la clase Punto
template < class T > 
	
	class Punto{
	  //! \name Atributos privados de la clase Punto
	   private: 
	      	T _x; //!< abscisa del Punto 
			T _y; //!< ordenada del Punto 


	   //! \name Funciones o métodos públicos de la clase Punto
	   public:

		//! \name CONSTRUCTORES
		/*! 
			\fn        inline Punto(T x=0, T y=0)
			\brief     Constructor que crea un Punto a partir de sus coordenadas x e y
			\attention Función sobrecargada        
		 	\note      Los parámetros tienen valores por defecto
			\param     x de tipo T, valor por defecto 0
			\param     y de tipo T, valor por defecto 0
			\pre       Los valores de x e y deben ser del tipo T
			\post      Los atributos de la clase Punto deben tener los valores x e y, respectivamente
			\sa setX(), setY()
		*/
		inline Punto(T x=0, T y=0)
		{
			setX(x);
			setY(y);

		}

		/*! 
			\fn 	   inline Punto(Punto const &q)
			\brief     Constructor de "copia" que crea un Punto a partir de otro Punto
			\attention Función sobrecargada        
			\param     q de tipo Punto pasado como referencia constante
			\pre       El Punto q debe existir
			\post      Los valores de los atributos de la clase actual deben ser iguales a los del objeto q
			\sa        getX(), getY(), setX(), setY()
		*/
		inline Punto(Punto const &q)
		{
			setX(q.getX());
			setY(q.getY());
		}

		//! \name OBSERVADORES

		/*! 
			\fn 	inline T getX()const
			\brief  Devuelve la coordenadas "x" de un Punto
			\return componente "x" del Punto (tipo T)
			\pre    El Punto debe existir
			\post   Ninguna
			\sa     getY()
		*/
		inline T getX()const
		{
			return _x;
		}
		/*! 
			\fn     inline T getY()const
			\brief  Devuelve la coordenadas "y" de un Punto
			\return componente "y" del Punto (tipo T)
			\pre    El Punto debe existir
			\post   Ninguna
			\sa     getX()
		*/
		inline T getY()const
		{
			return _y;

		}


		//! \name MODIFICADORES

		/*! 
			\fn    inline void setX(T v)		
			\brief Asigna un valor "v" a la coordenada "x" de un Punto
			\param v nuevo valor de la cordenada "x" del Punto
			\pre   El Punto debe existir
			\post  El valor del atributo _x debe ser v
			\sa    setY()
		*/
		inline void setX(T v)
		{
			_x = v;
		}


		/*! 
			\fn    inline void setY(T v)
			\brief Asigna un valor "v" a la coordenada "y" de un Punto
			\param v nuevo valor de la cordenada "y" del Punto
			\pre   El Punto debe existir
			\post  El valor del atributo _y debe ser v
			\sa    setX()
		*/
		inline void setY(T v)
		{
			_y = v;
		}


	    //!Operadores de la clase Punto
	   	/*! 
			\fn        inline Punto & operator=(Punto const &q)
			\brief     Operador que "copia" un Punto en otro Punto
			\attention Se sobrecarga el operador de asignación "="
			\param     q Punto que se va a copiar en el punto actual
			\pre       El Punto q debe existir
			\post      Ninguna
			\sa        getX(), getY(), setX(), setY()
		*/
		inline Punto<T> & operator=(T const &q)
		{
			setX(q.getX());
			setY(q.getY());

			return *this;
		}

		//! \name Funciones lectura y escritura de la clase Punto
		/*! 
			\fn 	 void leerPunto();
			\brief   Asigna a un Punto las coordenadas "x" e "y" leídas desde el teclado
			\pre     El Punto debe existir
			\post    Ninguna
			\warning Se deben teclear números del tipo T
			\sa      setX(), setY()
		*/
		void leerPunto(){
			T x, y;

			std::cout <<BIWHITE<< "\nLectura de las coordenadas de un punto: P(x,y) " << std::endl;

			std::cout <<BIBLUE<<"Abscisa: x --> "<<BIYELLOW;
			std::cin >> x;

			std::cout<<BIBLUE<< "Ordenada: y --> "<<BIYELLOW;
			std::cin >> y;
			std::cout<<RESET;

			// Se asignan los valores leídos a los atributos del punto   
			setX(x);
			setY(y);
		}


		/*! 
			\fn    void escribirPunto();
			\brief Escribe por pantalla las coordenadas de un Punto de la forma (x,y)
			\pre   El Punto debe tener valores asignados a sus coordenadas
			\post  Ninguna
			\sa    getX(), getY()
		*/
		void escribirPunto(){
			std::cout<<BIYELLOW<< "(" << getX() << ", " << getY() << ")";
		}
  
	}; // Fin de la definición de la clase Punto

//!  Definición de la plantilla de la clase Punto
template < class T > 
	//! Sobrecarga del operador de salida
	istream &operator>>(istream &stream, ed::Punto <T> punto){
                T x;
		std::getline(stream, x, ' ');
		punto.setX(x);
		std::getline(stream, x, '\n');
		punto.setY(x);
		return stream;
	}

} // \brief Fin de namespace ed.


//  _PUNTO_HPP_
#endif 
