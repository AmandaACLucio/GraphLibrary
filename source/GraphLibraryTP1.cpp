#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <fstream>
#include <map>
#include <stack>
#include <sstream>
#include <string>
#include <time.h>
#include "GraphLibrary.hpp" //precisa editar makefile para incluir essa biblioteca
#include "Estrutura_de_dados\Lista_adjacencia.hpp"
#include "Estrutura_de_dados\Vetor_adjacencia.hpp"
#include "Estrutura_de_dados\Matriz_adjacencia.hpp"
#include "Estrutura_de_dados\Estrutura_de_dados.hpp"
#include "FuncoesAuxiliares.hpp"

using namespace std;

Grafo::Grafo(string caminho, int estrutura, bool newPeso, bool newDirecionado){

    //1- lista 2-vetor 3-matriz
    direcionado = newDirecionado;
    peso = newPeso;
    numberNodes = 0;
    hasNode;
    estruturaEscolhida = estrutura;
    if(estrutura==1)  estruturaGrafo = new VectorListaAdjacencia();
    else if(estrutura==2) estruturaGrafo = new VectorVetorAdjacencia();
    else if(estrutura==3) estruturaGrafo = new MatrizAdjacencia();
    else throw current_exception;
    Entrada(caminho);
}

void Grafo::Entrada(string filename)
{
    int maior = 0;
    const char * filenameChar = filename.c_str();
    ifstream arquivoEntrada(filenameChar); // Abri arquivo para leitura
    int quantidadeDeVertices, valorUm, valorDois;
    double newPeso;
    bool realizouAdicao;
    double somaPeso=0;

    if (arquivoEntrada.is_open()) {

        arquivoEntrada >> numberNodes;

        estruturaGrafo->setSize(numberNodes);

        if (peso) {
            while(arquivoEntrada>>valorUm>>valorDois>>newPeso){

                if(newPeso<0){valueNegativo=true;}

                if(valorUm>maior){maior = valorUm;}
                if(valorDois>maior){maior=valorDois;}
                
                if(valorUm!=valorDois){

                    //se fizer a adição teremos um true
                    realizouAdicao = estruturaGrafo->addAresta(valorUm, valorDois, newPeso);
                    if (direcionado==false) estruturaGrafo->addAresta(valorDois, valorUm, newPeso); 


                    if(realizouAdicao){
                        numberArestas+=1;
                        graus[valorUm]=graus[valorUm]+1;
                        graus[valorDois]=graus[valorDois]+1;
                        somaPeso+=newPeso;
                    }
                }
            }
        }else{
            while(arquivoEntrada>>valorUm>>valorDois){
                
                if(valorUm!=valorDois){


                    //se fizer a adição teremos um true
                    realizouAdicao = estruturaGrafo->addAresta(valorUm, valorDois);
                    if (direcionado==false) estruturaGrafo->addAresta(valorDois, valorUm); 

                    if(realizouAdicao){
                        numberArestas+=1;
                        graus[valorUm]=graus[valorUm]+1;
                        graus[valorDois]=graus[valorDois]+1;
                    }
                }
            }
        }

        entradaOk = 0;

        arquivoEntrada.close();
    }else{
        cout << "ERRO: arquivo não foi aberto ou não existe" << endl;
        entradaOk = 1;
    }
}


