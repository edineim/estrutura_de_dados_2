#include<stdio.h>

void selectsort(int n, int ini[], int fim[]) {
    int i, j, p, aux, troca = 1;
    for (i = n - 1; i > 1 && troca; i--) {
        p = i;
        troca = 0;
        for (j = 0; j < i; j++)
            if (fim[j] > fim[p]) {
                p = j;
                troca = 1;
            }
        aux = fim[i];
        fim[i] = fim[p];
        fim[p] = fim[j];

        aux = ini[i];
        ini[i] = ini[p];
        ini[p] = ini[j];
    }
}

void selec_atv(int n, int ini[], int fim[]) {
    int i, j;

    printf ("Aulas alocadas: ");

    i = 0;
    printf("%d ", i);

    for (j = 1; j < n; j++) {

        if (ini[j] >= fim[i]) {
            printf ("%d ", j);
            i = j;
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);
    int ini[n], fim[n];

    for (int i=0; i<n;i++){
        scanf("%d %d", &ini[i], &fim[i]);
    }

    selectsort(n, ini, fim);
    selec_atv(n, ini, fim);

    return 0;
}
