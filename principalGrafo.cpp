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
    std::ofstream png;
    bool value;
    std::vector<std::vector<float> > matriz;
    std::vector<ed::Lado<ed::Punto<float> > > l;
    int control;

    int opcion, opcion2;
    std::string nombreFichero;
    int directed;
    bool direct, val=false;
    char nombreFichero2[10];


    std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
    PLACE(1,1);
    std::cout <<BIGREEN<<"BIENVENIDO AL PROGRAMA PRINCIPAL DEL GRAFO DE CARLOS LUQUE CÓRDOBA";
    PLACE(2,3);

    std::cout <<BIBLUE<<"\nEl grafo es dirigido (1) o no dirigido (2): ";
    std::cin>>directed;
    std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
    if(directed==1 || directed==2){
        switch(directed){
            case 1:
                direct=true;
                break;
            
            case 2:
                direct=false;
                break;
        }
    }else{
        std::cout<<BIRED<<"OPCIÓN "<<directed<<" NO VALIDA!!"<<RESET<<std::endl;
        exit(-1);
    }

    ed::Grafo <ed::Punto<float> > graph(direct);
    ed::Grafo <ed::Punto<float> > graph2(direct);
    ed::Grafo <ed::Punto<float> > graph3(direct);
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
                    PLACE(2,2);
                    std::cout<<BIPURPLE<<"[3] Grabar las matrices de adyacencia en un fichero"<<RESET<<std::endl;
                    std::cout<<BIBLUE<<"Introduce el nombre del fichero para la Matriz de Adyacencias: "<<BIYELLOW;
                    std::cin>>nombreFichero2;
                    std::cout<<RESET<<std::endl;
                    std::cout<<BIYELLOW<<"De que forma quiere exportar la matriz de adyacencias: \n"<<BICYAN<<"con etiquetas (1) "<<BIYELLOW<<"o"<<BICYAN<<" sin etiquetas (2)"<<RESET<<BIBLUE<<std::endl;
                    std::cout<<"Elección: ";
                    std::cin>>control;
                    std::cout<<RESET<<std::endl;
                    if(control==1){
                        graph.crearMatriz(graph.getVectorVertices(), graph.getVectorLado(), graph.getVectorEtiquetas().size()+1);
                        graph.matricesAFichero(nombreFichero2, graph.getVectorVertices(), graph.getMatriz(), graph.getVectorEtiquetas().size()+1);
                        graph.crearMatrizSinLabels(graph.getVectorVertices(), graph.getVectorLado());
                        std::cout<<BIGREEN<<"Se ha creado el fichero de la Matriz de Adyacencias con etiquetas correctamente"<<RESET<<std::endl;
                    }else{
                        graph.crearMatrizSinLabels(graph.getVectorVertices(), graph.getVectorLado());
                        graph.matricesAFicheroAlgoritmos(nombreFichero2, graph.getVectorVertices(), graph.getMatrizWLabels());
                        std::cout<<BIGREEN<<"Se ha creado el fichero de la Matriz de Adyacencias sin etiquetas correctamente"<<RESET<<std::endl;
                    }

                    std::cout<<BIBLUE<<"Introduce el nombre del fichero para imprimir el Algoritmo de Prim: "<<BIYELLOW;
                    std::cin>>nombreFichero2;
                    std::cout<<RESET<<std::endl;
                    graph2.setMatrizWLabels(ed::prim(graph, graph2));
                    graph.matricesAFicheroAlgoritmos(nombreFichero2, graph.getVectorVertices(), graph2.getMatrizWLabels());
                    std::cout<<BIGREEN<<"Se ha creado el fichero del Algoritmo de Prim correctamente"<<RESET<<std::endl;

                    std::cout<<BIBLUE<<"Introduce el nombre del fichero para imprimir el Algoritmo de Kruskal: "<<BIYELLOW;
                    std::cin>>nombreFichero2;
                    std::cout<<RESET<<std::endl;
                    graph2.setMatrizWLabels(ed::kruskal(graph, graph2));
                    graph.matricesAFicheroAlgoritmos(nombreFichero2, graph.getVectorVertices(), graph2.getMatrizWLabels());
                    std::cout<<BIGREEN<<"Se ha creado el fichero del Algoritmo de Kruskal correctamente"<<RESET<<std::endl;
                    std::cin.ignore();
                    break;

            //////////////////////////////////////////////////////////////////////////////
            case 4: 
                    std::cout <<BIPURPLE<< "[4] Mostrar los vertices y lados del Grafo" <<RESET<< std::endl;
                    if(graph.getVectorVertices().size()<2 && graph.getVectorLado().size()<1){
                        std::cout<<BIRED<<"No hay vertices o lados para mostrar"<<RESET<<std::endl;
                        break;
                    }else{
                        if(graph.getVectorVertices().size()>0){
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
                        }
                        if(graph.getVectorLado().size()>0){
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
                            PLACE(2,1);
                            break;
                        }
                    }

            case 5: 
                    std::cout<<BIPURPLE<< "[5] Mostrar la Matriz de Adyacencias: " <<RESET<< std::endl;
                    if(graph.getVectorVertices().size()<2 && graph.getVectorLado().size()<1){
                        std::cout<<BIRED<<"No hay suficientes vertices y lados como para crear una matriz"<<RESET<<std::endl;
                        break;
                    }else{
                        graph.crearMatriz(graph.getVectorVertices(), graph.getVectorLado(), graph.getVectorEtiquetas().size()+1);
                        graph.crearMatrizSinLabels(graph.getVectorVertices(), graph.getVectorLado());
                        graph.imprimirMatriz(graph.getVectorVertices(), graph.getMatriz(), graph.getVectorEtiquetas().size()+1);
                        val=true;
                        break;
                    }


            //////////////////////////////////////////////////////////////////////////////
            case 6: 
                std::cout <<BIPURPLE<<"[6] Algoritmo de Prim"<<RESET<< std::endl;
                if(val==false){
                    std::cout<<BIRED<<"Matriz de Adyacencias no creada aún"<<RESET<<std::endl;
                    break;
                }else{
                    graph2.setMatrizWLabels(ed::prim(graph, graph2));
                    graph.imprimirMatrizSinLabels(graph.getVectorVertices(), graph2.getMatrizWLabels());
                    break;
                }

            case 7: 
                std::cout <<BIPURPLE<< "[7] Algoritmo de Kruskal"<<RESET<< std::endl;
                if(val==false){
                    std::cout<<BIRED<<"Matriz de Adyacencias no creada aún"<<RESET<<std::endl;
                    break;
                }else{
                    graph2.setMatrizWLabels(ed::kruskal(graph, graph2));
                    graph.imprimirMatrizSinLabels(graph.getVectorVertices(), graph2.getMatrizWLabels());
                    break;
                }

            case 8: 
                    std::cout <<BIPURPLE<< "[8] Borrar un Vertice" <<RESET<<std::endl;
                    //graph.removeVertex();
                    break;

            //////////////////////////////////////////////////////////////////////////////
            case 9: 
                    std::cout <<BIPURPLE<< "[9] Borrar todos los vertices y lados" <<RESET<< std::endl;
                    break;

            case 10: 
                    std::cout <<BIPURPLE<< "[10] Insertar una Vertice" <<RESET<< std::endl;
                    break;

            case 11: 
                    std::cout <<BIPURPLE<< "[11] Insertar un Lado" <<RESET<<std::endl;
                    break;
            case 12: 
                    std::cout <<BIPURPLE<< "[12] Generar el Grafo en PNG" <<RESET<<std::endl;
                    std::cout<<BIBLUE<<"Introduce el nombre del fichero acabado en .dot: ";
                    nombreFichero="grafoDirigido.dot";
                    std::cout<<RESET<<std::endl;
                    l=graph.getVectorLado();
                    png.open(nombreFichero.c_str());
                    if(png.is_open()){
                        png<<l;               
                        png.close();
                        value=true;
                    }else
                        value=false;
                    
                    if(value){
                        std::cout<<BIGREEN<<"\nEl fichero .dot ha sido generado con exito, debe ejecutar el comando que se \nadjunta en el fichero comando.txt situado en el directorio"<<RESET<<std::endl;
                    }
                    else{
                        std::cout<<BIRED<<"Error al cargar el fichero"<<RESET<<std::endl;
                        std::cin.ignore();
                    }
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
}
