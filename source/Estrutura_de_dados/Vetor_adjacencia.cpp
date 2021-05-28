#include <iostream>
#include <vector>
#include "Vetor_adjacencia.hpp"
#include "Estrutura_de_dados.hpp"
#include "../FuncoesAuxiliares.hpp"

using namespace std;

NodeVec::NodeVec(){
}

NodeVec::NodeVec(int newData){
    data = newData;
}

NodeVec::NodeVec(int newData, float newWeight){
    data = newData;
    weight = newWeight;
}

VetorAdjacencia::VetorAdjacencia(){
    size = 0;
}

VetorAdjacencia::VetorAdjacencia(int node){
    NodeVec nodeTemp(node);
    nodes.push_back(nodeTemp);
    size = 1;
}

VetorAdjacencia::VetorAdjacencia(int node, float peso){
    NodeVec nodeTemp(node, peso);
    nodes.push_back(nodeTemp);
    size = 1;
}

bool VetorAdjacencia::add(int node){
    if(!search(node)){ //só adiciona se o nó não existir ainda
        if(size==0){
            nodes.push_back(node);
            size = 1;
            return true;
        }else{
            int positionInsert, aux;
            int positionAtual=size;

            positionInsert= searchPositionInsert(node);

            if(positionInsert==size){
                nodes.push_back(node);            
            }else{
                nodes.push_back(nodes.at(size-1));
                while(positionAtual!=positionInsert){
                    aux = nodes.at(positionAtual-1).data;
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

bool VetorAdjacencia::add(int node, float peso){
    NodeVec nodeTemp(node, peso);
    if(!search(node)){ //só adiciona se o nó não existir ainda
        if(size==0){
            nodes.push_back(nodeTemp);
            size = 1;
            return true;
        }else{
            int positionInsert;
            NodeVec aux;
            int positionAtual=size;
            positionInsert= searchPositionInsert(node);

            if(positionInsert==size){
                nodes.push_back(nodeTemp);            
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
        if(nodes.at(i).data==node){
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
        if(nodes.at(i).data>node){
            return i;
        }
    }
    return size;
}

void VetorAdjacencia::show(){
    cout<<" = (";

    for (int i = 0; i < nodes.size(); i++)
    {
        cout<<nodes.at(i).data<<" Peso-> "<<nodes.at(i).weight<<", ";
    }
    cout<<")"<<endl<<endl<<endl;
}

void VectorVetorAdjacencia::setSize(int newSizeVector){
    size = newSizeVector;//size será a quantidade de nós
    vetorDeVetores = Popular(vetorDeVetores,0 ,newSizeVector);
}

bool VectorVetorAdjacencia::addAresta(int valor1, int valor2){
    bool resposta; //precisa setar o tamanho antes
    resposta = vetorDeVetores.at(valor1).add(valor2);
    return resposta;
}

bool VectorVetorAdjacencia::addAresta(int valor1, int valor2, float weight){
    bool resposta; //precisa setar o tamanho antes
    resposta = vetorDeVetores.at(valor1).add(valor2, weight);
    return resposta;
}

void VectorVetorAdjacencia::show(bool weight){
    for(int i = 0; i<=size; i++){
        cout<<endl<<"vetor de "<<i;
        vetorDeVetores.at(i).show();
    }
}

pair <int,float> VectorVetorAdjacencia::vizinhoDeVertice(int vertice, int posicaoVizinho){
    
}


int VectorVetorAdjacencia::sizeVertice(int vertice){

}