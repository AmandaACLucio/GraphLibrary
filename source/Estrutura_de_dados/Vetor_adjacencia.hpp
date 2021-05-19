#ifndef __VETORADJACENCIA_H__
#define __VETORADJACENCIA_H__

#include <iostream>
#include <vector>
#include "Estrutura_de_dados.hpp"

using namespace std;

class VetorAdjacencia
{
    private:
        vector<int> nodes;
        vector<int[2]> nodesWeight;
        int size;

    public:
        VetorAdjacencia();
        VetorAdjacencia(int node);
        VetorAdjacencia(int node, int peso);
        bool add(int node);
        bool add(int node, int peso);
        bool search(int node);
        int searchPositionInsert(int node);
        void show();
};


class VectorVetorAdjacencia: public EstruturaDeDados
{    
    private:
        vector<VetorAdjacencia> vetorDeVetores;
    public:
        void setSize(int newSizeVector);
        bool addAresta(int valor1, int valor2);
        bool addAresta(int valor1, int valor2, float weight);
        void show(bool weight);
};

#endif
