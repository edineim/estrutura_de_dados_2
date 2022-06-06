#include <stdio.h>

int mochila(int b, int peso[], int valor[], int n)
{
    int V[n + 1][b + 1];

    for(int i = 0; i <= b; i++)
        V[0][i] = 0;

    for(int i = 1; i <= n; i++)
        V[i][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            if(peso[i - 1] <= j)
            {
                if((valor[i - 1] + V[i - 1][j - peso[i - 1]]) > V[i - 1][j])
                    V[i][j] = valor[i - 1] + V[i - 1][j - peso[i - 1]];
                else
                    V[i][j] = V[i - 1][j];
            }
            else
                V[i][j] = V[i - 1][j];
        }
    }
    return V[n][b];
}

int main(void){

    int b, N, i;

    scanf("%d", &b);
    scanf("%d", &N);

    int peso[N], valor[N];

    for(i=0; i<N; i++){
        scanf("%d %d", &peso[i], &valor[i]);
    }

    printf("%d", mochila(b, peso, valor, N));

    return 0;
}
