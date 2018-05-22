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

#include "Lado.hpp"
#include "Vertice.hpp"
#include "Punto.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed{

//!  Definición de la plantilla de la clase Grafo
template < class T > 

//!  Definición de la clase Grafo
class Grafo{
	
	private:
		std::vector<Vertice<T> > _vectorVertices; //! Vector de vertices de la STL
		typename std::vector<Vertice<T> >::const_iterator it;
		
		std::vector<std::vector<int> > _matriz;

		std::vector<Lado<T> > _vectorLado; //! Vector de vertices de la STL
		typename std::vector<Lado<T> >::const_iterator itEdge;
		
		std::vector<int>_label;

	public:
		//! Constructores de la clase Grafo
		inline Grafo(std::vector<Vertice<T> >v, std::vector<Lado<T> >l, std::vector<std::vector<int> >matriz){
			_vectorVertices=v;
			_vectorLado=l;
			_matriz=matriz;
		}
		
		//! Observadores públicos de la clase Grafo
		inline bool isEmpty(){
			if(_vectorVertices.size()==0)
				return true;
			else
				return false;
		}

		bool adjacent(Vertice <T> const &u, Vertice <T> const &v);

		bool has(typename std::vector<Vertice<T> >::const_iterator ot){
			#ifndef NDEBUG
				assert(isEmpty()==false);
			#endif
			ot=_vectorVertices.begin();
			for(ot; ot!=_vectorVertices.end(); ot++){
				if(ot==currVertex())
					return true;
			}
			return false;
		}

		bool hasEdge(typename std::vector<Lado<T> >::const_iterator otEdge){
			#ifndef NDEBUG
				assert(_vectorVertices.size()>=2);
			#endif
			otEdge=_vectorLado.begin();
			for(otEdge; otEdge!=_vectorLado.end(); otEdge++){
				if(otEdge==currEdge())
					return true;
			}
			return false;
		}

		inline bool hasCurrVertex(){
			if(has(it))
				return true;
			else
				return false;		
		}

