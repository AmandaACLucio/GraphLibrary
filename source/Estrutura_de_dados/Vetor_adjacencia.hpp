#ifndef __VETORADJACENCIA_H__
#define __VETORADJACENCIA_H__

#include <iostream>
#include <vector>
#include "Estrutura_de_dados.hpp"

using namespace std;

class NodeVec
{
    public:
        int data;
        float weight;

        NodeVec();
        NodeVec(int dataa);
        NodeVec(int dataa, float weight);
        void set(int i);
        int get();
};

class VetorAdjacencia
{
    private:
        vector<NodeVec> nodes;
        int size;

    public:
        VetorAdjacencia();
        VetorAdjacencia(int node);
        VetorAdjacencia(int node, float peso);
        bool add(int node);
        bool add(int node, float peso);
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
        pair <int,float> vizinhoDeVertice(int vertice, int posicaoVizinho);
        virtual int sizeVertice(int vertice);
};

#endif
