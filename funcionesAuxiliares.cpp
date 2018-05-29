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

	PLACE(posicion++,13);
	std::cout <<BICYAN<< "[1] Comprobar si el Grafo tiene vertices"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,13);
	std::cout <<BIYELLOW<< "[2] Cargar el Grafo desde un fichero"<<RESET;

	PLACE(posicion++,13);
	std::cout <<BIYELLOW<< "[3] Grabar las matrices de adyacencia en un fichero"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,13);
	std::cout <<BIGREEN<< "[4] Mostrar los vertices y lados del Grafo"<<RESET;

	PLACE(posicion++,13);
	std::cout <<BIGREEN<<"[5] Crear y mostrar la Matriz de Adyacencias"<<RESET;

	PLACE(posicion++,13);
	std::cout <<BIGREEN<<"[6] Algoritmo de Prim"<<RESET;

	PLACE(posicion++,13);
	std::cout <<BIGREEN<<"[7] Algoritmo de Kruskal"<<RESET;

	PLACE(posicion++,13);
	std::cout <<BIGREEN<<"[8] Borrar un Vertice"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,13);
	std::cout <<BIBLUE<< "[9] Borrar todos los vertices y lados"<<RESET;

	PLACE(posicion++,13);
	std::cout <<BIBLUE<<"[10] Insertar una Vertice"<<RESET;

	PLACE(posicion++,13);
	std::cout <<BIBLUE<< "[11] Insertar un Lado"<<RESET;

	PLACE(posicion++,13);
	std::cout <<BIBLUE<< "[12] Generar el Grafo en PNG"<<RESET;
	
	PLACE(posicion++,13);
	std::cout <<BIBLUE<< "[13] Generar el PNG de Prim y Kruskal"<<RESET;

	
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

std::vector<std::vector<float> > ed::prim(ed::Grafo <ed::Punto<float> > &graph, ed::Grafo <ed::Punto<float> > &graph2){
	// uso una copia de ady porque necesito eliminar columnas
	unsigned int nVertices=graph.getVectorVertices().size();
	std::vector< std::vector<float> > adyacencia = graph.getMatrizWLabels();
	std::vector< std::vector<float> > arbol(nVertices);
	std::vector<float> markedLines;
	std::vector<float> _padre;
	std::vector<float> _hijo;
	std::vector<float> coste;
	std::vector<float> :: iterator itVec;
	float minMax=0;

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
	    minMax+=min;
	    _padre.push_back(padre+1);
	    _hijo.push_back(hijo+1);
	    coste.push_back(min);
	}
	std::cout<<BIGREEN<<"El arbol abarcador de coste mínimo generado por el algitmo es: "<<RESET<<std::endl;
	graph.setPadre(_padre);
	graph.setHijo(_hijo);
	graph.setCoste(coste);
	graph.setMax(minMax);
	return arbol;
}

// Devuelve la matriz de adyacencia del árbol mínimo.
std::vector<std::vector<float> > ed::kruskal(ed::Grafo <ed::Punto<float> > &graph, ed::Grafo <ed::Punto<float> > &graph2){
    std::vector< std::vector<float> > adyacencia = graph.getMatrizWLabels();
    int nVertices=graph.getVectorVertices().size();
    std::vector<float> _padre;
	std::vector<float> _hijo;
	std::vector<float> coste;
    std::vector< std::vector<float> > arbol(nVertices);
    std::vector<float> visitado(nVertices); // Indica el que nodo ha sido visitado
    float minMax=0;

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
            _padre.push_back(Vertice1);
		    _hijo.push_back(Vertice2);
		    coste.push_back(min);
		    minMax+=min;
            // Todos los nodos del árbol del Vertice2 ahora visitadon al árbol del Vertice1.
        	float temp = visitado[Vertice2];
        	visitado[Vertice2] = visitado[Vertice1];
        	for(int k = 0; k < nVertices; k++)
        		if(visitado[k] == temp)
        			visitado[k] = visitado[Vertice1];
            arcos++;
        }
    }
   	std::cout<<BIGREEN<<"El arbol abarcador de coste mínimo generado por el algitmo es: "<<RESET<<std::endl;
	graph.setPadre(_padre);
	graph.setHijo(_hijo);
	graph.setCoste(coste);
	graph.setMax(minMax);
    return arbol;
}

