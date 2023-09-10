#ifndef TOPKELEMENTOS_HPP
#define TOPKELEMENTOS_HPP
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iomanip> 
#include <chrono>
#include "BinaryTree.hpp"
#include "AVL_Tree.hpp"
#include "HuffmanTree.hpp"

class topKItems
{
public:
    std::unordered_map<std::string, int> wordCount;
    void init(const std::string &filename);
    void printTopK(int k);
    void topKWords(int k);
    void VerificaArvoreECria(const std::string &listFilename, std::ofstream &outputFile, int k, int numFiles);

private:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> wordCountPorArquivo;
    std::unordered_set<std::string> unoderedStopWords;
    std::vector<std::pair<std::string, int>> vectortopKHeap;

    void tokenizacao(const std::string &line);
    void StopWords(const std::string &stopWordsFilename);
    void heapify(std::vector<std::pair<std::string, int>> &arr, int n, int subtree_root_index);
    void tratamentos(std::string &word, bool &stringVazia);

    void CreatTree(std::vector<std::pair<std::string, int>> &vectorBasicTree, std::ofstream &outputFile,  basicTree arvore);
    void CreatAVL(std::vector<std::pair<std::string, int>> &vectorAVLTree, AVLTree arvoreAVL, std::ofstream &outputFile);
    void CreatHuffman(std::vector<std::pair<std::string, int>> &vectorHuffmanTree, int k, HuffmanTree arvoreHuffman, std::ofstream &outputFile);
    void headerOutput(std::ofstream &outputFile, int numFiles, const std::string &word);
};

#endif
