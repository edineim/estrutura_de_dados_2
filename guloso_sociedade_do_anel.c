#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10000

int intMax = 2147483;

int **matriz(int l, int c)
{
    int i = 0;
    int **matriz = (int **)malloc(sizeof(int *) * l);
    for (i = 0; i < l; i++)
        matriz[i] = (int *)malloc(sizeof(int) * c);
    return matriz;
}

int caminho(int **mat, int lin, int col, int movX[], int movY[], int li, int ci, int lf, int cf, int flag)
{
    int l, c, i, laux = 0, caux = 0, soma;
    int aux = intMax;

    if (((li + 1) == lf) && ((ci + 1) == cf))
    {
        return 0;
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            l = li + movX[i];
            c = ci + movY[i];
            if ((l >= 0) && (l < lin) && (c >= 0) && (c < col) && (mat[l][c] < aux))
            {
                aux = mat[l][c];
                laux = l;
                caux = c;
            }
        }

        if (aux != intMax)
        {
            mat[li][ci] = intMax;
            soma = aux + caminho(mat, lin, col, movX, movY, laux, caux, lf, cf, flag);
            return soma;
        }
        else
        {
            flag = 1;
            return MAX;
        }
    }
}

int main()
{
    int i = 0, j = 0, lf, cf, flag;
    int l, c, li = 0, ci = 0, resp;
    int movX[] = {0, 1, 0, -1};
    int movY[] = {1, 0, -1, 0};
    flag = 1;
    scanf("%d %d", &l, &c);

    int **m = matriz(l, c);

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    lf = l;
    cf = c;

    li = 0;
    ci = 0;

    resp = caminho(m, l, c, movX, movY, li, ci, lf, cf, flag);
    if (resp >= MAX)
    {
        printf("sem solucao");
    }
    else
    {
        printf("%d", resp);
    }

    return 0;
}
