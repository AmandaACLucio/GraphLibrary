#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <map>
#include <stack>
#include <sstream>
#include <string>
#include <time.h>
#include <dirent.h>
#include <random>
#include "GraphLibrary.hpp" //precisa editar makefile para incluir essa biblioteca
#include "Estrutura_de_dados\Lista_adjacencia.hpp"
#include "Estrutura_de_dados\Vetor_adjacencia.hpp"
#include "Estrutura_de_dados\Matriz_adjacencia.hpp"
#include "Estrutura_de_dados\Estrutura_de_dados.hpp"
#include "FuncoesAuxiliares.hpp"


bool testaRaiz(int raiz){
    if(raiz>0) return true;
    return false;
}

int main(){



    int tamanho = 10;
    VectorListaAdjacencia lista;
    VectorVetorAdjacencia vector;

    lista.setSize(tamanho);
    vector.setSize(tamanho);

    cout<<"***"<<endl;
    vector.addAresta(4,5);
    lista.addAresta(4,5);
    cout<<"###"<<endl;

    for (int i = 0; i < tamanho; i++)
    {
        cout<<"tamanho do vertice "<<i<<" na lista: "<<lista.sizeVertice(i)<<endl;
        cout<<"tamanho do vertice "<<i<<" na vector: "<<vector.sizeVertice(i)<<endl<<endl;
    }

    cout<<lista.vizinhoDeVertice(4,5)<<endl;
    cout<<vector.vizinhoDeVertice(4,5)<<endl;

/*
    DIR *dir;
    string fileEntrada, fileSaida;
    vector<string> filesDados;
    struct dirent *lsdir;
    bool peso, direcao;
    int estrutura, option=0, raiz=1, nodeUm=1, nodeDois=1, entrada, iterator=0;

    vector<string> estruturas = {"ListaAdjacencia", "VetorAdjacencia", "MatrizAdjacencia"};
    vector<string> options={"Mostrar Grafo", "Saída com análise", "Diâmetro", "DFS", "Componentes Conexas", "Distância", "MST", "Excentricidade", "Sair"};

    cout<<endl;
    cout<<"********** Biblioteca de Grafos **************"<<endl<<endl;

    dir = opendir("./Dados");

    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        if(iterator>1)
            filesDados.push_back(lsdir->d_name);
        iterator++;
    }

    closedir(dir);

    inputInterface("Inicalmente escolha o arquivo que deseja abrir", filesDados, option);
    fileEntrada = "./Dados/"+filesDados.at(option-1);


    inputInterface("Escolha uma estrutura", estruturas, estrutura);

    inputInterface("Seu grafo tem peso? (Sim/ Nao) ", peso);
    inputInterface("Seu grafo é direcionado? (Sim/ Nao) ", direcao);

    Grafo newGrafo(fileEntrada,estrutura,peso,direcao);
    entrada = newGrafo.entradaOk;

    if(entrada==0){

        while(option<options.size()){

            inputInterface("Escolha uma análise para o seu grafo:", options, option);

            switch (option){

                case 1:
                    newGrafo.estruturaGrafo->show(true);
                    break;
                    
                case 2:
                    newGrafo.Saida();
                    break;
                
                case 3:
                    newGrafo.Diametro();
                    break;
                
                case 4:
                    inputInterface("Digite o valor da sua raiz: ", raiz);
                    newGrafo.DFS(raiz);
                    break;

                case 5:
                    inputInterface("Escreva um nome para o arquivo de saída (o mesmo aparecerá em Resultados após a execução e não precisa colocar a extensão): ", fileSaida, "Resultados");
                    newGrafo.ComponentesConexas(fileSaida);
                    break;

                case 6:
                    inputInterface("Qual o primeiro vértice? ", nodeUm);
                    inputInterface("Qual  o valor do segundo vértice? ", nodeDois);
                    newGrafo.Distancia(nodeUm, nodeDois);
                    break;
                
                case 7:
                    inputInterface("Digite o valor da sua raiz: ", raiz);
                    inputInterface("Escreva um nome para o arquivo de saída (o mesmo aparecerá em Resultados após a execução e não precisa colocar a extensão): ", fileSaida, "Resultados");
                    newGrafo.MST(raiz, fileSaida);
                    break;
                
                case 8:
                    inputInterface("Digite o valor da o vertíce para o qual deseja calcular a excentricidade: ", raiz);
                    newGrafo.Excentricidade(raiz);
                    break;

                default:
                    break;
            }
        
        }
    }

    return 0;*/

}