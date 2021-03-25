#include <stdio.h>
#include <math.h>

int main(){
    int franquia=7, N;

    scanf("%d", &N);

    int quantia = N - 10;
    int quantia2 = franquia + 20 + ((N - 30) * 2);
    int quantia3 = franquia + 20 + 140 + (N - 100) * 5;
    int soma = 0;

    if (N >= 0 && N <= 1000)
    {
        if (N <=10 && N >=0)
            printf("%d\n", franquia);
        else if (N >=11 && N <= 30){
        soma = quantia + franquia;
            printf("%d\n", soma);
        }
        else if (N >= 31 && N <= 100)
            printf("%d\n", quantia2);
        else if (N >=101)
            printf("%d\n", quantia3);
    }

    return 0;
}