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



vector<int> Grafo::Dijkstra(int nodeUm, int nodeDois){
    
    //float distancia[numberNodes];
    set<pair<int,float>> distancia; //first ->vertice, second ->peso
    vector<int> pai;
    int distanciaOrigem[numberNodes+1]; 

    for (int j = 0; j < numberNodes+1; j++){
        int infinito = INFINITO;
        distanciaOrigem[j] = infinito;
    }
    distancia.insert({nodeUm, 0});
    while (!distancia.empty())
    {
        int minVertice = distancia.begin()->first;
        int minPeso = distancia.begin()->second;

        distancia.erase(distancia.begin());
        
        int endFor= estruturaGrafo->sizeVertice(minVertice);

        for (int i = 0; i < endFor; i++)
        {
            //caso não tenho um viznho na posição i, a função vizinhoDeVertice retorna {-1, NAN}
            pair<int, float> node = estruturaGrafo->vizinhoDeVertice(minVertice, i, true);
            if (node.first !=-1 && (distanciaOrigem[node.first] > (minPeso + node.second)) )
            {
                distanciaOrigem[node.first] = (minPeso + node.second);
                distancia.insert({node.first, distanciaOrigem[node.first]});
            }
        }
        
    }
}

void Grafo::MST(int inicio){
    
    int tamanhoComponente, idComponente;
    int nivel[numberNodes+1];
    bool descoberto[numberNodes+1];
    vector<pair<int,float>> pai;
    set<pair<int,float>> distancia; //first ->vertice, second ->peso
    float custoTotal = 0; 

    string filesaida = "Temp.tx";

    for (int vertice = 0; vertice < numberNodes+1; vertice++){
        pai.push_back({-1, INFINITO});
    }
 
    distancia.insert({inicio, 0});

    //verificar se todos os nós já foram explorados
    while(!distancia.empty()){
        
        int minVertice = distancia.begin()->first;
        int minPeso = distancia.begin()->second;

        distancia.erase(distancia.begin());

        int endFor= estruturaGrafo->sizeVertice(minVertice);
        descoberto[minVertice] = true;

        for (int i = 0; i < endFor; i++){

            //caso não tenho um viznho na posição i, a função vizinhoDeVertice retorna {-1, NAN}
            pair<int, float> vizinho = estruturaGrafo->vizinhoDeVertice(minVertice, i, true);
            
            if (vizinho.first !=-1 && !descoberto[vizinho.first] && ((pai.at(vizinho.first).second) > (vizinho.second)) )
            {
                pai.at(vizinho.first)={minVertice, pai.at(vizinho.first).second};
                nivel[vizinho.first]=nivel[minVertice]+1;
            }          
        }
    }

    //calculo custo total da MST

    for(int i=0; i<pai.size(); i++){
        if(pai.at(i).second != INFINITO){
            custoTotal+=pai.at(i).second;
        }
    }
}