void ed::cargarFichero(ed::Grafo <ed::Punto<float> > &graph){
float x1, y1, x2, y2, f;
bool value;
int opcion2=0;
std::ifstream grap;
std::string nombreFichero;
int directed=graph.getDirected();
std::cout <<BIGREEN<< "\nPulse "<<BIYELLOW<<"1"<<BIGREEN<<" para cargar los vertices en el grafo desde el fichero" <<RESET;
std::cout <<BIGREEN<< "\nPulse "<<BIYELLOW<<"2"<<BIGREEN<<" para cargar los lados en el grafo desde el fichero" <<RESET;
std::cout <<BIGREEN<< "\nPulse "<<BIYELLOW<<"3"<<BIGREEN<<" para cargar los vertices y los lados en el grafo desde el fichero" <<RESET;
std::cout <<BIBLUE<<"\n\nIntroduce la opción deseada: "<<BIYELLOW;
std::cin>>opcion2;
    if(opcion2>0 && opcion2<4){
        std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
        switch(opcion2){
            case 1:
                PLACE(1,1);
                std::cout<<BIPURPLE<<"[2] Cargar el Grafo de vertices desde un fichero"<<RESET<<std::endl;
                PLACE(2,2);
                std::cout <<BIRED<<"ATENCION!!! NO INTRODUZCA LADOS" <<RESET<< std::endl;
                std::cout<<BIBLUE<<"Introduce el nombre del fichero de vertices: "<<BIYELLOW;
                std::cin>>nombreFichero;
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
                    std::cout<<BIGREEN<<"\nEl fichero de vertices ha sido cargado con exito"<<RESET<<std::endl;
                    std::cin.ignore();
                }
                else{
                    std::cout<<BIRED<<"Error al cargar el fichero de vertices"<<RESET<<std::endl;
                    std::cin.ignore();
                }
                break;
            
            case 2:
				PLACE(1,1);
                std::cout<<BIPURPLE<<"[2] Cargar el Grafo de lados desde un fichero"<<RESET<<std::endl;
                PLACE(2,2);
                if(graph.getVectorVertices().size()==0){
                    std::cout<<ONIRED<<BIYELLOW<<"El Grafo no tiene vertices, introduzca primero dos vertices como mínimo"<<RESET<<std::endl;
                    std::cin.ignore();
                }
                else{
                    std::cout <<BIRED<<"ATENCION!!! NO INTRODUZCA VERTICES" <<RESET<< std::endl;
                    std::cout<<BIBLUE<<"Introduce el nombre del fichero de lados: "<<BIYELLOW;
                    std::cin>>nombreFichero;
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
                        std::cout<<BIGREEN<<"\nEl fichero de lados ha sido cargado con exito"<<RESET<<std::endl;
                        std::cin.ignore();
                    }
                    else{
                        std::cout<<BIRED<<"Error al cargar el fichero de lados"<<RESET<<std::endl;
                        std::cin.ignore();
                    }
                }
                break;
            
            case 3:
            	PLACE(1,1);
                std::cout<<BIPURPLE<<"[2] Cargar el Grafo de vertices y lados desde ficheros"<<RESET<<std::endl;
                PLACE(2,2);
                std::cout <<BIRED<<"PRIMERO DEBE INTRODUCIR LOS VERTICES PARA PODER INTRODUCIR LOS LADOS" <<RESET<< std::endl;
                std::cout<<BIBLUE<<"Introduce el nombre del fichero de vertices: "<<BIYELLOW;
                std::cin>>nombreFichero;
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
                    std::cout<<BIGREEN<<"\nEl fichero de vertices ha sido cargado con exito"<<RESET<<std::endl;
                    std::cin.ignore();
                }
                else{
                    std::cout<<BIRED<<"Error al cargar el fichero de vertices"<<RESET<<std::endl;
                    std::cin.ignore();
                }
                PLACE(25,1);
                std::cout << "Pulse ";
                std::cout << BIGREEN;
                std::cout << "ENTER";
                std::cout << RESET;
                std::cout << " para introducir los ";
                std::cout << INVERSE;
                std::cout << "lados"; 
                std::cout << RESET;

                // Pausa
                std::cin.ignore();
                std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
                
                value=false;

                if(graph.getVectorVertices().size()==0){
                	PLACE(1,1);
                    std::cout<<ONIRED<<BIYELLOW<<"El Grafo no tiene vertices, introduzca primero dos vertices como mínimo"<<RESET<<std::endl;
                    PLACE(25,1);
                    std::cout << "Pulse ";
                    std::cout << BIGREEN;
                    std::cout << "ENTER";
                    std::cout << RESET;
                    std::cout << " para mostrar el ";
                    std::cout << INVERSE;
                    std::cout << "menú"; 
                    std::cout << RESET;
                }
                else{
                    PLACE(1,1);
                   	std::cout<<BIPURPLE<<"[3] Grabar las matrices de adyacencia en un fichero"<<RESET<<std::endl;
                    std::cout<<BIBLUE<<"Introduce el nombre del fichero de lados: "<<BIYELLOW;
                    std::cin>>nombreFichero;
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
                        std::cout<<BIGREEN<<"\nEl fichero lados ha sido cargado con exito"<<RESET<<std::endl;
                        std::cin.ignore();
                    }
                    else{
                        std::cout<<BIRED<<"Error al cargar el fichero de lados"<<RESET<<std::endl;
                        std::cin.ignore();
                    }
                    PLACE(25,1);
                    std::cout << "Pulse ";
                    std::cout << BIGREEN;
                    std::cout << "ENTER";
                    std::cout << RESET;
                    std::cout << " para mostrar el ";
                    std::cout << INVERSE;
                    std::cout << "menú"; 
                    std::cout << RESET;
                }
            break;
        }
    }else{
        std::cout<<BIRED<<"OPCIÓN "<<directed<<" NO VALIDA!!"<<RESET<<std::endl;
        std::cin.ignore();
    }
}

