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
        double weight;

        NodeVec();
        NodeVec(int dataa);
        NodeVec(int dataa, double weight);
        void set(int i);
        int get();
};

class VetorAdjacencia
{
    private:
        int sizeVetor;

    public:
        vector<NodeVec> nodes;

        VetorAdjacencia();
        VetorAdjacencia(int node);
        VetorAdjacencia(int node, double peso);
        bool add(int node);
        bool add(int node, double peso);
        bool search(int node);
        int searchPositionInsert(int node);
        int getSize();
        void show();
};


class VectorVetorAdjacencia: public EstruturaDeDados
{    
    private:
        vector<VetorAdjacencia> vetorDeVetores;
    public:
        void setSize(int newSizeVector);
        bool addAresta(int valor1, int valor2);
        bool addAresta(int valor1, int valor2, double weight);
        void show(bool weight);
        int vizinhoDeVertice(int vertice, int posicaoVizinho);
        pair <int,double> vizinhoDeVertice(int vertice, int posicaoVizinho, bool weight);
        virtual int sizeVertice(int vertice);
};

#endif
