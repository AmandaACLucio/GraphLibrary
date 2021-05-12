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
  

    Grafo(string caminho, int estrutura);
    Grafo(int estrutura, bool direcao, bool peso);
    void Entrada(string fileEntrada);
    void Saida(string fileSaida);
    vector<vector<int>> BFS(int raiz);
    vector<vector<int>> DFS(int raiz);
    int Grau(int vertice);
    int Distancia(int nodeUm, int nodeDois);
    void Diametro();
    vector<vector<int>> ComponentesConexas(string filesaida="temp.txt");
    bool MesmaComponente(int nodeUm, int nodeDois);

};