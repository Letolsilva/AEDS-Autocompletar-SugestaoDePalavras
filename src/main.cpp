#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "topKElementos.hpp"

int numFiles = 6; // Número de arquivos de entrada
int k = 20; // Valor de K

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i <= numFiles; ++i) {
        std::string filename = "data/input" + std::to_string(i) + ".txt";
        
        topKItems processor;
        processor.init(filename); // Inicializa o processamento para cada arquivo
        processor.topKWords(k); // Calcula o top K para o arquivo
        
        //processor.printTopK(k); 

        std::string listFilename = "data/lista.txt"; 
        std::cout<<"Arquivo "<<i<<std::endl;
        processor.processListAndDisplay(listFilename); // Processa a lista e exibe informações
        processor.wordCount.clear(); 
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Tempo de execucaoo: " << duration.count() << " ms" << std::endl;

    return 0;
}
