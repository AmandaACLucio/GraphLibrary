#ifndef __VETORADJACENCIA_H__
#define __VETORADJACENCIA_H__

#include <iostream>
#include <vector>
#include "Estrutura_de_dados.hpp"

using namespace std;

class VetorAdjacencia
{
    private:
        /* data */
        vector<int> nodes;
        int size;

    public:
        VetorAdjacencia();
        VetorAdjacencia(int node);
        bool add(int node);
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
        bool add(int valor1, int valor2);
        void show();
};

// Nova implementacao => Max
class VectorDeVetor: public EstruturaDeDados
{    
    private:
        vector<VetorAdjacencia> vetorDeVetores;
        int sizeVetorDeVetor;

    public:
        VectorDeVetor();
        void setSize(int newSizeVector);// nao e usado
        bool add(int valor1, int valor2);// nao e usado
        void show();
        void addVertice();
        bool addAresta(int valor1, int valor2);
};



#endif
