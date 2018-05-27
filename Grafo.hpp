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

#include <limits>

#include <fstream>

#include <stdio.h>

#include <vector>

#include "Punto.hpp"
#include "Lado.hpp"
#include "Vertice.hpp"
#include "macros.hpp"


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
		std::vector<Vertice<T> > _v;
		typename std::vector<Vertice<T> >::iterator it;
		
		//std::vector<std::vector<float> > matriz;

		std::vector<Lado<T> > _vectorLado; //! Vector de lados de la STL
		std::vector<Lado<T> > _l;
		typename std::vector<Lado<T> >::iterator itEdge;
		
		std::vector<int>_label;

	public:
		//! Constructores de la clase Grafo
		inline Grafo(std::vector<Vertice<T> >v, std::vector<Lado<T> >l){
			_v=v;
			_l=l;
		}

		//! Observadores públicos de la clase Grafo
		inline bool isEmpty(){
			if(getVectorVertices().size()==0)
				return true;
			else
				return false;
		}

		bool adjacent(int const u, int const v, std::vector<Lado<T> > l){
			typename std::vector<Lado<T> >::const_iterator otEdge;
				for(otEdge=l.begin();otEdge!=l.end();otEdge++){
					if((otEdge->getFirstVertex()==v && otEdge->getSecondVertex()==u) || (otEdge->getFirstVertex()==u && otEdge->getSecondVertex()==v)){
						return true;
					}
				}
				return false;
		}

		float getVectorCoste(std::vector<Lado<T> >l, int u, int v){
			typename std::vector<Lado<T> >::iterator otEdge;
			for(otEdge=_vectorLado.begin();otEdge!=_vectorLado.end();otEdge++){
				if((otEdge->other(u)==v))
					return otEdge->getLadoCoste();
				else if((otEdge->other(v)==u))
					return otEdge->getLadoCoste();
			}
			return 0;
		}

		inline bool hasCurrVertex(Vertice<T> &v){
			typename std::vector<Vertice<T> >::iterator ot;
			for(ot=_vectorVertices.begin();ot!=_vectorVertices.end();ot++){
				if(ot->getPunto().getX()==v.getPunto().getX() && ot->getPunto().getY()==v.getPunto().getY())
					return true;
			}
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

		std::vector< std::vector<float> > prim(){
			// uso una copia de ady porque necesito eliminar columnas
			unsigned int nVertices=getVectorVertices().size();
			std::vector< std::vector<float> > adyacencia = crearMatrizSinLabels(getVectorVertices(), getVectorLado());
			std::vector< std::vector<float> > arbol(nVertices);
			std::vector<float> markedLines;
			std::vector<float> :: iterator itVec;

			// Inicializo las distancias del arbol en INF.
			for(unsigned int i = 0; i < nVertices; i++)
			    arbol[i] = std::vector<float> (nVertices, 0);

			float padre = 0;
			float hijo = 0;
			while(markedLines.size() + 1 < nVertices){
			    padre = hijo;
			    // Marco la fila y elimino la columna del nodo padre.
			    markedLines.push_back(padre);
			    for(unsigned int i = 0; i < nVertices; i++)
			        adyacencia[i][padre] = 999;

			    // Encuentro la menor distancia entre las filas marcadas.
			    // El nodo padre es la linea marcada y el nodo hijo es la columna del minimo.
			    float min = 999;
			    for(itVec = markedLines.begin(); itVec != markedLines.end(); itVec++)
			        for(unsigned int i = 0; i < nVertices; i++)
			            if(min > adyacencia[*itVec][i]){
			                min = adyacencia[*itVec][i];
			                padre = *itVec;
			                hijo = i;
			            }

			    arbol[padre][hijo] = min;
			    arbol[hijo][padre] = min;
			}
			return arbol;
		}

		// Devuelve la matriz de adyacencia del árbol mínimo.
		std::vector<std::vector<float> > kruskal(){
		    std::vector< std::vector<float> > adyacencia = crearMatrizSinLabels(getVectorVertices(), getVectorLado());
		    int nVertices=getVectorVertices().size();
		    std::vector< std::vector<float> > arbol(nVertices);
		    std::vector<float> visitado(nVertices); // Indica el que nodo ha sido visitado

		    for(int i = 0; i < nVertices; i++){
		        arbol[i] =std::vector<float> (nVertices, 0);
		        visitado[i] = i;
		    }

		    float Vertice1=0;
		    float Vertice2=0;
		    float arcos = 1; // Atributo para controlar los ciclos
		    while(arcos < nVertices){
		        //Con este while buscamos el camino mínimo sin tener un ciclo
		        float min = 9999; //Infinito para los lados no visitados
		        for(int i = 0; i < nVertices; i++)
		            for(int j = 0; j < nVertices; j++)
		                if(min > adyacencia[i][j] && adyacencia[i][j]!=0 && visitado[i] != visitado[j]){
		                    min = adyacencia[i][j];
		                    Vertice1 = i;
		                    Vertice2 = j;
		                }

		        // Si los nodos no visitadon al mismo árbol agrego el arco al árbol mínimo.
		        if(visitado[Vertice1] != visitado[Vertice2]){
		            arbol[Vertice1][Vertice2] = min;
		            arbol[Vertice2][Vertice1] = min;

		            // Todos los nodos del árbol del Vertice2 ahora visitadon al árbol del Vertice1.
		        	float temp = visitado[Vertice2];
		        	visitado[Vertice2] = visitado[Vertice1];
		        	for(int k = 0; k < nVertices; k++)
		        		if(visitado[k] == temp)
		        			visitado[k] = visitado[Vertice1];

		            arcos++;
		        }
		    }
		    return arbol;
		}

		std::vector<std::vector<float> > crearMatriz(std::vector<Vertice<T> >v, std::vector<Lado<T> >l, unsigned int i){
			std::vector<std::vector<float> > Vector2 ( i, std::vector<float> (i));
    		for(unsigned int y=1;y<i;y++){
    				Vector2[y][0]=v[y-1].getLabel();
    				Vector2[0][y]=v[y-1].getLabel();
       			for(unsigned int x=1;x<i;x++){
	       			if(Vector2[y][x] == 0 || Vector2[y][x] ==0){	
	       				if(y==x){
       						Vector2[y][x]=0;
	       				}else{
		       				if(i-x!=0){
				       			if(adjacent(v[y-1].getLabel(), v[x-1].getLabel(), l)){
					            	Vector2[y][x]=getVectorCoste(l, v[y-1].getLabel(), v[x-1].getLabel());
					            	Vector2[x][y]=getVectorCoste(l, v[y-1].getLabel(), v[x-1].getLabel());
				            	}
					        }
					    }
				    }
       			}
    		}
    		return Vector2;
		}

		std::vector<std::vector<float> > crearMatrizSinLabels(std::vector<Vertice<T> >v, std::vector<Lado<T> >l){
			std::vector<std::vector<float> > Vector2 ( v.size(), std::vector<float> (v.size()));
    		for(unsigned int y=0;y<v.size();y++){
       			for(unsigned int x=0;x<v.size();x++){
	       			if(Vector2[y][x] == 0 || Vector2[y][x] ==0){	
	       				if(y==x){
       						Vector2[y][x]=0;
	       				}else{
				       		if(adjacent(v[y].getLabel(), v[x].getLabel(), l)){
					           	Vector2[y][x]=getVectorCoste(l, v[y].getLabel(), v[x].getLabel());
					           	Vector2[x][y]=getVectorCoste(l, v[y].getLabel(), v[x].getLabel());
				            }
					    }
				    }
       			}
    		}
    		return Vector2;
		}

		void crearGrafo(std::vector<Lado<T> >l, std::string const & nombreFichero){
			std::ifstream grap;
			grap.open(nombreFichero.c_str());
			if(grap.is_open()){
				for(itEdge=l.begin();itEdge!=l.end();itEdge++){
					fprintf(grap, "%d -> %d [label=\"%f\"]",itEdge->getFirstVertex(), itEdge->getSecondVertex(), itEdge->getLadoCoste());
				}
				grap.close();
			}
		}

		std::vector<Vertice<T> > getVectorVertices(){return _vectorVertices;}

		std::vector<Lado<T> > getVectorLado(){return _vectorLado;}
		
		std::vector<int> getVectorEtiquetas(){return _label;}

	//	typename std::vector<Vertice<T> >::iterator getIteradorVertice(){return *it;}
		typename std::vector<Lado<T> >::iterator getIteradorLado(){return itEdge;}

		//! Modificadores públicos del grafo de la clase Grafo
		void addVertex(T &punto){
			Vertice<T> v(punto, getVectorEtiquetas().size()+1);
			if(hasCurrVertex(v)){
				std::cout<<BIRED<<"Error ";
				v.getPunto().escribirPunto();
				std::cout<<" ya está en el grafo"<<std::endl;
			}
			else{
				_vectorVertices.push_back(v);
				if(getVectorVertices().size()==1)
					it=getVectorVertices().begin();
				std::cout<<BIYELLOW<<"Se ha insertado ";
				v.getPunto().escribirPunto();
				std::cout<<" con etiqueta: "<<v.getLabel()<<" correctamente"<<RESET<<std::endl;
				setLabelVertex(getVectorEtiquetas().size()+1);
			}
		//	nextVertex();
			//#ifndef NDEBUG
			//	assert(hasCurrVertex(it));
			//#endif	
		}

		inline void setLabelVertex(int label){
			_label.push_back(label);
		}

		void addEdge(int const u, int const v, Lado<T> &lado, double const coste){
			lado.setFirstVertex(u);
			lado.setSecondVertex(v);
			lado.setLadoCoste(coste);

			_vectorLado.push_back(lado);
			if(getVectorLado().size()==1)
				itEdge=getVectorLado().begin();

			#ifndef NDEBUG
			//	assert(this->hasCurrEdge());
				assert(coste>=0);
			#endif
		}

		void imprimirVertices(){
			for(unsigned int i=0;i<_vectorVertices.size();i++){      
				_vectorVertices[i].leerVertice();
			}
		}

		/*
			1. Si hay lados(bool adjacent) Se deben borrar sus lados por lo tanto primero se guardará el vertice en uno auxiliar, y mientras adjacent sea true se usará nextEdge() y currEdge y se borrará y se volverá al vertice con goToVertex
			2. Se borra el vertice actual (NO EL AUXILIAR CREADO) osea un _vectorVertices.erase(*this) y se hace un nextVertex()
			3. Borrar la etiqueta de ese vertice
		*/
		void removeVertex(){
			#ifndef	NDEBUG
				assert(hasCurrVertex(it));
			#endif
			do{
				removeEdge();
			}while(adjacent(currVertex(), nextVertex())==true); //Elimina todos los lados del vertice
			_label.erase(currVertex().getLabelVertex());
			_vectorVertices.erase(currVertex());
			#ifndef	NDEBUG
				assert(!hasCurrVertex(it));
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

		void imprimirMatriz(std::vector<Vertice<T> > v, std::vector<std::vector<float> > v2, unsigned int i){
    		for(unsigned int y=0;y<i;y++){
       			for(unsigned int x=0;x<i;x++){
            		std::cout<<BIBLUE<<v2[y][x]<<RESET<<"\t";
       			}
       			std::cout<<std::endl;
    		}
    		std::cout<<std::endl;
		}

		void matricesAFichero(std::vector<Vertice<T> > v, std::vector<std::vector<float> > v2, unsigned int i){
			std::string f;
			std::ifstream grap;
			std::cout<<BIBLUE<<"Introduce el nombre del fichero: ";
            std::getline(std::cin,f);
            std::cout<<RESET<<std::endl;
            matriz.open(f.c_str());
            for(unsigned int y=0;y<i;y++){
       			for(unsigned int x=0;x<i;x++){
					fprintf(f, "%f\t", v2[y][x]);
				}
				fprintf(f, "\n", v2[i]);
			}
		}

		void imprimirMatrizSinLabels(std::vector<Vertice<T> > v, std::vector<std::vector<float> > v2){
    		for(unsigned int y=0;y<v.size();y++){
       			for(unsigned int x=0;x<v.size();x++){
            		std::cout<<BIBLUE<<v2[y][x]<<RESET<<"\t";
       			}
       			std::cout<<std::endl;
    		}
    		std::cout<<std::endl;
		}


		//! Modificadores del cursor público de la clase Grafo
		/*void findFirstVertex(T x, T y){
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

		float findNextEdge(float coste){
			typename std::vector<Lado<T> >::const_iterator otEdge;
			for(otEdge=_vectorLado.begin(); otEdge!=_vectorLado.end(); otEdge++){
				if(otEdge->getLadoCoste()<coste)
					coste=otEdge->getLadoCoste();
			}
			std::cout<<"COSTES: "<<coste<<std::endl;
			return coste;
		//	#ifndef NDEBUG
		//		assert(hasEdge(*itEdge));
		//	#endif
		}

		int findNextLabel(float coste, int label){
			typename std::vector<Lado<T> >::const_iterator otEdge;
			for(otEdge=_vectorLado.begin(); otEdge!=_vectorLado.end(); otEdge++){
				std::cout<<"COSTE Lado: "<<otEdge->getLadoCoste()<<" Coste: "<<coste<<" ETIQUETA 1: "<<otEdge->getFirstVertex()<<" ETIQUETA 2: "<<otEdge->getSecondVertex()<<" Etiqueta label: "<<label<<std::endl;
				if(otEdge->getLadoCoste()==coste && (otEdge->getFirstVertex()==label)){
					std::cout<<"otEdge1: "<<otEdge->getFirstVertex()<<std::endl;
					return otEdge->getSecondVertex();
				}else if(otEdge->getLadoCoste()==coste && (otEdge->getSecondVertex()==label)){
					std::cout<<"otEdge2: "<<otEdge->getSecondVertex()<<std::endl;
					return otEdge->getFirstVertex();
				}
			}
			return 0;
		}
*/
		void goToVertex(ed::Vertice<T> const &vertice){
			it=getVectorVertices().at(vertice);
		}

		void goToEdge(int const &u, int const &v){
			typename std::vector<Lado<T> >::const_iterator otEdge=_vectorLado.begin();
			for(otEdge; otEdge != _vectorLado.end(); otEdge++){
				if(otEdge.getFirstVertex() == u && otEdge.getSecondVertex() == v){
					ed::Lado <T> *lado=new Lado<T>(u, v, otEdge.getLadoCoste());
					itEdge=_vectorLado.at(lado);
				}else if(otEdge.getSecondVertex() == u && otEdge.getFirstVertex() == v){
					ed::Lado <T> *lado=new Lado<T>(v, u, otEdge.getLadoCoste());
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
			it;
			#ifndef NDEBUG
				assert(hasCurrVertex(it));
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
			itEdge->itEdge++;
			#ifndef NDEBUG
				assert(hasCurrEdge(itEdge));
			#endif
		}
	}; //Se cierra la clase Grafo
	
	//! Sobrecarga del operador de salida
	//ostream &operator<<(ostream &stream, Vertice<T>  const &vertice){

	//! Sobrecarga del operador de entrada
	//istream &operator>>(istream &stream, Vertice<T> &vertice); 

} //Se cierra el espacio de nombres de la asignatura ED

// MODELO DE COMPILACION POR INCLUSION

#include "Grafo.cpp"

#endif