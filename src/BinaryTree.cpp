#include "BinaryTree.hpp"

void basicTree::insertTree(TreeNode **t, const std::pair<std::string, int> &r)
{
    if (*t == nullptr)
    {
        *t = new TreeNode(r);
        (*t)->right = NULL;
        (*t)->left = NULL;
        (*t)->data = r;
    }
    else if (r.second <= (*t)->data.second)
    {
        insertTree(&(*t)->left, r);
    }
    else if (r.second > (*t)->data.second)
    {
        insertTree(&(*t)->right, r);
    }
}

void basicTree::printBinaryTreeInOrder(TreeNode *root, std::ofstream &outputFile)
{
    if (root == nullptr)
    {
        return;
    }
    printBinaryTreeInOrder(root->left, outputFile);
    outputFile << root->data.first << " ";
    printBinaryTreeInOrder(root->right, outputFile);
}

void basicTree::widthPath(TreeNode *t)
{
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
        }
        std::cout << "\n";
    }
}

TreeNode *basicTree::copyNode(TreeNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    TreeNode *copiedNode = new TreeNode(node->data);
    copiedNode->left = copyNode(node->left);
    copiedNode->right = copyNode(node->right);

    return copiedNode;
}
