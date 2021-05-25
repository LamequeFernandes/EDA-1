//#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
   int *dados;
   int N, topo;
} pilha;

/*
void *cria_pilha(){
   pilha *p = malloc(sizeof(pilha));
   p-> N = 100;
   p-> dados = malloc(p->N*sizeof(int));
   p->topo = -1;
   return p;
}


void pilha_inicia(pilha *p){
   p->topo = -1;
}

int pilha_vazia (pilha *p){
   if (p->topo == -1)
      return 1;
   else
      return 0;   
}

int pilha_cheia(pilha *p){
   if(p->topo == MAXTAM - 1)
      return 1;
   else
      return 0;
}


void empilha (pilha *p, int x){
   if(pilha_cheia(p) == 1)
      printf("ERRO: Pilha cheia\n");
   else{
      p->topo++;
      p->dados[p->topo] = x;
   }
}
*/

int desempilha(pilha *p, int *y){  
   if(p -> topo == NULL)
      return 0;
   else{      
      *y = p -> dados[p -> topo-1];
      p -> topo--;
      return 1;
   }   
}

/*
int pilha_remove (pilha *p){
   int aux;
   if(pilha_vazia(p))
      printf("ERRO: Pilha Vazia");
   else{
      aux = p->dados[p->topo];
      p->topo--;
      return aux;
   }
}

int main(){
   pilha *p = (pilha*)malloc(sizeof(pilha));
   pilha_inicia(p);

   empilha(p, 7);
   empilha(p, 12);
   empilha(p, 5);

   int aux;

   aux = pilha_remove(p);
   printf("\n SAIU: %d", aux);
   

   return 0;
}
*/