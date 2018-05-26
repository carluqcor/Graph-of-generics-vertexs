/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 4
  \author Carlos Luque Córdoba
  \date   anywhere
*/


#include <iostream>

#include <fstream>

#include <string>

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <vector>
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"
#include "distancia.hpp"
#include "Punto.hpp"
#include "Vertice.hpp"
#include "Lado.hpp"
#include "Grafo.hpp"

#include "macros.hpp"

#include <cmath>

int ed::menu(){
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,12);
	std::cout <<BICYAN<< "[1] Comprobar si el montículo tiene mediciones"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,12);
	std::cout <<BIYELLOW<< "[2] Cargar el montículo desde un fichero"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIYELLOW<< "[3] Grabar el montículo en un fichero"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,12);
	std::cout <<BIGREEN<< "[4] Consultar datos del montículo"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIGREEN<<"[5] Mostrar mediciones ordenadas por precipitación del montículo"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIGREEN<<"[6] Mostrar estadisticas de una fecha"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIGREEN<<"[7] Mostrar estadisticas de un mes"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIGREEN<<"[8] Borrar todas las mediciones del montículo"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,12);
	std::cout <<BIBLUE<< "[9] Consultar el top"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIBLUE<<"[10] Insertar una medición"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIBLUE<< "[11] Modificar la cima"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIBLUE<< "[12] Eliminar la cima"<<RESET;

	
	posicion++;

	PLACE(posicion++,11);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,11);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}

void ed::añadirVertices(std::string const & nombreFichero, std::string const & nombreFichero2, ed::Grafo <ed::Punto<float> > graph(std::vector<Vertice<T> > v, std::vector<Lado<T> > l)){
	std::ifstream grap, grap2;
	bool value, value2;
	ed::Punto<float> punto;
	ed::Vertice<ed::Punto<float> > vertice;
	ed::Lado<ed::Punto<float> > lado;
	grap.open(nombreFichero.c_str());
	std::string f;
	grap2.open(nombreFichero2.c_str());
	if(grap.is_open()){
		if(grap2.is_open()){
			while(!grap.eof()){
	 			grap>>punto;
	 			grap2>>lado;
	  			if(!grap.eof())
					graph.addVertex(punto,vertice);
					graph.addEdge()
	 		}
	 	}
 	grap.close();
 	grap2.close();
 	value=true;
 	}else
 		value=false;
 
 	if(value)
		std::cout<<BIGREEN<<"El fichero ha sido cargado con exito"<<RESET<<std::endl;
	else
		std::cout<<BIRED<<"Error al cargar el fichero"<<RESET<<std::endl;
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void ed::prim(ed::Grafo <ed::Punto<float> > graphT){
    std::vector<std::vector<float> >matriz=graphT.crearMatriz(graphT.getVectorVertices(), graphT.getVectorLado(), graphT.getVectorEtiquetas().size()+1);
	int label, flag, peso, min, from=0, to=0,k;
	int i, current;
	unsigned int j,l;
	std::cout<<"\n ¿Por qué vertice empezamos el algoritmo? (Introduzca la etiqueta del vertice): ";
	std::cin>>label;
	std::cout<<std::endl;
	int V=graphT.getVectorVertices().size()-1;

	//search whether graph contains x
	flag = 0;
	for(i =0; i<V; i++){
		std::cout<<"HOLA "<<graphT.getVectorVertices()[i].getLabel()<<"Etiqueta: "<<label<<std::endl;
		if(graphT.getVectorVertices()[i].getLabel() == label){
			flag = 1;
		}
	}

	if(flag == 0){
		std::cout<<"\n No es un vertice válido ";
		return;//terminate the fn
	}

	//i contains index of start vertex
	//mark i as visited, representing that i is a node of tree
	graphT.setFrom(label);

	//MST MUST HAVE ALL VERTICES OF GRAPH
	for(i =0; i<V; i++){
		std::cout<<"I: "<<i<<" Vertices: "<<V<<std::endl;
		min = 999;//infinite

		for(j = 0; j < (graphT.getFrom().size()); j++){ //from the visited list i.e. from the tree 
			//FETCH A CURRENT VERTEX FROM MST
			std::cout<<"J: "<<i<<" From: "<<graphT.getFrom().size()<<std::endl;
			current = graphT.getVectorVertices()[i].getLabel();
			std::cout<<graphT.getVectorVertices()[i].getLabel()<<std::endl;

			//FOR THE CURRENT VERTEX FIND UNVISITED EDGE WITH MINIMUM WEIGHT
				for(k = 1; k<V; k++){
					std::cout<<"Current: "<<current<<"K: "<<k<<std::endl;
					if(matriz[current][k] != 999){//an edge exists

						//if k is not visited

						flag =0; //not found
						for(l =1 ; l< (graphT.getFrom().size()); l++){
							if(graphT.getFrom()[l]== k){
								flag = 1;//found
							}
						}

						if(flag == 0){ //unvisited k
							peso=matriz[current+1][k+1];
						if(peso < min){
							min=peso;
							from=current;
							to=k;
						}
					}//if flag == 0
				}//if matriz[current][k] != 999
			}//for k
		}//for j
		graphT.setFrom(from);
		graphT.setTo(to);
		graphT.setPeso(min);
	} //for i
	std::cout<<"Desde\t"<<"Para\t"<<"Coste\t"<<std::endl;
			for(unsigned int i=0; i<graphT.getFrom().size();i++){
				std::cout<<graphT.getFrom()[i]<<"\t"<<graphT.getTo()[i]<<"\t"<<graphT.getPeso()[i]<<std::endl;
			}
	std::cout<<"Size From: "<<graphT.getFrom().size()<<" Size To: "<<graphT.getTo().size()<<" Size Peso: "<<graphT.getPeso().size()<<std::endl;
}