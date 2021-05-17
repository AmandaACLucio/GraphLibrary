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
        void setSize(int numeroVertices);   
        bool add(int verticeUm, int verticeDois);
        void show();
        void addVertice();// nao e usado
        bool addAresta(int valor1, int valor2);// nao e usado
};

class MatrizDeMatriz: public EstruturaDeDados
{
    //size_t numberNodes;
    bool** matriz;

    public:
        MatrizDeMatriz();   
        void setSize(int numeroVertices);   
        bool add(int verticeUm, int verticeDois);
        void show();
        void addVertice();
        bool addAresta(int valor1, int valor2);
};

#endif