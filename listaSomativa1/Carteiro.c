#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    int i, j;
    scanf("%d%d", &n, &m)
    int *casas, *endCasas;
    casas = malloc(n * sizeof(int));


    for (i = 0; i < n; i++)
        scanf("%d", &casas[i]);    

    for (j = 0; j < m; j++)
        scanf("%d", &casas[j]);

    return 0;
}