bool ed::grabarFichero(ed::Grafo <ed::Punto<float> > &graph){
	int control;
	char nombreFichero2[10];
	bool val=false;
	ed::Grafo <ed::Punto<float> > graph2(graph.getDirected());
	PLACE(2,2);
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
        val=true;
    }else{
        graph.crearMatrizSinLabels(graph.getVectorVertices(), graph.getVectorLado());
        graph.matricesAFicheroAlgoritmos(nombreFichero2, graph.getVectorVertices(), graph.getMatrizWLabels());
        std::cout<<BIGREEN<<"Se ha creado el fichero de la Matriz de Adyacencias sin etiquetas correctamente"<<RESET<<std::endl;
        val=true;
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
    return val;
}

void ed::generarPNGPrim(char *nombreFichero2, std::vector<float> padre, std::vector<float> hijo, std::vector<float> coste){
	FILE *f;
	std::cout<<BIBLUE<<"Introduce"<<BIYELLOW<<" Prim.dot "<<BIBLUE<<"para generar el PNG de Prim: "<<BIYELLOW;
	cin>>nombreFichero2;
    std::cout<<RESET<<std::endl;

		f=fopen(nombreFichero2, "w" );
		fprintf(f, "graph A {\n");
    for(unsigned int i=0;i<padre.size();i++){
		fprintf(f, "%.2f -- %.2f [label=\"%.4f\"];\n", padre[i], hijo[i], coste[i]);
	}
	fprintf(f, "}");
	fclose(f);
}

void ed::generarPNGKruskal(char *nombreFichero2, std::vector<float> padre, std::vector<float> hijo, std::vector<float> coste){
	FILE *f;
	std::cout<<BIBLUE<<"Introduce"<<BIYELLOW<<" Kruskal.dot "<<BIBLUE<<"para generar el PNG de Kruskal: "<<BIYELLOW;
	cin>>nombreFichero2;
    std::cout<<RESET<<std::endl;

		f=fopen(nombreFichero2, "w" );
		fprintf(f, "graph A {\n");
    for(unsigned int i=0;i<padre.size();i++){
		fprintf(f, "%.2f -- %.2f [label=\"%.4f\"];\n", padre[i], hijo[i], coste[i]);
	}
	fprintf(f, "}");
	fclose(f);
}