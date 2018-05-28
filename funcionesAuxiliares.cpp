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
