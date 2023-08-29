#ifndef TOPKELEMENTOS_HPP
#define TOPKELEMENTOS_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode
{
    std::pair<std::string, int> data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(std::pair<std::string, int> val) : data(val), left(nullptr), right(nullptr) {}
};

class topKItems
{
public:
    void init(const std::string &filename);
    void printTopK(int k);
    void topKWords(int k);
    void processListAndDisplay(const std::string &listFilename);
    std::unordered_map<std::string, int> wordCount;

private:
   
    TreeNode *binaryTreeRoot = nullptr;

    std::unordered_map<std::string, std::unordered_map<std::string, int>> wordCountPerFile;
    std::unordered_set<std::string> unoderedStopWords;
    std::vector<std::pair<std::string, int>> vectortopKHeap;

    void tokenizacao(const std::string &line);
    void StopWords(const std::string &stopWordsFilename);
    void heapify(std::vector<std::pair<std::string, int>> &arr, int n, int subtree_root_index);
    void tratamentos(std::string &word, bool &stringVazia);


    void printBinaryTreeInOrder(TreeNode *root);
    void insertTree(TreeNode** t, const std::pair<std::string, int>& r);
    void widthPath(TreeNode *t);

};

#endif
