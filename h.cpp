//**** Comienza Archivo grafo.h *****//
#include <vector>

using namespace std;
class Grafo
{
public:
    Grafo();
    Grafo(int nodos);
    vector< vector<int> > prim();
private:
    const int INF = numeric_limits<int>::max();
    int cn; //cantidad de nodos
    vector< vector<int> > ady; //matriz de adyacencia
};
//**** Finaliza Archivo grafo.h *****//


//**** Comienza Archivo grafo.cpp *****//
Grafo::Grafo()
{
}

Grafo::Grafo(int nodos)
{
    this->cn = nodos;
        this->ady = vector< vector<int> > (cn);

        for(int i = 0; i < cn; i++)
            ady[i] = vector<int> (cn, INF);
}

vector< vector<int> > Grafo :: prim(){
    // uso una copia de ady porque necesito eliminar columnas
    vector< vector<int> > adyacencia = this->ady;
    vector< vector<int> > arbol(cn);
    vector<int> markedLines;
    vector<int> :: iterator itVec;

    // Inicializo las distancias del arbol en INF.
    for(int i = 0; i < cn; i++)
        arbol[i] = vector<int> (cn, INF);

    int padre = 0;
    int hijo = 0;
    while(markedLines.size() + 1 < cn){
        padre = hijo;
        // Marco la fila y elimino la columna del nodo padre.
        markedLines.push_back(padre);
        for(int i = 0; i < cn; i++)
            adyacencia[i][padre] = INF;

        // Encuentro la menor distancia entre las filas marcadas.
        // El nodo padre es la linea marcada y el nodo hijo es la columna del minimo.
        int min = INF;
        for(itVec = markedLines.begin(); itVec != markedLines.end(); itVec++)
            for(int i = 0; i < cn; i++)
                if(min > adyacencia[*itVec][i]){
                    min = adyacencia[*itVec][i];
                    padre = *itVec;
                    hijo = i;
                }

        arbol[padre][hijo] = min;
        arbol[hijo][padre] = min;
    }
    return arbol;
}