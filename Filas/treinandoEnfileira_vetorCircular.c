#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
  int *dados;
  int N, p, u;
}fila;

void inicializa(fila *f){
  f->N = 1;
  f->dados = malloc(sizeof(int));
  if(f->dados==NULL)
    exit(EXIT_FAILURE);
  f->p = 0;
  f->u = 0;
}

int enfileira(fila *f, int x){
  int i,j;
  if((f->u + 1) % f->N == f->p){
    f->dados = realloc(f->dados, f->N * sizeof(fila));
    if(f->dados==NULL)
      return 0;
    if(f->p==0 && f->u==f->N-1)
      f->dados[f->N-1] = f->dados[f->p];
    else if(f->u < f->p){
      if(f->u-1<(f->N-f->p)){
        for(i=0, j=f->N; i<f->u; i++, j++)
          f->dados[j] = f->dados[i];
        f->u += f->N;
      }
      else{
        for(i=f->p, j = f->N+f->p; i < f->N; i++, j++)
          f->dados[j] = f->dados[i];
        f->p += f->N;
      }
    }
    f->N*=2;
  }
  f->dados[f->u++] = x;
  if(f->u == f->N)
    f->u = 0;
  return 1;
}

void imprime(fila *f){
  for(int i=0; i<f->N; i++)
    printf("%d ",f->dados[i]);
  printf("\n");
}
int main(){
  fila f;
  inicializa(&f);
  for(int i=1; i<=4; i++){
    enfileira(&f,i);
    printf("%dª iteração: ",i);
    imprime(&f);
  }
  return 0;
}