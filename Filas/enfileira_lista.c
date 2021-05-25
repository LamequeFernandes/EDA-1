#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

/*
void enfifira_01(celula **f, int x){
   celula *novo = malloc(sizeof(celula));
   novo->prox = (*f)->prox;
   (*f)->prox = novo;
   (*f)->dado = x;
   *f = novo;
}
*/
celula *enfileira(celula *f, int x){
   celula *novo = malloc(sizeof(celula));
   if(novo == NULL)
      return NULL;
   else{
      novo->prox = f->prox;
      f->prox = novo;
      f->dado = x;
      return novo;
   }
}

