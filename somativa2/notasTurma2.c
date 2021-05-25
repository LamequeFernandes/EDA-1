#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct celula{
   char matricula[10];
   double mediaAtividades;
   double mediaProvas;
   struct celula *prox;
}celula;


celula *cria_lista(){
   celula *le = malloc (sizeof(celula));
   le -> prox = NULL;
   return le;
}

void insereInicio(celula *le, char *m, double a, double p){
   celula *novo = malloc(sizeof(celula));
   strcpy(novo->matricula, m);
   novo->mediaAtividades = a;
   novo->mediaProvas = p;

   novo->prox = le->prox;
   le->prox = novo; 
}
 
void *printList(celula *le){
   celula *aponta = le->prox;

   if(aponta == NULL) 
      printf("Lista vazia");   

   while(aponta != NULL){
      printf(" {%s, ", aponta->matricula);
      printf("%.1f, ", aponta->mediaAtividades);
      printf("%.1f} ->", aponta->mediaProvas);
      aponta = aponta->prox;
   }
   if(aponta == NULL)
      printf(" NULL\n");
   printf("\n");
}

celula *chamadaL1(celula *le, celula *l1){
   l1->prox = le->prox;
   le->prox = le->prox->prox;
   l1->prox->prox = NULL;
   l1 = l1->prox;
   return l1;
}
celula *chamadaL2(celula *le, celula *l2){
   l2->prox = le->prox;
   le->prox = le->prox->prox;
   l2->prox->prox = NULL;
   l2 = l2->prox;
   return l2;
}

void relatorioMediaAtividades(celula *le, celula *l1, celula *l2, double media){
   for(le = le -> prox; le != NULL; le = le -> prox){
      if(le->prox->mediaAtividades <= media){
         l1->prox = le->prox;
         le->prox = le->prox->prox;
         l1->prox->prox = NULL;
         l1 = l1->prox;
      }
      else{
         l2->prox = le->prox;
         le->prox = le->prox->prox;
         l2->prox->prox = NULL;
         l2 = l2->prox;
      }
   }
}

/*
void relatorioMediaAtividades(celula *le, celula *l1, celula *l2, double media){  
//   celula *p = le->prox;
   while (le->prox != NULL){
      if(le->mediaAtividades <= media){
         for(int i = 0; i <= 10; i++)
            l1->prox->matricula[i] = le->prox->matricula[i];
         l1->prox->mediaAtividades = le->prox->mediaAtividades;
         l1->prox->mediaProvas = le->prox->mediaProvas;
         
         le->prox = le->prox->prox;
         l1->prox->prox = NULL;
         l1 = l1->prox;   
         
      }
      else{         
         for (int i = 0; i <= 10; i++)
            l2->prox->matricula[i] = le->prox->matricula[i];  
         l2->prox->mediaAtividades = le->prox->mediaAtividades;
         l2->prox->mediaProvas = le->prox->mediaProvas; 

         le->prox = le->prox->prox;
         l2->prox->prox = NULL;
         l2 = l2->prox;                     
      }      
   }   
}
*/

int main(){

   celula *le = cria_lista();
   celula *l1 = cria_lista();
   celula *l2 = cria_lista();

   insereInicio(le, "140164006", 10, 8);
   insereInicio(le, "160016169", 4, 2);
   insereInicio(le, "170062465", 9.5, 8.5);
   insereInicio(le, "190262661", 5, 7);
   printf("le ->");
   printList(le);
   relatorioMediaAtividades(le, l1, l2, 6);
   printf("l1 ->");
   printList(l1);
   printf("l2 ->");
   printList(l2);

   return 0;
}
