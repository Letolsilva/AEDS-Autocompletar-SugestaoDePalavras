#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include "BinaryTree.hpp"

class Huffman
{
public:
    std::string word; 
    int freq;
    Huffman *left;
    Huffman *right;

    Huffman(std::string word, int frequency)
    {
        this->word = word;
        freq = frequency;
        left = right = NULL;
    }
};

class Compare
{
public:
    bool operator()(Huffman *a, Huffman *b)
    {
        return a->freq > b->freq;
    }
};

class HuffmanTree
{
private:

public:
    void printHuffmanLevels(Huffman *t);
    Huffman *generateHuffmanTree(std::priority_queue<Huffman *, std::vector<Huffman *>, Compare> &pq);
    void HuffmanCodes(std::string data[], int freq[], int size, int K, std::ofstream &outputFile);
    void printCodes(Huffman* root,int arr[], int top, std::ofstream &outputFile);
};

#endif
