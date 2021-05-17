 #include <fstream>
 #include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <vector>
 #include <algorithm>
#include "Estrutura_de_dados\Estrutura_de_dados.hpp"
 #include "Estrutura_de_dados\Lista_adjacencia.hpp"

 using namespace std;

vector<int> nodes;
vector<bool> hasNode;
ListaAdjacencia listaAdjd;
int tamanhoNodes = 0;

void popularMax(int tamanho){
    cout<<"Entrou no popular"<<endl;
    cout<<"Tamanho dos nodes: "<<tamanhoNodes<<"Tamanho solicitado: "<<tamanho<<endl;
    int valor = tamanho - tamanhoNodes;
    for (int i = 1; i <= valor; i++)
    {
        cout<<"Interacao: "<<i<<endl;
        hasNode.push_back(false);
        //ListaAdjacencia novo;
        //listaAdj.push_back(novo);
    }
    tamanhoNodes = tamanho;
}

 int main ()
 {
     
    FILE *file;
        file = fopen("max.txt","rt");
        int n1;
        hasNode.push_back(false);
        listaAdj.add(4);
        
        if (file==NULL)
        {
            printf("ERRO !!");
            exit(0);
        }
        
        // add primeiro vertice
        fscanf(file,"%d ", &n1);
        printf("%d \n",n1);
        popular(n1);
        hasNode.at(n1) = true;
        getchar();
        //hasNode.at(n2) = true;
        
        while (!feof(file))    // fecha quando os arquivos acabarem
        {   
            int temp[1];
            fscanf(file,"%d%d", &temp[0],&temp[1]);

            printf("\n Aresta entre :%d %d",temp[0], temp[1]); 
            getchar();
            for (int i = 0; i <= 1; i++)
            {
                if (tamanhoNodes < temp[i])
                {
                    popular(temp[i]);
                }
                if (hasNode.at(temp[i])) //verificar se vertice n2  existe
                {  
                    cout<<"n2: "<<temp[i]<<" Esxiste "<<endl;    
                }else hasNode.at(temp[i]) = true;
                nodes.push_back(temp[i]);  
            }
            // criar aresta entre n2 e n3 
        }
 }