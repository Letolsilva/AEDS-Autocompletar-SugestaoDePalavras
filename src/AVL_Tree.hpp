#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>
#include <string>
#include <queue>
struct TreeAVL
{
    std::pair<std::string, int> data;
    TreeAVL *left;
    TreeAVL *right;
    int height;
    int weight;
    TreeAVL(const std::pair<std::string, int> &d) : data(d), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    TreeAVL *root;

    int getWeight(TreeAVL *t);
    int getMaxWeight(int a, int b);
    void rotacaoSimplesDireita(TreeAVL **t);
    void rotacaoSimplesEsquerda(TreeAVL **t);
    void rotacaoDuplaDireita(TreeAVL **t);
    void rotacaoDuplaEsquerda(TreeAVL **t);

public:
    AVLTree();
    ~AVLTree();
    void printInOrder(TreeAVL *t);
    void printAVLLevels(TreeAVL *t);
    void insertTree(TreeAVL **t, const std::pair<std::string, int> &data);
};
#endif // TREEAVL_HPP