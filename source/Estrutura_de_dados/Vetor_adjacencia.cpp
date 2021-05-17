#include <iostream>
#include <vector>
#include "Vetor_adjacencia.hpp"
#include "Estrutura_de_dados.hpp"
#include "../FuncoesAuxiliares.hpp"

using namespace std;

VetorAdjacencia::VetorAdjacencia(){
    size = 0;
}
VetorAdjacencia::VetorAdjacencia(int node){
    nodes.push_back(node);
    size = 1;
}

bool VetorAdjacencia::add(int node){
    if(!search(node)){ //só adiciona se o nó não existir ainda
        if(size==0){
            nodes.push_back(node);
            size = 1;
            return true;
        }else{
            int positionInsert, next, aux;
            int positionAtual=size;

            positionInsert= searchPositionInsert(node);

            if(positionInsert==size){
                nodes.push_back(node);            
            }else{
                nodes.push_back(nodes.at(size-1));
                while(positionAtual!=positionInsert){
                    aux = nodes.at(positionAtual-1);
                    nodes.at(positionAtual) = aux;
                    positionAtual--;
                }
                nodes.at(positionInsert) = node;
            }
            size=size+1;
            return true;
        }
    }
    return false;
}

bool VetorAdjacencia::search(int node){
    for(int i=0; i<nodes.size(); i++){
        if(nodes.at(i)==node){
            return true;
        }
    }
    return false;
}

int VetorAdjacencia::searchPositionInsert(int node){
    if(size==0){
        return 0;
    }
    for(int i=0; i<nodes.size(); i++){
        if(nodes.at(i)>node){
            return i;
        }
    }
    return size;
}

void VetorAdjacencia::show(){
    cout<<" = (";

    for (int i = 0; i < nodes.size(); i++)
    {
        cout<<nodes.at(i)<<", ";
        /* code */
    }
    cout<<")";

}

void VectorVetorAdjacencia::setSize(int newSizeVector){
    size = newSizeVector;//size será a quantidade de nós
    vetorDeVetores = Popular(vetorDeVetores,0 ,newSizeVector);
}

bool VectorVetorAdjacencia::add(int valor1, int valor2){
    bool resposta; //precisa setar o tamanho antes
    resposta = vetorDeVetores.at(valor1).add(valor2);
    vetorDeVetores.at(valor2).add(valor1);
    return resposta;
}

void VectorVetorAdjacencia::show(){
    for(int i; i<vetorDeVetores.size(); i++){
        cout<<"vetor de "<<i<<endl;
        vetorDeVetores.at(i).show();
    }
}

//************************************* Vector de Vector ***************************
VectorDeVetor::VectorDeVetor(){
    sizeVetorDeVetor = 0;
}

void VectorDeVetor::addVertice(){
    VetorAdjacencia vectemp;
    vetorDeVetores.push_back(vectemp);
    sizeVetorDeVetor++;
}

bool VectorDeVetor::addAresta(int valor1, int valor2){
    vetorDeVetores.at(valor1).add(valor2);
}

void VectorDeVetor::show(){
    for (int i = 0; i < sizeVetorDeVetor; i++)
    {
        cout<<endl<<"Vector: "<<i;
        vetorDeVetores.at(i).show();
    }
    
}

//nao e usado
void VectorDeVetor::setSize(int newSizeVector){
}

bool VectorDeVetor::add(int valor1, int valor2){
    return 0;
}

