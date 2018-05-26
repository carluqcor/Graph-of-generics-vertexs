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
/*
int ed::anadirVertices(std::string const & nombreFichero, ed::Grafo <ed::Punto<float> > graph){
	int j=0;
	std::ifstream grap;
	bool value;
	ed::Punto<float> punto;
	ed::Vertice<ed::Punto<float> > vertice(-1);
	grap.open(nombreFichero.c_str());
	std::string f;
	if(grap.is_open()){
		while(!grap.eof()){
	 		grap>>punto;
	  		if(!grap.eof()){
				graph.addVertex(punto,vertice);
				j++;
	  		}
		}
 	grap.close();
 	value=true;
 	}else
 		value=false;
 
 	if(value){
		std::cout<<BIGREEN<<"El fichero ha sido cargado con exito"<<RESET<<std::endl;
		return j;
 	}
	else{
		std::cout<<BIRED<<"Error al cargar el fichero"<<RESET<<std::endl;
		return 0;
	}
}
*/