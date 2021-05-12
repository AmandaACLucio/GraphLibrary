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
    
    map<int, int> graus;

    //1- lista 2-vetor 3-matriz
    int estruturaEscolhida;
    EstruturaDeDados *estruturaGrafo;   
  
    //TP1
    Grafo(string caminho, int estrutura);
    void Entrada(string fileEntrada);
    void Saida(string fileSaida);
    vector<vector<int>> BFS(int raiz);
    vector<vector<int>> DFS(int raiz);
    int Grau(int vertice);
    int Distancia(int nodeUm, int nodeDois);
    void Diametro();
    vector<vector<int>> ComponentesConexas(string filesaida="temp.txt");
    bool MesmaComponente(int nodeUm, int nodeDois);

    //TP2
    void Entrada(string fileEntrada, bool peso);
    vector<int> Dijkstra(int nodeUm, int nodeDois); //caminho mínimo
    int Distancia(int nodeUm, int nodeDois, bool peso); //usando Dijkstra
    void MST(); //escrita no formato de grafo em um arquivo de saída
    int Excentricidadeint(int nodeUm, int nodeDois);

};