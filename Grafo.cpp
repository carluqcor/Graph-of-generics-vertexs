/*! 
   \file  Grafo.cpp
   \brief Fichero que contiene el código de las funciones de la clase Grafo
   \author Carlos Luque Córdoba
   \date   anywhere
*/


// Ficheros de cabecera
#include <iostream>

//Se incluye el fichero hpp
#include "Grafo.hpp"

#include "macros.hpp"

#include <cmath>

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales

//! Observadores públicos de la clase Grafo
bool ed::Grafo::has(ed::Vertice const &u){
	#ifndef NDEBUG
		assert(isEmpty()==false);
	#endif
	std::vector<Vertice>::iterator ot=_vectorVertices.begin();
	for(ot, ot!=_vectorVertices.end(), ot++){
		if(ot==u)
			return true;
	}
	return false;
}

bool ed::Grafo::hasEdge(ed::Lado const &lado){
	#ifndef NDEBUG
		assert(_vectorVertices.size()>=2);
	#endif
	std::vector<Lado>::iterator otEdge=_vectorLado.begin();
	for(otEdge, otEdge!=_vectorLado.end(),otEdge++){
		if(otEdge==lado)
			return true;
	}
	return false;
}

//! Modificador públicos de la clase Grafo
/*
	1. Si hay lados(bool adjacent) Se deben borrar sus lados por lo tanto primero se guardará el vertice en uno auxiliar, y mientras adjacent sea true se usará nextEdge() y currEdge y se borrará y se volverá al vertice con goToVertex
	2. Se borra el vertice actual (NO EL AUXILIAR CREADO) osea un _vectorVertices.erase(*this) y se hace un nextVertex()
	3. Borrar la etiqueta de ese vertice
*/
void ed::Grafo::removeVertex(){
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



void ed::Grafo::removeEdge(){
	#ifndef	NDEBUG
		assert(hasCurrEdge());
	#endif
	_vectorLado.erase(itEdge);
	itEdge=nextEdge();
	#ifndef	NDEBUG
		assert(!hasCurrEdge());
	#endif
}


//! Modificadores públicos de los cursores de la clase Grafo
void ed::Grafo::findFirstVertex(){
	if(has(_vectorVertices.begin()));
	std::cout<<"El primer vertice es: "<<_vectorVertices.begin()<<std::endl;
	#ifndef NDEBUG
		assert(has(_vectorVertices.begin()));
	#endif
}

void ed::Grafo::findNextVertex(){
	std::vector<Vertice>::iterator ot=it++;
	#ifndef NDEBUG
		assert(has(ot));
	#endif
	std::cout<<"El siguiente vertice es: <<"<ot<<std::endl;
}

void ed::Grafo::findFirstEdge(){
	if(has(_vectorLado.begin()));
	std::cout<<"El primer lado es: "<<_vectorLado.begin()<<std::endl;
	#ifndef NDEBUG
		assert(hasEdge(_vectorLado.begin()));
	#endif
}

void ed::Grafo::findNextEdge(){
	std::vector<Lado>::iterator ot=itEdge++;
	#ifndef NDEBUG
		assert(hasEdge(ot));
	#endif
	std::cout<<"El siguiente vertice es: <<"<ot<<std::endl;
}

void ed::Grafo::goToVertex(ed::Vertice const &vertice){
	#ifndef NDEBUG
		assert(has(vertice));
	#endif
	it=_vectorVertices.at(vertice);
	#ifndef NDEBUG
		assert(std::abs((currVertex().getDataX())-(vertice.getDataX()))<COTA_ERROR && std::abs((currVertex().getDataY())-(vertice.getDataY()))<COTA_ERROR);
	#endif
}

void ed::Grafo::goToEdge(ed::Vertice const &u, ed::Vertice const &v){
	#ifndef NDEBUG
		assert(hasEdge(vertice));
	#endif
	std::vector<Lado>::iterator ot=_vectorLado.begin();
	for(ot, ot != _vectorLado.end();ot++){
		if(ot.getFirstVertex() == u && ot.getSecondVertex() == v){
			ed::Lado lado=new ed::Lado(ot.getLadoName(), u, v, ot.getLadoCoste());
			itEdge=_vectorLado.at(lado);
		}else if(ot.getSecondVertex() == u && ot.getFirstVertex() == v){
			ed::Lado lado=new ed::Lado(ot.getLadoName(), v, u, ot.getLadoCoste());
			itEdge=_vectorLado.at(lado);
		}
	}
}

void ed::Grafo::goToFirstVertex(){
	#ifndef NDEBUG
		assert(has(_vectorVertices.begin()));
		assert(!isEmpty());
	#endif
		it=_vectorVertices.begin();
}

void ed::Grafo::nextVertex(){
	it++;
	#ifndef NDEBUG
		assert(has(vertice));
	#endif
}

void ed::Grafo::goToFirstEdge(){
	#ifndef NDEBUG
		assert(hasEdge(_vectorLado.begin()));
		assert(_vectorVertices.size>=2);
	#endif
		itEdge=_vectorLado.begin();
}

void ed::Grafo::nextEdge(){
	itEdge++;
	#ifndef NDEBUG
		assert(hasEdge(itEdge));
	#endif
}