#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "topKElementos.hpp"

int numFiles = 6; // Número de arquivos de entrada
int k = 20;       // Valor de K

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream outputFile("output.txt");
    if (!outputFile)
    {
        std::cerr << "Erro ao abrir o arquivo de saída" << std::endl;
        return 1;
    }

    for (int i = 1; i <= numFiles; ++i)
    {
        std::string filename = "data/input" + std::to_string(i) + ".txt";

        topKItems processor;
        processor.init(filename); 
        processor.topKWords(k);  
        // processor.printTopK(k);

        std::string listFilename = "data/lista.txt";
        std::cout << "Arquivo " << i << std::endl;
        processor.processListAndDisplay(listFilename, outputFile, k, i); 

        processor.wordCount.clear();
    }

    outputFile.close();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Tempo de execucaoo: " << duration.count() << " ms" << std::endl;

    return 0;
}
