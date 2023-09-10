<h1 align="center" font-size="200em"><b>AEDS-Autocompletar-SugestaoDePalavras</b></h1>

<div align = "center" >


[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

## ✒️ Introdução
<p align="justify">
Este programa em C++ foi desenvolvido como parte do curso de Algoritmos e Estruturas de Dados I. Seu principal propósito é identificar os k elementos mais valiosos em um conjunto de dados e usar esses elementos para criar um sistema de autocompletar e sugestão de palavras para os usuários. Para atingir esse objetivo, utilizamos as estruturas de árvore binária, árvore AVL e árvore de Huffman, permitindo-nos comparar o desempenho dessas estruturas durante o desenvolvimento.
</p>

## 💻 Objetivos

O propósito fundamental deste projeto é desenvolver e implementar estruturas de árvores com o objetivo de processar e analisar textos de forma eficiente. Essas estruturas de árvores desempenharão um papel crucial na manipulação de dados textuais, permitindo a busca, classificação, extração de informações relevantes e facilitando análises mais profundas dos conteúdos textuais. 

<strong><h4>Condições impostas: </h4></strong>
- Inicialmente, este código realiza a leitura de um arquivo de entrada denominado ```data/input(x).txt```. O arquivo contém o texto que será submetido à análise. No contexto, o valor de x é o valor de uma variável ajustável no início do arquivo ```main```, denominada numFiles. Para este código em particular, numFiles é igual a 6. Lembrando que ```data``` é a pasta criada para os arquivos de entrada.

- Para usar o sistema, o usuário deve adicionar um arquivo à pasta "data" chamado `input.data`, que contém uma lista de palavras. Cada palavra neste arquivo será tratada como um termo de pesquisa para o sistema, com uma palavra por linha.

- Existe um arquivo de ```stop words``` para análise. Sendo as stop words artigos e conjunções que podem ser alteradas de acordo com a preferência do usuário. As palavras presentes neste arquivo serão desconsideradas da contagem das top k palavras.

- Após a conclusão do processo, um arquivo denominado output.txt será automaticamente gerado para apresentar informações de saída de maneira organizada. Este arquivo incluirá o nome do arquivo que está sendo lido, a palavra pesquisada e sua frequência. Além disso, haverá uma representação em ordem das três árvores com base na frequência, bem como a árvore de Huffman de acordo com o código gerado.

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
As mesmas estruturas utilizadas no trabalho de topKItems continuaram sendo usada para locaçizar as tops K palavras.

<h3><b>Unodered_map</b></h3>

`std:unordered_map` é um contêiner associativo que contém pares chave-valor com chaves exclusivas. Pesquisa, inserção e remoção de elementos têm complexidade de tempo constante média. Internamente, os elementos não são classificados em nenhuma ordem específica, mas organizados em baldes. Em qual balde um elemento é colocado depende inteiramente do hash de sua chave. Chaves com o mesmo código hash aparecem no mesmo bucket. Isso permite acesso rápido a elementos individuais, pois uma vez que o hash é calculado, ele se refere ao balde exato em que o elemento é colocado. Internamente unordered_map é implementado usando Hash Table, a chave fornecida para mapear é hash nos índices de uma tabela hash, e é por isso que o desempenho da estrutura de dados depende muito da função hash, nela se tem o Hashing que refere-se ao processo de gerar uma saída de tamanho fixo a partir de uma entrada de tamanho variável usando as fórmulas matemáticas conhecidas como funções de hash. Esta técnica determina um índice ou local para o armazenamento de um item em uma estrutura de dados.

<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/baf62470-0a98-4279-98b2-541dfe83d17d" width="500px" />
</div>

<br>
A interface engloba uma função bucket_count que opera em tempo constante. Além disso, apresenta outra função chamada bucket_size, cujo desempenho está linearmente relacionado ao tamanho do balde.

Essencialmente, essas características descrevem a implementação do método de tratamento de colisões por encadeamento. Ao adotar o encadeamento de colisões, a satisfação de todos os requisitos torna-se uma tarefa relativamente fácil e direta. A função bucket_count() retorna o número de elementos presentes na estrutura de dados, enquanto a função bucket_size() retorna o número de elementos na lista de colisões associada a cada balde. A obtenção desses valores em tempo constante e linear, respectivamente, é uma operação simples e direta.

Neste código emprega se uma tabela de hash para armazenar as palavras e suas frequencias, resultando em inserções e buscas rápidas com complexidade média de O(1). Isso é benéfico quando é crucial, pois torna possível utilizar palavras como chaves para contabilizar suas frequências e acessa-las para obter as top K elementos.


<h3><b>Unodered_set</b></h3>

`std::unordered_set` é um contêiner associativo que contém um conjunto de objetos exclusivos do tipo Key. Pesquisa, inserção e remoção têm complexidade de tempo constante média. Internamente, os elementos não são classificados em nenhuma ordem específica, mas organizados em baldes. Em qual balde um elemento é colocado depende inteiramente do hash de seu valor. Isso permite acesso rápido a elementos individuais, pois uma vez que um hash é calculado, ele se refere ao balde exato em que o elemento é colocado. O unordered_set é implementado como tabelas de hash.

Os elementos do contêiner não podem ser modificados (mesmo por não const iteradores), pois a modificação pode alterar o hash de um elemento e corromper o contêiner. Portanto, optou-se por armazenar as stopWords, que foram carregadas de um arquivo de texto. Essa abordagem permite uma comparação otimizada para determinar se palavras são stopwords ou não. Isso se deve ao fato de que todas as operações no unordered_set têm uma complexidade de tempo constante em média (O(1)), embora em casos extremos possam chegar a uma complexidade de tempo linear (O(n)).

<h3><b>Regex</b></h3>

A biblioteca de expressões regulares disponibiliza uma classe que representa as próprias expressões regulares, que são uma forma de minilinguagem utilizada para realizar a correspondência de padrões em strings.

Uma "expressão regular", também conhecida como `regex`, é uma sequência específica de caracteres que define um padrão de pesquisa. Isso pode ser empregado em algoritmos de busca, localização ou substituição de strings, entre outras aplicações. Expressões regulares também são utilizadas para validar entradas.

No código, o regex foi empregado para preservar os caracteres que tenho interesse em que sejam reconhecidos nas palavras. 

Os iteradores regex são usados ​​para percorrer todo o conjunto de correspondências de expressões regulares encontradas em uma sequência.
O `std::regex_iterator` é um iterador somente leitura que permite acessar correspondências individuais de uma expressão regular dentro de uma sequência de caracteres. 

Durante a construção e em cada incremento, esse iterador chama a função std::regex_search e armazena o resultado (ou seja, guarda uma cópia do valor de std::match_results < BidirIt >). O primeiro objeto desse tipo pode ser lido no momento da construção do iterador ou quando ocorre a primeira operação de desreferenciamento. Caso contrário, a desreferenciação apenas retorna uma cópia da correspondência de expressão regular mais recentemente obtida.

O padrão utilizado na construção do std::regex_iterator representa o indicador do final da sequência. Quando um std::regex_iterator válido é incrementado após ter alcançado a última correspondência (ou seja, quando std::regex_search retorna false), ele se iguala ao iterador que denota o final da sequência.

<h3><b>Heapify_min</b></h3>

heapify_min foi implementado sem a utilização de estrutura pronta. 

`Heapify` é um método de converter um conjunto de valores em um heap. A lógica por trás do algoritmo heapify determinará em que tipo de heap o conjunto de valores se tornará.

Neste algoritmo foi utilizado o heapify_min, que é uma Árvore Binária Completa contendo o menor valor no nó raiz, seguido por valores maiores no próximo nível, seguido por valores ainda maiores no próximo nível e assim por diante. Assim, o último nível desta árvore binária deve conter os maiores valores presentes no array de valores que estamos inserindo. Neste código, um heap é utilizado para armazenar palavras e suas frequências dos K maiores elementos dos textos lidos. No entanto, é importante observar que, entre esses K maiores elementos, o menor deles é mantido no nó raiz.
Imagine que o vetor contém as maiores frequências encontradas, o heap fica assim:
<div align="center">
<img src="https://github.com/Letolsilva/AEDS---Caminho-guloso/assets/109817570/de15ef20-39f3-4be0-8364-93eb9306bb63" width="500px" />
</div>
É possível acessar os filhos esquerdo e direito de um nó através das fórmulas 2 * i + 1 e 2 * i + 2, respectivamente.<br>
Obs: "i" recebeu o nome de subtree_root_index neste código.

Heapify um único nó leva complexidade de tempo O(log K), onde K é o número total de nós. Portanto, construir todo o Heap levará N operações de heapify e a complexidade de tempo total será O(N*log K).

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
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/5764665c-0b57-4f70-ab4b-a1b667e98e7a" width="500px" />
</div>

<h4>Complexidade de espaço:<h4>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/d25f271e-c25d-402b-9b0e-351dfcc16c7f" width="500px" />
</div>

<h3><b>Árvore AVL</b></h3>
A árvore AVL pode ser definida como uma árvore de pesquisa binária com altura balanceada em que cada nó está associado a um fator de equilíbrio que é calculado subtraindo a altura de sua subárvore direita daquela de sua subárvore esquerda.

Diz-se que a árvore está balanceada se o fator de equilíbrio de cada nó estiver entre -1 e 1, caso contrário, a árvore ficará desequilibrada e precisará ser balanceada.

- Se o fator de equilíbrio de qualquer nó for 1, significa que a subárvore esquerda está um nível acima da subárvore direita.

- Se o fator de equilíbrio de qualquer nó for 0, significa que a subárvore esquerda e a subárvore direita contêm altura igual.

- Se o fator de equilíbrio de qualquer nó for -1, significa que a subárvore esquerda está um nível abaixo da subárvore direita.

Uma árvore AVL é fornecida na figura a seguir. Podemos ver que o fator de equilíbrio associado a cada nó está entre -1 e +1. portanto, é um exemplo de árvore AVL.
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/2544b8e5-2203-445a-8a10-6fc6f597ccfa" width="500px" />
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

- `init ` é responsável por iniciar o processo de processamento de um arquivo de texto, assim ela inicia abrindo o arquivo de entrada ```data/input(x).txt```, assegura-se de que a abertura tenha ocorrido sem problemas e, em seguida, aciona a função ```StopWords``` para carregar palavras que devem ser excluídas da contagem de frequência. Após essa etapa, ela procede à leitura de cada linha do arquivo de entrada e direciona cada linha para a função ```tokenizacao ```.

- ```StopWords:``` Após abrir o arquivo e verificar a abertura bem-sucedida, ela lê cada linha do arquivo e converte cada palavra em minúsculas para garantir uniformidade. As palavras processadas dessa maneira são então inseridas em uma unodered_set chamada ```unorderedStopWords```, permitindo uma rápida verificação de pertencimento durante a  função tokenização. Ao final, o arquivo é fechado.

- ```Tratamentos:``` Esta funçao realiza tratamentos especificos para caracteres especias encontrados durante os testes. Primeiramente, verifica se a palavra termina em hífen e remove-o. Em seguida, verifica se a palavra começa com hífen e, dependendo das circunstâncias, remove um ou dois hífens do início da palavra. Além disso, ela trata o caso em que as palavras possuem caracteres especiais " ” " e " “ " no final ou início, eliminando-os quando apropriado. A função também detecta se a palavra foi completamente esvaziada após essas operações de tratamento, indicando assim que a palavra não tem mais conteúdo significativo. Isso é útil para que a função de tokenização, pois esses tratamentos ajudam a normalizar as palavras, garantindo que a contagem de frequência seja precisa e livre de ruídos indesejados.

- ```Tokenizacao:``` Essa função transforma as linhas do texto em palavras individuais. Para isso, ela aplica o regex para identificar padrões de palavras, incluindo letras, números, apóstrofos, caracteres acentuados e hifens. Durante o processo, a função itera através dos resultados obtidos pelo regex e aplica a funçao ```tratamentos```. Se a palavra resultante não estiver vazia após os tratamentos, ela é convertida para minúsculas e verifica-se se não é uma ```StopWords```. Caso não seja uma, ela é contabilizada no unordered_map chamado ```wordCount```, para posteriormente calcular a frequência das palavras no texto. 

- ```topKWords:``` A função desempenha um papel central na identificação das palavras mais frequentes no texto, usando uma abordagem baseada em heap. Durante a iteração pelo mapa não ordenado chamado `wordCount`, que mantém as palavras e suas contagens, essa função constrói um heap. Durante a iteração, ele aumenta o tamanho da estrutura topKHeap. Se o tamanho ainda for menor ou igual a k, ele adiciona a entrada atual ao final do vetor vectortopKHeap. Então, ele chama uma função chamada heapify para reorganizar o heap de modo que ele mantenha as propriedades corretas. Se o tamanho da estrutura topKHeap exceder k, o código verifica se a contagem da palavra atual é maior que a contagem da palavra no topo do heap. Se sim, ele substitui a palavra no topo do heap com a palavra atual e chama heapify novamente para manter as propriedades do heap. <br>
Ao final do processamento, o heap é montado de forma inicial, contendo os "k" elementos de maior contagem, permitindo identificar eficientemente as palavras mais frequentes no texto.

- ```heapify:``` Ela recebe como entrada um vetor de pares representando palavras e suas contagens, o tamanho do heap (n) e o índice da raiz da subárvore sendo analisada. A função compara as contagens dos elementos presentes no índice da raiz e seus filhos esquerdo e direito, identificando o menor entre eles. Se o menor não for a raiz da subárvore, a função troca os elementos e chama recursivamente heapify na subárvore afetada, assegurando que a hierarquia e a propriedade de heap mínima sejam mantidas em toda a estrutura. 

- ```printTopK:``` Imprime as palavras e suas frequências na ordem que esta no heap.

- `VerificaArvoreECria:`A função recebe como entrada um arquivo contendo uma lista de palavras que o usuário deseja pesquisar em um texto. Para cada palavra lida, ela verifica se a palavra está presente no texto e se possui uma contagem positiva. Se a palavra existe e tem uma contagem positiva, a função a processa para atualizar uma estrutura de dados chamada "heap" que captura as k+1 palavras mais relevantes. Se a palavra da lista já está no heap, ela é excluída e o heap mantém apenas as k palavras mais relevantes. Se a palavra não está no heap, a palavra menos relevante (na posição 0) é excluída, mantendo o heap com k elementos.
Se a palavra não existe no texto ou tem uma contagem zero, a função não cria uma estrutura de árvore para ela e passa para a próxima palavra. Além disso, a função cria três tipos diferentes de árvores (uma árvore básica, uma árvore AVL e uma árvore de Huffman) com base no heap e suas contagens e escreve informações formatadas em um arquivo de saída. 

- `headerOutput:` é responsável por criar um cabeçalho formatado em um arquivo de saída, utilizado para registrar informações sobre a frequência de palavras em vários arquivos de texto. 

- `CreatTree e insertTree:` A `creatTree` tem como objetivo criar uma árvore binária de busca a partir de do heap (vectorBasicTree). Ela inicializa um ponteiro para o nó raiz como nulo, percorre o vetor de pares e insere cada par na árvore por meio da função insertTree da instância arvore. A função `insertTree` faz parte de uma classe chamada basicTree e é responsável por inserir um nó em uma árvore binária de busca de acordo com a regra de ordenação baseada na frequência da palavra. Se o nó atual for nulo, um novo nó é criado com os dados da palavra e inserido ali. Caso contrário, a função compara a frequência da palavra com a do nó atual e a insere na subárvore esquerda se for menor/igual ou na subárvore direita se for maior. Isso mantém a árvore organizada pela frequência das palavras. Em seguida imprime uma árvore binária de busca a partir dos dados fornecidos no vetor, registrando-a em um arquivo de saída em inordem.

- `CreatAVL e insertAVL:` CreatAVL é responsável por criar uma Árvore AVL (Árvore de Busca Binária Equilibrada) a partir do heap (vectorAVLTree). Ela começa declarando um ponteiro root para a raiz da árvore AVL como nulo. Em seguida, ela itera através do vetor e insere cada par na árvore AVL por meio da função insertAVL da instância arvoreAVL. `insertAVL` é utilizada para inserir um novo nó em uma Árvore AVL de acordo com a frequência associada à palavra. O código inicia verificando se o nó atual (*t) é nulo. Se for nulo, um novo nó é criado com os dados da palavra e os ponteiros left e right são inicializados como nulos. Além disso, o campo weight do nó é definido como 0. Se o nó não for nulo, a função compara a frequência da palavra com a do nó atual e insere a palavra na subárvore esquerda ou direita, dependendo da comparação. Após a inserção, a função verifica se o fator de equilíbrio da árvore foi violado e, se necessário, realiza rotações para restaurar o equilíbrio da árvore. Finalmente, o campo weight do nó é atualizado para refletir a altura da subárvore enraizada no nó atual. Esta funçao utiliza de verias funções como `rotacaoSimplesDireita`, `rotacaoSimplesEsquerda`, `rotacaoDuplaDireita` e `rotacaoDuplaEsquerda` para manter a árvore balanceada. Essas funções são chamadas quando ocorrem violações do fator de equilíbrio da árvore durante a inserção de um novo nó. Além das funçoes `getWeight` e ` getMaxWeight` que auxiliam no cálculo e na atualização das alturas das subárvores em uma árvore AVL. Após a construção da árvore AVL, a função escreve uma mensagem indicando a criação da árvore no arquivo de saída.

- `CreatHuffman, HuffmanCodes, generateHuffmanTree e printCodes:` A função CreatHuffman é usada para criar uma árvore de Huffman a partir do vetor heap(vectorHuffmanTree) e registrá-la em um arquivo de saída. Primeiro, a função determina o tamanho do vetor vectorHuffmanTree e cria dois arrays: um para armazenar as palavras (word) e outro para armazenar as frequências (freq). Em seguida, ela copia os valores das palavras e frequências do vetor vectorHuffmanTree para esses arrays. Logo, após a função HuffmanCodes da instância arvoreHuffman é chamada para construir a árvore de Huffman. A função `HuffmanCodes` pertence à classe HuffmanTree e é responsável por gerar códigos de Huffman para um conjunto de palavras com base em suas frequências e registrá-los em um arquivo de saída. Ela inicia criando uma fila de prioridade (priority_queue) de nós Huffman, onde cada nó representa uma palavra e sua frequência. Em seguida, percorre o conjunto de palavras e suas frequências, criando um nó Huffman para cada palavra e inserindo-o na fila de prioridade. Depois, a função chama outra função chamada `generateHuffmanTree` para construir a árvore de Huffman a partir dos nós na fila de prioridade. Ela opera em um loop até que reste apenas um nó na fila, o qual se tornará a raiz da árvore de Huffman. A cada iteração, ela remove os dois nós de maior prioridade (menor frequência) da fila, que representam as palavras menos frequentes. Em seguida, cria um novo nó combinado que não tem uma palavra associada, mas possui a soma das frequências dos nós removidos. Esse novo nó tem os nós removidos como filhos (esquerdo e direito) e é inserido de volta na fila de prioridade. O processo continua até que reste apenas um nó na fila, que representa a raiz da árvore de Huffman completa. Uma vez que a árvore é construída, a função chama `printCodes` para gerar os códigos de Huffman para as palavras e registrá-los no arquivo de saída. Esses códigos são usados para representar as palavras de forma mais eficiente, onde palavras mais frequentes recebem códigos mais curtos. Posteriormente, a função `CreatHuffman` escreve uma mensagem indicando a criação da árvore de Huffman no arquivo de saída.

- `printInOrder:` Esta função imprime as árvores no formato inordem. No arquivo de saída, todas as árvores foram impressas nessa ordem, organizadas de acordo com sua frequência, sendo que apenas a árvore de Huffman foi impressa inordem de acordo com seus códigos.

- `print(nome da arvore)Levels:` Essa função tem o objetivo de imprimir a árvore em níveis, permitindo a verificação da sua estrutura para garantir sua correção. Embora não seja utilizada no código principal, ela pode ser chamada a qualquer momento para analisar a organização da árvore.
## 🎯Resultados

<h3><b>Configurando</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/AEDS---Caminho-guloso/assets/109817570/208e52e6-f803-4895-a435-490c49f9fe97" width="500px" />
</div>

Configurando para ler apenas um arquivo usando a variável ```numFiles``` e a variável  ```k``` para selecionar os top 20 elementos, no arquivo `main.cpp`.

<h3><b>Entrada</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Labirinto-Recorrente/assets/109817570/e4995ae5-f616-4b05-8822-e7c571db83ca" width="500px" />
</div>

<h3><b>Saída</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/767c2b1d-6584-4067-ae34-be9486b21c44" width="300px" />
</div>

<h3><b>Saída com os dois textos fornecidos como testes</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Top-K-Elementos/assets/109817570/dd912173-40ca-4650-a581-82cb62b66faf" width="300px" />
</div>
A saída obtida é resultado da fusão das palavras mais comuns encontradas nos textos "Dom Casmurro" e "A semana Texto-fonte: Obra Completa de Machado de Assis", ambos fornecidos como entradas de teste pelo professor e presentes nos arquivos "input1.txt" e "input2.txt", localizados na pasta data deste código.<br>

Pode-se confirmar que as sáidas estão corretas analisando os filhos esquerdos e direitos, com 2 * i + 1 e 2 * i + 2.<br>
Obs: Novamente i recebeu o nome de subtree_root_index neste codigo.


<h3><b>Tempo de execução</b></h3>
O código foi executado em um notebook Acer Nitro 5 com processador Ryzen 7.
<div align="center">
<img src="https://github.com/Letolsilva/AEDS---Caminho-guloso/assets/109817570/5bc326ce-66a9-4398-a6f3-d6345201b159" width="200px" />
</div>


## ✔️Conclusão
Conheci um método otimizado para busca e pesquisa em textos, com aplicações potenciais em várias outras situações. Ao compreender o conceito de heap e suas interações com estruturas abstratas de dados, pude estabelecer uma hierarquia em árvore para os elementos armazenados, permitindo um acesso eficiente a eles. Além disso, aprendi mais sobre estruturas de árvores e apliquei esses conhecimentos no algoritmo. Descobri também novas funções e estruturas que contribuiu para este código, possibilitando a execução de tarefas já conhecidas e abordadas mas desta vez de forma mais avançada.

## 🚨Importante

- Antes de compilar o código, é essencial definir dois parâmetros no arquivo main.cpp localizados no início do código: o valor de `k` (linha 12), que representa o tamanho do heap, e o número de arquivos que serão lidos numFiles (linha 8). 

- Certifique-se de ter os textos desejados armazenados na pasta data, nomeados como input(número do arquivo).txt, sendo que o número do arquivo deve começar a partir de 1 e incrementar sequencialmente. Na pasta main, escolha o número adequado de arquivos a serem lidos.

- O programa fornecerá uma única saída, apresentando as palavras mais frequentes encontradas nos arquivos especificados pelo parâmetro numFiles. Isso permitirá uma análise eficiente das palavras mais recorrentes nos textos fornecidos.


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

## Contato

<div>
 <br><p align="justify"> Letícia de Oliveira Silva</p>
 <a href="https://t.me/letolsilva">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:letolsilva22@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>letolsilva22@gmail.com</i>
</a>



