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

#include "Vertice.hpp"
#include "GrafoInterfaz.hpp"
#include "Punto.hpp"

//Librería que incluye el uso de abs para el control de cota de error
#include <cmath>

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la clase Grafo
class Grafo : public ed::GrafoInterfaz{
	
	private:
		std::vector<Vertice> _vectorVertices; //! Vector de vertices de la STL
		std::vector<Vertice>::iterator it;
		//Vertice *it;
		
		Matriz _adjacent;

		std::vector<Lado> _vectorLado; //! Vector de vertices de la STL
		std::vector<Lado>::iterator itEdge;
		//Lado *itEdge;

		std::vector<int>_label;

	public:
		//! Constructores de la clase Grafo
		inline Grafo(std::vector<Vertice>v, std::vector<Lado>l, Matriz adjacent){
			_vectorVertices=v;

		}
		
		//! Observadores públicos de la clase Grafo
		inline bool isEmpty(){
			bool val=false;
			if(_vectorVertices.empty())
				val=true;
			#ifndef NDEBUG
				assert(val==(_vectorVertices.size()==0));
			#endif
				return val;
		}
		bool adjacent(Vertice const &u, Vertice const &v);

		bool has(std::vector<Vertice>::iterator ot);

		bool hasEdge(std::vector<Lado>::iterator otEdge);

		inline bool hasCurrVertex(){
			if(has(it))
				return true;
			else
				return false;		
		}

		inline Vertice currVertex(){
			#ifndef NDEBUG
				assert(hasCurrVertex());
			#endif
			
			return *it;
		}

		inline bool hasCurrEdge(){
			if(hasEdge(itEdge))
				return true;
			else
				return false;	
		}
		
		inline Lado currEdge(){
			#ifndef NDEBUG
				assert(hasCurrEdge());
			#endif
				return *itEdge;
		}

		int getLabelVertex(Vertice const &u) const {
			bool value=false;
			unsigned int i;
			for(i=0;i<(_label.size());i++){
				if(_label[i]==u.getLabel())
					value=true;
			}
			#ifndef NDEBUG
				assert(value==false);
			#endif

			return _label.at(u.getLabel());
		}

		//! Modificadores públicos del grafo de la clase Grafo
		inline void addVertex(double x, double y){
		Punto <float> *punto = new Punto<float>(x,y);
			Vertice vertice = new Vertice(punto, (_label.size())+1);
			_vectorVertices.push_back(vertice);
			setLabelVertex(_label.size()+1);
			#ifndef NDEBUG
				assert(this->hasCurrVertex());
			#endif
		}

		inline void setLabelVertex(int label){
			_label.push_back(label);
		}

		inline void addEdge(Vertice &u, Vertice &v, Lado &lado, double coste){
			lado.setLadoName(getLabelVertex(u)+" "+	getLabelVertex(v));
			lado.setFirstVertex(u);
			lado.setSecondVertex(v);
			lado.setLadoCoste(coste);

			_vectorLado.push_back(lado);

			#ifndef NDEBUG
				assert(this->hasCurrEdge());
				assert(has(u) && has(v));
				assert(coste>=0);
			#endif
		}

		void removeVertex();
		void removeEdge();

		inline void removeAllVertexAndEdges(){
			_vectorLado.clear();
			_vectorVertices.clear();
			#ifndef NDEBUG
				assert(isEmpty());
			#endif
		}

		//! Modificadores públicos de los cursores de la clase Grafo
		
		void findFirstVertex(double x, double y);

		void findNextVertex(double x, double y);

		void findFirstEdge();

		void findNextEdge();

		void goToVertex(Vertice const &vertice);
		/*
			Se puede recorrer el vector con un iterador y que busque si el vertice pasado por parámetro es igual al actual y si no que avance al siguiente
		*/

		void goToEdge(Vertice const &u, Vertice const &v);

		void goToFirstVertex();

		void nextVertex();

		void goToFirstEdge();

		void nextEdge();

	}; //Se cierra la clase Grafo
	
	//! Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Vertice const &vertice);

	//! Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Vertice &vertice); 

} //Se cierra el espacio de nombres de la asignatura ED
#endif