void Grafo::Saida(string fileSaida)
{    
    //número de vértices, número de arestas, grau mínimo, grau máximo, grau médio,mediana de grau
    const char * filenameChar = fileSaida.c_str();
    ofstream arquivoSaida (filenameChar); // Cria um arquivo texto para gravação

    vector<int> grausList;
    int grauMinimo, grauMaximo = 0, sumGraus=0, grauMedio, pontoMediana, grauMediana;

    cout<<numberNodes<<endl;
    
    for(int i=1; i<=numberNodes; i++){
        
        int grauNode = graus[i];

        sumGraus+=grauNode;
        grausList.push_back(grauNode);
    }

    sort (grausList.begin(), grausList.end()); //ordena para calcular mediana


    grauMinimo=grausList.at(0);
    grauMaximo=grausList.at(grausList.size()-1);
    grauMedio = sumGraus/numberNodes;
    
    if(numberNodes%2==1){
        pontoMediana=(numberNodes-1)/2;
        grauMediana=grausList.at(pontoMediana);
    }else{
        pontoMediana=(numberNodes)/2;
        grauMediana=(grausList.at(pontoMediana)+grausList.at(pontoMediana-1))/2;
    }

    if (arquivoSaida.is_open())
    { 
        arquivoSaida << "Número de Vertíces: "<<numberNodes<<endl;
        arquivoSaida << "Número de Arestas: "<<numberArestas<<endl;
        arquivoSaida << "Grau Minimo: "<<grauMinimo<<endl;
        arquivoSaida << "Grau Máximo: "<<grauMaximo<<endl;
        arquivoSaida << "Grau Médio: "<<grauMedio<<endl;
        arquivoSaida << "Mediana de Grau: "<<grauMediana<<endl;

    }else{
        cout << "Erro ao criar arquivo de Saída."<<endl;        
    }
    arquivoSaida.close();
}

vector<vector<int>> Grafo::BFS(int raiz)
{
    vector<bool> verticesMarcados;
    vector<int> fila, marcadosList, pai, nivel;

    vector<vector<int>> retorno; // <<pai><nivel>>
    
    verticesMarcados = Popular(verticesMarcados,0, numberNodes);
    pai = Popular(pai,0, numberNodes);
    nivel = Popular(nivel,0, numberNodes);


    //marca v e inseri na fila
    pai.at(raiz)=0;
    verticesMarcados.at(raiz) = true;
    int apagamentos = 0;
    marcadosList.push_back(raiz);
    fila.push_back(raiz);
    int nivelValue = 0;

    //Enquanto a fila não estiver vazia retirar v da fila, e para todo vizinho w de v, se w não estiver marcado, marcar w e inserir w na fila

    //1- lista 2-vetor 3-matriz
    while(fila.size()!=0){

        vector<int> filhos;

        int explorado = fila.at(0);
        fila.erase(fila.begin());
        nivel.at(explorado) = nivelValue;
        nivelValue=nivel.at(pai.at(explorado))+1;
        int endFor= estruturaGrafo->sizeVertice(explorado);
        
        for(int vertice=0; vertice < endFor; vertice++){
            int filho = estruturaGrafo->vizinhoDeVertice(explorado, vertice);
            if(!verticesMarcados.at(filho)){
                pai.at(filho)= explorado;
                verticesMarcados.at(filho) = true;
                marcadosList.push_back(filho);
                fila.push_back(filho);
            }
        }
    }
    retorno.push_back(pai);
    retorno.push_back(nivel);
    retorno.push_back(marcadosList);

    return retorno;
}

vector<vector<int>> Grafo::DFS(int raiz) //DFS - Depth First Search
{
    printf("Entrando na DFS\n");
    int nivel = 0;
    stack<int>  pilhaDfs; // salvar sequencia da DFS
    bool descobertos[numberNodes+1]; // cria um vetor para identificar vertices ja vizitados
    vector<int> pai;
    vector<int> filho;
    vector<int> niv;
    vector<vector<int>> retorno; // <<pai><nivel>>
    pai.push_back(0);
    //filho.push_back(raiz);
    niv.push_back(0);

    for (int i = 0; i < numberNodes+1; i++) descobertos[i] = false; //marca todos vertices como náo descobertos 

    pilhaDfs.push(raiz);
    descobertos[raiz] = true;

    bool achou = false;
    while (!pilhaDfs.empty()) // enquanto a pilha pilhaDfs náo estiver vazia
    {
        int k = pilhaDfs.top();
        if (!(find(filho.begin(), filho.end(), k) != filho.end())){
            filho.push_back(k);
        }
        
        for (int i = 0; i <= numberNodes+1; i++)
        {
            if (!descobertos[i] && estruturaGrafo->vizinhoDeVertice(k,i))
            {
                pilhaDfs.push(i);
                pai.push_back(k);
                descobertos[i] = true;
                achou = true;
                break;
            }
        }
        if (achou)
        {
            nivel++;
            niv.push_back(nivel);
            achou = false;
            
        }else{
            //Retirando da pilha
            pilhaDfs.pop();
            nivel--;
            achou = false;
        }
        
    }
    retorno.push_back(pai);
    retorno.push_back(niv);
    retorno.push_back(filho);
    return retorno;
}

