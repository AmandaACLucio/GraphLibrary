#include <iostream>
#include "Lista_adjacencia.hpp"
#include "Estrutura_de_dados.hpp"
#include "../FuncoesAuxiliares.hpp"

using namespace std;

NodeList::NodeList(int dataa){
    this->next = NULL;
    this->data = dataa;
}

void NodeList::set(int i){
    this->data = i;
}

int NodeList::get(){
    return data;
}

NodeList* NodeList::get_next(){
    return next;
}

void NodeList::add(NodeList* data){
    next = data;
}

ListaAdjacencia::ListaAdjacencia(){
    top = NULL;
    last = NULL;
}   

ListaAdjacencia::ListaAdjacencia(int node){
    top = new NodeList(node);
    last = top;
}

bool ListaAdjacencia::add(int data){
    if(!search(data)){
        NodeList* new_node = new NodeList(data);
        if (top == NULL)
        {
            top = new_node;
            last = new_node;
        }else{
            last->add(new_node);
            this->last = new_node;
        }
        return true;        
    }
    return false;

}

bool ListaAdjacencia::sortedInsert(int data){
    
    if(!search(data)){

        NodeList* node = new NodeList(data);
        NodeList* pre = NULL;
        NodeList *curr = top;

        while(curr!=NULL && data>curr->data){
            pre = curr;
            curr = curr->next;
        }
        node->next = curr;
        if(pre==NULL){
            top = node;
        }else{
            pre->next = node;
        }
        return true;
    }
    return false;

}

void ListaAdjacencia::remove(){
    if (top == NULL)
    {
        if (top->get_next() == NULL)
        {
            top = NULL;
        }
    }
    
}

void ListaAdjacencia::show(){

    cout<<"Inicio da lista"<<endl;
    NodeList* nodee = top;
    while (nodee != NULL)
    {
        int c = nodee->get();
        cout<<c<<endl;
        nodee = nodee->get_next();
    }
    cout<<"Fim da lista"<<endl;

}

bool ListaAdjacencia::search(int i){
    NodeList* nodee = top;
    while (nodee != NULL)
    {
        int c = nodee->get();
        if (c == i)
        {
            return true;
        }
        nodee = nodee->get_next();
    }
    return false;
}

int ListaAdjacencia::size(){
    int tamanho = 0;
    NodeList* nodee = top;
    
    while (nodee != NULL)
    {
        tamanho++;
        int c = nodee->get();
        nodee = nodee->get_next();
    }
    
    return tamanho;
}

NodeList* ListaAdjacencia::getTop(){
    
    return top;
}

void VectorListaAdjacencia::setSize(int newSizeVector){
    size = newSizeVector; //size será a quantidade de nós
    vetorDeListas = Popular(vetorDeListas,0 ,newSizeVector);
}

bool VectorListaAdjacencia::add(int valor1, int valor2){
    bool resposta; //precisa setar o tamanho antes
    resposta = vetorDeListas.at(valor1).sortedInsert(valor2);
    vetorDeListas.at(valor2).sortedInsert(valor1);
    return resposta;
}

void VectorListaAdjacencia::show(){
    for(int i; i<vetorDeListas.size(); i++){
        cout<<"lista de "<<i<<endl;
        vetorDeListas.at(i).show();
    }
}