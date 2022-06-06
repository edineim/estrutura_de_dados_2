#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct no No;

struct no
{
    int item;
    int bf;
    No *dir;
    No *esq;
};

typedef struct arvore
{
    No *raiz;
    int balanceamento;
} Arvore;

void inicializa(Arvore *arvore)
{
    arvore->raiz = NULL;
    arvore->balanceamento = 1;
}

int maior(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

int altura(No *no)
{
    if (no == NULL)
    {
        return 0;
    }
    else
        return 1 + maior(altura(no->esq), altura(no->dir));
}

No *cria(int chave)
{
    No *no = (No *)malloc(sizeof(No));
    if(no == NULL)
        return NULL;
    no->item = chave;
    no->esq = NULL;
    no->dir = NULL;
    no->bf = 0;

    return no;
}

No *insert(No *raiz, int valor)
{

    if (raiz == NULL)
        return cria(valor);

    if (valor < raiz->item)
        raiz->esq = insert(raiz->esq, valor);
    else if (valor > raiz->item)
        raiz->dir = insert(raiz->dir, valor);

    return raiz;
}

void balanceamento(No *raiz)
{
    if (raiz != NULL)
    {
        int alturaEsq = altura(raiz->esq);
        int alturaDir = altura(raiz->dir);
        raiz->bf = alturaEsq - alturaDir;
        balanceamento(raiz->esq);
        balanceamento(raiz->dir);
    }
}

void AVL(No *raiz, Arvore *arvore)
{
    if (raiz != NULL)
    {
        if (raiz->bf > 1 || raiz->bf < -1)
        {
            arvore->balanceamento = 0;
            return;
        }
        AVL(raiz->dir, arvore);
        AVL(raiz->esq, arvore);
    }
}
int main()
{
    int qtd, i, chave;
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    inicializa(arvore);

    scanf("%d", &qtd);
    scanf("%d", &chave);

    arvore->raiz = insert(arvore->raiz, chave);

    for (i = 0; i < qtd; i++)
    {
        scanf("%d", &chave);

        insert(arvore->raiz, chave);
    }

    balanceamento(arvore->raiz);
    AVL(arvore->raiz, arvore);
    printf("%d", arvore->balanceamento);

    return 0;
}