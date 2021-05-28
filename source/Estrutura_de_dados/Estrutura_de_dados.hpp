#ifndef __ESTRUTURADEDADOS_H__
#define __ESTRUTURADEDADOS_H__

#include <iostream>

using namespace std;

class EstruturaDeDados{
 
    public:

    int size;

    virtual void setSize(int newSizeVector)=0;
    virtual bool addAresta(int valor1, int valor2)=0;
    virtual bool addAresta(int valor1, int valor2, float weight)=0;
    virtual void show(bool weight)=0;
    virtual pair <int,float> vizinhoDeVertice(int vertice, int posicaoVizinho);
    virtual int sizeVertice(int vertice);
    //virtual void addVertice();
    //virtual bool addAresta(int valor1, int valor2);

};

#endif
