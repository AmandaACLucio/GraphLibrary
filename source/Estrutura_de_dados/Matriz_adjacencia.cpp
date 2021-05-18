#include <iostream>
#include <vector>
#include "Matriz_adjacencia.hpp"
#include "Estrutura_de_dados.hpp"


using namespace std;

MatrizAdjacencia::MatrizAdjacencia(){
    size = 1;
}

void MatrizAdjacencia::setSize(int numeroVertices){
    size = numeroVertices;
    matriz = new bool*[numeroVertices+1];
    for (int i = 0; i < numeroVertices+1; i++) {
        matriz[i] = new bool[numeroVertices+1];
        for (int j = 0; j < numeroVertices+1; j++)
            matriz[i][j] = false;
    }
}

bool MatrizAdjacencia::addAresta(int verticeUm, int verticeDois){
    
    if(matriz[verticeUm][verticeDois]==false && matriz[verticeDois][verticeUm]==false){
        matriz[verticeUm][verticeDois]=true;
        matriz[verticeDois][verticeUm]=true;
        return true;
    }
    return false;       
}

bool MatrizAdjacencia::addAresta(int verticeUm, int verticeDois, float weight){
    if(matriz[verticeUm][verticeDois]==false && matriz[verticeDois][verticeUm]==false){
        matriz[verticeUm][verticeDois]=true;
        matriz[verticeDois][verticeUm]=true;
        return true;
    }
    return false;       
}

void MatrizAdjacencia::show(){       
    for(int linha=0; linha<size+1; linha++){
        for(int coluna=0; coluna<size+1; coluna++){
            cout<<matriz[linha][coluna]<<" ";
        }
        cout<<endl;
    }    
}


        