		inline Vertice<T> currVertex(){
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
		
		inline Lado<T> currEdge(){
			#ifndef NDEBUG
				assert(hasCurrEdge());
			#endif
				return *itEdge;
		}

		int getLabelVertex(Vertice<T> const &u) const {
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
		void addVertex(T x, T y){
			Punto <float> *punto = new Punto<float>(x,y);
			Vertice <T> *vertice = new Vertice <T>(punto, (_label.size())+1);
			_vectorVertices.push_back(vertice);
			setLabelVertex(_label.size()+1);
			#ifndef NDEBUG
				assert(this->hasCurrVertex());
			#endif	
		}

		inline void setLabelVertex(int label){
			_label.push_back(label);
		}

		void addEdge(Vertice<T> &u, Vertice<T> &v, Lado<T> &lado, double coste){
			lado.setLadoName(getLabelVertex(u)+" "+	getLabelVertex(v));
			lado.setFirstVertex(u);
			lado.setSecondVertex(v);
			lado.setLadoCoste(coste);

			_vectorLado.push_back(lado);

			#ifndef NDEBUG
				assert(this->hasCurrEdge());
				assert(coste>=0);
			#endif
		}
		

		//! Modificador públicos de la clase Grafo
		/*
			1. Si hay lados(bool adjacent) Se deben borrar sus lados por lo tanto primero se guardará el vertice en uno auxiliar, y mientras adjacent sea true se usará nextEdge() y currEdge y se borrará y se volverá al vertice con goToVertex
			2. Se borra el vertice actual (NO EL AUXILIAR CREADO) osea un _vectorVertices.erase(*this) y se hace un nextVertex()
			3. Borrar la etiqueta de ese vertice
		*/
		void removeVertex(){
			#ifndef	NDEBUG
				assert(hasCurrVertex());
			#endif
			do{
				removeEdge();
			}while(adjacent(currVertex(), nextVertex())==true); //Elimina todos los lados del vertice
			_label.erase(currVertex().getLabelVertex());
			_vectorVertices.erase(currVertex());
			#ifndef	NDEBUG
				assert(!hasCurrVertex());
			#endif
		}

		void removeEdge(){
			#ifndef	NDEBUG
				assert(hasCurrEdge());
			#endif
			_vectorLado.erase(itEdge);
			itEdge=nextEdge();
			#ifndef	NDEBUG
				assert(!hasCurrEdge());
			#endif
		}

		inline void removeAllVertexAndEdges(){
			_vectorLado.clear();
			_vectorVertices.clear();
			#ifndef NDEBUG
				assert(isEmpty());
			#endif
		}

		void findFirstVertex(T x, T y){
			Punto <float> *punto = new Punto<float>(x,y);
			typename std::vector<Vertice<T> >::const_iterator ot;
			for(ot=_vectorVertices.begin(); ot!=_vectorVertices.end(); ot++){
				if(punto==ot.getPunto())
					it=ot;
			}
			#ifndef NDEBUG
				assert(hasEdge(it));
			#endif
		}

		void findNextVertex(T x, T y){
			Punto <float> *punto = new Punto<float>(x,y);
			typename std::vector<Vertice<T> >::const_iterator ot;
			for(ot=_vectorVertices.begin(); ot!=_vectorVertices.end(); ot++){
				if(punto==ot.getPunto())
					it=ot;
			}
			#ifndef NDEBUG
				assert(hasEdge(it));
			#endif
		}

		void findFirstEdge(float coste){
			typename std::vector<Lado<T> >::const_iterator otEdge;
			for(otEdge=_vectorLado.begin(); otEdge!=_vectorLado.end(); otEdge++){
				if(coste==otEdge.getLadoCoste())
					itEdge=otEdge;
			}
			#ifndef NDEBUG
				assert(hasEdge(itEdge));
			#endif
		}

		void findNextEdge(float coste){
			typename std::vector<Lado<T> >::const_iterator otEdge;
			for(otEdge=_vectorLado.begin(); otEdge!=_vectorLado.end(); otEdge++){
				if(coste==otEdge.getLadoCoste())
					itEdge=otEdge;
			}
			#ifndef NDEBUG
				assert(hasEdge(itEdge));
			#endif
		}

		void goToVertex(ed::Vertice<T> const &vertice){
			it=_vectorVertices.at(vertice);
			#ifndef NDEBUG
				assert(std::abs((currVertex().getDataX())-(vertice.getDataX()))<COTA_ERROR && std::abs((currVertex().getDataY())-(vertice.getDataY()))<COTA_ERROR);
			#endif
		}

		void goToEdge(ed::Vertice<T> const &u, ed::Vertice<T> const &v){
			typename std::vector<Lado<T> >::const_iterator otEdge=_vectorLado.begin();
			for(otEdge; otEdge != _vectorLado.end(); otEdge++){
				if(otEdge.getFirstVertex() == u && otEdge.getSecondVertex() == v){
					ed::Lado <T> *lado=new Lado<T>(otEdge.getLadoName(), u, v, otEdge.getLadoCoste());
					itEdge=_vectorLado.at(lado);
				}else if(otEdge.getSecondVertex() == u && otEdge.getFirstVertex() == v){
					ed::Lado <T> *lado=new Lado<T>(otEdge.getLadoName(), v, u, otEdge.getLadoCoste());
					itEdge=_vectorLado.at(lado);
				}
			}
		}

		void goToFirstVertex(){
			#ifndef NDEBUG
				assert(has(_vectorVertices.begin()));
				assert(!isEmpty());
			#endif
				it=_vectorVertices.begin();
		}

		void nextVertex(){
			it++;
			#ifndef NDEBUG
				assert(has(it));
			#endif
		}

		void goToFirstEdge(){
			#ifndef NDEBUG
				assert(hasEdge(_vectorLado.begin()));
				assert(_vectorVertices.size>=2);
			#endif
				itEdge=_vectorLado.begin();
		}

		void nextEdge(){
			itEdge++;
			#ifndef NDEBUG
				assert(hasEdge(itEdge));
			#endif
		}
	}; //Se cierra la clase Grafo
	
	//! Sobrecarga del operador de salida
	//ostream &operator<<(ostream &stream, Vertice<T> const &vertice);

	//! Sobrecarga del operador de entrada
	//istream &operator>>(istream &stream, Vertice<T> &vertice); 

} //Se cierra el espacio de nombres de la asignatura ED

// MODELO DE COMPILACION POR INCLUSION

#include "Grafo.cpp"

#endif