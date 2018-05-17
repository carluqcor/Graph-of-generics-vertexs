/*! 
   \file Punto.hpp
   \brief Fichero de la clase Punto
   \author Carlos Luque Córdoba
   \date   anywhere
*/

#ifndef _PUNTO_HPP_
#define _PUNTO_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

#include <cmath>

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Punto
class Punto{

	private:
		double _x;
		double _y; 

	public:
		//!Constructores de la clase Punto
		inline Punto(double x=0.0, double y=0.0){
			setDataX(x);
			setDataY(y);
		}
		//!Observadores públicos de la clase Punto
		inline double getDataX(){return _x;}
		inline double getDataY(){return _y;}

		//!Modificadores públicos de la clase Punto
		inline void setDataX(double vector){
			_x=vector;	

			#ifndef NDEBUG
				assert(std::abs(getDataX()-vector)<COTA_ERROR);
			#endif
		}

		inline void setDataY(double vector){
			_y=vector;
			
			#ifndef NDEBUG
				assert(std::abs(getDataY()-vector)<COTA_ERROR);
			#endif
		}

		inline void setData(double x, double y){
			setDataX(x);
			setDataY(y);
		}
	}; //Se cierra la clase Punto
} //Se cierra el espacio de nombres de la asignatura ED
#endif