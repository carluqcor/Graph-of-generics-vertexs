/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 4
  \author Carlos Luque Córdoba
  \date   29/05/2018
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
	std::cout <<BIBLUE<<"[10] Insertar un Vertice"<<RESET;

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
	unsigned int nVertices=graph.getVectorVertices().size(); //Numero de vertices del grafo
	std::vector< std::vector<float> > adyacencia = graph.getMatrizWLabels(); //Se hace una copia de la matriz de adyacencias de la clase grafo para poder borrar lados
	std::vector< std::vector<float> > arbolAbarcador(nVertices); //Matriz del arbol abarcador
	std::vector<float> visitados; //Vector de visitados
	std::vector<float> _padre; //Vector flotantes de FROM (visitados)
	std::vector<float> _hijo; //Vector flotantes de TO (siguiente)
	std::vector<float> coste; //Vector flotantes de coste de los lados
	std::vector<float> :: iterator itVec; //Iterador de flotantes para conseguir el minimo, anterior y el siguiente lado a visitar
	float minMax=0; //Flotante para recoger la suma del camino mínimo del arbol abarcador

	// Se inicializan todos los lados del arbol a 0
	for(unsigned int i = 0; i < nVertices; i++)
	    arbolAbarcador[i] = std::vector<float> (nVertices, 0); 

	float from = 0; //Visitados
	float to = 0; //Siguiente a visitar

	while(visitados.size() + 1 < nVertices){ //Mientras que la cantidad de los superados +1 porque se cuenta el 0 no sea => que el número de vertices
	    from = to; //Se le asignará a from el siguiente coste mínimo que puede visitar
	    // Marco la fila y elimino la columna del nodo from.
	    visitados.push_back(from); //Y se añade al vector de visitados
	    for(unsigned int i = 0; i < nVertices; i++)
	        adyacencia[i][from] = 9999; //Se marcan los lados con 9999 suponiendo que es el infinito

	    // Encuentro la menor distancia entre las filas marcadas.
	    // El nodo from es la linea marcada y el nodo to es la columna del minimo.
	    float min = 9999;
	    for(itVec = visitados.begin(); itVec != visitados.end(); itVec++)
	        for(unsigned int i = 0; i < nVertices; i++)
	            if(min > adyacencia[*itVec][i]){ //Si el minimo de coste es mayor que la posicion de la matriz del visitado y lo que valga i en ese momento
	                min = adyacencia[*itVec][i]; //Se cogera lo que valga la matriz de adyacencia en ese momento porque és menor que min
	                from = *itVec; //Se guarda en from el lado visitado
	                to = i; //se guarda en from el siguiente lado a visitar
	            }

	    arbolAbarcador[from][to] = min; //En la posicion del visitado y el siguiente por visitar de la matriz (EL LADO QUE UNE LOS DOS VERTICES) se guarda el valor mínimo del lado posible
	    arbolAbarcador[to][from] = min; //Lo mismo para crear una matriz símétrica
	    minMax+=min;   //Se guarda el valor del lado visitado
	    _padre.push_back(from+1); //Se guarda el valor del visitado
	    _hijo.push_back(to+1); //Se guarda el valor del siguiente a visitar
	    coste.push_back(min); //Se guarda el valor del coste del lado
	}
	graph.setPadre(_padre); //Ajusta el vector de FROM de la clase grafo
	graph.setHijo(_hijo); //Ajusta el vector de TO de la clase grafo
	graph.setCoste(coste); //Ajusta el vector de costes de lados de la clase grafo
	graph.setMax(minMax); //Ajusta el atributo flotante de la clase grafo
	return arbolAbarcador;
}

