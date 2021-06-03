﻿#include <iostream>
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


pair<double, vector<double>> Grafo::Dijkstra(int nodeUm, int nodeDois, string filesaida){
    
    vector<bool> explorados;
    pair<double, vector<double>> retorno;
    set<pair<double, int>> distancia; //Acumula vetores descobertos e não explorados - first ->vertice, second ->peso 
    vector<pair<int,double>> pai; //para construção do resultado
    vector<double> distanciaOrigem; 

    if(valueNegativo){
        cout<<"Dijkstra não pode ser aplicado para grafos com peso negativo"<<endl;
        retorno.first= 0;
        retorno.second = {0};
        return retorno;
    }

    for (int j = 0; j < numberNodes+1; j++){
        distanciaOrigem.push_back(INFINITO);
        pai.push_back({0, 0});
        explorados.push_back(false);
    }

    distanciaOrigem.at(nodeUm) = 0;
    distancia.insert({0, nodeUm});

    pai.at(nodeUm).first = 0;
    pai.at(nodeUm).second = nan(""); //vertíce RAIZ do grafo

    while (!distancia.empty())
    {
        int minVertice = distancia.begin()->second; //vertice com menor peso
        int minPeso = distancia.begin()->first;

        distancia.erase(distancia.begin());
        
        int endFor= estruturaGrafo->sizeVertice(minVertice);

        explorados.at(minVertice) = true;

        for (int i = 0; i < endFor; i++)
        {
            //caso não tenho um viznho na posição i, a função vizinhoDeVertice retorna {-1, NAN}
            pair<int, double> vizinho = estruturaGrafo->vizinhoDeVertice(minVertice, i, true);

            if(vizinho.first == -1){
                cout<< "Loop fora de range"<<endl;
            }

            //se existe o vizinho, ele ainda não foi explorado e a sua distancia da origem é maior que a distância gerada pela descoberto do vertice minVertice

            if (vizinho.first !=-1 && !explorados[vizinho.first] && (distanciaOrigem.at(vizinho.first)> (distanciaOrigem.at(minVertice) + vizinho.second)) )
            {

                pai.at(vizinho.first).first=minVertice;
                pai.at(vizinho.first).second=vizinho.second;

                distanciaOrigem.at(vizinho.first) = distanciaOrigem.at(minVertice) + vizinho.second;

                distancia.insert({distanciaOrigem.at(vizinho.first), vizinho.first});

            }
        }   
    }

    double custoTotal=distanciaOrigem.at(nodeDois);

    //função para gerar txt com nome definido ou padrão
    EscreveNovoGrafo(pai, filesaida, custoTotal);

    retorno.first= custoTotal;
    retorno.second = distanciaOrigem;
    
    return(retorno);

}

void Grafo::MST(int inicio, string filesaida){
    
    vector<bool> explorados;
    vector<pair<int,double>> pai;
    set<pair<double, int>> distancia; //first ->vertice, second ->peso - Acumula vetores descobertos e não explorados
    double custoTotal = 0;

    for (int vertice = 0; vertice < numberNodes+1; vertice++){
        pai.push_back({-1, INFINITO});
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
            pair<int, double> vizinho = estruturaGrafo->vizinhoDeVertice(minVertice, i, true);


            if(vizinho.first == -1){
                cout<< "Loop fora de range"<<endl;
            }
            

            if (vizinho.first !=-1 && !explorados[vizinho.first] && ((pai.at(vizinho.first).second) > (vizinho.second)) )
            {

                pai.at(vizinho.first).first=minVertice;
                pai.at(vizinho.first).second=vizinho.second;

                distancia.insert({vizinho.second, vizinho.first});
            }          
        }
    }

    //calculo custo total da MST

    for(int i=0; i<pai.size(); i++){
        if(pai.at(i).second != INFINITO && !isnan(pai.at(i).second)){
            custoTotal+=pai.at(i).second;
        }
    }

    cout<<"Custo Total: "<<custoTotal<<endl;

    EscreveNovoGrafo(pai, filesaida, custoTotal);

}

double Grafo::Excentricidade(int vertice){

    bool mesmaComponente=false;
    int verticeDois=2;
    double excentricidade=0;
    vector<double> distanciaOrigem;

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

    cout<<"O valor da excentricidade é "<<excentricidade<<endl;

    return excentricidade;

}