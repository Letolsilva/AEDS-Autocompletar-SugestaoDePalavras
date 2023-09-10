#include "AVL_Tree.hpp"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree()
{
}

int AVLTree::getWeight(TreeAVL **t)
{
    if (*t == nullptr)
    {
        return -1;
    }
    return (*t)->weight;
}

int AVLTree::getMaxWeight(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void AVLTree::rotacaoSimplesDireita(TreeAVL **t)
{
    TreeAVL *aux;
    aux = (*t)->left;
    (*t)->left = aux->right;
    aux->right = (*t);
    (*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
    aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
    (*t) = aux;
}

void AVLTree::rotacaoSimplesEsquerda(TreeAVL **t)
{
    TreeAVL *aux;
    aux = (*t)->right;
    (*t)->right = aux->left;
    aux->left = (*t);
    (*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
    aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
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

void AVLTree::insertAVL(TreeAVL **t, const std::pair<std::string, int> &AVL)
{
    if (*t == nullptr)
    {
       //std::cout << AVL.first << " "<< "NULL" << std::endl;
        *t = new TreeAVL(AVL);
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->weight = 0;
        (*t)->data = AVL;
    }
    else
    {
        if (AVL.second < (*t)->data.second)
        {
            //std::cout << AVL.first << " " << "ESQUERDA" << std::endl;
            insertAVL(&(*t)->left, AVL);
            if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2)
            {
               //std::cout << AVL.first << " "<< "FOI IGUAL A 2 ESQUERDA" << std::endl;
                if (AVL.second < (*t)->left->data.second)
                {
                   //std::cout << AVL.first << " "<< "ROTAÇAO DIREITA" << std::endl;
                    rotacaoSimplesDireita(t);
                }
                else
                {
                   //std::cout << AVL.first << " " << "ROTAÇAO DUPLA DIREITA" << std::endl;
                    rotacaoDuplaDireita(t);
                }
            }
        }
       else if (AVL.second >= (*t)->data.second)
        {
          // std::cout << AVL.first << " "<< "DIREITAA" << std::endl;
            insertAVL(&(*t)->right, AVL);
            if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2)
            {
              //std::cout << AVL.first << " "<< "FOI IGUAL A 2 DIREITA" << std::endl;
                if (AVL.second >= (*t)->right->data.second)
                {
                    //std::cout << AVL.first << " "<< "ROTAÇAO ESQUERDA" << std::endl;
                    rotacaoSimplesEsquerda(t);
                }
                else
                {
                   // std::cout << AVL.first << " " << "ROTAÇAO DUPLA ESQUERDA" << std::endl;
                    rotacaoDuplaEsquerda(t);
                }
            }
        }
        // std::cout << (*t)->weight << " "
        //           << "ACABOU" << std::endl;
        // std::cout << getWeight(&(*t)->right) << " "
        //           << "DIREITA WEIGHT" << std::endl;
        // std::cout << getWeight(&(*t)->left) << " "
        //           << "ESQUERDA WEIGHT" << std::endl;
    }
    (*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}

void AVLTree::printBinaryTreePosOrdem(TreeAVL *t, std::ofstream &outputFile)
{
  if(!(t == nullptr)){
    printBinaryTreePosOrdem(t->left, outputFile); 
    printBinaryTreePosOrdem(t->right, outputFile); 
    outputFile<< t->data.first << " " ;
  }
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