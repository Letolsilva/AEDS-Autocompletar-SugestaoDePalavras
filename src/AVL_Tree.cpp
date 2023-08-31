#include "AVL_Tree.hpp"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree()
{
   
}

int AVLTree::getWeight(TreeAVL *t)
{
    return (t == nullptr) ? -1 : t->weight;
}

int AVLTree::getMaxWeight(int a, int b)
{
    return (a > b) ? a : b;
}

void AVLTree::rotacaoSimplesDireita(TreeAVL **t)
{
    TreeAVL *aux;
    aux = (*t)->left;
    (*t)->left = aux->right;
    aux->right = (*t);
    (*t)->weight = getMaxWeight(getWeight((*t)->left), getWeight((*t)->right)) + 1;
    aux->weight = getMaxWeight(getWeight(aux->left), (*t)->weight) + 1;
    (*t) = aux;
}

void AVLTree::rotacaoSimplesEsquerda(TreeAVL **t)
{
    TreeAVL *aux;
    aux = (*t)->right;
    (*t)->right = aux->left;
    aux->left = (*t);
    (*t)->weight = getMaxWeight(getWeight((*t)->left), getWeight((*t)->right)) + 1;
    aux->weight = getMaxWeight(getWeight(aux->left), (*t)->weight) + 1;
    (*t) = aux;
}

void AVLTree::rotacaoDuplaDireita(TreeAVL **t)
{
    rotacaoSimplesEsquerda(&(*t)->left);
    rotacaoSimplesDireita(t);
}

void AVLTree::rotacaoDuplaEsquerda(TreeAVL **t)
{
    rotacaoSimplesDireita(&(*t)->right);
    rotacaoSimplesEsquerda(t);
}

void AVLTree::insertTree(TreeAVL **t, const std::pair<std::string, int> &AVL)
{
    if (*t == nullptr)
    {
        *t = new TreeAVL(AVL);
    }
    else
    {
        if (AVL.second <= (*t)->data.second)
        {
            insertTree(&(*t)->left, AVL);
            if ((getWeight((*t)->left) - getWeight((*t)->right)) == 2)
            {
                if (AVL.second <= (*t)->left->data.second){
                    rotacaoSimplesDireita(t);
                }else{
                    rotacaoDuplaDireita(t);
                }
                    
            }
        }
        else if (AVL.second > (*t)->data.second)
        {
            insertTree(&(*t)->right, AVL);
            if ((getWeight((*t)->right) - getWeight((*t)->left)) == 2)
            {
                if (AVL.second > (*t)->right->data.second){
                    rotacaoSimplesEsquerda(t);
                }else{
                    rotacaoDuplaEsquerda(t);
                }
            }
        }

        (*t)->weight = getMaxWeight(getWeight((*t)->left), getWeight((*t)->right)) + 1;
    }
}

void AVLTree::printInOrder(TreeAVL *t)
{
    if (t == nullptr)
    {
        return;
    }
    printInOrder(t->left);
    std::cout << t->data.first << ": " << t->data.second << "\n";
    printInOrder(t->right);
}
void AVLTree::printAVLLevels(TreeAVL *t)
{
    if (t == nullptr)
    {
        return;
    }
    std::queue<TreeAVL *> q;
    q.push(t);
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeAVL *curr = q.front();
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