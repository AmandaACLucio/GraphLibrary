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
#include "GraphLibrary.hpp" //precisa editar makefile para incluir essa biblioteca
#include "Estrutura_de_dados\Lista_adjacencia.hpp"
#include "Estrutura_de_dados\Vetor_adjacencia.hpp"
#include "Estrutura_de_dados\Matriz_adjacencia.hpp"
#include "Estrutura_de_dados\Estrutura_de_dados.hpp"
#include "FuncoesAuxiliares.hpp"



int main(){

    //Grafo grafo("source/grafo_W_1.txt",2,true,false);

    MatrizAdjacencia vec;
    getchar();

    vec.setSize(10);
    
    vec.addAresta(1,2,1.56);
    vec.addAresta(2,1,1.56);


    vec.addAresta(2,4,4.56);
    vec.addAresta(2,3,7.20);
    vec.addAresta(3,8,0.56);
    vec.addAresta(4,8,2.56);
    getchar();

    vec.show(true);

    pair <int, float> i = vec.vizinhoDeVertice(1,1,true);
    cout<<"Vertice: "<<i.first<<" Peso: "<<i.second<<endl;

    pair <int, float> o = vec.vizinhoDeVertice(1,2,true);
    cout<<"Vertice: "<<o.first<<" Peso: "<<o.second<<endl;

    pair <int, float> p = vec.vizinhoDeVertice(1,3,true);
    cout<<"Vertice: "<<p.first<<" Peso: "<<p.second<<endl;

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
}