std::vector<std::vector<float> > ed::kruskal(ed::Grafo <ed::Punto<float> > &graph, ed::Grafo <ed::Punto<float> > &graph2){
    std::vector< std::vector<float> > adyacencia = graph.getMatrizWLabels(); //Se hace una copia de la matriz de adyacencias de la clase grafo para poder borrar lados
    int nVertices=graph.getVectorVertices().size(); //Número de vertices del grafo
    std::vector<float> _padre; //Vector flotantes de FROM (visitados)
    std::vector<float> _hijo; //Vector flotantes de TO (no visitados)
    std::vector<float> coste; //Vector flotantes de coste de los lados
    std::vector< std::vector<float> > arbolAbarcador(nVertices); //Matriz del arbol abarcador
    std::vector<float> visitado(nVertices); // Indica el que nodo ha sido visitado
    float minMax=0;  //Flotante para recoger la suma del camino mínimo del arbol abarcador

    for(int i = 0; i < nVertices; i++){
        arbolAbarcador[i] =std::vector<float> (nVertices, 0); //Se inicializan los lados a 0
        visitado[i] = i;
    }

    float Vertice1=0; //Atributo FROM (visitado)
    float Vertice2=0; //Atributo TO (siguiente)
    float ciclos = 1; // Atributo para evitar escoger lados que produzcan ciclos
    while(ciclos < nVertices){
        //Con este while buscamos un lado que no produzca ciclos
        float min = 9999; //Atributo de comparación
        for(int i = 0; i < nVertices; i++)
            for(int j = 0; j < nVertices; j++)
                if(min > adyacencia[i][j] && adyacencia[i][j]!=0 && visitado[i] != visitado[j]){ //Si min es mayor que lo que valga la matriz de adyacencias en esa posición y la matriz de adyacencias en esa 
                                                                                                 //posición sea 0 y que el visitado en la posicion i no sea igual al que se ha visitado en la posición j
                    min = adyacencia[i][j]; //Se cogera lo que valga la matriz de adyacencia en esa posición porque és menor que el valor de min
                    Vertice1 = i; //From será i
                    Vertice2 = j; //To será j
                }
            //"Sort de lados de coste mínimo"
        if(visitado[Vertice1] != visitado[Vertice2]){ //Si el visitado en la posicion from no es igual al visitado en la posicion to
            arbolAbarcador[Vertice1][Vertice2] = min; //En la posicion del visitado y el siguiente por visitar de la matriz (EL LADO QUE UNE LOS DOS VERTICES) se guarda el valor mínimo del lado posible
            arbolAbarcador[Vertice2][Vertice1] = min; //Para generar la matriz simétrica
            _padre.push_back(Vertice1); //Ajusta el vector de FROM de la clase grafo
		    _hijo.push_back(Vertice2); //Ajusta el vector de TO de la clase grafo
		    coste.push_back(min); //Ajusta el vector de costes de lados de la clase grafo
		    minMax+=min; //Suma del camino mínimo del arbol abarcador
           
            //Los lados TO (siguiente a visitar) visitan el subarbol de FROM (visitados)
        	float temp = visitado[Vertice2];
        	visitado[Vertice2] = visitado[Vertice1];
        	for(int k = 0; k < nVertices; k++)
        		if(visitado[k] == temp)
        			visitado[k] = visitado[Vertice1];
            ciclos++; //Contador para controlar los ciclos
        }
    }
    graph.setPadre(_padre); //Ajusta el vector de FROM de la clase grafo
    graph.setHijo(_hijo); //Ajusta el vector de TO de la clase grafo
    graph.setCoste(coste); //Ajusta el vector de costes de lados de la clase grafo
    graph.setMax(minMax); //Ajusta el atributo flotante de la clase grafo
    return arbolAbarcador;
}