int Grafo::Grau(int vertice)
{
    return graus[vertice];
}


double Grafo::Distancia(int nodeUm, int nodeDois, string file) //Usar BFS
{
    //se não for da mesma componente retorna -1 = infinito
    vector<int> nivel;
    vector<double> distancias;
    double distancia;
    
    if(MesmaComponente(nodeUm, nodeDois)){

        if(peso){
            distancias = Dijkstra(nodeUm, nodeDois, file).second;
            distancia = distancias.at(nodeDois);
        }else{
            nivel =  BFS(nodeUm).at(1);
            distancia = nivel.at(nodeDois);
        }

        return distancia;
    }else{
        cout<<"Os vertíces não pertencem a um mesma componente"<<endl;
        return -1;
    }
}

void Grafo::Diametro(){

    vector<vector<int>> componentes;
    vector<int> maximos, nivels;
    int idComponente=0, numberComponentes = 0;

    componentes = ComponentesConexas();
    numberComponentes = componentes.at(1).at(0);
    maximos = Popular(maximos, 0, numberComponentes);

    for(int vertice=1; vertice<componentes.at(0).size(); vertice++){

        nivels = BFS(vertice).at(1);
        idComponente = componentes.at(0).at(vertice);

        if(MaximoVector(nivels)>maximos.at(idComponente)){
            maximos.at(idComponente) = MaximoVector(nivels);
        }
    }

    for(int componente=1; componente<maximos.size(); componente++){
        cout<<"Componente "<<componente<<" tem diâmetro igual a "<<maximos.at(componente)<<endl;
    }
}

vector<vector<int>> Grafo::ComponentesConexas(string filesaida) // Usar BFS
{
    vector<bool> verticesDesmarcados;
    vector<int> componente, componentesMapeadas, tamanhoComponente;
    vector<vector<int>> respostaBFS, dadosComponentes;

    int quantidadeComponente = 0;

    const char * filenameChar = filesaida.c_str();
    ofstream arquivoCC (filenameChar);
    
    //Desmarcar todos os vértices
    verticesDesmarcados=Popular(verticesDesmarcados, 0, numberNodes);
    componentesMapeadas=Popular(componentesMapeadas, 0, numberNodes);

    if (arquivoCC.is_open())
    {   

        for(int vertice=1; vertice<numberNodes+1; vertice++){
            if(!verticesDesmarcados.at(vertice)){
                quantidadeComponente+=1;
                //Escolher vértice s qualquer

                componente = BFS(vertice).at(2);
                //registrar componente
                arquivoCC<<"Componente conexa "<<quantidadeComponente<<" com "<<componente.size()<<" vertices: ";
                for(int i=0; i<componente.size(); i++){
                    arquivoCC<<componente.at(i)<<" ";
                    componentesMapeadas.at(componente.at(i))=quantidadeComponente;
                }
                arquivoCC<<endl<<endl;
                verticesDesmarcados = MapeiaIntBool(componente, numberNodes, verticesDesmarcados);
            }
        }
    }else{
        cout << "Erro ao criar arquivo de Saída."<<endl;        
    }
    arquivoCC.close();

    tamanhoComponente.push_back(quantidadeComponente);
    dadosComponentes.push_back(componentesMapeadas);
    dadosComponentes.push_back(tamanhoComponente);
    return dadosComponentes;
}

bool Grafo::MesmaComponente(int nodeUm, int nodeDois){
 
    vector<bool> verticesDesmarcados;
    vector<int> componente;

    int quantidadeComponente = 0;

    //Desmarcar todos os vértices
    verticesDesmarcados=Popular(verticesDesmarcados, 0, numberNodes);
    componente = BFS(nodeUm).at(2);
    verticesDesmarcados = MapeiaIntBool(componente, numberNodes, verticesDesmarcados);
    if(verticesDesmarcados.at(nodeDois)==false){
        return false;
    }
    return true;
}