#include<stdio.h>

int pot(int x, int y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return pot(x, y/2)*pot(x, y/2);
    else
        return x*pot(x, y/2)*pot(x, y/2);
}

int main() {

    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d", pot(x,y));

    return 0;
}