void ed::cargarFichero(ed::Grafo <ed::Punto<float> > &graph, bool direct){
float x1, y1, x2, y2, f;
bool value;
int opcion2=0;
std::ifstream grap;
std::string nombreFichero;
int directed=graph.getDirected();
std::cout <<BIGREEN<< "\nPulse "<<BIYELLOW<<"[1]"<<BIGREEN<<" para cargar los vertices en el grafo desde el fichero" <<RESET;
std::cout <<BIGREEN<< "\nPulse "<<BIYELLOW<<"[2]"<<BIGREEN<<" para cargar los lados en el grafo desde el fichero" <<RESET;
std::cout <<BIGREEN<< "\nPulse "<<BIYELLOW<<"[3]"<<BIGREEN<<" para cargar los vertices y los lados en el grafo desde el fichero" <<RESET;
std::cout << BIRED << "\nPulse "<<BIYELLOW<<"[0]"<<BIRED<<" Volver al menú "<<RESET;
std::cout <<BIBLUE<<"\n\nIntroduce la opción deseada: "<<BIYELLOW;
std::cin>>opcion2;
std::cout<<RESET;
    if(opcion2!=0){
        if(opcion2>0 && opcion2<4){
            std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
            switch(opcion2){
                case 1: //Solo se cargan vertices
                    PLACE(1,1);
                    std::cout<<BIPURPLE<<"[2] Cargar el Grafo de vertices desde un fichero"<<RESET<<std::endl;
                    PLACE(2,1);
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
                        graph.imprimirVertices();
                        std::cout<<BIGREEN<<"\nEl fichero de vertices ha sido cargado con exito"<<RESET<<std::endl;
                        std::cin.ignore();
                    }
                    else{
                        std::cout<<BIRED<<"Error al cargar el fichero de vertices"<<RESET<<std::endl;
                        std::cin.ignore();
                    }
                    break;
                
                case 2: //Solo se cargan lados
    				PLACE(1,1);
                    std::cout<<BIPURPLE<<"[2] Cargar el Grafo de lados desde un fichero"<<RESET<<std::endl;
                    PLACE(2,1);
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
                                    if(graph.getDirected()==true)
                                        graph.addEdge(graph.devolverEtiqueta(v1), graph.devolverEtiqueta(v2), Lado,  f);
                                    else{
                                        graph.addEdge(graph.devolverEtiqueta(v1), graph.devolverEtiqueta(v2), Lado,  f);
                                        graph.addEdge(graph.devolverEtiqueta(v2), graph.devolverEtiqueta(v1), Lado,  f);
                                    }
                                }
                            }
                        grap.close();
                        value=true;
                        }else
                            value=false;
                        
                        if(value){
                            graph.imprimirLados();
                            std::cout<<BIGREEN<<"\nEl fichero de lados ha sido cargado con exito"<<RESET<<std::endl;
                            std::cin.ignore();
                        }
                        else{
                            std::cout<<BIRED<<"Error al cargar el fichero de lados"<<RESET<<std::endl;
                            std::cin.ignore();
                        }
                    }
                    break;
                
                case 3: //Se cargan vertices y lados
                	PLACE(1,1);
                    std::cout<<BIPURPLE<<"[2] Cargar el Grafo de vertices y lados desde ficheros"<<RESET<<std::endl;
                    PLACE(2,1);
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
                        graph.imprimirVertices();
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
                        PLACE(2,1);
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
                       	std::cout<<BIPURPLE<<"[2] Cargar el Grafo de vertices y lados desde fichero"<<RESET<<std::endl;
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
                                    if(graph.getDirected()==true)
                                        graph.addEdge(graph.devolverEtiqueta(v1), graph.devolverEtiqueta(v2), Lado,  f);
                                    else{
                                        graph.addEdge(graph.devolverEtiqueta(v1), graph.devolverEtiqueta(v2), Lado,  f);
                                        graph.addEdge(graph.devolverEtiqueta(v2), graph.devolverEtiqueta(v1), Lado,  f);
                                    }
                                }
                            }
                        grap.close();
                        value=true;
                        }else
                            value=false;
                        
                        if(value){
                            graph.imprimirLados();
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
    }else
        return;
}

bool ed::grabarFichero(ed::Grafo <ed::Punto<float> > &graph, bool p, bool k){
	int control;
	char nombreFichero2[10];
	bool val=false;
	ed::Grafo <ed::Punto<float> > graph2(graph.getDirected());
	PLACE(2,1);
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
    if(p==true){
        std::cout<<BIBLUE<<"Introduce el nombre del fichero para imprimir el Algoritmo de Prim: "<<BIYELLOW;
        std::cin>>nombreFichero2;
        std::cout<<RESET<<std::endl;
        graph2.setMatrizWLabels(ed::prim(graph, graph2));
        graph.matricesAFicheroAlgoritmos(nombreFichero2, graph.getVectorVertices(), graph2.getMatrizWLabels());
        std::cout<<BIGREEN<<"Se ha creado el fichero del Algoritmo de Prim correctamente"<<RESET<<std::endl;
    }else{
        std::cout<<BIRED<<"No se puede guardar el arbol abarcador de prim porque el grafo no es conexo"<<RESET<<std::endl;
        std::cin.ignore();
    }

    if(p==true){
        std::cout<<BIBLUE<<"Introduce el nombre del fichero para imprimir el Algoritmo de Kruskal: "<<BIYELLOW;
        std::cin>>nombreFichero2;
        std::cout<<RESET<<std::endl;
        graph2.setMatrizWLabels(ed::kruskal(graph, graph2));
        graph.matricesAFicheroAlgoritmos(nombreFichero2, graph.getVectorVertices(), graph2.getMatrizWLabels());
        std::cout<<BIGREEN<<"Se ha creado el fichero del Algoritmo de Kruskal correctamente"<<RESET<<std::endl;
        std::cin.ignore();
    }else{
        std::cout<<BIRED<<"No se puede guardar el arbol abarcador de kruskal porque el grafo no es conexo"<<RESET<<std::endl;
        std::cin.ignore();
    }
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
		fprintf(f, "%.2f -- %.2f [label=\"%.4f\"];\n", padre[i]+1, hijo[i]+1, coste[i]+1); //Herramienta dot de graphviz
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
		fprintf(f, "%.2f -- %.2f [label=\"%.4f\"];\n", padre[i]+1, hijo[i]+1, coste[i]+1); //Herramienta dot de graphviz
	}
	fprintf(f, "}");
	fclose(f);
}

