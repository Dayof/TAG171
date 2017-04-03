# Links de Amizade

Primeiro projeto da matéria de Teoria e Aplicação de Grafos (TAG) do semestre de 2017/1.

## Execução

Para executar este programa basta executar os seguintes comandos no terminal:

```
  $ bash run_all.sh
```

Este comando acima compila o programa utilizando o [Makefile](https://github.com/Dayof/TAG171/blob/master/Makefile) e já o executa em seguida. Caso queira só executar o programa sem necessariamente compilar, executar o seguinte comando:

```
  $ sudo make
```

## Pré-requisitos do sistema

Este programa foi implementado utilizando o sistema operacional macOS Sierra, versão 10.12.3. A linguagem de programação utilizada para implementar todo o projeto foi C++11.

## Detalhes sobre o projeto

Este programa utiliza o arquivo [amigos.txt](https://github.com/Dayof/TAG171/blob/master/amigos.txt) para gerar um grafo de ligação de amizades dos alunos da turma A de TAG de 2017/1. Este arquivo pode conter algumas inconsistências sobre as ligações pois foi gerado por humanos desatentos, portanto, o programa já trata estas inconsistências ao inserir alguma ligação a um dado vértice, deixando assim um grafo não direcionado.

### Funcionalidades

O programa realiza as seguintes funcionalidades a partir do menu principal:

- Opção 1 : Calcula todos os graus dos vértices do grafo e imprime em ordem decrescente estes dados no seguinte formato ``MATRICULA has X friends``, ``X`` representa o número de grau do vértice vinculado aquela matrícula.

- Opção 2 : Calcula o maior clique do grafo e imprime no seguinte formato ``CLIQUE DE X VERTICES \n [MATRICULA - NOME]``. Neste programa com a lista fornecida foi possível encontrar 3 cliques máximos com tamanhos iguais a 6, portanto será mostrado todos estes cliques encontrados.

- Opção 3 : Permite sair do programa.

### Fluxo do programa

- Lê os dados de matrícula, nome e ligações de cada aluno;
- Insere os dados de matrícula e nome ao vértices principais;
- Processa e insere no grafo cada referência da ligação de cada aluno;
- Conta o grau de cada vértice e guarda este dado;
- Executa o algoritmo de ``Bron-Kerbosch`` para calcular todos os cliques maximais do grafo;
- Ordena apenas os maiores cliques maximais encontrados pelo algoritmo acima;
- Mostra o menu;
- Capta opção do usuário;
- Executa ação que o usuário requisitou;
- Fecha o programa.

## Autoria

- Dayanne Fernandes da Cunha
    - E-mail: dayannefernandesc@gmail.com
    - GitHub: [Dayof](https://github.com/Dayof)
