#include<stdio.h>
#include<stdlib.h>
/*
typedef struct no{
   int valor;
   struct no *proximo;
}no;

typedef struct{
   no *cabeca;
   int tam;
}Lista;

Lista* createList(){
   Lista* lista = malloc(sizeof(Lista));
   lista->tam = 0;
   lista->cabeca = NULL;
   return lista;
}

void insereInicio(Lista* lista, int x){
   no *novo = malloc(sizeof(no));
   novo->valor = x;
   novo->proximo = lista->
}

int main(){
   Lista *lista = createList();
   
   printf("%d\n", lista->tam);

   return 0;
}
*/

typedef struct no{
   int valor, tam;
   struct no *proximo;
}no;

no* createList(){
   no* lista = malloc(sizeof(no));
   lista->tam = 0;
   lista->proximo = NULL;
   return lista;
}


void insereInicio(no* lista, int x){
   no *novo = malloc(sizeof(no));
   novo->valor = x;
   novo->proximo = lista->proximo;
   lista->proximo = novo;
}

void printList(no *lista){
   no *aponta = lista = lista->proximo;

   if(aponta == NULL) 
      printf("Lista vazia");

   while(aponta != NULL){
      printf("%d ", aponta->valor);
      aponta = aponta->proximo;
   }

   printf("\n");
}

int main(){
   no *lista = createList();
   
   //printf("%d\n", lista->tam);

   insereInicio(lista, 7);
   insereInicio(lista, 12);
   insereInicio(lista, 4);

   printList(lista);

   //printf("%d %d\n", lista->proximo->valor, lista->proximo->proximo->valor);

   return 0;
}