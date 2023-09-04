#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode
{
    std::pair<std::string, int> data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(std::pair<std::string, int> val) : data(val), left(nullptr), right(nullptr) {}
};

class basicTree
{
public:
    void insertTree(TreeNode **t, const std::pair<std::string, int> &r);
    void printBinaryTreeInOrder(TreeNode *root, std::ofstream &outputFile);
    void widthPath(TreeNode *t);

private:
    //TreeNode *binaryTreeRoot = nullptr;
};

#endif
