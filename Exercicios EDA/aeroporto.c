#include<stdio.h>

int main(){
    int voosAeroporto[101];
    int a, maior, v, x, y;

    scanf("%d %d", &a, &v);
    while (a != 0 && v !=0) {
        for(int i = 1; i <= a; i++) voosAeroporto[i] = 0;

        maior = 0;
        for (int i = 0; i < v; i++) {
            scanf("%d %d", &x, &y);
            voosAeroporto[x]++;
            voosAeroporto[y]++;

            if (voosAeroporto[x] > maior) maior = voosAeroporto[x];
            if (voosAeroporto[y] > maior) maior = voosAeroporto[y];
        }

        printf("Teste %d\n", teste);
        for(int i = 1; i <= a; i++)
            if(voosAeroporto[i] == maior) printf("%d", i); 

        printf("\n\n")      

        scanf("%d %d", &a, &v);
        teste++;
    }
    

    return 0;
}