bool ed::principio(){
    int directed;
    bool direct=false;
    PLACE(1,1);
    std::cout <<BIGREEN<<"BIENVENIDO AL PROGRAMA PRINCIPAL DEL GRAFO DE CARLOS LUQUE CÓRDOBA";
    PLACE(2,3);

    std::cout <<BICYAN<< "\nPulse "<<BIYELLOW<<"[1]"<<BICYAN<<" para activar el grafo Dirigido"<<RESET;
    std::cout <<BICYAN<< "\nPulse "<<BIYELLOW<<"[2]"<<BICYAN<<" para activar el grafo No Dirigido"<<RESET;
    std::cout << BIRED << "\nPulse "<<BIYELLOW<<"[0]"<<BIRED<<" cerrar el programa "<<RESET;

    std::cout <<BIBLUE<<"\n\nIntroduce la opción deseada: "<<BIYELLOW;
    std::cin>>directed;
    std::cout<<RESET<<CLEAR_SCREEN<<std::endl;
    if(directed!=0){
        if(directed==1 || directed==2){
            switch(directed){
                case 1:
                    direct=true;
                    break;
                
                case 2:
                    direct=false;
                    break;
            }
             return direct;
        }else{
            std::cout<<BIRED<<"OPCIÓN "<<directed<<" NO VALIDA!!"<<RESET<<std::endl;
            exit(-1);
        }
    }else{
        PLACE(1,1);
        std::cout<<BIRED"Saliendo... gracias por usar mi programa"<<RESET<<std::endl;
        exit(-1);      
    }
}

void ed::borrarVerticeLados(ed::Grafo <ed::Punto<float> > &graph){
    ed::Punto<float> punto(0, 0);
    punto.leerPunto();
    ed::Punto<float> punto2(punto);
    ed::Vertice<ed::Punto<float> >v(punto, -1);
    ed::Vertice<ed::Punto<float> >v2(punto, -1);
    v2.setLabel(graph.devolverEtiqueta(v));
    graph.removeVertexEdges(v2);
}

void ed::leerVertice(ed::Grafo <ed::Punto<float> > &graph){
    bool val;
    ed::Punto<float> punto(0, 0);
    punto.leerPunto();
    val=graph.addVertex(punto);
    if(val){
        graph.getVectorVertices()[graph.getVectorVertices().size()-1].imprimirVertice();
        std::cin.ignore();
    }else
        return;
}

void ed::leerLado(ed::Grafo <ed::Punto<float> > &graph){
    int u, v;
    bool val;
    float coste=0;
    ed::Lado<Punto<float> >lado(0);
    std::cout<<BIWHITE<<"Vertices Disponibles"<<RESET<<std::endl;
    for(unsigned int i=1;i<graph.getVectorVertices().size()+1;i++){
        std::cout<<BIYELLOW<<i<<" ";
    }
    std::cout<<BIBLUE<<"\nIntroduzca el primer Vertice del lado"<<RESET<<BIYELLOW<<std::endl;
    cin>>u;
    std::cout<<RESET;
    std::cout<<BIBLUE<<"Introduzca el segundo Vertice del lado"<<RESET<<BIYELLOW<<std::endl;
    cin>>v;
    std::cout<<RESET;
    if(graph.devolverBoolEtiqueta(u) && graph.devolverBoolEtiqueta(v)){
        coste=ed::calcularDistanciaEuclidea(graph.devolverPunto(u).getX(), graph.devolverPunto(u).getY(), graph.devolverPunto(v).getX(), graph.devolverPunto(v).getY());
        val=graph.addEdge(u,v,lado,coste); 
        if(val){
            graph.getVectorLado()[graph.getVectorLado().size()-1].imprimirLado();
            std::cin.ignore();
        }else
            return;
    }
}
