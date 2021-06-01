﻿#include <iostream>
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

    
    Grafo grafo("Dados/grafo_W_5.txt",1,true,false);

    int randdd = grafo.numberNodes;
    clock_t inicio, fim;
    double tempoTotal;
    int interacoes = 10;

    vector<clock_t> tempos;
    
    
    int arr[] = { 10, 20, 30, 40, 50 };
  
    for (int x : arr){
        inicio= clock();
        int s = grafo.Excentricidade(x);
        fim= clock();
        double time_spent = (double)(fim - inicio) / CLOCKS_PER_SEC;
        cout<<"Rodou a excentricidade do vertice "<<x<<" em "<<time_spent<<" segundos - Resultado: "<<s<<endl;
    }











}
/*
    for (int i = 0; i < interacoes; i++)
    {
        inicio= clock();
        int aleatorio = rand() % randdd;
        grafo.Excentricidade(aleatorio);
        fim= clock();
        double time_spent = (double)(fim - inicio) / CLOCKS_PER_SEC;
        cout<<"Rodou a excentricidade do vertice "<<aleatorio<<" em "<<time_spent<<" segundos"<<endl;
        tempos.push_back(time_spent);
        tempoTotal += time_spent;
    }

    cout<<"Tempo medio: "<<(tempoTotal/interacoes)<<endl;
    //Grafo grafo("./Dados/rede_colaboracao.txt",1,true,false);
    
    Grafo grafo("./Dados/grafo_W_5.txt",2,true,false);

    //grafo.Distancia(1,4340321);

    //grafo.ComponentesConexas();


/*     clock_t inicio, fim;
    inicio= clock();
    grafo.MST();
    fim= clock();
    double Tempo = (fim-inicio)*1000.0/CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo); */


    /*     vector<int> v1 = {20, 30, 40, 25, 15, 50};
        
        // Converting vector into a heap
        // using make_heap()
        make_heap(v1.begin(), v1.end(),  greater<>{});
        cout << "The maximum element of heap is : ";
        cout << v1.front() << endl;



        Grafo grafo("Dados/grafo_W_4.txt",2,true,false);
    */    


    /////////NÃO DELETAR DAQUI PRA BAIXO ////////////

    /* DIR *dir;
    string fileEntrada, fileSaida, temPeso, ehDirecionado;
    vector<string> filesDados;
    struct dirent *lsdir;
    bool peso, direcao;
    int estrutura, option=0, iteratoOption;

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
    cout<<"O numero do arquivo é? ";
    cin>>option;
    fileEntrada = filesDados.at(option-1);


    cout<<"Escolha uma estrutura"<<endl;
    cout<<"1. Lista de Adjacência"<<endl;
    cout<<"2. Vetor de Adjacência"<<endl;
    cout<<"3. Matriz de Adjacência"<<endl;

    cout<<"Qual o número da estrutura desejada?";
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

    vector<string> options={"Saída com análise", "Menor Caminho", "DFS", "Componentes Conexas", "Distância", "MST", "Sair"};

    while(option!=options.size()){
        cout<<"Escolha uma análise para o seu grafo"<<endl;
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
        
        default:
            break;
        }
    
    } */

/*
    Grafo grafo("source/grafo_W_1.txt",1,true,false);
    grafo.estruturaGrafo->show(true);

     int estrutura = 1;
    clock_t inicio, fim;
    inicio= clock();
    Grafo teste("Dados/grafo_1.txt", estrutura);
    fim= clock();
    printf ( "tempo gasto %f segundos para o grafo 1:\n",((double)( fim - inicio ) / ((double)CLOCKS_PER_SEC )));
    inicio= clock();
    Grafo teste2("Dados/grafo_2.txt", estrutura);
    fim= clock();
    printf ( "tempo gasto %f segundos para o grafo 2:\n",((double)( fim - inicio ) / ((double)CLOCKS_PER_SEC )));
    inicio= clock();
    Grafo teste3("Dados/grafo_3.txt", estrutura);
    fim= clock();
    printf ( "tempo gasto %f segundos para o grafo 3:\n",((double)( fim - inicio ) / ((double)CLOCKS_PER_SEC )));
    inicio= clock();
    Grafo teste4("Dados/grafo_4.txt", estrutura);
    fim= clock();
    printf ( "tempo gasto %f segundos para o grafo 4:\n",((double)( fim - inicio ) / ((double)CLOCKS_PER_SEC )));
    inicio= clock();
    Grafo teste5("Dados/grafo_5.txt", estrutura);
    fim= clock();
    printf ( "tempo gasto %f segundos para o grafo 5:\n",((double)( fim - inicio ) / ((double)CLOCKS_PER_SEC )));
    inicio= clock();
    Grafo teste6("Dados/grafo_6.txt", estrutura);
    fim= clock();
    printf ( "tempo gasto %f segundos para o grafo 6:\n",((double)( fim - inicio ) / ((double)CLOCKS_PER_SEC ))); */
//}