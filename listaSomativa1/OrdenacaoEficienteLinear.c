#include <stdio.h>
#include <stdlib.h>

int indice(int *vetor, int n) {
  int i;
  if (n==1)
    return 0;
  i = indice(vetor, n-1);
  if (vetor[n-1] > vetor[i])
    return n-1;
  return i;
}

void troca(int *vetor, int i, int j){
  int tmp = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = tmp;
}

void ordena(int *vetor, int n){
  if(n>0){
    int i = indice(vetor,n);
    troca(vetor,i,n-1);
    ordena(vetor,n-1);
  }
}

int main(){
    int n, i;
    int *vetor;
    scanf("%d", &n);
    vetor = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }   

    ordena(vetor, n);
    for(int i=0; i<n; i++)
        printf("%d ",vetor[i]);
    printf("\n");
    
    return 0;
}

