#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
   char caracteres[100];
   struct pilha* prox;
}pilha;

int empilha (pilha *p, char x[100]){
   pilha *novo = malloc(sizeof(pilha));
   if(novo == NULL)
      return 0;
   else{
      strcpy(novo->caracteres, x);
      novo->prox = p->prox;
      p-> prox = novo;
      return 1;
   }
}

void *printList(pilha *le){
   pilha *aponta = le->prox;

   if(aponta == NULL) 
      printf("Lista vazia");
   else
      printf("pilha -> ");

   while(aponta != NULL){
      printf(" %s \n", aponta->caracteres);
      aponta = aponta->prox;
   }
}

int desempilha(pilha *p){
   pilha *lixo = p -> prox;
   if(p -> prox == NULL)
      return 0;
   else{        
      p -> prox = lixo -> prox;
      free(lixo);
      return 1;
   }
}

int main(){
   pilha *p;
   
   p = malloc(sizeof(pilha));
   p->prox = NULL;
   
   char x[10] ,frase[100];
   
   pilha *lixo = p->prox;
   while(scanf("%s", x) != EOF){

 //     scanf("%s", x);      
      if(strcmp(x, "desfazer") == 0){
         if(p->prox == NULL)
            printf("NULL\n");
         else
            printf("%s\n", p->prox->caracteres);            
            desempilha(p);      
      }
      if(strcmp(x, "inserir") == 0){
         scanf(" %[^\n]",frase);
         empilha(p, frase); 
      }
   }
}
