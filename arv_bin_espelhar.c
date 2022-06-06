#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node Node;

struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
};

Node* criar(int item)
{
    Node * tree = (Node *) malloc(sizeof(Node));

    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Node* inserir(int item, Node* tree)
{

    if (tree == NULL)
        tree = criar(item);

    else if (item < tree->item)
        tree->left = inserir(item, tree->left);

    else if (item > tree->item)
        tree->right = inserir(item, tree->right);

    return tree;
}

int altura_tree(Node *tree)
{
    int left;
    int right;

    if (tree != NULL)
    {
        left = 1 + altura_tree(tree->left);
        right = 1 + altura_tree(tree->right);

        if(left > right)
            return left;
        else
            return right;
    }
    return 0;
}

void espelhar(struct Node* tree)
{
    if(tree != NULL)
    {
        Node* aux;

        espelhar(tree->left);
        espelhar(tree->right);

        aux = tree->left;
        tree->left = tree->right;
        tree->right = aux;
    }
}

void infix(Node*tree)
{
    if (tree != NULL)
    {
        infix(tree->left);
        printf("%d ", tree->item);
        infix(tree->right);
    }
}


int main()
{
    int i=0, n, num;

    scanf("%d",&n);
    scanf("%d",&num);

    Node *no = criar(num);

    while (i < n-1)
    {
        scanf("%d",&num);
        inserir(num, no);
        i++;
    }

    espelhar(no);
    infix(no);

    return 0;
}
