#include<stdlib.h>
#include<stdio.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

int desenfileira(celula *f, int *y){
   celula *descarte = f->prox;
   if(f->prox!=NULL){
      *y = descarte->dado;
      f->prox = descarte->prox;
      free(descarte);
      return 1;
   }
   else
      return 0;
}