#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <string>
#include <time.h>
#include <set>
#include "GraphLibrary.hpp" //precisa editar makefile para incluir essa biblioteca
#include "Estrutura_de_dados\Lista_adjacencia.hpp"
#include "Estrutura_de_dados\Vetor_adjacencia.hpp"
#include "Estrutura_de_dados\Matriz_adjacencia.hpp"
#include "Estrutura_de_dados\Estrutura_de_dados.hpp"
#include "FuncoesAuxiliares.hpp"


using namespace std;



vector<int> Grafo::Dijkstra(int nodeUm, int nodeDois){
    int infinito = 99999999;
    //float distancia[numberNodes];
    set<pair<int,float>> distancia;
    vector<bool> explorados;
    vector<int> pai;


    for (int i = 0; i < numberNodes; i++)
    {
        distancia.insert({i, infinito});
        explorados.at(i) = false;
    }
    distancia.at(0) = 0;
    make_heap(distancia.begin(), distancia.end(),  std::greater<>{});
    while (explorados!=hasNode)
    {
        int ultimo = distancia.back();
        distancia.pop_back();
        int distanciaMinima = 0;

        if ()
        {
            
        }
        
        int vs ;//= pesquisa(s,hasNode);
        pair<
        
    }
}

// Dijkstra(G, s)
//      Para cada vértice v
//              dist[v] = infinito
//       Define conjunto S = 0 // inicia vazio
//       dist[s] = 0
//       Enquanto S != V
//          Selecione u em V-S, tal que dist[u] é mínima       *
//          Adicione u em S
//          Para cada vizinho v de u faça
//              Se dist[v] > dist[u] + w(u,v) então
//                  dist[v] = dist[u] + w(u,v)
//Retorna dist[]



void Grafo::MST(int inicio){
    
    int tamanhoComponente, idComponente;
    int pai[numberNodes+1];
    vector<float> custo;

    string filesaida = "Temp.tx";
    vector<int> componentes;
    vector<int[2]> floresta;

    string filesaida = "Temp.tx";
    componentes = ComponentesConexas(filesaida).at(1); //retorna um vetor de vetor com componentes mapeadas, pois Prim não funciona para grafos não conexos

    tamanhoComponente = BFS(inicio).at(2).size();
    idComponente = componentes.at(inicio);

    for (int vertice = 0; vertice < numberNodes+1; vertice++){
        custo.push_back(numberNodes+1); //infinito
        pai[vertice]=-1;
    }

    custo.at(inicio) = 0;
    make_heap(custo.begin(), custo.end(), std::greater<>{});

    //verificar se todos os nós já foram explorados
    while(floresta.size()!=tamanhoComponente){
        
        auto menorPeso = custo.back();
        int dupla[2] = {inicio, menorPeso};
        floresta.push_back(dupla);
        //função que pega vizinhos
        vector<int[2]> vizinhos; //vector de listas com [vizinho, peso]
        for(int i=0; i<vizinhos.size(); i++){
            if(custo[vizinhos.at(i)[0]]>vizinhos.at(i)[1]){
                custo[vizinhos.at(i)[0]]=vizinhos.at(i)[1];
            }
        }
    }
}
