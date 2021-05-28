#include <iostream>
#include <vector>
#include <cmath>
#include "Matriz_adjacencia.hpp"
#include "Estrutura_de_dados.hpp"


using namespace std;

MatrizAdjacencia::MatrizAdjacencia(){
    size = 1;
}

void MatrizAdjacencia::setSize(int numeroVertices){

    size = numeroVertices;
}

bool MatrizAdjacencia::addAresta(int verticeUm, int verticeDois){

    if(inicializada==false){
        matriz = new bool*[size+1];
        for (int i = 0; i < size+1; i++) {
            matriz[i] = new bool[size+1];
            for (int j = 0; j < size+1; j++)
                matriz[i][j] = false;
        }
        inicializada=true;       
    }


    if(matriz[verticeUm][verticeDois]==false && matriz[verticeDois][verticeUm]==false){
        matriz[verticeUm][verticeDois]=true;
        matriz[verticeDois][verticeUm]=true;
        return true;
    }
    return false;       
}

bool MatrizAdjacencia::addAresta(int verticeUm, int verticeDois, float weight){

    if(inicializada==false){

        matrizWeight = new float*[size+1];
        for (int i = 0; i < size+1; i++) {
            matrizWeight[i] = new float[size+1];
            for (int j = 0; j < size+1; j++){
                matrizWeight[i][j] = nan("");
            }
        }
        inicializada=true;
    }

    if(isnan(matrizWeight[verticeUm][verticeDois]) && isnan(matrizWeight[verticeDois][verticeUm])){
        matrizWeight[verticeUm][verticeDois]=weight;
        matrizWeight[verticeDois][verticeUm]=weight;
        return true;
    }
    return false;       
}

void MatrizAdjacencia::show(bool weight){
    
    if(weight){
        for(int linha=0; linha<size+1; linha++){
            for(int coluna=0; coluna<size+1; coluna++){
                cout<<matrizWeight[linha][coluna]<<" ";
            }
            cout<<endl;
        }        
    }else{
        for(int linha=0; linha<size+1; linha++){
            for(int coluna=0; coluna<size+1; coluna++){
                cout<<matrizWeight[linha][coluna]<<" ";
            }
            cout<<endl;
        }         
    }
}
pair <int,float> MatrizAdjacencia::vizinhoDeVertice(int vertice, int posicaoVizinho){
    
}


int MatrizAdjacencia::sizeVertice(int vertice){

}


        
