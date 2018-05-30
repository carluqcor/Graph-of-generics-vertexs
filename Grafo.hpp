/*! 
   \file Grafo.hpp
   \brief Fichero de la clase Grafo
   \author Carlos Luque Córdoba
   \date   29/05/2018
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

// Abs para cotas de error de numeros reales positivos
#include <cmath>

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales

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
		//! Atributos privados de la clase Grafo
		std::vector<Vertice<T> > _vectorVertices; //! Vector de vertices de la STL
		typename std::vector<Vertice<T> >::iterator it; //! Iterador de tipo Vertice genérico
		
		std::vector<Lado<T> > _vectorLado; //! Vector de lados de la STL
		typename std::vector<Lado<T> >::iterator itEdge; //! Iterador de tipo Lado genérico

		std::vector<int>_label; //! Vector de enteros para guardar las etiquetas de los vertices y controlar así que no se repitan

		std::vector<std::vector<float> > _matriz; //! Vector de vectores de tipo float para guardar la matriz con etiquetas
		std::vector<std::vector<float> > _matrizwLabels; //! Vector de vectores de tipo float para guardar la matriz sin etiquetas
		
		std::vector<float> _padre; //! Vector de float para guardarlos los Vertices FROM de los Algoritmos Prim y Kruskal
		std::vector<float> _hijo; //! Vector de float para guardarlos los Vertices TO de los Algoritmos Prim y Kruskal
		std::vector<float> _coste; //! Vector de float para guardarlos los costes de los lados de los Algoritmos Prim y Kruskal
		float _max; //! Flotante privada para guardar el coste mínimo del Arbol Abarcador

		bool _dirigido; //! Booleana privada para guardar el estado del grafo (Dirigido o No Dirigido)

		

	public:
		//! Constructores de la clase Grafo
		/*! 
			\fn        inline Grafo(bool dirigido)
			\brief     Constructor que crea un Grafo Dirigido o No Dirigido según la booleana pasada como referencia
			\attention Función sobrecargada        
			\param     dirigido: Booleana pasada como referencia para ajustar el estado del grafo
			\pre       Ninguna
			\post      El atributo de la clase grafo debe ser igual al pasado como parámetro
			\sa 	   getDirected(), setDirected
		*/
		inline Grafo(bool dirigido){
			setDirected(dirigido);
			#ifndef NDEBUG
				assert(getDirected()==dirigido);
			#endif
		}

		//! Observadores públicos de la clase Grafo
		/*! 
			\fn        inline bool isEmpty() 
			\brief     Función que comprueba si el grafo está vacio
			\note      Función inline de tipo bool
			\return    True si no hay ningún Vertice en el Grafo, false si hay Vertices
			\pre       Ninguna
			\post      Ninguna
			\sa        getVectorVertices()
		*/
		inline bool isEmpty(){
			if(getVectorVertices().size()==0)
				return true;
			else
				return false;
		}

		/*! 
			\fn        inline std::vector<std::vector<float> > getMatriz()
			\brief     Función que devuelve el atributo privado _matriz
			\note      Función inline de tipo vector de vectores flotantes 
			\return    Devuelve el atributo privado _matriz
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline std::vector<std::vector<float> > getMatriz(){return _matriz;}
		/*! 
			\fn        inline std::vector<std::vector<float> > getMatrizWLabels()
			\brief     Función que devuelve el atributo privado _matrizwLabels
			\note      Función inline de tipo vector de vectores flotantes 
			\return    Devuelve el atributo privado _matrizwLabels
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline std::vector<std::vector<float> > getMatrizWLabels(){return _matrizwLabels;}
		
		/*! 
			\fn        inline bool getDirected() const 
			\brief     Función que devuelve el estado del grafo
			\note      Función inline de tipo bool
			\return    Devuelve el atributo privado _dirigido
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline bool getDirected()const {return _dirigido;}

		/*! 
			\fn        inline adjacent(int const u, int const v, vector<Lado<T> > l)		
			\brief     Función que comprueba si 2 vertices están unidos por un Lado
			\note      Función de tipo bool
			\param     u: Etiqueta de tipo entero
			\param     v: Etiqueta de tipo entero
			\param     l: Vector de Lados genéricos
			\return    Devuelve true si están unidos, si no devuelve false
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		bool adjacent(int const u, int const v, std::vector<Lado<T> > l){
			typename std::vector<Lado<T> >::const_iterator otEdge;
				for(otEdge=l.begin();otEdge!=l.end();otEdge++){
					if((otEdge->getFirstVertex()==v && otEdge->getSecondVertex()==u) || (otEdge->getFirstVertex()==u && otEdge->getSecondVertex()==v)){
						return true;
					}
				}
				return false;
		}

		/*! 
			\fn        float getVectorCoste(vector<Lado<T> >l, int u, int v)		
			\brief     Función que comprueba si la etiqueta pasada a other devuelve la contraria pasada por parámetro devuelve el coste del lado
			\note      Función de tipo float
			\param     l: Vector de Lados genéricos
			\param     u: Etiqueta de tipo entero
			\param     v: Etiqueta de tipo entero
			\return    Devuelve el coste del lado si ha encontrado el lado, si no devolverá 0 para controlarlo en la matriz
			\pre       Ninguna
			\post      Ninguna
			\sa        other(), crearMatriz(), crearMatrizSinLabels()
		*/
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

		/*! 
			\fn        int devolverEtiqueta(Vertice<T> const &v)	
			\brief     Función que devuelve la etiqueta del vertice pasado como referencia
			\note      Esta función es usada cuando se crea un vertice y tenemos el punto pero no la etiqueta y el vertice ya se encuentra en el grafo
			\param     v: Objeto de la clase Vertice pasado por referencia constante
			\return    Devuelve la etiqueta del vertice pasado como referencia desde la lista de Vertices
			\pre       Ninguna
			\post      Ninguna
			\sa        getPunto(), addVertex()
		*/
		int devolverEtiqueta(Vertice<T> const &v){
			typename std::vector<Vertice<T> >::iterator ot;
			for(ot=_vectorVertices.begin();ot!=_vectorVertices.end();ot++){
				if(ot->getPunto().getX()==v.getPunto().getX() && ot->getPunto().getY()==v.getPunto().getY())
					return ot->getLabel();
			}
				return 0;		
		}

		/*! 
			\fn        bool devolverBoolEtiqueta(int u)
			\brief     Función que comprueba si la etiqueta pasada como parámetro es etiqueta de algun vertice
			\note      Función de tipo bool
			\param     u: Etiqueta de tipo entero
			\return    Devuelve true si la etiqueta coincide con alguna del vector de Vertices, si no devuelve false
			\pre       Ninguna
			\post      Ninguna
			\sa        getLabel()
		*/
		bool devolverBoolEtiqueta(int u){
			typename std::vector<Vertice<T> >::iterator ot;
			for(ot=_vectorVertices.begin();ot!=_vectorVertices.end();ot++){
				if(ot->getLabel()==u)
					return true;
			}
				return false;		
		}

		/*! 
			\fn        Punto<float> devolverPunto(int u)
			\brief     Función que devuelve el Punto del vertice que tiene como etiqueta la pasada como parámetro
			\note      Función de tipo Punto flotante
			\param     u: Etiqueta de tipo entero
			\attention Ese 0 que devuelve es controlado en las funciones en las que se usa esta función
			\return    Devuelve el punto del Vertice si la etiqueta ha coincidido con alguna del vector de vertices, si no devuelve 0
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		Punto<float> devolverPunto(int u){
			typename std::vector<Vertice<T> >::iterator ot;
			for(ot=_vectorVertices.begin();ot!=_vectorVertices.end();ot++){
				if(ot->getLabel()==u)
					return ot->getPunto();
			}
				return 0;		
		}

		/*! 
			\fn        bool hasCurrVertex(Vertice<T> const &v)		
			\brief     Función que comprueba si el vertice pasado como referencia constante está en el grafo
			\note      Función de tipo bool
			\param     v: Objeto de la clase Vertice pasado por referencia constante
			\return    Devuelve true si encuentra el vertice, si no devuelve false
			\pre       Ninguna
			\post      Ninguna
			\sa        getPunto(), addVertex()
		*/
		bool hasCurrVertex(Vertice<T> const &v){
			typename std::vector<Vertice<T> >::iterator ot;
			for(ot=_vectorVertices.begin();ot!=_vectorVertices.end();ot++){
				if(ot->getPunto().getX()==v.getPunto().getX() && ot->getPunto().getY()==v.getPunto().getY())
					return true;
			}
				return false;		
		}

		/*! 
			\fn        inline Vertice<T> currVertex() const	
			\brief     Función que devuelve el vertice actual
			\note      Función inline de tipo Vertice genérico
			\return    Devuelve el vertice actual
			\pre       Ninguna
			\post      Ninguna
			\sa        hasCurrVertex()
		*/
		inline Vertice<T> currVertex()const{return *it;}

		/*! 
			\fn        bool hasCurrEdge(Lado<T> const &l)		
			\brief     Función que comprueba si el lado pasado como referencia constante está en el grafo
			\note      Función de tipo bool
			\param     l: Objeto de la clase Lado pasado por referencia constante
			\return    Devuelve true si encuentra el lado en el grafo, si no devuelve false
			\pre       Ninguna
			\post      Ninguna
			\sa        addEdge(), removeVertexEdges()
		*/
		bool hasCurrEdge(Lado<T> const &l){
			typename std::vector<Lado<T> >::iterator otEdge;
			for(otEdge=_vectorLado.begin();otEdge!=_vectorLado.end();otEdge++){
				if((otEdge->getFirstVertex()==l.getFirstVertex() && otEdge->getSecondVertex()==l.getSecondVertex())){
					return true;
				}
			}
			return false;		
		}
		
		/*! 
			\fn        inline Lado<T> currEdge()const
			\brief     Función que devuelve el vertice actual
			\note      Función inline de tipo Lado genérico
			\return    Devuelve el lado actual
			\pre       Ninguna
			\post      Ninguna
			\sa        hasCurrEdge()
		*/
		inline Lado<T> currEdge()const{return *itEdge;}

		/*! 
			\fn        inline vector<Vertice<T> > getVectorVertices()const	
			\brief     Función que devuelve el vector de vertices genéricos _vectorVertices
			\note      Función inline de tipo Vertice genérico
			\return    Devuelve el vector de vertices genéricos _vectorVertices
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline std::vector<Vertice<T> > getVectorVertices()const{return _vectorVertices;}

		/*! 
			\fn        inline vector<Lado<T> > getVectorLado()const	
			\brief     Función que devuelve el vector de lados genéricos _vectorLado
			\note      Función inline de tipo Lado genérico		
			\return    Devuelve el vector de lados genéricos _vectorLado
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline std::vector<Lado<T> > getVectorLado()const{return _vectorLado;}
		
		/*! 
			\fn        inline vector<int> getVectorEtiquetas()const	
			\brief     Función que devuelve el vector de enteros de etiquetas _label
			\note      Función inline de tipo vector de enteros
			\return    Devuelve el vector de enteros de etiquetas _label
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline std::vector<int> getVectorEtiquetas()const{return _label;}

		/*! 
			\fn        inline vector<float> getPadre()const	
			\brief     Función que devuelve el vector de flotantes (_padre) de los vertices FROM de los algoritmos
			\note      Función inline de tipo vector de flotantes
			\return    Devuelve el vector de flotantes (_padre) de los vertices FROM de los algoritmos
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline std::vector<float> getPadre()const{return _padre;}

		/*! 
			\fn        inline vector<float> getHijo()const	
			\brief     Función que devuelve el vector de flotantes (_hijo) de los vertices TO de los algoritmos
			\note      Función inline de tipo vector de flotantes
			\return    Devuelve el vector de flotantes (_hijo) de los vertices TO de los algoritmos
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline std::vector<float> getHijo()const{return _hijo;}

		/*! 
			\fn        inline vector<float> getCoste()const	
			\brief     Función que devuelve el vector de flotantes (_coste) de los costes de los lados de los algoritmos
			\note      Función inline de tipo vector de flotantes
			\return    Devuelve el vector de flotantes (_coste) de los costes de los lados de los algoritmos
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline std::vector<float> getCoste()const{return _coste;}

		/*! 
			\fn        inline getMax()const	
			\brief     Función que devuelve el atributo flotante del coste mínimo del arbol abarcador actual
			\note      Función inline de tipo flotante
			\return    Devuelve el atributo flotante del coste mínimo del arbol abarcador actual
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		inline float getMax()const{return _max;}

		/*! 
			\fn        bool addVertex(T &punto)	
			\brief     Función añade un Vertice al grafo
			\note      Función de tipo bool
			\attention El vertice no debe existir, si no, no lo introducirá
			\param     punto: Punto genérico pasado como referencia
			\return    Devuelve true si se ha añadido correctamente, si no devuelve false
			\pre       No debe existir el vertice
			\post      Debe existir el vertice y la etiqueta asignada debe ser única
			\sa        hasCurrVertex(), escribirPunto(), setLabelVertex()
		*/
		bool addVertex(T &punto){
			Vertice<T> v(punto, getVectorEtiquetas().size()+1); //Se controla que la etiqueta es única para este vertice
			if(hasCurrVertex(v)){  //Se comprueba que si existe el vertice no lo introduzca otra vez
				std::cout<<BIRED<<"Error ";
				v.getPunto().escribirPunto();
				std::cout<<BIRED<<" ya está en el grafo"<<RESET<<std::endl;
				return false;
			}
			else{
				#ifndef NDEBUG
					assert(hasCurrVertex(v)==false);
				#endif
				_vectorVertices.push_back(v);	//Se añade el Vertice al grafo
				if(getVectorVertices().size()==1)
					it=getVectorVertices().begin();
				setLabelVertex(getVectorEtiquetas().size()+1); //Añade la etiqueta del vertice al vector de etiquetas
			#ifndef NDEBUG
				assert(hasCurrVertex(v));
			#endif
			return true;	
			}
		}

		/*! 
			\fn        bool addEdge(int const u, int const v, Lado<T> &lado, float const coste)	
			\brief     Función añade un lado al grafo
			\note      Función de tipo bool
			\attention El lado no debe existir, debe haber al menos 2 vertices para que se pueda añadir un lado
			\attention No se permiten lados que conduzcan a un mismo vertice (No se admiten ciclos de vertices a sí mismos)
			\return    Devuelve true si se ha añadido correctamente, si no devuelve false
			\pre       No debe existir el lado, la distancia euclidea entre los vertices debe ser mayor o igual que 0, los vertices no pueden ser los mismos, el coste del lado y el pasado por parámetro no debe superarS la cota de error al ser restados
			\post      Debe existir el lado
			\sa        hasCurrEdge(), setFirstVertex(), setSecondVertex(), setLadoCoste(), getLadoCoste(), getVectorLado()
		*/
		bool addEdge(int const u, int const v, Lado<T> &lado, float const coste){
			if(u!=v){ //Los vertices no pueden ser el mismo vertice
				lado.setFirstVertex(u);
				lado.setSecondVertex(v);
				lado.setLadoCoste(coste);
				if(hasCurrEdge(lado)){ //Se comprueba que si el lado existe no se introduzca otra vez
					std::cout<<BIRED<<"Error el lado "<<u<<" "<<v<<" -> "<<coste<<" ya está en el grafo"<<RESET<<std::endl;
					return false;
				}else{
					#ifndef NDEBUG
						assert(hasCurrEdge(lado)==false); //No debe existir para que se pueda introducir
						assert(coste>=0); //La distancia euclidea debe ser mayor o igual a 0
						assert(u!=v); //No se pueden crear lados que generen ciclos 
						assert(std::abs(lado.getLadoCoste()-coste)<COTA_ERROR);
					#endif
					if(coste<0){ //Si el coste es menor que 0 no se introduce el lado
						std::cout<<BIRED<<"Error el coste no puede ser menor a 0"<<std::endl;
						return false;
					}else{ //Permite introducir el lado
						_vectorLado.push_back(lado); //Se añade el lado al grafo
						if(getVectorLado().size()==1)
							itEdge=getVectorLado().begin();
						#ifndef NDEBUG
							assert(hasCurrEdge(lado));
						#endif
							return true;
					}
				}
			}else{ //Los vertices no pueden ser el mismo vertice
				std::cout<<BIRED<<"No se permiten lados que tengan el mismo vertice"<<RESET<<std::endl;
				std::cin.ignore();
				return false;
			}
		}

		//! Modificadores públicos del grafo de la clase Grafo
		/*! 
			\fn        inline void setLabelVertex(int label)
			\brief     Añade al vector de etiquetas la nueva etiqueta del vertice introducido
			\note      Función inline de tipo void
			\param     label: Label de tipo entero
			\pre       No debe existir en el vector de etiquetas la etiquetas a introducir
			\post      Ninguna
			\sa        addVertex()
		*/
		inline void setLabelVertex(int label){_label.push_back(label);}

		/*! 
			\fn        void recogerCamino(vector<float> padre, vector<float> hijo, vector<float> coste)
			\brief     Regoce y muestra por pantalla el camino que ha tomado el arbol abarcador
			\note      Función de tipo void
			\param     padre: Vector de flotantes donde se guardan los lados visitados
			\param     hijo: Vector de flotantes donde se guardan los lados a visitar
			\param     coste: Vector de flotantes donde se guardan los costes de los lados por los que ha pasado el arbol abarcador
			\pre       Ninguna
			\post      Ninguna
			\sa        prim(), kruskal()
		*/
		void recogerCamino(std::vector<float> padre, std::vector<float> hijo, std::vector<float> coste){
			for(unsigned int i=0; i<padre.size();i++){
				std::cout<<BIBLUE<<"("<<padre[i]<<", "<<hijo[i]<<")"<<"   "<<coste[i]<<std::endl;
			}
		}

		/*! 
			\fn        void crearMatriz(vector<Vertice<T> >v, vector<Lado<T> >l, unsigned int i)
			\brief     Función que genera la matriz de adyacencias con las etiquetas en las posiciones 0 de x e y
			\note      Función de tipo void
			\attention El atributo privado _matriz es ajustado con la matriz al final de la función
			\param     v: Vector de vertices genéricos pasado como parámetro
			\param     l: Vector de lados genéricos pasado como parámetro
			\param     i: Contador entero sin signo para añadirle una posición más a la matriz para que las etiquetas y los valores de la matriz se ajusten correctamente
			\pre       Ninguna
			\post      Ninguna
			\sa        setMatriz()
		*/
		void crearMatriz(std::vector<Vertice<T> >v, std::vector<Lado<T> >l, unsigned int i){
			std::vector<std::vector<float> > Vector2 ( i, std::vector<float> (i));
    		for(unsigned int y=1;y<i;y++){
    				Vector2[y][0]=v[y-1].getLabel(); //Se insertan las etiquetas en las posiciones 0 de x e y 
    				Vector2[0][y]=v[y-1].getLabel();
       			for(unsigned int x=1;x<i;x++){
	       			if(Vector2[y][x] == 0 || Vector2[y][x] ==0){	
	       				if(y==x){
       						Vector2[y][x]=0;
	       				}else{
		       				if(i-x!=0){
				       			if(adjacent(v[y-1].getLabel(), v[x-1].getLabel(), l)){
				       				if(getDirected()==true)
					            		Vector2[y][x]=getVectorCoste(l, v[y-1].getLabel(), v[x-1].getLabel()); //Dirigido
				            		else{
										Vector2[y][x]=getVectorCoste(l, v[y-1].getLabel(), v[x-1].getLabel()); //No dirigido
										Vector2[x][y]=getVectorCoste(l, v[y-1].getLabel(), v[x-1].getLabel());
				            		}
				            	}
					        }
					    }
				    }
       			}
    		}
    		setMatriz(Vector2);
		}

		/*! 
			\fn        void crearMatrizSinLabels(vector<Vertice<T> >v, vector<Lado<T> >l)
			\brief     Función que genera la matriz de adyacencias sin etiquetas 
			\note      Función de tipo void
			\attention El atributo privado _matrizwLabels es ajustado con la matriz al final de la función
			\param     v: Vector de vertices genéricos pasado como parámetro
			\param     l: Vector de lados genéricos pasado como parámetro
			\pre       Ninguna
			\post      Ninguna
			\sa        setMatrizWLabels()
		*/
		void crearMatrizSinLabels(std::vector<Vertice<T> >v, std::vector<Lado<T> >l){
			std::vector<std::vector<float> > Vector2 ( v.size(), std::vector<float> (v.size()));
    		for(unsigned int y=0;y<v.size();y++){
       			for(unsigned int x=0;x<v.size();x++){
	       			if(Vector2[y][x] == 0 || Vector2[y][x] ==0){	
	       				if(y==x){
       						Vector2[y][x]=0;
	       				}else{
				       		if(adjacent(v[y].getLabel(), v[x].getLabel(), l)){
					           	if(getDirected()==true)
					            	Vector2[y][x]=getVectorCoste(l, v[y].getLabel(), v[x].getLabel()); //Dirigido
				            	else{
									Vector2[y][x]=getVectorCoste(l, v[y].getLabel(), v[x].getLabel()); //No Dirigido
									Vector2[x][y]=getVectorCoste(l, v[y].getLabel(), v[x].getLabel());
				            	}
				            }
					    }
				    }
       			}
    		}
    		setMatrizWLabels(Vector2);
		}

		/*! 
			\fn        void crearGrafo(vector<Lado<T> >l, string const & nombreFichero)
			\brief     Función que genera el fichero .dot para que la aplicación graphviz genere el grafo en PNG con los vertices y los lados del grafo actual
			\note      Función de tipo void
			\attention El fichero debe tener la extensión .dot
			\param     l: Vector de lados genéricos pasado como parámetro
			\param     nombreFichero: string pasado como referencia constante para el nombre del fichero
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		void crearGrafo(std::vector<Lado<T> >l, std::string const & nombreFichero){
			std::ifstream grap;
			grap.open(nombreFichero.c_str());
			if(grap.is_open()){
				for(itEdge=l.begin();itEdge!=l.end();itEdge++){
					fprintf(grap, "%d -> %d [label=\"%f\"]",itEdge->getFirstVertex(), itEdge->getSecondVertex(), itEdge->getLadoCoste()); //Sirve para crear el .dot del arbol sin aplicar los algoritmos
				}
				grap.close();
			}
		}

		/*! 
			\fn        inline void setMatriz(vector<vector<float> > matriz)
			\brief     Función que ajusta el atributo _matriz de la clase Grafo a la matriz pasada como parámetro
			\note      Función inline de tipo void
			\attention La matriz debe ser generada con etiquetas
			\param     matriz: Vector de vectores flotantes para guardar la matriz con etiquetas
			\pre       Ninguna
			\post      Ninguna
			\sa        getMatriz()
		*/
		inline void setMatriz(std::vector<std::vector<float> > matriz){_matriz=matriz;}

		/*! 
			\fn        inline void setMatrizWLabels(vector<vector<float> > matrizwLabels)
			\brief     Función que ajusta el atributo _matrizwLabels de la clase Grafo a la matriz pasada como parámetro
			\note      Función inline de tipo void
			\attention La matriz debe ser generada sin etiquetas
			\param     matrizwLabels: Vector de vectores flotantes para guardar la matriz sin etiquetas
			\pre       Ninguna
			\post      Ninguna
			\sa        getMatrizWLabels()
		*/
		inline void setMatrizWLabels(std::vector<std::vector<float> > matrizwLabels){_matrizwLabels=matrizwLabels;}

		/*! 
			\fn        inline void setPadre(vector<float>  &padre)
			\brief     Función que ajusta el atributo _padre de la clase Grafo al vector de flotantes padre pasado como referencia
			\note      Función inline de tipo void
			\param     padre: Vector de flotantes para guardar los lados visitados de los algoritmos de arboles abarcadores
			\pre       Ninguna
			\post      Ninguna
			\sa        prim(), kruskal(), getPadre()
		*/
		inline void setPadre(std::vector<float>  &padre){_padre=padre;}

		/*! 
			\fn        inline void setHijo(vector<float>  &hijo)
			\brief     Función que ajusta el atributo _hijo al vector de flotantes hijo pasado como referencia
			\note      Función inline de tipo void
			\param     hijo: Vector de flotantes para guardar los lados a visitar de los algoritmos de arboles abarcadores
			\pre       Ninguna
			\post      Ninguna
			\sa        prim(), kruskal(), getHijo()
		*/
		inline void setHijo(std::vector<float>  &hijo){_hijo=hijo;}

		/*! 
			\fn        inline void setCoste(vector<float>  &coste)
			\brief     Función que ajusta el atributo _coste al vector de flotantes coste pasado como referencia
			\note      Función inline de tipo void
			\param     coste: Vector de flotantes para guardar los costes de los lados de coste mínimo de los algoritmos de arboles abarcadores
			\pre       Ninguna
			\post      Ninguna
			\sa        prim(), kruskal(), getCoste()
		*/
		inline void setCoste(std::vector<float>  &coste){_coste=coste;}

		/*! 
			\fn        inline void setMax(float  &max)
			\brief     Función que ajusta el atributo _max al flotante max pasado como referencia
			\note      Función inline de tipo void
			\param     max: Vector de flotantes para guardar el coste mínimo generado por el arbol abarcador de los algoritmos
			\pre       Ninguna
			\post      Ninguna
			\sa        prim(), kruskal(), getMax()
		*/
		inline void setMax(float &max){_max=max;}

		/*! 
			\fn        inline void setDirected(bool dirigido)
			\brief     Función que ajusta el atributo principal de la clase grafo
			\note      Función inline de tipo void
			\param     dirigido: Booleano para ajustar el estado del grafo en dirigido o no dirigido
			\pre       Ninguna
			\post      Ninguna
			\sa        getDirected()
		*/
		inline void setDirected(bool dirigido){_dirigido=dirigido;}

		/*! 
			\fn        void imprimirVertices()
			\brief     Función que imprime los vertices del grafo
			\note      Función de tipo void
			\attention Debe haber vertices en el grafo
			\pre       Ninguna
			\post      Ninguna
			\sa        imprimirVertice()
		*/
		void imprimirVertices(){
			unsigned int i;
			int parar=0;
			std::cout<<BIBLUE<<"(X, Y) -> Etiqueta"<<RESET<<std::endl;
			for(i=0;i<_vectorVertices.size();i++){	
				if(parar==21){
					PLACE(25,1);
					std::cout << "Pulse ";
					std::cout << BIGREEN;
					std::cout << "ENTER";
					std::cout << RESET;
					std::cout << " para mostrar la siguiente ";
					std::cout << INVERSE;
					std::cout << "página"; 
					std::cout << RESET;

					// Pausa
					std::cin.ignore();
					std::cin.ignore();
					PLACE(2,1);
					std::cout << CLEAR_SCREEN;
					PLACE(1,1);
					std::cout<<BIBLUE<<"(X, Y) -> Etiqueta"<<RESET<<std::endl;
					parar=0;
				}else{
					_vectorVertices[i].imprimirVertice();
					parar++;
				}
			
			}
		}
		
		/*! 
			\fn        void imprimirLados()
			\brief     Función que imprime los lados del grafo
			\note      Función de tipo void
			\attention Debe haber vertices y lados en el grafo
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		void imprimirLados(){
			unsigned int i;
			int parar=0;
			std::cout<<BIBLUE<<"(V1, V2) -> Coste"<<RESET<<std::endl;
			for(i=0;i<_vectorLado.size();i++){	
				if(parar==21){
					PLACE(25,1);
					std::cout << "Pulse ";
					std::cout << BIGREEN;
					std::cout << "ENTER";
					std::cout << RESET;
					std::cout << " para mostrar la siguiente ";
					std::cout << INVERSE;
					std::cout << "página"; 
					std::cout << RESET;

					// Pausa
					std::cin.ignore();
					std::cin.ignore();
					PLACE(2,1);
					std::cout << CLEAR_SCREEN;
					PLACE(1,1);
					std::cout<<BIBLUE<<"(V1, V2) -> Coste"<<RESET<<std::endl;
					parar=0;
				}else{
					std::cout<<BIYELLOW<<"("<<_vectorLado[i].getFirstVertex()<<", "<<_vectorLado[i].getSecondVertex()<<") -> "<<_vectorLado[i].getLadoCoste()<<RESET<<std::endl;
					parar++;
				}
			}
		}
			
		/*! 
			\fn        removeVertexEdges(Vertice<T> v)
			\brief     Función que elimina los lados conectados al vertice pasado como parámetro
			\note      Función de tipo void
			\param 	   v: Objeto de tipo Vertice genérico
			\attention Debe haber 2 vertices como mínimo y 1 lado en el grafo
			\pre       Que exista el vertice
			\post      Ninguna
			\sa        hasCurrVertex(), hasCurrEdge(), removeEdge(), getLabel()
		*/	
		void removeVertexEdges(Vertice<T> v){
			if(hasCurrVertex(v)){
				#ifndef	NDEBUG
					assert(hasCurrVertex(v)); //Se comprueba si el vertice pasado por referencia existe en el grafo
				#endif
				bool value=false;
				if(_vectorLado.size()!=0){ //Si hay algún lado comprueba si está conectado al vertice
					do{
						value=removeEdge(v.getLabel());
					}while(value==false); //Mientras que removeEdge no nos diga que no hay más lados que borrar seguirá iterando
				}
				std::cout<<BIGREEN<<"\nLos lados del vertice se han borrado correctamente"<<RESET<<std::endl;
			}else{
		        std::cout<<BIRED<<"No existe ese vertice"<<RESET<<std::endl;
		        std::cin.ignore();
		        return;
    		}
		}

		/*! 
			\fn        bool removeEdge(int const &u)
			\brief     Función que elimina los lados conectados al vertice pasado como parámetro
			\note      Función de tipo bool
			\return    Devuelve verdadero si se ha borrado el lado, si no devuelve false
			\attention Este return sirve para saber si quedan lados aun por borrar en removeVertexEdges()
			\param     u: Etiqueta de tipo entero pasada como parámetro constante
			\attention Debe haber 2 vertices como mínimo y 1 lado en el grafo
			\pre       Que exista el lado
			\post      Que no exista el lado
			\sa        hasCurrEdge(), removeVertexEdges()
		*/	
		bool removeEdge(int const &u){
			for(itEdge=_vectorLado.begin(); itEdge != _vectorLado.end(); itEdge++){
				if(itEdge->getFirstVertex() == u){
					std::cout<<BIGREEN<<"El lado"<<BIYELLOW;
					itEdge->imprimirLado();
					std::cout<<BIGREEN<<"se ha borrado correctamente"<<RESET<<std::endl;					
					_vectorLado.erase(itEdge);
					return false;
				}else if(itEdge->getSecondVertex() == u){
					std::cout<<BIGREEN<<"El lado "<<BIYELLOW;
					itEdge->imprimirLado();
					std::cout<<BIGREEN<<"se ha borrado correctamente"<<RESET<<std::endl;
					_vectorLado.erase(itEdge);
					return false;
				}
			}
			return true;
		}

		/*! 
			\fn        inline void removeAllVertexAndEdges()
			\brief     Función que elimina los lados y vertices del grafo
			\note      Función inline de tipo void
			\attention Primero se borran todos los lados de los vertices para no tener conflicto con el grafo, luego se borran los vertices
			\attention Debe haber 2 vertices como mínimo y 1 lado en el grafo
			\pre       Que el grafo tenga elementos
			\post      Que el grafo esté vacio
			\sa        isEmpty()
		*/	
		inline void removeAllVertexAndEdges(){
			_vectorLado.clear();
			_vectorVertices.clear();
			_label.clear();
			#ifndef NDEBUG
				assert(isEmpty());
			#endif
		}

		//! Función de escritura por pantalla
		/*! 
			\fn        void imprimirMatriz(vector<Vertice<T> > v, vector<vector<float> > v2, unsigned int i)
			\brief     Función que imprime la matriz de adyacencias con etiquetas por pantalla
			\note      Función de tipo void
			\param     v: Vector de vertices genéricos pasado como parámetro
			\param     v2: Vector de vectores flotante pasado como parámetro
			\param     i: Contador entero sin signo para añadirle una posición más a la matriz para que las etiquetas y los valores de la matriz se ajusten correctamente
			\attention Debe haber 2 vertices como mínimo y 1 lado en el grafo
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		void imprimirMatriz(std::vector<Vertice<T> > v, std::vector<std::vector<float> > v2, unsigned int i){
    		for(unsigned int y=0;y<i;y++){
       			for(unsigned int x=0;x<i;x++){
            		std::cout<<BIBLUE<<v2[y][x]<<RESET<<"\t";
       			}
       			std::cout<<std::endl;
    		}
    		std::cout<<std::endl;
		}

		/*! 
			\fn        void imprimirMatrizSinLabels(vector<Vertice<T> > v, vector<vector<float> > v2)
			\brief     Función que imprime la matriz de adyacencias sin etiquetas por pantalla
			\note      Función de tipo void
			\param     v: Vector de vertices genéricos pasado como parámetro
			\param     v2: Vector de vectores flotante pasado como parámetro
			\attention Debe haber 2 vertices como mínimo y 1 lado en el grafo
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		void imprimirMatrizSinLabels(std::vector<Vertice<T> > v, std::vector<std::vector<float> > v2){
    		for(unsigned int y=0;y<v.size();y++){
       			for(unsigned int x=0;x<v.size();x++){
            		std::cout<<BIBLUE<<v2[y][x]<<RESET<<"\t";
       			}
       			std::cout<<std::endl;
    		}
    		std::cout<<std::endl;
		}

		/*! 
			\fn        void matricesAFichero(char *nombreFichero, vector<Vertice<T> > v, vector<vector<float> > v2, unsigned int i)
			\brief     Función que imprime en un fichero la matriz de adyacencias con etiquetas por pantalla
			\note      Función de tipo void
			\param     nombreFichero: Char para el nombre del fichero, ya que se usan la función fprintf()
			\param     v: Vector de vertices genéricos pasado como parámetro
			\param     v2: Vector de vectores flotante pasado como parámetro
			\param     i: Contador entero sin signo para añadirle una posición más a la matriz para que las etiquetas y los valores de la matriz se ajusten correctamente		
			\attention Debe haber 2 vertices como mínimo y 1 lado en el grafo
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		void matricesAFichero(char *nombreFichero, std::vector<Vertice<T> > v, std::vector<std::vector<float> > v2, unsigned int i){
			FILE *f;
            std::cout<<RESET<<std::endl;

   			f=fopen(nombreFichero, "w" );
            for(unsigned int y=0;y<i;y++){
       			for(unsigned int x=0;x<i;x++){
					fprintf(f, "| %.2f | ", v2[y][x]);
				}
				fprintf(f, "\n");
			}
			fprintf(f, "\n");
			fclose(f);
		}

		/*! 
			\fn        void matricesAFicheroAlgoritmos(char *nombreFichero, vector<Vertice<T> > v, vector<vector<float> > v2)
			\brief     Función que imprime en un fichero la matriz de los Algoritmos de Arbol Abarcador sin etiquetas por pantalla
			\note      Función de tipo void
			\param     nombreFichero: Char para el nombre del fichero, ya que se usan la función fprintf()
			\param     v: Vector de vertices genéricos pasado como parámetro
			\param     v2: Vector de vectores flotante pasado como parámetro
			\attention Debe haber 2 vertices como mínimo y 1 lado en el grafo
			\pre       Ninguna
			\post      Ninguna
			\sa        Ninguna
		*/
		void matricesAFicheroAlgoritmos(char *nombreFichero, std::vector<Vertice<T> > v, std::vector<std::vector<float> > v2){
			FILE *f;
            std::cout<<RESET<<std::endl;

   			f=fopen(nombreFichero, "w" );
            for(unsigned int y=0;y<v.size();y++){
       			for(unsigned int x=0;x<v.size();x++){
					fprintf(f, "| %.2f | ", v2[y][x]);
				}
				fprintf(f, "\n");
			}
			fprintf(f, "\n");
			fclose(f);
		}
	}; //Se cierra la clase Grafo
} //Se cierra el espacio de nombres de la asignatura ED

// MODELO DE COMPILACION POR INCLUSION

#include "Grafo.cpp"

#endif