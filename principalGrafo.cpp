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
#include "funcionesAuxiliares.hpp"

/*! 
    \brief   Programa principal de la práctica 4: Grafo Abarcador de coste mínimo
    \return  int
*/
int main(){
    float x, y;
    std::ifstream grap;
    bool value;

    int opcion;
    std::string nombreFichero;

    std::vector<ed::Vertice<ed::Punto<float> > > vectorVertices; //! Vector de Vertices de Puntos de la STL

    std::vector<ed::Lado<ed::Punto<float> > >  vectorLado; //! Vector Lados de Puntos de la STL

    ed::Grafo <ed::Punto<float> > graph(vectorVertices, vectorLado);
    do{
        // Se elige la opción del menún
        opcion = ed::menu();        

        std::cout << CLEAR_SCREEN;
        PLACE(3,1);

        // Se ejecuta la opción del menú elegida
        switch(opcion){
            case 0: 
                    std::cout << INVERSE;
                    std::cout << "Fin del programa" << std::endl;
                    std::cout << RESET;
            break;

           ///////////////////////////////////////////////////////////////////

            case 1: 
                    std::cout<<BIPURPLE<< "[1] Comprobar si el Grafo tiene vertices"<<RESET<< std::endl;
                    if(graph.getVectorVertices().size()==0)
                        std::cout<<ONIRED<<BIYELLOW<<"El Grafo está vacío"<<RESET<<std::endl;
                    else
                        std::cout<<BIGREEN<<"Al menos hay un Verice en el Grafo"<<RESET<<std::endl;
                    break;

            //////////////////////////////////////////////////////////////////////////////
            case 2: 
                    std::cout <<BIPURPLE<< "[2] Cargar el montículo desde un fichero" <<RESET<< std::endl;
                    std::cout<<BIBLUE<<"Introduce el nombre del fichero: ";
                    std::getline(std::cin,nombreFichero);
                    std::cout<<RESET<<std::endl;
                    grap.open(nombreFichero.c_str());
                    if(grap.is_open()){
                        while(!grap.eof()){
                            grap>>x>>y;
                            ed::Punto<float> punto(x, y);
                            if(!grap.eof()){
                                graph.addVertex(punto);
                            }
                        }
                    grap.close();
                    value=true;
                    }else
                        value=false;
                    
                    if(value)
                        std::cout<<BIGREEN<<"\nEl fichero ha sido cargado con exito"<<RESET<<std::endl;
                    else{
                        std::cout<<BIRED<<"Error al cargar el fichero"<<RESET<<std::endl;
                    }
                break;

            case 3: 
                    
                    break;

            //////////////////////////////////////////////////////////////////////////////
            case 4: 
                    break;

            case 5: 
                    std::cout<<BIPURPLE<< "[5] Mostrar las mediciones del montículo: " <<RESET<< std::endl;

                    break;


            //////////////////////////////////////////////////////////////////////////////
            case 6: 
                    std::cout <<BIPURPLE<< "[6] Mostrar estadisticas de una fecha"<<RESET<< std::endl;
                    break;

            case 7: 
                    std::cout <<BIPURPLE<< "[7] Mostrar estadisticas de un mes"<<RESET<< std::endl;
                    break;


            case 8: 
                    std::cout <<BIPURPLE<< "[8] Borrar todas las mediciones del montículo" <<RESET<<std::endl;
                    break;

            //////////////////////////////////////////////////////////////////////////////
            case 9: 
                    std::cout <<BIPURPLE<< "[9] Consultar el top\n" <<RESET<< std::endl;
                    break;

            case 10: 
                    std::cout <<BIPURPLE<< "[10] Insertar una medición" <<RESET<< std::endl;
                    break;

            case 11: 
                    std::cout <<BIPURPLE<< "[11] Modificar la cima" <<RESET<<std::endl;
                    break;
            case 12: 
                    std::cout <<BIPURPLE<< "[12] Eliminar la cima" <<RESET<<std::endl;
                    break;
            //////////////////////////////////////////////////////////////////////////////
            default:
                std::cout << BIRED;
                std::cout << "Opción incorrecta ";
                std::cout << RESET;
                std::cout << "--> ";
                std::cout << ONIRED;
                std::cout << opcion << std::endl;
                std::cout << RESET;
     }
  
    if (opcion !=0)
    {
        PLACE(25,1);
        std::cout << "Pulse ";
        std::cout << BIGREEN;
        std::cout << "ENTER";
        std::cout << RESET;
        std::cout << " para mostrar el ";
        std::cout << INVERSE;
        std::cout << "menú"; 
        std::cout << RESET;

        // Pausa
        std::cin.ignore();

        std::cout << CLEAR_SCREEN;
    }
      }while(opcion!=0);

    return 0;


 //float dist;
   // unsigned int i=1;
    
    
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
    
    //unsigned int i, j;

   //anadirVertices(nombreFichero, graph);

    std::vector<std::vector<float> > matriz;

    


    //graph.addVertex(punto, Vertice1);
    //graph.addVertex(punto2, Vertice2);
    //graph.addVertex(punto3, Vertice3);
    //graph.addVertex(punto4, Vertice4);
    //graph.addVertex(punto5, Vertice5);
    //std::cout<<graph.getVectorVertices().size()<<std::endl;
    
   /*
    dist=ed::calcularDistanciaEuclidea(punto.getX(), punto.getY(), punto2.getX(), punto2.getY());

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
*/
}
