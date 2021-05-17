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
    sizeLista = 0;
}   

ListaAdjacencia::ListaAdjacencia(int node){
    top = new NodeList(node);
    last = top;
    sizeLista = 0;
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
        sizeLista++;
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
        sizeLista++;
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

    NodeList* nodee = top;
    while (nodee != NULL)
    {
        int c = nodee->get();
        cout<<c<<", ";
        nodee = nodee->get_next();
    }
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
    return sizeLista;
}

NodeList* ListaAdjacencia::getTop(){
    
    return top;
}

//Essa funcao popular e ineficiente, pois ele recebe uma vetor de lista e cria outro
//Pra se tornar mais eficiente ele deveria modificar o vetor de lista, custando menos memoria assim
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
//************************************************** Vector De Lista *******************
VectorDeLista::VectorDeLista(){
    sizeVetorDeListas = 0;
}

void VectorDeLista::addVertice(){
    ListaAdjacencia listemp;
    vetorDeListas.push_back(listemp);
    sizeVetorDeListas++;
}

bool VectorDeLista::addAresta(int valor1, int valor2){
    return vetorDeListas.at(valor1).sortedInsert(valor2);
}

void VectorDeLista::show(){
    for(int i = 0; i<sizeVetorDeListas; i++){
        cout<<endl<<"lista "<<i<<" :";
        vetorDeListas.at(i).show();
    }

}

//Náo e usado
void VectorDeLista::setSize(int newSizeVector){
}

bool VectorDeLista::add(int valor1, int valor2){
}

//************************************************** Lista De Lista *******************

ListaDeLista::ListaDeLista(){
    listaDeListas.add(0);
    sizeListaDeListas = 0;
}

void ListaDeLista::addVertice(){
    ListaAdjacencia* new_list = new ListaAdjacencia;
    if (top == NULL)
    {
        top = new_list;
        last = new_list;
    }else{
        //last->add(new_list);
        this->last = new_list;
    }
    sizeListaDeListas++;
}

bool ListaDeLista::addAresta(int valor1, int valor2){
    //return listaDeListas.at(valor1).sortedInsert(valor2);
}

void ListaDeLista::show(){
    for(int i = 0; i<sizeListaDeListas; i++){
        cout<<endl<<"lista "<<i<<" :";
        //listaDeListas.at(i).show();
    }

}

//Náo e usado
void ListaDeLista::setSize(int newSizeVector){
}

bool ListaDeLista::add(int valor1, int valor2){
}