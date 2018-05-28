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
    float x1, y1, x2, y2, f;
    std::ifstream grap;
    bool value;
    std::vector<std::vector<float> > matriz;

    int opcion, opcion2;
    std::string nombreFichero;
    int directed;
    bool direct;

    std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
    PLACE(1,1);
    std::cout <<BIGREEN<<"BIENVENIDO AL PROGRAMA PRINCIPAL DEL GRAFO DE CARLOS LUQUE CÓRDOBA";
    PLACE(2,3);

    std::cout <<BIBLUE<<"\nEl grafo es dirigido (0) o no dirigido (1): ";
    std::cin>>directed;
    std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
    if(directed==0 || directed==1){
        switch(directed){
            case 0:
                direct=true;
                break;
            
            case 1:
                direct=false;
                break;
        }
    }else{
        std::cout<<BIRED<<"OPCIÓN "<<directed<<" NO VALIDA!!"<<RESET<<std::endl;
        exit(-1);
    }

    ed::Grafo <ed::Punto<float> > graph(direct);
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
                    PLACE(1,1);
                    std::cout <<BIPURPLE<< "[2] Cargar el grafo desde ficheros" <<RESET<< std::endl;
        
                        std::cout <<BIGREEN<< "\nPulse "<<BIYELLOW<<"1"<<BIGREEN<<" para cargar los vertices en el grafo desde el fichero" <<RESET;
                        std::cout <<BIGREEN<< "\nPulse "<<BIYELLOW<<"2"<<BIGREEN<<" para cargar los lados en el grafo desde el fichero" <<RESET;
                        std::cout <<BIGREEN<< "\nPulse "<<BIYELLOW<<"3"<<BIGREEN<<" para cargar los vertices y los lados en el grafo desde el fichero" <<RESET;
                        std::cout <<BIBLUE<<"\n\nIntroduce la opción deseada: "<<BIYELLOW;
                        std::cin>>opcion2;
                        if(opcion2>0 && opcion<4){
                            std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
                            switch(opcion2){
                                case 1:
                                    PLACE(2,2);
                                    std::cout <<BIRED<<"ATENCION!!! NO INTRODUZCA LADOS" <<RESET<< std::endl;
                                    std::cout<<BIBLUE<<"Introduce el nombre del fichero: ";
                                    std::cin>>nombreFichero;
                                    std::cout<<RESET<<std::endl;
                                    std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
                                    PLACE(1,1);
                                    grap.open(nombreFichero.c_str());
                                    if(grap.is_open()){
                                        while(!grap.eof()){
                                            grap>>x1>>y1;
                                            ed::Punto<float> punto(x1, y1);
                                            if(!grap.eof()){
                                                graph.addVertex(punto);
                                            }
                                        }
                                    grap.close();
                                    value=true;
                                    }else
                                        value=false;
                                    
                                    if(value){
                                        std::cout<<BIGREEN<<"\nEl fichero ha sido cargado con exito"<<RESET<<std::endl;
                                        std::cin.ignore();
                                    }
                                    else{
                                        std::cout<<BIRED<<"Error al cargar el fichero"<<RESET<<std::endl;
                                        std::cin.ignore();
                                    }
                                    break;
                                
                                case 2:
                                    PLACE(2,2);
                                    if(graph.getVectorVertices().size()==0){
                                        std::cout<<ONIRED<<BIYELLOW<<"El Grafo no tiene vertices, introduzca primero dos vertices como mínimo"<<RESET<<std::endl;
                                        std::cin.ignore();
                                    }
                                    else{
                                        std::cout <<BIRED<<"ATENCION!!! NO INTRODUZCA VERTICES" <<RESET<< std::endl;
                                        std::cout<<BIBLUE<<"Introduce el nombre del fichero: ";
                                        std::cin>>nombreFichero;
                                        std::cout<<RESET<<std::endl;
                                        std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
                                        PLACE(1,1);
                                        grap.open(nombreFichero.c_str());
                                        if(grap.is_open()){
                                            while(!grap.eof()){
                                                grap>>x1>>y1>>x2>>y2;
                                                ed::Punto<float> punto1(x1, y1);
                                                ed::Punto<float> punto2(x2, y2);
                                                f=ed::calcularDistanciaEuclidea(punto1.getX(), punto1.getY(), punto2.getX(), punto2.getY());
                                                ed::Vertice<ed::Punto<float> > v1(punto1, -1);
                                               ed::Vertice<ed::Punto<float> > v2(punto2, -1);
                                               ed::Lado<ed::Punto<float> >Lado(f);

                                                if(graph.devolverEtiqueta(v1)!=0 && graph.devolverEtiqueta(v2)!=0){
                                                    if(!grap.eof()){
                                                        graph.addEdge(graph.devolverEtiqueta(v1), graph.devolverEtiqueta(v2), Lado,  f);
                                                    }
                                                }
                                            }
                                        grap.close();
                                        value=true;
                                        }else
                                            value=false;
                                        
                                        if(value){
                                            std::cout<<BIGREEN<<"\nEl fichero ha sido cargado con exito"<<RESET<<std::endl;
                                            std::cin.ignore();
                                        }
                                        else{
                                            std::cout<<BIRED<<"Error al cargar el fichero"<<RESET<<std::endl;
                                            std::cin.ignore();
                                        }
                                    }
                                    break;
                                
                                case 3:

                                    break;
                            }
                        }else{
                            std::cout<<BIRED<<"OPCIÓN "<<directed<<" NO VALIDA!!"<<RESET<<std::endl;
                            std::cin.ignore();
                            break;
                        }
                    break;

            case 3: 
                    
                    break;

            //////////////////////////////////////////////////////////////////////////////
            case 4: 
                    std::cout <<BIPURPLE<< "[4] Mostrar los vertices y lados del Grafo" <<RESET<< std::endl;
                    std::cout <<BIYELLOW<< "Estos son los vertices del Grafo" <<RESET<< std::endl;
                    graph.imprimirVertices();
                    PLACE(25,1);
                    std::cout << "Pulse ";
                    std::cout << BIGREEN;
                    std::cout << "ENTER";
                    std::cout << RESET;
                    std::cout << " para mostrar la siguiente ";
                    std::cout << INVERSE;
                    std::cout << "los lados"; 
                    std::cout << RESET;

                    // Pausa
                    std::cin.ignore();
                    PLACE(2,1);
                    std::cout << CLEAR_SCREEN;
                    std::cout <<BIYELLOW<< "Estos son los lados del Grafo" <<RESET<< std::endl;
                    graph.imprimirLados();
                    PLACE(25,1);
                    std::cout << "Pulse ";
                    std::cout << BIGREEN;
                    std::cout << "ENTER";
                    std::cout << RESET;
                    std::cout << " para mostrar la siguiente ";
                    std::cout << INVERSE;
                    std::cout << "el menú"; 
                    std::cout << RESET;

                    // Pausa
                    std::cin.ignore();
                    PLACE(2,1);
                    std::cout << CLEAR_SCREEN;
                    break;

            case 5: 
                    std::cout<<BIPURPLE<< "[5] Mostrar la Matriz de Adyacencias: " <<RESET<< std::endl;
                    graph.setMatriz(graph.crearMatriz(graph.getVectorVertices(), graph.getVectorLado(), graph.getVectorEtiquetas().size()+1));
                    graph.imprimirMatriz(graph.getVectorVertices(), graph.getMatriz(), graph.getVectorEtiquetas().size()+1);
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

   
    matriz=graph.prim();

    graph.imprimirMatrizSinLabels(graph.getVectorVertices(), matriz);

    matriz=graph.kruskal();

    graph.imprimirMatrizSinLabels(graph.getVectorVertices(), matriz);
*/
}
