#ifndef __ESTRUTURADEDADOS_H__
#define __ESTRUTURADEDADOS_H__

#include <iostream>

using namespace std;

class EstruturaDeDados{
 
    public:

    int size;

    virtual void setSize(int newSizeVector)=0;
    virtual bool add(int valor1, int valor2)=0;
    virtual void show()=0;
    void addVertice();
    bool addAresta(int valor1, int valor2);

};

#endif
