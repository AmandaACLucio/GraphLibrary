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


int main(){

    DIR *dir;
    string fileEntrada, fileSaida, temPeso, ehDirecionado, nameFile;
    vector<string> filesDados;
    struct dirent *lsdir;
    bool peso, direcao;
    int estrutura, option=0, iteratoOption, raiz=1, nodeUm=1, nodeDois=1, entrada;

    cout<<"********** Biblioteca de Grafos **************"<<endl;
    cout<<"Inicalmente escolha o arquivo que deseja abrir"<<endl;

    dir = opendir("./Dados");
    iteratoOption = 1;

    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        cout<<iteratoOption<<": "<<lsdir->d_name<<endl;
        filesDados.push_back(lsdir->d_name);
        iteratoOption++;
    }

    closedir(dir);

    iteratoOption=filesDados.size();
    option=filesDados.size()+1;
    
    while(option>iteratoOption){
        cout<<"O numero do arquivo é? ";
        cin>>option;
    }

    fileEntrada = "./Dados/"+filesDados.at(option-1);


    cout<<"Escolha uma estrutura"<<endl;
    cout<<"1. Lista de Adjacência"<<endl;
    cout<<"2. Vetor de Adjacência"<<endl;
    cout<<"3. Matriz de Adjacência"<<endl;

    cout<<"Qual o número da estrutura desejada? ";
    cin>>estrutura;

    cout<<"Seu grafo tem peso? (Sim/ Não) ";
    cin>>temPeso;

    if(temPeso=="Sim") peso=true;
    else peso=false;

    cout<<"Seu grafo é direcionado? (Sim/ Não) ";
    cin>>ehDirecionado;

    if(ehDirecionado=="Sim") direcao=true;
    else direcao=false;

    Grafo newGrafo(fileEntrada,estrutura,peso,direcao);
    entrada = newGrafo.entradaOk;

    vector<string> options={"Saída com análise", "Diâmetro", "DFS", "Componentes Conexas", "Distância", "MST", "Excentricidade", "Sair"};
    
    if(entrada==0){

        while(option!=options.size()){
            cout<<"Escolha uma análise para o seu grafo:"<<endl;
            for(int i=0; i<options.size(); i++){
                cout<<i+1<<": "<<options.at(i)<<endl;;
            }
            cout<<"Qual é o número da opção? ";
            cin>>option;

            switch (option)
            {
            case 1:
                newGrafo.Saida();
                break;
            
            case 2:
                newGrafo.Diametro();
                break;
            
            case 3:
                cout<<"Digite o valor da sua raiz: ";
                cin>>raiz;
                newGrafo.DFS(raiz);
                break;

            case 4:
                cout<<"Escreva um nome para o arquivo de saída (o mesmo aparecerá em Resultados após a execução e não precisa colocar a extensão) ";
                cin>>nameFile;
                fileSaida="./Resultados/"+nameFile+".txt";
                newGrafo.ComponentesConexas(fileSaida);
                break;

            case 5:
                cout<<"Qual o primeiro vértice? ";
                cin>>nodeUm;
                cout<<endl<<"Qual o valor do segundo vértice? ";
                cin>>nodeDois;
                newGrafo.Distancia(nodeUm, nodeDois);
                break;
            
            case 6:
                cout<<"Digite o valor da sua raiz: ";
                cin>>raiz;
                cout<<"Escreva um nome para o arquivo de saída (o mesmo aparecerá em Resultados após a execução e não precisa colocar a extensão) ";
                cin>>nameFile;
                fileSaida="./Resultados/"+nameFile+".txt";
                newGrafo.MST(raiz, fileSaida);
                break;
            
            case 7:
                cout<<"Digite o valor da o vertíce para o qual deseja calcular a excentricidade ";
                cin>>raiz;
                newGrafo.Excentricidade(raiz);
                break;

            default:
                break;
            }
        
        }
    }

    return 0;

}