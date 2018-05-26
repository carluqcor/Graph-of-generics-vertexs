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
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "macros.hpp"
#include "distancia.hpp"
#include "Punto.hpp"
#include "Vertice.hpp"
#include "Lado.hpp"
#include "Grafo.hpp"
#include "kruskal.hpp"
#include "funcionesAuxiliares.hpp"

/*! 
	\brief   Programa principal de la práctica 4: Grafo Abarcador de coste mínimo
	\return  int
*/
int main(){
	float dist;
    unsigned int i=1;
    std::string nombreFichero;
    std::getline(std::cin,nombreFichero);
    
    //ed::Punto <float> punto(0.0, 0.0);
    //ed::Punto <float> punto2(0.0, 1.0);
    //ed::Punto <float> punto3(3.0, 1.0);
    //ed::Punto <float> punto4(3.0, 3.0);
    //ed::Punto <float> punto5(8.0, 1.0);
    //ed::Vertice <ed::Punto<float> > Vertice1(-1);
    //ed::Vertice <ed::Punto<float> > Vertice2(-1);
    //ed::Vertice <ed::Punto<float> > Vertice3(-1);
    //ed::Vertice <ed::Punto<float> > Vertice4(-1);
    //ed::Vertice <ed::Punto<float> > Vertice5(-1);
    
    //  unsigned int i, j;

    std::vector<ed::Vertice<ed::Punto<float> > > vectorVertices; //! Vector de Vertices de Puntos de la STL

    std::vector<ed::Lado<ed::Punto<float> > >  vectorLado; //! Vector Lados de Puntos de la STL

    ed::Grafo <ed::Punto<float> > graph(vectorVertices, vectorLado);

    añadirVertices(nombreFichero, graph);

    std::vector<std::vector<float> > matriz;

    //graph.addVertex(punto, Vertice1);
    //graph.addVertex(punto2, Vertice2);
    //graph.addVertex(punto3, Vertice3);
    //graph.addVertex(punto4, Vertice4);
    //graph.addVertex(punto5, Vertice5);

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

    (Vertice5.getPunto()).escribirPunto();
    std::cout<<"Label 5: "<<Vertice5.getLabel()<<std::endl;

    ed::Lado <ed::Punto<float> > edge(dist);
    graph.addEdge(Vertice1.getLabel(), Vertice2.getLabel(), edge, dist);

    edge.imprimirLado();

    dist=ed::calcularDistanciaEuclidea(punto.getX(), punto.getY(), punto3.getX(), punto3.getY());

    ed::Lado <ed::Punto<float> > edge1(dist);
    graph.addEdge(Vertice1.getLabel(), Vertice3.getLabel(), edge1, dist);

    edge1.imprimirLado();

    dist=ed::calcularDistanciaEuclidea(punto.getX(), punto.getY(), punto4.getX(), punto4.getY());

    ed::Lado <ed::Punto<float> > edge2(dist);

    graph.addEdge(Vertice1.getLabel(), Vertice4.getLabel(), edge2, dist);

    edge2.imprimirLado();


    dist=ed::calcularDistanciaEuclidea(punto.getX(), punto.getY(), punto5.getX(), punto5.getY());

    ed::Lado <ed::Punto<float> > edge3(dist);

    graph.addEdge(Vertice1.getLabel(), Vertice5.getLabel(), edge3, dist);

    edge3.imprimirLado();

    dist=ed::calcularDistanciaEuclidea(punto2.getX(), punto2.getY(), punto3.getX(), punto3.getY());

    ed::Lado <ed::Punto<float> > edge4(dist);

    graph.addEdge(Vertice2.getLabel(), Vertice3.getLabel(), edge4, dist);

    edge4.imprimirLado(); //

    dist=ed::calcularDistanciaEuclidea(punto2.getX(), punto2.getY(), punto4.getX(), punto4.getY());

    ed::Lado <ed::Punto<float> > edge5(dist);

    graph.addEdge(Vertice2.getLabel(), Vertice4.getLabel(), edge5, dist);

    edge5.imprimirLado();

      dist=ed::calcularDistanciaEuclidea(punto2.getX(), punto2.getY(), punto5.getX(), punto5.getY());

    ed::Lado <ed::Punto<float> > edge6(dist);

    graph.addEdge(Vertice2.getLabel(), Vertice5.getLabel(), edge6, dist);

    edge6.imprimirLado();//

      dist=ed::calcularDistanciaEuclidea(punto3.getX(), punto3.getY(), punto4.getX(), punto4.getY());

    ed::Lado <ed::Punto<float> > edge7(dist);

    graph.addEdge(Vertice3.getLabel(), Vertice4.getLabel(), edge7, dist);

    edge7.imprimirLado();


  dist=ed::calcularDistanciaEuclidea(punto3.getX(), punto3.getY(), punto5.getX(), punto5.getY());

    ed::Lado <ed::Punto<float> > edge8(dist);

    graph.addEdge(Vertice3.getLabel(), Vertice5.getLabel(), edge8, dist);

    edge8.imprimirLado();

  dist=ed::calcularDistanciaEuclidea(punto4.getX(), punto4.getY(), punto5.getX(), punto5.getY());

    ed::Lado <ed::Punto<float> > edge9(dist);

    graph.addEdge(Vertice4.getLabel(), Vertice5.getLabel(), edge9, dist);

    edge9.imprimirLado();

    matriz=graph.crearMatriz(graph.getVectorVertices(), graph.getVectorLado(), graph.getVectorEtiquetas().size()+1);

    graph.imprimirMatriz(graph.getVectorVertices(), matriz, graph.getVectorEtiquetas().size()+1);

    matriz=graph.prim();

    graph.imprimirMatrizSinLabels(graph.getVectorVertices(), matriz);

    matriz=graph.kruskal();

    graph.imprimirMatrizSinLabels(graph.getVectorVertices(), matriz);
}
