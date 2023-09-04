#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "topKElementos.hpp"
#include <queue>
#include <algorithm>

void topKItems::init(const std::string &filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }

    std::string line;
    StopWords("stopwords.txt");

    while (std::getline(inputFile, line))
    {
        tokenizacao(line);
    }
    wordCountPerFile[filename] = wordCount; // Armazena o wordCount atual no mapa separado por arquivo
    inputFile.close();
}

void topKItems::StopWords(const std::string &stopWordsFilename)
{
    std::string fullPath = "data/" + stopWordsFilename;
    std::ifstream stopWordsFile(fullPath);
    if (!stopWordsFile)
    {
        std::cerr << "Erro ao abrir o arquivo de stop words: " << stopWordsFilename << std::endl;
        return;
    }

    std::string stopWord;
    while (std::getline(stopWordsFile, stopWord))
    {
        for (char &c : stopWord)
        {
            c = tolower(c);
        }
        unoderedStopWords.insert(stopWord);
    }
    stopWordsFile.close();
}
void topKItems::tratamentos(std::string &word, bool &stringVazia)
{
    if (!word.empty() && word.back() == '-')
    {
        word.pop_back();
    }

    if (!word.empty() && word.front() == '-')
    {
        if (word.length() >= 2 && word.substr(0, 2) == "--")
        {
            word.erase(0, 2);
        }
        else
        {
            word.erase(0, 1);
        }
    }

    if (word.length() >= 3 && word.substr(word.length() - 3) == "”")
    {
        word.erase(word.length() - 3);
    }

    if (word.length() >= 3 && word.substr(0, 3) == "“")
    {
        word.erase(0, 3);
    }
    if (word.empty())
    {
        stringVazia = true;
    }
}
void topKItems::tokenizacao(const std::string &line)
{
    std::string word;
    std::regex wordRegex("[a-zA-Z0-9'À-Ÿ\\-“”]+");
    std::sregex_iterator iterador(line.begin(), line.end(), wordRegex);
    std::sregex_iterator fim;

    while (iterador != fim)
    {
        word = iterador->str();
        bool stringVazia = false;
        tratamentos(word, stringVazia);
        if (stringVazia == false)
        {
            for (char &c : word)
            {
                c = tolower(c);
            }
            if (unoderedStopWords.find(word) == unoderedStopWords.end())
            {
                wordCount[word]++;
            }
        }
        ++iterador;
    }
    wordCount.erase("-");
    wordCount.erase("—");
}

void topKItems::topKWords(int k)
{
    int topKHeapSize = 0;

    for (const auto &fileEntry : wordCountPerFile)
    {
        const auto &wordCount = fileEntry.second;

        for (const auto &entry : wordCount)
        {
            topKHeapSize++;

            if (topKHeapSize <= k + 1)
            {
                vectortopKHeap.push_back(entry);
                heapify(vectortopKHeap, topKHeapSize, 0);
            }
            else if (entry.second > vectortopKHeap[0].second)
            {
                vectortopKHeap[0] = entry;
                heapify(vectortopKHeap, k + 1, 0);
            }
        }
    }
    if (topKHeapSize < k)
    {
        k = topKHeapSize;
    }

    for (int i = k / 2 - 1; i >= 0; --i)
    {
        heapify(vectortopKHeap, k, i);
    }

    // // // Reorganizar os elementos dentro do heap usando heapify
    // for (int i = k - 1; i > 0; --i)
    // {
    //     std::swap(vectortopKHeap[0], vectortopKHeap[i]);
    //     heapify(vectortopKHeap, i, 0);
    // }
}

void topKItems::printTopK(int k)
{
    std::cout << "\nTop " << k << " maiores Elementos encontrados \n";
    int aux = vectortopKHeap.size();
    for (int i = 0; i < aux; ++i)
    {
        std::cout << vectortopKHeap[i].first << ": " << vectortopKHeap[i].second << std::endl;
    }
}

void topKItems::heapify(std::vector<std::pair<std::string, int>> &vectorAux, int n, int subtree_root_index)
{
    int minimum = subtree_root_index;
    int left_child = 2 * subtree_root_index + 1;
    int right_child = 2 * subtree_root_index + 2;

    if (left_child < n && vectorAux[left_child].second < vectorAux[minimum].second)
    {
        minimum = left_child;
    }

    if (right_child < n && vectorAux[right_child].second < vectorAux[minimum].second)
    {
        minimum = right_child;
    }

    if (minimum != subtree_root_index)
    {
        std::swap(vectorAux[subtree_root_index], vectorAux[minimum]);
        heapify(vectorAux, n, minimum);
    }
}

