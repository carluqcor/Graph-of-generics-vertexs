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

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void ed::prim(ed::Grafo <ed::Punto<float> > graphT){
    matriz=graphT.crearMatriz(graphT.getVectorVertices(), graphT.getVectorLado(), graphT.getVectorEtiquetas().size()+1);
	int label, flag, visited[],i,j,k,l;
	std::cout<<"\n ¿Por qué vertice empezamos el algoritmo? (Introduzca la etiqueta del vertice): ";
	std::cin>>label;
	std::endl;
	int min=graphT.getPeso();
	int from=graphT.getFrom();
	int to=graphT.getTo();

	//search whether graph contains x
	flag = 0;
	for(i =0; i<n; i++){
		if(graphT.getVectorVertices()[i].getLabel() == label){
			flag = 1;
		}
	}

	if(flag == 0){
		cout<<"\n No es un vertice válido ";
		return;//terminate the fn
	}

	//i contains index of start vertex
	//mark i as visited, representing that i is a node of tree
	visited[graphT.getVectorVertices()[i].getLabel()] = 1;

	//MST MUST HAVE ALL VERTICES OF GRAPH
	for(i =0; i< n-1; i++){
		min = 999;//infinite

		for(j = 0; j < v; j++){ //from the visited list i.e. from the tree 
			//FETCH A CURRENT VERTEX FROM MST
			current = visited[graphT.getVectorVertices()[i].getLabel()];

			//FOR THE CURRENT VERTEX FIND UNVISITED EDGE WITH MINIMUM WEIGHT
				for(k = 0; k< n; k++){
					if(matriz[current+1][k+1] != 999){//an edge exists

						//if k is not visited

						flag =0; //not found
						for(l =0 ; l< v; l++){
							if(visited[l]== k){
								flag = 1;//found
							}
						}

						if(flag == 0){ //unvisited k
							wt= matriz[current+1][k+1];
						if(wt < min){
							min =wt;
							from = current;
							to = k;
						}
					}//if flag == 0
				}//if matriz[current][k] != 999
			}//for k
		}//for j

		//ADD IT AS A NODE IN TREE
		graphT.setFrom()
		graphT.setTo();
		graphT.setPeso();
		mstIndx++;

		//mark to as visited, representing that to is a node of tree
		visited[v] = to;
		v++;

	} //for i

	printPrim();
}