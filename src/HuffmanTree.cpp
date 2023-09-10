#include "HuffmanTree.hpp"

void HuffmanTree::printInOrder(Huffman *node)
{
    if (node == nullptr)
        return;

    printInOrder(node->left);
    std::cout << node->word << ": " << node->freq << std::endl;
    printInOrder(node->right);
}

void HuffmanTree::printHuffmanLevels(Huffman *t)
{
    if (t == nullptr)
        return;

    std::queue<Huffman *> q;
    q.push(t);

    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i)
        {
            Huffman *current = q.front();
            q.pop();
            std::cout << current->word << ": " << current->freq << " | ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        std::cout << std::endl;
    }
}

Huffman* HuffmanTree::generateHuffmanTree(std::priority_queue<Huffman*, std::vector<Huffman*>, Compare>& pq)
{
   while (pq.size() != 1)
    {
        Huffman *left = pq.top();
        pq.pop();
        Huffman *right = pq.top();
        pq.pop();

        Huffman *combined = new Huffman("",left->freq + right->freq);
        combined->left = left;
        combined->right = right;

        pq.push(combined);
    }

    return pq.top();

}


void HuffmanTree::HuffmanCodes(std::string data[], int freq[], int size, int K, std::ofstream &outputFile)
{
    std::priority_queue<Huffman*, std::vector<Huffman*>, Compare> pq;
    for (int i = 0; i < size; i++) {
        Huffman* newNode = new Huffman(data[i], freq[i]);
        pq.push(newNode);
    }
 
    Huffman* root = generateHuffmanTree(pq);
    int arr[K];
    printCodes(root,arr, 0, outputFile);
    // std::cout<<"Huffman"<<std::endl;
    // printHuffmanLevels(root);
}

void HuffmanTree::printCodes(Huffman* root,int arr[], int top, std::ofstream &outputFile)
{
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left,
                   arr, top + 1, outputFile);
    }
 
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, outputFile);
    }
 
    if (!root->left && !root->right) {
        outputFile << root->word;
         outputFile<<"(";
        for (int i = 0; i < top; i++) {
            outputFile<< arr[i];
        }
        outputFile<<")"<<" ";
    }
}

