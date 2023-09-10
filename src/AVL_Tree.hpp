#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
struct TreeAVL
{
    std::pair<std::string, int> data;
    TreeAVL *left;
    TreeAVL *right;
    int weight;
    TreeAVL(const std::pair<std::string, int> &d) : data(d), left(nullptr), right(nullptr), weight(0) {}
};

class AVLTree
{
private:
    TreeAVL *root;

    int getWeight(TreeAVL **t);
    int getMaxWeight(int a, int b);
    void rotacaoSimplesDireita(TreeAVL **t);
    void rotacaoSimplesEsquerda(TreeAVL **t);
    void rotacaoDuplaDireita(TreeAVL **t);
    void rotacaoDuplaEsquerda(TreeAVL **t);

public:
    AVLTree();
    ~AVLTree();
    void printBinaryTreePosOrdem(TreeAVL *t, std::ofstream &outputFile);
    void printAVLLevels(TreeAVL *t);
    void insertAVL(TreeAVL **t, const std::pair<std::string, int> &data);
};
#endif 