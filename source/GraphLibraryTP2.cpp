#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <string>
#include <time.h>
#include <set>
#include "GraphLibrary.hpp"
#include "Estrutura_de_dados\Lista_adjacencia.hpp"
#include "Estrutura_de_dados\Vetor_adjacencia.hpp"
#include "Estrutura_de_dados\Matriz_adjacencia.hpp"
#include "Estrutura_de_dados\Estrutura_de_dados.hpp"
#include "FuncoesAuxiliares.hpp"
#define INFINITO 0x3f3f3f3f


using namespace std;


pair<float, vector<float>> Grafo::Dijkstra(int nodeUm, int nodeDois, string filesaida){
    
    vector<bool> explorados;
    pair<float, vector<float>> retorno;
    set<pair<float, int>> distancia; //first 
    vector<pair<int,float>> pai; 
    vector<int> nivel;
    vector<float> distanciaOrigem; 

    for (int j = 0; j < numberNodes+1; j++){
        distanciaOrigem.push_back(INFINITO);
        nivel.push_back(0);
        pai.push_back({0, 0});
        explorados.push_back(false);
    }

    distanciaOrigem.at(nodeUm) = 0;
    distancia.insert({0, nodeUm});

    pai.at(nodeUm).first = 0;
    pai.at(nodeUm).second = nan("");

    while (!distancia.empty())
    {
        int minVertice = distancia.begin()->second;
        int minPeso = distancia.begin()->first;

        distancia.erase(distancia.begin());
        
        int endFor= estruturaGrafo->sizeVertice(minVertice);

        explorados.at(minVertice) = true;

        for (int i = 0; i < endFor; i++)
        {
            //caso não tenho um viznho na posição i, a função vizinhoDeVertice retorna {-1, NAN}
            pair<int, float> vizinho = estruturaGrafo->vizinhoDeVertice(minVertice, i, true);

            if(vizinho.first == -1){
                cout<< "Loop fora de range"<<endl;
            }

            if (vizinho.first !=-1 && !explorados[vizinho.first] && (distanciaOrigem.at(vizinho.first)> (distanciaOrigem.at(minVertice) + vizinho.second)) )
            {

                pai.at(vizinho.first).first=minVertice;
                pai.at(vizinho.first).second=vizinho.second;

                nivel.at(vizinho.first)+=1;

                distanciaOrigem.at(vizinho.first) = distanciaOrigem.at(minVertice) + vizinho.second;

                distancia.insert({distanciaOrigem.at(vizinho.first), vizinho.first});

            }
        }   
    }


    float custoTotal=distanciaOrigem.at(nodeDois);

    EscreveNovoGrafo(pai, nivel, filesaida, custoTotal);

    retorno.first= custoTotal;
    retorno.second = distanciaOrigem;
    
    return(retorno);

}

void Grafo::MST(int inicio, string filesaida){
    
    vector<int> nivel;
    vector<bool> explorados;
    vector<pair<int,float>> pai;
    set<pair<float, int>> distancia; //first ->vertice, second ->peso
    float custoTotal = 0; 

    for (int vertice = 0; vertice < numberNodes+1; vertice++){
        pai.push_back({-1, INFINITO});
        nivel.push_back(0);
        explorados.push_back(false);
    }
 
    distancia.insert({0, inicio});
    pai.at(inicio).first = 0;
    pai.at(inicio).second = nan("");

    //verificar se todos os nós já foram explorados
    while(!distancia.empty()){
        
        int minVertice = distancia.begin()->second;
        int minPeso = distancia.begin()->first;

        distancia.erase(distancia.begin());

        int endFor= estruturaGrafo->sizeVertice(minVertice);

        explorados.at(minVertice) = true;

        for (int i = 0; i < endFor; i++){

            //caso não tenho um viznho na posição i, a função vizinhoDeVertice retorna {-1, NAN}
            pair<int, float> vizinho = estruturaGrafo->vizinhoDeVertice(minVertice, i, true);


            if(vizinho.first == -1){
                cout<< "Loop fora de range"<<endl;
            }
            

            if (vizinho.first !=-1 && !explorados[vizinho.first] && ((pai.at(vizinho.first).second) > (vizinho.second)) )
            {

                pai.at(vizinho.first).first=minVertice;
                pai.at(vizinho.first).second=vizinho.second;

                nivel.at(vizinho.first)=nivel.at(minVertice)+1;

                distancia.insert({vizinho.second, vizinho.first});
            }          
        }
    

    }

    //calculo custo total da MST

    for(int i=0; i<pai.size(); i++){
        if(pai.at(i).second != INFINITO){
            custoTotal+=pai.at(i).second;
        }
    }

    cout<<"Custo Total: "<<custoTotal;

    EscreveNovoGrafo(pai, nivel, filesaida, custoTotal);

}

void Grafo::EscreveNovoGrafo(vector<pair<int,float>> pai, vector<int> nivel, string filesaida, int custoTotal){

    const char * filenameChar = filesaida.c_str();
    ofstream arquivoCC (filenameChar);
    int valueUm, valueDois;
    float pesoAresta;

    if (arquivoCC.is_open())
    {

        arquivoCC<<nivel.size()-1<<endl;

        for(int valueUm=1; valueUm<pai.size(); valueUm++){
            
            valueDois=pai.at(valueUm).first;
            pesoAresta=pai.at(valueUm).second;
            if(valueDois!=-1){
                arquivoCC<<valueUm<<" "<<valueDois<<" "<<pesoAresta<<endl;
            }

        }
        
        arquivoCC<<"Custo Total: "<<custoTotal<<endl;
    }else{
        cout << "Erro ao criar arquivo de Saída."<<endl;        
    }
    arquivoCC.close();
}

float Grafo::Excentricidade(int vertice){

    bool mesmaComponente=false;
    int verticeDois=2;
    float excentricidade=0;
    vector<float> distanciaOrigem;

    while(!mesmaComponente){
        if(verticeDois!=vertice){
            mesmaComponente = MesmaComponente(vertice, verticeDois);
            distanciaOrigem = Dijkstra(vertice, verticeDois).second;
            verticeDois++;
        }
    }

    for(int i=0; i<distanciaOrigem.size(); i++){
        if((distanciaOrigem.at(i)>excentricidade) && (distanciaOrigem.at(i)!=INFINITO)){
            excentricidade = distanciaOrigem.at(i);
        }
    }

    return excentricidade;

}