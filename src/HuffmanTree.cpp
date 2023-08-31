#include "HuffmanTree.hpp"

void Huffman::printInOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    printInOrder(node->left);
    std::cout << node->data.first << ": " << node->data.second << "\n";
    printInOrder(node->right);
}

void Huffman::printHuffmanLevels(TreeNode *t)
{
    if (t == nullptr)
    {
        return;
    }
    std::queue<TreeNode *> q;
    q.push(t);
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr)
            {
                std::cout << curr->data.first << ": " << curr->data.second << " ";
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            else
            {
                std::cout << "null ";
            }
        }
        std::cout << "\n";
    }
}

