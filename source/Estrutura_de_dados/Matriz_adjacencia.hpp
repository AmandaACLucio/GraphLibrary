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
    double** matrizWeight;
    bool inicializada=false; //se a matriz já foi inicializada

    public:
        MatrizAdjacencia();
        MatrizAdjacencia(int numeroVertices);
        void setSize(int numeroVertices);
        bool addAresta(int verticeUm, int verticeDois);
        bool addAresta(int valor1, int valor2, double weight);
        void show(bool weight);
        int vizinhoDeVertice(int vertice, int posicaoVizinho);        
        pair <int,double> vizinhoDeVertice(int vertice, int posicaoVizinho, bool weight);
        virtual int sizeVertice(int vertice);
};

#endif