void topKItems::processListAndDisplay(const std::string &listFilename, std::ofstream &outputFile, int k, int numFiles)
{
    std::ifstream listFile(listFilename);
    if (!listFile)
    {
        std::cerr << "Erro ao abrir o arquivo de lista: " << listFilename << std::endl;
        return;
    }
    std::string word;
    while (listFile >> word)
    {
        std::vector<std::pair<std::string, int>> vectortopKHeapAux = vectortopKHeap;
        if (wordCount.find(word) != wordCount.end() && wordCount[word] > 0)
        {
            bool isTopK = false;
            for (auto topKEntryAux = vectortopKHeapAux.begin(); topKEntryAux != vectortopKHeapAux.end(); ++topKEntryAux)
            {
                if (topKEntryAux->first == word)
                {
                    isTopK = true;
                    vectortopKHeapAux.erase(topKEntryAux);
                    for (int i = k / 2 - 1; i >= 0; --i)
                    {
                        heapify(vectortopKHeap, k, i);
                    }
                    break;
                }
            }

            if (!isTopK)
            {
                std::pair<std::string, int> minFreqPair = vectortopKHeapAux[0];
                vectortopKHeapAux[0] = vectortopKHeapAux.back();
                vectortopKHeapAux.pop_back();
                heapify(vectortopKHeapAux, k, 0);

                wordCount.erase(minFreqPair.first);
            }
        }
        else
        {
            outputFile<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
            outputFile<< word << " não encontrada no texto "<< numFiles << std::endl;
            std::cout<< word << " não encontrada no texto "<< numFiles << std::endl;
            continue;
        }
        writeFormattedToFile(outputFile, numFiles, word);
        basicTree arvore;
        CreatTree(vectortopKHeapAux, outputFile, arvore);

        AVLTree avlTree;
        CreatAVL(vectortopKHeapAux, avlTree, outputFile);

        HuffmanTree huffmanTree;
        CreatHuffman(vectortopKHeapAux, k, huffmanTree, outputFile);
        std::cout<< word;
        std::cout << wordCount[word] << std::endl;
        std::cout << "Top K Palavras depois:\n";
        for (const auto &entry : vectortopKHeapAux)
        {
            std::cout << entry.first << ": " << entry.second << "\n";
        }
        std::cout << "-------------------\n";
        std::cout << "\n";
    }

    listFile.close();
}

void topKItems::CreatTree(std::vector<std::pair<std::string, int>> &vectorBasicTree, std::ofstream &outputFile, basicTree arvore)
{
    //Testada e tudo certo, check!
    TreeNode *root = nullptr;
    for (const auto &entry : vectorBasicTree)
    {
        arvore.insertTree(&root, entry);
    }
    // outputFile << "Árvore Binária em ordem inordem:\n";
    outputFile << std::left << std::setw(48) << std::setfill(' ') << "ARVORE BINÁRIA(InOrdem): " << std::endl;
    outputFile << "[";
    arvore.printBinaryTreeInOrder(root, outputFile);
    outputFile << "]";
    outputFile << std::endl;
    // arvore.widthPath(root);
    // std::cout << std::endl;
    outputFile << "\n";
}

void topKItems::CreatAVL(std::vector<std::pair<std::string, int>> &vectorAVLTree, AVLTree arvoreAVL, std::ofstream &outputFile)
{
    TreeAVL *root = nullptr;
    for (const auto &entry : vectorAVLTree)
    {
        arvoreAVL.insertTree(&root, entry);
    }
    outputFile << std::left << std::setw(48) << std::setfill(' ') << "ARVORE AVL(InOrdem): " << std::endl;
    outputFile << "[";
    arvoreAVL.printInOrder(root, outputFile);
    outputFile << "]";
    outputFile << std::endl;
    outputFile << "\n";

     std::cout << "Árvore AVL em ordem inordem:\n";
    //  arvoreAVL.printInOrder(root);
    //arvoreAVL.printAVLLevels(root);
    //std::cout << "\n";
}
void topKItems::CreatHuffman(std::vector<std::pair<std::string, int>> &vectorHuffmanTree, int k, HuffmanTree arvoreHuffman, std::ofstream &outputFile)
{
    int size = vectorHuffmanTree.size();
    std::string word[size];
    int freq[size];

    for (int i = 0; i < size; ++i)
    {
        word[i] = vectorHuffmanTree[i].first;
        freq[i] = vectorHuffmanTree[i].second;
    }
    outputFile << std::left << std::setw(48) << std::setfill(' ') << "ARVORE HUFFMAN(InOrdem): " << std::endl;
    outputFile << "[";
    arvoreHuffman.HuffmanCodes(word,freq,size,k, outputFile);
    outputFile << "]";
    outputFile << std::endl;
    outputFile << "\n";

}

void topKItems::writeFormattedToFile(std::ofstream &outputFile, int numFiles, const std::string &word)
{
    outputFile<< "---------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
    outputFile << std::left << std::setw(12) << "TEXTOS"
               << std::left << std::setw(20) << "PALAVRAS DA LISTA"
               << std::left << std::setw(20) << "FREQUENCIA" << std::endl;

    outputFile << std::left << std::setw(12) << "Arquivo" << numFiles << " "
               << std::left << std::setw(20) << word
               << std::left << std::setw(20) << wordCount[word] << std::endl;
    outputFile << std::endl;
}
