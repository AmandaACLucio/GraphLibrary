#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "Estrutura_de_dados\Lista_adjacencia.hpp"
#include "Estrutura_de_dados\Vetor_adjacencia.hpp"
#include "Estrutura_de_dados\Matriz_adjacencia.hpp"
#include "Estrutura_de_dados\Estrutura_de_dados.hpp"
#include "FuncoesAuxiliares.hpp"

using namespace std;

class Grafo
{   

    public:

    int numberNodes;
    int numberArestas;
    vector<bool> hasNode;
    map<int, int> graus;
    bool direcionado;
    bool peso;

    //1- lista 2-vetor 3-matriz
    int estruturaEscolhida;
    EstruturaDeDados *estruturaGrafo;   
  
    //TP1
    Grafo(string caminho, int estrutura, bool newPeso, bool newDirecionado);
    void Entrada(string fileEntrada);

    void Saida(string fileSaida="graphSaida.txt");
    vector<vector<int>> BFS(int raiz);
    vector<vector<int>> DFS(int raiz);
    int Grau(int vertice);
    int Distancia(int nodeUm, int nodeDois);
    void Diametro();
    vector<vector<int>> ComponentesConexas(string filesaida="graphComponentesConexas.txt");
    bool MesmaComponente(int nodeUm, int nodeDois);

    //TP2
    void Dijkstra(int nodeUm, int nodeDois, string filesaida="Dijkstra.txt"); //caminho mínimo
    int Distancia(int nodeUm, int nodeDois, bool peso); //usando Dijkstra
    void MST(int inicio=1, string filesaida="MST.txt"); //escrita no formato de grafo em um arquivo de saída
    int Excentricidade(int nodeUm, int nodeDois);
    void EscreveNovoGrafo(vector<pair<int,float>> pai, vector<int> nivel, string filesaida);

};