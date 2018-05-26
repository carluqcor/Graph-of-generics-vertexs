/*!
	\file principalGrafo.cpp
	\brief Programa principal de la práctica 4 de ED: Grafo Abarcador de coste mínimo
	\author Carlos Luque Córdoba
  	\date   anywhere
	\version 1.0
*/

/*!
 \mainpage Implementación de un Grafo Abarcador de coste mínimo
 \author   Carlos Luque Córdoba
 \date     anywhere
 \version  1.0
*/

// Para los flujos de entrada y salida y para usar locale
#include <iostream>
#include <string>

#include <vector>

#include "macros.hpp"
#include "distancia.hpp"
#include "Punto.hpp"
#include "Vertice.hpp"
#include "Lado.hpp"
#include "Grafo.hpp"
#include "funcionesAuxiliares.hpp"

/*! 
	\brief   Programa principal de la práctica 4: Grafo Abarcador de coste mínimo
	\return  int
*/

int main(){
	float dist;
    unsigned int i=1;
	ed::Punto <float> punto(3, 5);
    ed::Punto <float> punto2(2, 1);
    ed::Punto <float> punto3(4, 2);
    ed::Punto <float> punto4(10, 7);
    ed::Vertice <ed::Punto<float> > Vertice1(-1);
    ed::Vertice <ed::Punto<float> > Vertice2(-1);
    ed::Vertice <ed::Punto<float> > Vertice3(-1);
    ed::Vertice <ed::Punto<float> > Vertice4(-1);

  //  unsigned int i, j;

    std::vector<ed::Vertice<ed::Punto<float> > > vectorVertices; //! Vector de Vertices de Puntos de la STL

	std::vector<ed::Lado<ed::Punto<float> > >  vectorLado; //! Vector Lados de Puntos de la STL

    ed::Grafo <ed::Punto<float> > graph(vectorVertices, vectorLado);

    std::vector<std::vector<float> > matriz;

    graph.addVertex(punto, Vertice1);
    graph.addVertex(punto2, Vertice2);
    graph.addVertex(punto3, Vertice3);
    graph.addVertex(punto4, Vertice4);

    i++;
    i++;
    i++;
    i++;

    dist=ed::calcularDistanciaEuclidea(punto.getX(), punto.getY(), punto2.getX(), punto2.getY());

    (Vertice1.getPunto()).escribirPunto();
    std::cout<<"Label: "<<Vertice1.getLabel()<<std::endl;

    (Vertice2.getPunto()).escribirPunto();
    std::cout<<"Label 2: "<<Vertice2.getLabel()<<std::endl;

    (Vertice3.getPunto()).escribirPunto();
    std::cout<<"Label 3: "<<Vertice3.getLabel()<<std::endl;

    (Vertice4.getPunto()).escribirPunto();
    std::cout<<"Label 4: "<<Vertice4.getLabel()<<std::endl;

    ed::Lado <ed::Punto<float> > edge(dist);
    graph.addEdge(Vertice1.getLabel(), Vertice2.getLabel(), edge, dist);

    edge.imprimirLado();

    dist=ed::calcularDistanciaEuclidea(punto2.getX(), punto2.getY(), punto3.getX(), punto3.getY());

    ed::Lado <ed::Punto<float> > edge1(dist);
    graph.addEdge(Vertice2.getLabel(), Vertice3.getLabel(), edge1, dist);

	edge1.imprimirLado();

    dist=ed::calcularDistanciaEuclidea(punto.getX(), punto.getY(), punto3.getX(), punto3.getY());

    ed::Lado <ed::Punto<float> > edge2(dist);

    graph.addEdge(Vertice1.getLabel(), Vertice3.getLabel(), edge2, dist);

    edge2.imprimirLado();


    dist=ed::calcularDistanciaEuclidea(punto3.getX(), punto3.getY(), punto4.getX(), punto4.getY());

    ed::Lado <ed::Punto<float> > edge3(dist);

    graph.addEdge(Vertice3.getLabel(), Vertice4.getLabel(), edge3, dist);

    edge3.imprimirLado();

    matriz=graph.crearMatriz(graph.getVectorVertices(), graph.getVectorLado(), graph.getVectorEtiquetas().size()+1);

    graph.imprimirMatriz(graph.getVectorVertices(), matriz, graph.getVectorEtiquetas().size()+1);
    ed::prim(graph);
}