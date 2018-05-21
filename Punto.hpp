/*! \par Fichero: Punto.hpp
   Punto representa la clase punto del plano euclídeo definida mediante template (plantilla)
*/
#ifndef _PUNTO_HPP_
#define _PUNTO_HPP_

// Facilita la entrada y salida 
#include <iostream>

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


         //! \name OPERADORES
   
	/*! 
		\fn        inline Punto & operator=(Punto const &q)
		\brief     Operador que "copia" un Punto en otro Punto
		\attention Se sobrecarga el operador de asignación "="
		\param     q Punto que se va a copiar en el punto actual
		\pre       El Punto q debe existir
		\post      Ninguna
		\sa        getX(), getY(), setX(), setY()
	*/
	inline Punto & operator=(Punto const &q)
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
	void leerPunto();


	/*! 
		\fn    void escribirPunto();
		\brief Escribe por pantalla las coordenadas de un Punto de la forma (x,y)
		\pre   El Punto debe tener valores asignados a sus coordenadas
		\post  Ninguna
		\sa    getX(), getY()
	*/
	void escribirPunto();
  
}; // Fin de la definición de la clase Punto


} // \brief Fin de namespace ed.

//////////////////////////////////////////////////////////////////////////////////////

// MODELO DE COMPILACION POR INCLUSION

#include "Punto.cpp"

///////////////////////////////////////////////////////////////////////////////////////////



//  _PUNTO_HPP_
#endif 
