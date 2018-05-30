/*! 
   \file  distancia.hpp
   \brief Fichero que contiene el código de las funcion para calcular la distancia euclidea entre dos puntos
   \author Carlos Luque Córdoba
   \date   29/05/2018
*/


#ifndef _DISTANCIA_HPP_
#define _DISTANCIA_HPP_

// Facilita la entrada y salida 
#include <iostream>
#include <cmath>

// Se incluye en el espacio de nombres ed
namespace ed{

	//!  Definición de la plantilla de la clase Punto
	template <typename T> 
	/*! 
		\brief Calcula la distancia euclídea de dos Punto2D con coordenadas del tipo T
		\param x1 abscisa del primer Punto
		\param y1 oordenada del primer Punto
		\param x2 abscisa del primer Punto
		\param y2 oordenada del primer Punto
		\return Resultado de tipo T que representa la distancia entre los puntos (x1, y1) y (x2, y2)
		\pre   Ninguna
		\post  El valor devuelto debe ser igual a la distancia euclídea entre los puntos (x1, y1) y (x2, y2)
		\sa getX(), getY() de la clase Punto2D, sqrt
	*/
	inline T calcularDistanciaEuclidea(T x1, T y1, T x2, T y2){
		return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	}

} // fin del espacio de nombre ed
#endif // _DISTANCIA_HPP_
 
