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
	ed::Punto <float> punto(3, 5);
    ed::Punto <float> punto2(2, 1);
    ed::Vertice <ed::Punto<float> > Vertice1(punto, 0);
    ed::Vertice <ed::Punto<float> > Vertice2(punto2, 0);

    std::vector<ed::Vertice<ed::Punto<float> > > vectorVertices; //! Vector de Vertices de Puntos de la STL
	
	std::vector<std::vector<int> > matriz;

	std::vector<ed::Lado<ed::Punto<float> > >  vectorLado; //! Vector Lados de Puntos de la STL

    //ed::Grafo <ed::Lado <ed::Vertice<ed::Punto<float> > > > graph(vectorVertices, vectorLado, matriz);

    punto.escribirPunto();
    punto2.escribirPunto();

    dist=ed::calcularDistanciaEuclidea(punto.getX(), punto.getY(), punto2.getX(), punto2.getY());

    std::cout<<"Distancia: "<<dist<<std::endl;

    Vertice2.setPunto(punto2);
    Vertice2.setLabel(1);

    (Vertice1.getPunto()).escribirPunto();
    std::cout<<"Label: "<<Vertice1.getLabel()<<std::endl;

    (Vertice2.getPunto()).escribirPunto();
    std::cout<<"Label: "<<Vertice2.getLabel()<<std::endl;

    ed::Lado <ed::Punto<float> >  edge(Vertice1, Vertice2, dist);
    
	std::cout<<"First: ";
    (edge.getFirstVertex()->getPunto()).escribirPunto();
    std::cout<<std::endl;
    std::cout<<"Second: ";
    (edge.getSecondVertex()->getPunto()).escribirPunto();
    std::cout<<std::endl;
    std::cout<<"Coste: %f",edge.getLadoCoste();
    std::cout<<std::endl;
}


