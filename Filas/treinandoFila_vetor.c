#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
   int *v;
   int ini, fim, N;
}fila;

fila *f;

//criação 
fila *cria_fila(){
   fila *f = malloc(sizeof(fila));
   f->v = malloc(100*sizeof(int));
   f->N = 10;
   f->ini = 0;
   f->fim = 0;
   return f;
}

//remoção
int desenfileira(fila *f, int *y){
   if(f->ini == f->fim)
      return 0;
   *y = f->v[f->ini];
   f->ini = (f->ini+1) % f->N;
   return 1;
}

//fila cheia
int filha_cheia(fila *f){
   if(f->ini == 0 && f->fim == f->N-1 || f->ini == f-> fim+1)
      return 1;
   else
      return 0;
}



//insersão
int enfileira(fila *f, int x){
   if(fila_cheia(f))
      if(!redimensiona(f))
         return 0;
   f->v[f->fim] = x;
   f->fim = (f->fim+1) % f->N;
   return 1;
}

//destruir fila
void destroi_fila(fila *f){
   free(f->v);
   free(f);
}

