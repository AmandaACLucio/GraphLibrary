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


        NodeList(int dataa);
        void set(int i);
        int get();
        NodeList* get_next();        
        void add(NodeList* data);
};

class ListaAdjacencia
{
    private:
        /* data */
        NodeList* top;
        NodeList* last;

    public:

        ListaAdjacencia();
        ListaAdjacencia(int node);
        bool add(int data);        
        void remove();
        void show();
        bool search(int i);
        int size();
        NodeList* getTop();
        bool sortedInsert(int val);

};


class VectorListaAdjacencia: public EstruturaDeDados
{    
    private:
        vector<ListaAdjacencia> vetorDeListas;

    public:
        void setSize(int newSizeVector);
        bool add(int valor1, int valor2);
        void show();
};

#endif
