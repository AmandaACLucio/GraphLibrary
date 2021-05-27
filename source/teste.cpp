 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <vector>
#include <algorithm>
#include <functional>
#include <string_view>

using namespace std;

int main()
{
    int nodeUm = 5;
    //int nodeDois = 3;
    int numberNodes = 55;
    int infinito = 99999999;
    vector<bool> hasNode;
    cout<<"Teste"<<endl;

    vector<pair<float,int>> distancia; //fist: peso second: no
    vector<bool> s;
/*
    for (int i = 0; i < numberNodes; i++)
    {
        pair<int,float>  f = {i,infinito};
        distancia.push_back(f);
        s.push_back(false);
        hasNode.push_back(true);
    }
    while (s!=hasNode)
    {
        int ultimo = distancia.back().first;
        distancia.pop_back();
        int distanciaMinima = 0;
    }
    */
    distancia.push_back({4.5,2});
    distancia.push_back({5.2,1});
    distancia.push_back({8.4,3});


    make_heap(distancia.begin(), distancia.end(),   std::greater<>{});
/*
    distancia2.push_back(5);
    distancia2.push_back(1);
    distancia2.push_back(3);
*/

    auto top = distancia.front();
    //cout<<top.first<<"   "<<top.second;
    cout<<"vertice: "<<top.second<<" peso: "<<top.first<<endl<<endl<<endl;


    distancia.push_back({1.2,8});
    
    make_heap(distancia.begin(), distancia.end(),   std::greater<>{});
    auto topp = distancia.front();

    cout<<"vertice: "<<topp.second<<" peso: "<<topp.first<<endl<<endl<<endl;

    

    cout<<"vertice: "<<topp.second<<" peso: "<<topp.first<<endl<<endl<<endl;


/*
    distancia.at(nodeUm).second = 0;
    cout<<"top- fist: "<<distancia.back().first<<" second: "<<distancia.back().second<<endl;
   */ 
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
