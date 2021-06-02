# Graph-Library
Biblioteca construída em clang-x64 com c++17, sendo testado no compilador mingw64 por Amanda Lucio e Lucas Máximo.

## Table of Contents:
- [Como usar](#Como-usar)
  - [Atributos da classe](#Atributos-da-classe)
  - [Criação de objeto](#criacao-de-objetos)
- [Representações](#Representações)
  - [Estrutura de Dados](#Estrutura-de-Dados)
  - [Lista de Adjacência](#Lista-de-Adjacência)
  - [Vetor de Adjacência](#Vetor-de-Adjacência)
  - [Matriz de Adjacência](#Matriz-de-Adjacência)
- [Métodos](#Métodos)
  - [BFS](#bfs)
  - [DFS](#dfs)
  - [Componentes Conexas](#Componentes-Conexas)
  - [Diâmetro](#Diâmetro)
  - [Distância](#Distância)
  - [Dijkstra](#Dijkstra)
  - [MST](#MST)
  - [Excentricidade](#Excentricidade)
- [Como rodar](#Como-Rodar)
- [Estudos de Caso](#Estudos-de-Caso)


## Como usar
A biblioteca é criada à partir da classe Grafos. Nesta foram adicionado métodos e atríbutos que facilitem a experiência do usuário. 

### Atributos da classe
A classe contém alguns atributos principais:

- Inteiro estruturaEscolhida: Permite a escolha entre [1 (Lista de Adjacência)](#Lista-de-Adjacência), [2 (Vetor de Adjacência)](#Vetor-de-Adjacência) e [3 (Matriz de Adjacência)](#Matriz-de-Adjacência) 
- EstruturaDeDados *estruturaGrafo: Objeto da classe virtual [EstruturaDeDados](#Estrutura-de-Dados) que criará a estrutura 
- Booleano Peso: É verdadeiro se tiver peso
- Booleano Direcionado: É verdadeiro se for direcionado

### Criação de objetos
Ao passar parâmetros para criação do objeto a inicialização chama o método entrada e cria um objeto do tipo [EstruturaDeDados](#Estrutura-de-Dados). A chamada será:

Grafo(string pathOfFile, int estrutura, bool Peso, bool 
Direcionado)

## Representações
A biblioteca pode representar grafos usando Lista de Adjacência, Vetor de Adjacência e Matriz de Adjacência.

### Estrutura de Dados
A classe virtual EstruturaDeDados Foi criado as três estruturas de dados, lista de adjacência, matriz de adjacência e vetor de adjacência, Evitando a utilização de bibliotecas de estruturas de dados já prontas, com objetivo de se obter mais controle sobre o retorno das funções. 

### Lista de Adjacência
Através de abstração, VectorListaAdjacencia foi construído como uma subclasse de EstruturaDeDados. Ela representa uma vetor com várias listas de adjacência. Entre os métodos abstraídos dentro da classe temos: addAresta (adiciona aresta ordenanda), show (mostra o que está contido no vetor) e vizinhoDeVertice(chama o vizinho de um vertíce em determinada posição). 

### Vetor de Adjacência
Através de abstração, VectorVetorAdjacencia foi construído como uma subclasse de EstruturaDeDados. Ela representa uma vetor com vários vetores de adjacência. Entre os métodos abstraídos dentro da classe temos: addAresta (adiciona aresta ordenanda), show (mostra o que está contido no vetor) e vizinhoDeVertice(chama o vizinho de um vertíce em determinada posição).

### Matriz de Adjacência
Através de abstração, MatrizAdjacencia foi construído como uma subclasse de EstruturaDeDados. Ela representa um array n por n, sendo n o número de vértices. Entre os métodos abstraídos dentro da classe temos: addAresta (adiciona aresta ordenanda), show (mostra o que está contido no vetor) e vizinhoDeVertice(chama o vizinho de um vertíce em determinada posição).

## Métodos
Foram implementados vários métodos para a classe grafo. Temos:

### BFS
O BFS (Breadth First Search) pode percorrer o gráfico a partir de um determinado nó (início) e executar todos os nós conectados a este vértice. Esta função pode nos dar a árvore geradora, dando o pai (que descobriu o nó) e seu grau (grau do pai +1). Essa função também pode nos fornecer o caminho mais curto do início do nó até um vértice.

### DFS
O DFS (Depth First Search) pode percorrer o gráfico como o [BFS] (# bfs), mas diferente desta, ele explora o vertíce mais recente e não o mais antigo. Desta forma, ela vai o mais longe possível em um galho e depois volta a um ponto fixo.

### Componentes Conexas
Esta função nos dá o número de componentes conectados de um gráfico e o vértice que pertence a cada componente em um txt. A função funciona rodando um bfs simples em um vértice, e após, dentro de um loop for, é só verificar se o próximo foi visitado. Se sim, basta verificar o próximo. Se não, execute o bfs para este vértice. O processo até que todos os vertíces sejam avaliados.

### Diâmetro
Esta função retorna o diâmetro de um gráfico (O caminho mínimo máximo entre dois vértices). Assim, a implementação consistiu em executar um [BFS] (# bfs) para cada vértice do grafo, e retornar o maior valor possível entre dois nós.

### Distância
A distância é o caminho mais curto de um vértice a ao vértice b. Assim, a implementação consistiu em usar um simples [BFS](#bfs) (para grafos sem peso) e [Dijkstra](#Dijkstra) (para grafos com peso) e medir a distância entre a e b.

### Dijkstra
O Dijkstra é uma forma de percorrer o gráfico como o [BFS] (# bfs), buscando o menor caminho. A diferença está no fato do algoritmo escolher o caminho mais curto entre um vértice e seus vizinhos através do peso. Buscando, desta forma, a aresta de menor peso. Essa implementação retorna no formato txt de grafo uma árvore com o menor caminho. Assim como o custo do menor caminho no fim desse arquivo. OBS: só viável se seu gráfico for conexo e seu peso for positivo.

### MST
O algorítmo utilizado para construção da MST (Minimum Spanning Tree) foi o Prim. Ele funciona como o algoritmo de Dijkstra, a diferença está na comparação dos tamanhos, pois ao invés de comparar a distância da origem do vertíce com a distância da origem do vertíce mais o valor da aresta, se compara o peso da aresta registrado com o peso da aresta encontrado.

## Como rodar

Foi desenvolvida uma interface simples com menu para rodar o programa. Os resultados serão mostrados na pasta Resultados e seus grafos devem ser colocados na pasta dados. Para utilizar a interface, é necessário fazer uma configuração prévia no SO utilizado.

- Windows: Para rodar o programa você pode utilizar a pasta no .vscode, alterando o caminho para seu diretório e para seu compilador no arquivos json task e settings. Para rodar, basta usar o atalho ctrl+shift+p e rodar a nova task.

- Linux: Você pode utilizar o makefile para gerar o arquivo executável. Nesse caso, só precisa de utilizar o comando make interface.

## Estudos de Caso
Abaixo você pode ver os grafos usados para estudo de caso:
- Grafos sem peso:
  - [grafo_1.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_1.txt.gz)
  - [grafo_2.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_2.txt.gz)
  - [grafo_3.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_3.txt.gz)
  - [grafo_4.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_4.txt.gz)
  - [grafo_5.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_5.txt.gz)
  - [grafo_6.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_6.txt.gz)
- Grafos com Peso:
  - [grafo_1.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_1.txt)
  - [grafo_2.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_2.txt)
  - [grafo_3.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_3.txt)
  - [grafo_4.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_4.txt)
  - [grafo_5.txt](https://www.cos.ufrj.br/~daniel/grafos/data/grafo_5.txt)
  - [rede_colaboracao.txt](https://www.cos.ufrj.br/~daniel/grafos/data/rede_colaboracao.txt)
  - [rede_colaboracao_vertices.txt](https://www.cos.ufrj.br/~daniel/grafos/data/rede_colaboracao_vertices.txt)
  
