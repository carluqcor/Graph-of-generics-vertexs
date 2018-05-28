/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 4
  \author Carlos Luque Córdoba
  \date   anywhere
*/

#include <cstdlib>
#include <iostream>
#include <string>
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

using namespace std;

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
	std::cout <<BICYAN<< "[1] Comprobar si el Grafo tiene vertices"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,12);
	std::cout <<BIYELLOW<< "[2] Cargar el Grafo desde un fichero"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIYELLOW<< "[3] Grabar las matrices de adyacencia en un fichero"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,12);
	std::cout <<BIGREEN<< "[4] Mostrar los vertices y lados del Grafo"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIGREEN<<"[5] Mostrar la Matriz de Adyacencias"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIGREEN<<"[6] Algoritmo de Prim"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIGREEN<<"[7] Algoritmo de Kruskal"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIGREEN<<"[8] Borrar un Vertice"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,12);
	std::cout <<BIBLUE<< "[9] Borrar todos los vertices y lados"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIBLUE<<"[10] Insertar una Vertice"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIBLUE<< "[11] Insertar un Lado"<<RESET;

	PLACE(posicion++,12);
	std::cout <<BIBLUE<< "[12] Generar el Grafo en PNG"<<RESET;

	
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

std::vector<std::vector<float> > ed::prim(ed::Grafo <ed::Punto<float> > graph, ed::Grafo <ed::Punto<float> > graph2){
	// uso una copia de ady porque necesito eliminar columnas
	unsigned int nVertices=graph.getVectorVertices().size();
	std::vector< std::vector<float> > adyacencia = graph.getMatrizWLabels();
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
std::vector<std::vector<float> > ed::kruskal(ed::Grafo <ed::Punto<float> > graph, ed::Grafo <ed::Punto<float> > graph2){
    std::vector< std::vector<float> > adyacencia = graph.getMatrizWLabels();
    int nVertices=graph.getVectorVertices().size();
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