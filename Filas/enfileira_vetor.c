#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
   int *dados;
   int N, p, u;
}fila;
/*
//criação 
fila *cria_fila(){
   fila *f = malloc(sizeof(fila));
   f->dados = malloc(100*sizeof(int));
   f->N = 10;
   f->p = 0;
   f->u = 0;
   return f;
}

//remoção
int desenfileira(fila *f, int *y){
   if(f->p == f->u)
      return 0;
   *y = f->dados[f->p];
   f->p = (f->p+1) % f->N;
   return 1;
}
*/
//fila cheia
int fila_cheia(fila *f){
   if(f->p == 0 && f->u == f->N-1 || f->p == f-> u+1)
      return 1;
   else
      return 0;
}

//redimenciona
int redimensiona(fila *f){
   f->dados = realloc(f->dados, f->N * sizeof(fila));
   if(f->dados == NULL)
      return 0;
    if(f->p == 0 && f->u == f->N-1)
      f->dados[f->N - 1] = f->dados[f->p];
    else if(f->u < f->p){
      if(f->u - 1 < (f->N - f->p)){
        for(int i = 0, j = f->N; i<f->u; i++, j++)
          f->dados[j] = f->dados[i];
        f->u += f->N;
      }
      else{
        for(int i=f->p, j = f->N + f->p; i < f->N; i++, j++)
          f->dados[j] = f->dados[i];
        f->p += f->N;
      }
    }
    f->N *= 2;
    return 1;
  } 

//insersão
int enfileira(fila *f, int x){
   if(fila_cheia(f))
      if(!redimensiona(f))
         return 0;
   f->dados[f->u] = x;
   f->u = (f->u+1) % f->N;
   return 1;
}
/*
//destruir fila
void destroi_fila(fila *f){
   free(f->dados);
   free(f);
}
*/