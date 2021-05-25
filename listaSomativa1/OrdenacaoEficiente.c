#include <stdio.h>
#include <stdlib.h>

    void porSelecao(int *vetor, int n){
        int i, j;
        for (i = 0; i < n-1; i++){
            int m = i;
            for (j = i+1; j < n; j++)
                if (vetor[j] < vetor[m])
                    m = j;
            if(m != i){
                int aux = vetor[m];
                vetor[m] = vetor[i];
                vetor[i] = aux;
            }                          
        }            
} 

int main(){

    int n, i = 0;
    scanf("%d", &n);
    int *quantidadeElementos;
    quantidadeElementos = malloc(n * sizeof(int));

    while (i < n){
        scanf("%d", &quantidadeElementos[i]);
        i++;
    }
    
    porSelecao(quantidadeElementos, n);  

    for(int i=0; i<n-1; i++)
            printf("%d ",quantidadeElementos[i]);
            
    printf("%d\n", quantidadeElementos[n-1]);   

    free(quantidadeElementos);    
    return 0;
}
