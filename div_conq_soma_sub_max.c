#include<stdio.h>

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int max1(int a, int b, int c){

    int x = max(a, b);
    return max(x, c);
}

int soma_max(int v[], int esq, int meio, int dir){

    int soma = 0, soma_esq = -10000;

    for(int i=meio; i>=esq; i--){
        soma += v[i];
        if(soma>soma_esq){
            soma_esq = soma;
        }
    }

    soma = 0;
    int soma_dir = -10000;
    for(int i =meio+1; i<=dir; i++){
        soma += v[i];
        if(soma>soma_dir){
            soma_dir = soma;
        }
    }

    return max1((soma_esq+soma_dir), soma_esq, soma_dir);

}

int sub_soma_max(int v[], int esq, int dir){

    if(esq == dir){
        return v[esq];
    }

    int meio = (esq + dir)/2;

    return max1(sub_soma_max(v, esq, meio), sub_soma_max(v, meio+1, dir), soma_max(v, esq, meio, dir));

}


int main() {

    int n;
    scanf("%d", &n);

    int v[n];
    for (int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    printf("%d", sub_soma_max(v, 0, n-1));

    return 0;
}
