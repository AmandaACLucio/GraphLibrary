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

NodeVec::NodeVec(int newData, double newWeight){
    data = newData;
    weight = newWeight;
}

VetorAdjacencia::VetorAdjacencia(){
    sizeVetor = 0;
}

VetorAdjacencia::VetorAdjacencia(int node){
    NodeVec nodeTemp(node);
    nodes.push_back(nodeTemp);
    sizeVetor = 1;
}

VetorAdjacencia::VetorAdjacencia(int node, double peso){
    NodeVec nodeTemp(node, peso);
    nodes.push_back(nodeTemp);
    sizeVetor = 1;
}

bool VetorAdjacencia::add(int node){
    if(!search(node)){ //só adiciona se o nó não existir ainda
        if(sizeVetor==0){
            nodes.push_back(node);
            sizeVetor = 1;
            return true;
        }else{
            int positionInsert, aux;
            int positionAtual=sizeVetor;

            positionInsert= searchPositionInsert(node);

            if(positionInsert==sizeVetor){
                nodes.push_back(node);            
            }else{
                nodes.push_back(nodes.at(sizeVetor-1));
                while(positionAtual!=positionInsert){
                    aux = nodes.at(positionAtual-1).data;
                    nodes.at(positionAtual) = aux;
                    positionAtual--;
                }
                nodes.at(positionInsert) = node;
            }
            sizeVetor=sizeVetor+1;
            return true;
        }
    }
    return false;
}

bool VetorAdjacencia::add(int node, double peso){


    NodeVec nodeTemp(node, peso);
    if(!search(node)){ //só adiciona se o nó não existir ainda
        if(sizeVetor==0){
            nodes.push_back(nodeTemp);
            sizeVetor = 1;
            return true;
        }else{
            int positionInsert;
            NodeVec aux;
            int positionAtual=sizeVetor;
            positionInsert= searchPositionInsert(node);

            if(positionInsert==sizeVetor){
                nodes.push_back(nodeTemp);            
            }else{
                nodes.push_back(nodes.at(sizeVetor-1));
                while(positionAtual!=positionInsert){
                    aux = nodes.at(positionAtual-1);
                    nodes.at(positionAtual) = aux;
                    positionAtual--;
                }
                nodes.at(positionInsert) = node;
            }
            sizeVetor=sizeVetor+1;
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

int VetorAdjacencia::getSize(){
    return sizeVetor;
}

int VetorAdjacencia::searchPositionInsert(int node){
    if(sizeVetor==0){
        return 0;
    }
    for(int i=0; i<nodes.size(); i++){
        if(nodes.at(i).data>node){
            return i;
        }
    }
    return sizeVetor;
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

bool VectorVetorAdjacencia::addAresta(int valor1, int valor2, double weight){
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

int VectorVetorAdjacencia::vizinhoDeVertice(int vertice, int posicaoVizinho){
    int vizinho;

    if(posicaoVizinho>=size || vertice>=size){
        vizinho = -1;
    }else{
        vizinho = vetorDeVetores.at(vertice).nodes.at(posicaoVizinho).data;
    }

    return vizinho;
}

pair <int,double> VectorVetorAdjacencia::vizinhoDeVertice(int vertice, int posicaoVizinho, bool weight){
    
    pair <int, double> dupla;
    int vizinho;
    double pesoVertice;
    int sizeValue = sizeVertice(vertice);

    if(sizeValue==-1 || posicaoVizinho>=sizeValue){
        pesoVertice = nan("");
        dupla = {-1, pesoVertice};
    }else{
        pesoVertice = vetorDeVetores.at(vertice).nodes.at(posicaoVizinho).weight;
        vizinho = vetorDeVetores.at(vertice).nodes.at(posicaoVizinho).data;
        dupla = {vizinho, pesoVertice};
    }

    return dupla;
}

int VectorVetorAdjacencia::sizeVertice(int vertice){
    if(vertice>=vetorDeVetores.size()){
        return -1;
    }
    int sizeValue = vetorDeVetores.at(vertice).getSize();
    return sizeValue;
}