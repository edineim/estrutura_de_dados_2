#include <stdio.h>
int soma_max(int v[], int n){

    int max_atual = -1000000000;
    int max_terminando_aqui = 0;

    for(int i = 0; i<n; i++){
        max_terminando_aqui += v[i];
        if (max_atual < max_terminando_aqui)
            max_atual = max_terminando_aqui;

        if (max_terminando_aqui < 0)
            max_terminando_aqui = 0;
    }
    return max_atual;
}

int main()
{
    int n;
    scanf("%d", &n);
    int v[n];
    
    for (int i=0; i<n;i++){
        scanf("%d", &v[i]);
    }
    printf("%d", soma_max(v, n));
    return 0;
}
