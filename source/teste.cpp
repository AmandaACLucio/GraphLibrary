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

    vector<pair<float,int>> distancia; //fist: peso second: no
    vector<bool> s;

    distancia.push_back({9,0});
    distancia.push_back({5.2,1});
    distancia.push_back({1.5,2});
    distancia.push_back({8.4,3});
    distancia.push_back({3.4,4});
    distancia.push_back({9.4,5});
    
    cout<<endl<<endl<<"*** Antes do make_heap ***"<<endl;
    for (auto i : distancia) cout <<"Vertice: "<< i.second <<" peso: "<< i.first << ' ';

    make_heap(distancia.begin(), distancia.end(),   std::greater<>{});

    cout<<endl<<endl<<"*** Depois do make_heap ***"<<endl;

    for (auto i : distancia) cout <<"Vertice: "<< i.second <<" peso: "<< i.first << ' ';

    auto top = distancia.front();
    cout<<endl<<endl<<"O menor valor do heap. vertice: "<<top.second<<" peso: "<<top.first<<endl<<endl<<endl;

    
    distancia.at(1).first = 2.8;
    distancia.at(2).first = 3.8;
    distancia.at(3).first = 1.6;
    distancia.at(5).first = 2.7;
    distancia.at(4).first = 1.2;
    

    cout<<endl<<endl<<"*** Depois do at ***"<<endl;

    for (auto i : distancia) cout <<"Vertice: "<< i.second <<" peso: "<< i.first << ' ';

    auto topp = distancia.front();
    cout<<endl<<endl<<"O menor valor do heap. vertice: "<<topp.second<<" peso: "<<topp.first<<endl<<endl<<endl;

    cout<<endl<<endl<<"*** Depois do push heap ***"<<endl;

    push_heap(distancia.begin(), distancia.end(),   std::greater<>{});
    for (auto i : distancia) cout <<"Vertice: "<< i.second <<" peso: "<< i.first << ' ';

    auto toppp = distancia.front();
    cout<<endl<<endl<<"O menor valor do heap. vertice: "<<toppp.second<<" peso: "<<toppp.first<<endl<<endl<<endl;
    cout<<endl<<endl;




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
