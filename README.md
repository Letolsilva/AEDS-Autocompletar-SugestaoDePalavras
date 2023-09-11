<h1 align="center" font-size="200em"><b>AEDS-Autocompletar-SugestaoDePalavras</b></h1>

<div align = "center" >


[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

## ✒️ Introdução
<p align="justify">
Este programa em C++ foi desenvolvido como parte do curso de Algoritmos e Estruturas de Dados I. Seu principal propósito é identificar os k elementos mais valiosos em um conjunto de dados e usar esses elementos para criar um sistema de autocompletar e sugestão de palavras para os usuários. Para atingir esse objetivo, utilizamos as estruturas de árvore binária, árvore AVL e árvore de Huffman, permitindo-nos comparar o desempenho dessas estruturas durante o desenvolvimento.
Este código incorpora a implementação da atividade anterior de AEDS. Para obter mais detalhes sobre esta parte do código, você pode acessar o seguinte link: <a href="https://github.com/Letolsilva/Top-K-Elementos.git">Top K elementos no GitHub</a>

</p>

## 💻 Objetivos

O propósito fundamental deste projeto é desenvolver e implementar estruturas de árvores com o objetivo de processar e analisar textos de forma eficiente. Essas estruturas de árvores desempenharão um papel crucial na manipulação de dados textuais, permitindo a busca, classificação, extração de informações relevantes e facilitando análises mais profundas dos conteúdos textuais. 

<strong><h4>Condições impostas: </h4></strong>
- Inicialmente, este código realiza a leitura de um arquivo de entrada denominado ```data/input(x).txt```. O arquivo contém o texto que será submetido à análise. No contexto, o valor de x é o valor de uma variável ajustável no início do arquivo ```main```, denominada numFiles. Para este código em particular, numFiles é igual a 6. Lembrando que ```data``` é a pasta criada para os arquivos de entrada.
>O professor forneceu seis textos, cujos nomes foram modificados para se adaptarem ao código, seguindo a regra do formato "data/input(x).txt". Eles foram numerados na ordem em que foram apresentados, e o mesmo padrão foi aplicado na escrita dentro do arquivo output, com o nome "arquivo x", seguindo a mesma numeração do input. Abaixo está a relação dos textos e seus respectivos nomes no formato "input(x).txt" e "arquivo x":<br>
>filosofia.txt -> input1.txt -> arquivo 1<br>
>filosofia2.txt -> input2.txt -> arquivo 2<br>
>globalizacao.txt -> input3.txt -> arquivo 3<br>
>politica.txt -> input4.txt -> arquivo 4<br>
>ti.txt -> input5.txt -> arquivo 5<br>
>ti2.txt -> input6.txt -> arquivo 6

- Para usar o sistema, o usuário deve adicionar um arquivo à pasta "data" chamado `input.data`, que contém uma lista de palavras. Cada palavra neste arquivo será tratada como um termo de pesquisa para o sistema, com uma palavra por linha.

- Existe um arquivo de ```stop words``` para análise. Sendo as stop words artigos e conjunções que podem ser alteradas de acordo com a preferência do usuário. As palavras presentes neste arquivo serão desconsideradas da contagem das top k palavras.

- Após a conclusão do processo, um arquivo denominado output.txt será automaticamente gerado para apresentar informações de saída de maneira organizada. Este arquivo incluirá o nome do arquivo que está sendo lido, da forma "Arquivo x", a palavra pesquisada e sua frequência. Além disso, haverá uma representação em ordem das três árvores com base na frequência, bem como a árvore de Huffman de acordo com o código gerado, em PosOrdem.

- Foi visto como melhor o programa seguir o padrão de abrir um arquivo, procurar todas as palavras da lista dentro dele e, em seguida, passar para o próximo. Na saída, esse padrão será seguido. Quando uma palavra da lista não estiver presente no texto, o arquivo de saída registrará a mensagem "(palavra) não encontrada no texto x" para fornecer informações claras sobre o resultado da pesquisa.

## 📄Arquivos
- <strong>Main.cpp:</strong> Na função main, inicia uma instância do topKItems, arquivos de entrada são processados e é chamado as funçoes, além de definir o tamanho do heap.
- <strong>topKElementos.hpp:</strong> Declaração das funções.
- <strong>topKELementos.cpp:</strong> Desenvolvimento das funções. 
- <strong>BinaryTree.hpp:</strong> Declara as funçoes da arvore binaria. 
- <strong>BinaryTree.cpp:</strong> Arquivo com as implementação das funções relacionadas à árvore binária.
- <strong>AVL_Tree.hpp:</strong> Declara as funçoes da arvore AVL. 
- <strong>AVL_Tree.cpp:</strong> Arquivo com as implementação das funções relacionadas à árvore AVL.
- <strong>HuffmanTree.hpp:</strong> Declara as funçoes da arvore de Huffman. 
- <strong>HuffmanTree.cpp:</strong> Arquivo com as implementação das funções relacionadas à árvore de HUffman.
- <strong>data/input.txt:</strong> Texto de entrada.
- <strong>data/stopwords.txt:</strong> Stop words, como por exemplo, para artigo (a, o, as,os) e para conjunções (e, ou).

## 🔨Resolução do problema

Visando encontrar uma solução eficiente e rápida para resolução do problema, foram usadas as seguintes estruturas de dados:

As mesmas estruturas utilizadas no trabalho de topKItems continuaram sendo usada para localizar as tops K palavras mais frequentes para esta atividade do autocompletar, você pode acessar pelo link:  <a href="https://github.com/Letolsilva/Top-K-Elementos.git">Top K elementos no GitHub</a>

<h3><b>Árvore Binária</b></h3>

Uma árvore binária é uma estrutura de dados não linear que segue um padrão hierárquico, onde cada nó pode ter no máximo dois filhos, um à esquerda e outro à direita. Cada nó em uma árvore binária contém uma referência para seus filhos esquerdo e direito, além de armazenar um elemento de dados. O nó no topo da hierarquia é conhecido como o nó raiz da árvore.

Em uma árvore de pesquisa binária, o valor do nó esquerdo deve ser menor que o nó pai e o valor do nó direito deve ser maior que o nó pai. Esta regra é aplicada recursivamente às subárvores esquerda e direita da raiz. 
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/c972b72b-8335-4228-aa84-d327961e4820" width="500px" />
</div>
Na figura acima, podemos observar que o nó raiz é 40, e todos os nós da subárvore esquerda são menores que o nó raiz, e todos os nós da subárvore direita são maiores que o nó raiz.

Neste código os valores iguais a raiz, são direcionados para a esquerda, a escolha de direcionar elementos iguais para a esquerda foi feita após observações que demonstraram que essa abordagem resultava em uma árvore mais balanceada. Isso foi confirmado através de testes realizados com os textos fornecidos. 

As imagens abaixo poderá ser observado a complexidade de tempo e espaço da árvore de pesquisa binária. Veremos a complexidade de tempo para operações de inserção, exclusão e pesquisa no melhor caso, no caso médio e no pior caso. Onde 'n' é o número de nós na árvore fornecida.

<h4>Complexidade de tempo:<h4>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/5764665c-0b57-4f70-ab4b-a1b667e98e7a" width="600px" />
</div>

<h4>Complexidade de espaço:<h4>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/d25f271e-c25d-402b-9b0e-351dfcc16c7f" width="600px" />
</div>

<h3><b>Árvore AVL</b></h3>
A árvore AVL pode ser definida como uma árvore de pesquisa binária com altura balanceada em que cada nó está associado a um fator de equilíbrio que é calculado subtraindo a altura de sua subárvore direita daquela de sua subárvore esquerda.

Diz-se que a árvore está balanceada se o fator de equilíbrio de cada nó estiver entre -1 e 1, caso contrário, a árvore ficará desequilibrada e precisará ser balanceada.

- Se o fator de equilíbrio de qualquer nó for 1, significa que a subárvore esquerda está um nível acima da subárvore direita.

- Se o fator de equilíbrio de qualquer nó for 0, significa que a subárvore esquerda e a subárvore direita contêm altura igual.

- Se o fator de equilíbrio de qualquer nó for -1, significa que a subárvore esquerda está um nível abaixo da subárvore direita.

Uma árvore AVL é fornecida na figura a seguir. Podemos ver que o fator de equilíbrio associado a cada nó está entre -1 e +1. portanto, é um exemplo de árvore AVL.
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/2544b8e5-2203-445a-8a10-6fc6f597ccfa" width="400px" />
</div>
Pode-se observar que os filhos da esquerda continuam sendo menores que seus pais e os filhos da direita maiores. No código da árvore AVL, foi uma decisão direcionar os filhos iguais para a direita, com o objetivo de obter resultados mais precisos e alinhados com as expectativas ao confirmá-los nos softwares de gerador de árvores AVL.

<h4><b>Rotações</b></h4>

Realizamos rotação na árvore AVL apenas caso o Balance Factor seja diferente de -1, 0 e 1 . Existem basicamente quatro tipos de rotações que são as seguintes:

- Rotação LL: o nó inserido está na subárvore esquerda da subárvore esquerda de A
- Rotação RR: o nó inserido está na subárvore direita da subárvore direita de A
- Rotação LR: o nó inserido está na subárvore direita da subárvore esquerda de A
- Rotação RL: o nó inserido está na subárvore esquerda da subárvore direita de A
Onde o nó A é o nó cujo fator de equilíbrio é diferente de -1, 0, 1.

As duas primeiras rotações LL e RR são rotações simples e as próximas duas rotações LR e RL são rotações duplas. Para uma árvore ficar desequilibrada a altura mínima deve ser no mínimo 2.
<h4><b>Complexidade</b></h4>
A árvore AVL controla a altura da árvore de pesquisa binária, não permitindo que ela seja distorcida. O tempo necessário para todas as operações em uma árvore de pesquisa binária de altura h é O(h) . No entanto, pode ser estendido para O(n) se o BST ficar distorcido (ou seja, pior caso). Ao limitar esta altura ao log n, a árvore AVL impõe um limite superior em cada operação como O (log n), onde n é o número de nós.

<h3><b>Árvore Huffman</b></h3>

Codificação Huffman é uma técnica de compactação de dados para reduzir seu tamanho sem perder nenhum detalhe. Foi desenvolvido pela primeira vez por David Huffman. A codificação Huffman geralmente é útil para compactar os dados nos quais há caracteres que ocorrem com frequência.

Neste código, utilizamos as palavras e suas frequências para criar uma árvore. O processo de codificação de Huffman inicia-se com a construção de uma árvore com base nas frequências das palavras. Posteriormente, essa árvore é usada para gerar códigos individuais para cada palavra. A codificação de Huffman é gerada atribuindo "1" quando se move para a direita na árvore e "0" quando se move para a esquerda. Essa abordagem de codificação é usada para criar o código correspondente a cada palavra na árvore de Huffman.
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/27bb9e0f-0557-4851-b2da-8020be32f30f" width="500px" />
</div>

Para decodificar o código, podemos pegar o código e percorrer a árvore para encontrar o caractere. Seja 101 para ser decodificado, podemos percorrer a partir da raiz como na figura abaixo.
<h4><b>Complexidade</b></h4>
A complexidade de tempo para codificar cada string única com base em sua frequência é O(nlog n).
A extração da frequência mínima da fila de prioridade ocorre 2*(n-1)várias vezes e sua complexidade é O(log n). Assim, a complexidade geral é O(nlog n).


## 🔨 Funções 
<div align="justify">

- `VerificaArvoreECria:`A função recebe como entrada um arquivo contendo uma lista de palavras que o usuário deseja pesquisar em um texto. Para cada palavra lida, ela verifica se a palavra está presente no texto e se possui uma contagem positiva. Se a palavra existe e tem uma contagem positiva, a função a processa para atualizar uma estrutura de dados chamada "heap" que captura as k+1 palavras mais relevantes. Se a palavra da lista já está no heap, ela é excluída e o heap mantém apenas as k palavras mais relevantes. Se a palavra não está no heap, a palavra menos relevante (na posição 0) é excluída, mantendo o heap com k elementos.
Se a palavra não existe no texto ou tem uma contagem zero, a função não cria uma estrutura de árvore para ela e passa para a próxima palavra. Além disso, a função cria três tipos diferentes de árvores (uma árvore básica, uma árvore AVL e uma árvore de Huffman) com base no heap e suas contagens e escreve informações formatadas em um arquivo de saída. 

- `headerOutput:` é responsável por criar um cabeçalho formatado em um arquivo de saída, utilizado para registrar informações sobre a frequência de palavras em vários arquivos de texto. 

- `CreatTree e insertTree:` A `creatTree` tem como objetivo criar uma árvore binária de busca a partir de do heap com as top K palavras. Ela inicializa um ponteiro para o nó raiz como nulo, percorre o vetor de pares e insere cada par na árvore por meio da função insertTree da instância arvore. A função `insertTree` faz parte de uma classe chamada basicTree e é responsável por inserir um nó em uma árvore binária de busca de acordo com a regra de ordenação baseada na frequência da palavra. Se o nó atual for nulo, um novo nó é criado com os dados da palavra e inserido ali. Caso contrário, a função compara a frequência da palavra com a do nó atual e a insere na subárvore esquerda se for menor/igual ou na subárvore direita se for maior. Isso mantém a árvore organizada pela frequência das palavras. Em seguida imprime uma árvore binária de busca a partir dos dados fornecidos no vetor, registrando-a em um arquivo de saída em Posordem.

- `CreatAVL e insertAVL:` CreatAVL é responsável por criar uma Árvore AVL (Árvore de Busca Binária Equilibrada) a partir do heap utilizado no trabalho anterior para capturar as top K palavras. Ela começa declarando um ponteiro root para a raiz da árvore AVL como nulo. Em seguida, ela itera através do vetor e insere cada par na árvore AVL por meio da função insertAVL da instância arvoreAVL. `insertAVL` é utilizada para inserir um novo nó em uma Árvore AVL de acordo com a frequência associada à palavra. O código inicia verificando se o nó atual (*t) é nulo. Se for nulo, um novo nó é criado com os dados da palavra e os ponteiros left e right são inicializados como nulos. Além disso, o campo weight do nó é definido como 0. Se o nó não for nulo, a função compara a frequência da palavra com a do nó atual e insere a palavra na subárvore esquerda ou direita, dependendo da comparação. Após a inserção, a função verifica se o fator de equilíbrio da árvore foi violado e, se necessário, realiza rotações para restaurar o equilíbrio da árvore. Finalmente, o campo weight do nó é atualizado para refletir a altura da subárvore enraizada no nó atual. Esta funçao utiliza de varias funções como `rotacaoSimplesDireita`, `rotacaoSimplesEsquerda`, `rotacaoDuplaDireita` e `rotacaoDuplaEsquerda` para manter a árvore balanceada. Essas funções são chamadas quando ocorrem violações do fator de equilíbrio da árvore durante a inserção de um novo nó. Além das funçoes `getWeight` e ` getMaxWeight` que auxiliam no cálculo e na atualização das alturas das subárvores em uma árvore AVL. Após a construção da árvore AVL, a função escreve uma mensagem indicando a criação da árvore no arquivo de saída.

- `CreatHuffman, HuffmanCodes, generateHuffmanTree e printCodes:` A função CreatHuffman é usada para criar uma árvore de Huffman a partir do vetor heap e registrá-la em um arquivo de saída. Primeiro, a função determina o tamanho do vetor vectorHuffmanTree e cria dois arrays: um para armazenar as palavras (word) e outro para armazenar as frequências (freq). Em seguida, ela copia os valores das palavras e frequências do vetor vectorHuffmanTree para esses arrays. Logo, após a função HuffmanCodes da instância arvoreHuffman é chamada para construir a árvore de Huffman. A função `HuffmanCodes` pertence à classe HuffmanTree e é responsável por gerar códigos de Huffman para um conjunto de palavras com base em suas frequências e registrá-los em um arquivo de saída. Ela inicia criando uma fila de prioridade (priority_queue) de nós Huffman, onde cada nó representa uma palavra e sua frequência. Em seguida, percorre o conjunto de palavras e suas frequências, criando um nó Huffman para cada palavra e inserindo-o na fila de prioridade. Depois, a função chama outra função chamada `generateHuffmanTree` para construir a árvore de Huffman a partir dos nós na fila de prioridade. Ela opera em um loop até que reste apenas um nó na fila, o qual se tornará a raiz da árvore de Huffman. A cada iteração, ela remove os dois nós de maior prioridade (menor frequência) da fila, que representam as palavras menos frequentes. Em seguida, cria um novo nó combinado que não tem uma palavra associada, mas possui a soma das frequências dos nós removidos. Esse novo nó tem os nós removidos como filhos (esquerdo e direito) e é inserido de volta na fila de prioridade. O processo continua até que reste apenas um nó na fila, que representa a raiz da árvore de Huffman completa. Uma vez que a árvore é construída, a função chama `printCodes` para gerar os códigos de Huffman para as palavras e registrá-los no arquivo de saída. Esses códigos são usados para representar as palavras de forma mais eficiente, onde palavras mais frequentes recebem códigos mais curtos. Posteriormente, a função `CreatHuffman` escreve uma mensagem indicando a criação da árvore de Huffman no arquivo de saída.

- `printPosOrder:` Esta função imprime as árvores no formato Posordem. No arquivo de saída, todas as árvores foram impressas nessa ordem, organizadas de acordo com sua frequência.

- `print(nome da arvore)Levels:` Essa função tem o objetivo de imprimir a árvore em níveis, permitindo a verificação da sua estrutura para garantir sua correção. Embora não seja utilizada no código principal, ela pode ser chamada a qualquer momento para analisar a organização da árvore.
## 🎯Resultados

Este código foi testado com 12 palavras na lista (input.txt) e 6 textos. Para analise dos resultados, iremos pegar a palavra da lista "assim" e analisar ela no texto 6, no qual ela apareceu 201 vezes.

Primeiramente vamos configurar na main, para seis arquivos e o nosso K valendo 20.
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/345e826c-c91c-4ca3-9b98-480c35ed2d31" width="500px" />
</div>

Inicialmente, o nosso heap terá k+1 palavras para passar pelo processo de verificação já mencionado nas funções acima. Basicamente, esse processo consiste em verificar se a palavra existe no texto e se está dentro do heap, e as modificações necessárias serão feitas.

<h3><b>Top K+1 palavras do texto 6</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/0942937c-7305-4ce3-a11e-455d99d1520a" width="300px" />
</div>

Após processarmos o heap para verificar as palavra "assim", obtemos o seguinte novo heap:

<h3><b>Heap usado para a criação das árvores</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/c31daba0-9fb3-4f83-8961-8ea53ae10e82" width="300px" />
</div>

Já sabemos que esta palavra se encontra no texto seis e também aparece no seu heap, portanto essa palavra não será considerada nas contruções das árvores.

As imagens a seguir vão ser as saídas printadas por níveis no terminal, para analisarmos se a contrução da árvore esta correta e análise do tempo da construção de cada árvore.

<h3><b>Saída árvore binária por níveis:</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/9a246c6d-3516-4291-b162-64eb4635740f" width="500px" />
</div>

<h3><b>Saída árvore AVL por níveis:</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/110b1473-8012-4279-a23e-5ec7dcce58a8" width="600px" />
</div>

<h3><b>Saída árvore Huffman por níveis:</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/9b8a354d-4e3a-47ff-9051-1947a902579a" width="600px" />
</div>

As saídas por níveis fornecidas são úteis para visualizar e validar as estruturas das árvores criadas no programa. 

Após a criação das árvores, elas foram registradas em um arquivo chamado "output.txt" e impressas na forma Posordem. Como exemplo, a saída da palavra "assim" do texto 6 ficou da seguinte forma:
<h3><b>Saída no output:</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/8a237244-d661-4ae8-a57a-c8301989c56a" width="800px" />
</div>
Todo o output segue um padrão consistente, onde são apresentados o texto ao qual a palavra pertence, a própria palavra da lista e sua frequência. Logo abaixo, são impressas as três árvores exibidas na forma Posordem. Esse método de impressão foi escolhido porque na árvore de Huffman as palavras são impressas seguindo este criterio, e para manter a lógica, as outras árvores também seguem este padrão.

<h3><b>Tempo de execução</b></h3>
O código foi executado em um notebook Acer Nitro 5 com processador Ryzen 7.
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/24c99777-6a53-4973-a487-e85be4b3ae61" width="300px" />
</div>

## ✔️Conclusão
Cada uma dessas estruturas de dados possui características distintas que podem ser mais adequadas para diferentes cenários.

A Árvore Binária Padrão, por exemplo, é simples de implementar, fácil de entender e útil para várias operações de pesquisa. No entanto, ela não é eficiente em algumas operações em texto, como a busca por palavras frequentes, devido à falta de balanceamento automático.

A Árvore AVL, por outro lado, mantém o balanceamento automático, garantindo tempos de pesquisa razoáveis, mesmo em grandes conjuntos de dados. Embora seja mais complexa do que a árvore binária padrão, do meu ponto de vista, em termos de complexidade de tempo e espaço, a Árvore AVL seria uma excelente escolha para a implementação deste código. A Árvore AVL destaca-se quando a eficiência da pesquisa é crítica, especialmente em cenários que envolvem textos extensos e inúmeras operações de busca.

Por último, a Árvore de Huffman é ideal para compactação de texto, gerando códigos binários eficientes para palavras com base em suas frequências, o que parece se encaixar perfeitamente na demanda desta implementação. No entanto, é importante notar que ela não é adequada para a pesquisa de palavras individuais em um texto, pois não foi projetada para essa finalidade.

Vale ressaltar que, ao tentar cronometrar o tempo de execução da construção de cada árvore, todas elas apresentaram um tempo de execução muito rápido, indicando eficiência no processamento e construção das estruturas. porém em termos de complexidade de tempo, foi possível observar que a Árvore AVL demonstrou o melhor desempenho.

## 🚨Importante

- Antes de compilar o código, é essencial definir dois parâmetros no arquivo main.cpp localizados no início do código: o valor de `k` (linha 10), que representa o tamanho do heap, e o número de arquivos que serão lidos numFiles (linha 9). 

- Certifique-se de ter os textos desejados armazenados na pasta data, nomeados como input(número do arquivo).txt, sendo que o número do arquivo deve começar a partir de 1 e incrementar sequencialmente. Na pasta main, escolha o número adequado de arquivos a serem lidos.

- Adicionar a lista de palavras que deseja pesquisar com o nome "input.txt".

- O programa irá gerar um arquivo chamado "output.txt" dentro da pasta denominada "src", onde serão apresentadas as árvores criadas para as palavras.


## 👾Compilação e execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Após temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

## ✔️Referências
https://www.javatpoint.com/binary-search-tree<br>
https://www.javatpoint.com/avl-tree<br>
https://www.programiz.com/dsa/huffman-coding

## Contato

<div>
 <br><p align="justify"> Letícia de Oliveira Silva</p>
 <a href="https://t.me/letolsilva">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:letolsilva22@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>letolsilva22@gmail.com</i>
</a>



