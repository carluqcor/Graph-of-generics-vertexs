/*! 
   \file Grafo.hpp
   \brief Fichero de la clase Grafo
   \author Carlos Luque Córdoba
   \date   anywhere
*/

#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

#include <vector>

#include "Vertice.h"

//Librería que incluye el uso de abs para el control de cota de error
#include <cmath>

#include "Punto.hpp"


#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Grafo
class Grafo: public ed::GrafoInterfaz{
	
	private:
		std::vector<Vertice> _vectorVertices; //!Vector de vertices de la STL
		std::vector<Vertice>::iterator it;
		std::vector<Lado> _ladoVertices; //!Vector de vertices de la STL
		int _grafoMatriz [_vectorVertices.size()] [_vectorVertices.size()]; //!Matriz cuadrada de adyacencias ES ESTATICA
		std::vector<int>_label;
		Vertice _currVertex;
		Lado _currEdge;

	public:
		//!Constructores de la clase Grafo
		inline Grafo(std::vector<Vertice>v, std::vector<Lado>l, int matriz[_vectorVertices.size()][_vectorVertices.size()]){

		}

		//!Observadores públicos de la clase Grafo
		inline bool isEmpty(){
			bool val=false;
			if(_vectorVertices.empty())
				val=true;
			#ifndef NDEBUG
				assert(val==(size()==0));
			#endif
				return val;
		}

		bool adjacent(Vertice &u, Vertice &v);

		bool hasCurrVertex(){
			for(it=_vectorVertices.begin(); it != jugadores_.end(); it++){
				if(it==(*(this)))
					return true;
			}
			return false;		
		}

		inline Vertice currVertex(){
			#ifndef NDEBUG
				assert(this->hasCurrVertex());
			#endif
				return *this;
		}

		bool hasCurrEdge();
		
		inline Lado currEdge(){
			#ifndef NDEBUG
				assert(this->hasCurrEdge());
			#endif
				return *this;
		}

		int getLabelVertex() const {
			bool value=false;
			int i,j;
			for(i=0;i<(_label.size());i++){
				for(j=1;j<(label.size());j++){
					if(_label[i]==_label[j])
						value=true;
				}
			}
			#ifndef NDEBUG
				assert(value==false);
			#endif

			return this->_label;
		}

		//! Modificadores públicos del grafo de la clase Grafo
		inline void addVertex(double x, double y){
			Punto punto = new Punto(x,y);
			Vertice vertice =new Vertice(punto, _vectorVertices.size()+1);
			_vectorVertices.pushBack(vertice);
			setLabelVertex(_vectorVertices.size()+1);
			#ifndef NDEBUG
				assert(this->hasCurrEdge());
				assert(std::abs(currVertex().getDataX()-x)<COTA_ERROR && abs(currVertex().getDataY()-y)<COTA_ERROR)
			#endif
		}

		inline void setLabelVertex(int label){
			_label.push(label);
		}

		void addEdge(Vertice const &u, Vertice const &v, Lado &lado);

		void removeVertex();
		/*
			1.Si hay lados(bool adjacent) Se deben borrar sus lados por lo tanto primero se guardará el vertice en uno auxiliar, y mientras adjacent sea true se usará nextEdge() y currEdge y se borrará y se volverá al vertice con goToVertex
			2.Se borra el vertice actual (NO EL AUXILIAR CREADO) osea un _vectorVertices.erase(*this) y se hace un nextVertex()
		*/

		inline void removeEdge(){
			#ifndef NDEBUG
				assert(this->hasCurrEdge());
			#endif
			
			_ladoVertices.erase(currVertex());

			#ifndef NDEBUG
				assert((this->hasCurrEdge())==false);
			#endif
		}

		inline void removeAllVertexAndEdges(){
			_ladoVertices.clear();
			_vectorVertices.clear();
			#ifndef NDEBUG
				assert(isEmpty());
			#endif
		}

		//! Modificadores públicos del cursor del grafo de la clase Grafo
		void findFirstVertex(double x, double y);

		void findNextVertex(double x, double y);

		void findFirstEdge(/**/);

		void findNextEdge(/**/);

		void goToVertex(Vertice const &vertice);
		/*
			Se puede recorrer el vector con un iterador y que busque si el vertice pasado por parámetro es igual al actual y si no que avance al siguiente
		*/

		void goToEdge(Vertice const &u, Vertice const &v);

		void goToFirstVertex();

		void nextVertex();

		void goToFirstEdge();

		void nextEdge();


	//! Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Vertice const &vertice);

	//! Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Vertice &vertice); 

	}; //Se cierra la clase Grafo
} //Se cierra el espacio de nombres de la asignatura ED
#endif