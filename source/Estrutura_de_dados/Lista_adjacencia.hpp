#ifndef __LISTAADJACENCIA_H__
#define __LISTAADJACENCIA_H__

#include <iostream>
#include <vector>
#include "Estrutura_de_dados.hpp"

using namespace std;

class NodeList
{
    public:
        /* data */
        //NodeList* prior;
        NodeList* next;
        int data;
        float weight;

        NodeList(int dataa);
        NodeList(int dataa, float weight);
        void set(int i);
        int get();
        NodeList* get_next();        
        void add(NodeList* data);
};

class ListaAdjacencia
{
    private:
        NodeList* top;
        NodeList* last;
        int sizeLista;

    public:

        ListaAdjacencia();
        ListaAdjacencia(int node);
        bool add(int data); 
        void show();
        bool search(int i);
        int size();
        NodeList* getTop();
        bool sortedInsert(int val);
        bool sortedInsert(int val, float newWeight);
};

class VectorListaAdjacencia: public EstruturaDeDados
{    
    private:
        vector<ListaAdjacencia> vetorDeListas;

    public:
        //VectorListaAdjacencia(int newSizeVector);
        void setSize(int newSizeVector);
        bool addAresta(int valor1, int valor2);
        bool addAresta(int valor1, int valor2, float weight);
        void show(bool weight);
        pair <int,float> vizinhoDeVertice(int vertice, int posicaoVizinho);
        virtual int sizeVertice(int vertice);
};
#endif




