// Fichero: Punto.cpp

// Ficheros de cabecera
#include <iostream>
#include <cmath>

#include "Punto.hpp"

// Espacios de nombres utilizados
using namespace std;

/*
 Definiciones de las funciones lectura y escritura de la clase Punto

*/

template < class T >  
void ed::Punto< T >::escribirPunto()
{
  cout << "(" << getX() << ", " << getY() << ")" << endl; 
}


template < class T >  
void ed::Punto< T >::leerPunto()
{
  T x, y;

  cout << "\n Lectura de las coordenadas de un punto: P(x,y) " << endl;

  cout << " Abscisa: x --> ";
  cin >> x;

  cout << " Ordenada: y --> ";
  cin >> y;

  // Se asignan los valores leídos a los atributos del punto   
  setX(x);
  setY(y);
}


