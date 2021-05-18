#ifndef __MATRIZADJACENCIA_H__
#define __MATRIZADJACENCIA_H__

#include <iostream>
#include <vector>
#include "Estrutura_de_dados.hpp"


using namespace std;

class MatrizAdjacencia: public EstruturaDeDados
{
    //size_t numberNodes;
    bool** matriz;

    public:
        MatrizAdjacencia();
        MatrizAdjacencia(int numeroVertices);
        void setSize(int numeroVertices);   
        bool addAresta(int verticeUm, int verticeDois);
        bool addAresta(int valor1, int valor2, float weight);
        void show();
};

#endif

