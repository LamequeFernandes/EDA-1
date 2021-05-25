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
   else
      printf("le ->");

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


void relatorioMediaAtividades(celula *le, celula *l1, celula *l2, double media){  
// celula *aux = le->prox;
   while (le->prox != NULL){
      if(le->prox->mediaAtividades >= media){
         for(int i = 0; i <= 10; i++)
            l1->matricula[i] = le->matricula[i];
         l1->mediaAtividades = le->mediaAtividades;
         l1->mediaProvas = le->mediaProvas;
         le->prox->prox = NULL;
         l1->prox->prox = NULL;
         l1 = l1->prox;
      }
      else{
         for(int i = 0; i <= 10; i++)
            l2->matricula[i] = le->matricula[i];
         l2->mediaAtividades = le->mediaAtividades;
         l2->mediaProvas = le->mediaProvas;
         le->prox->prox = NULL;
         l2->prox->prox = NULL;
         l2 = l2->prox;
      }      
   }   
}

int main(){

   celula *le = cria_lista();
   celula *l1 = cria_lista();
   celula *l2 = cria_lista();

   insereInicio(le, "180104390", 7.8, 8.8);
   insereInicio(le, "160104000", 4, 3);
   insereInicio(le, "190104390", 3.8, 9.8);
   printList(le);
   relatorioMediaAtividades(le, l1, l2, 5);
   printList(l1);

   return 0;
}












/*void chamadaL1(celula *l1){
   celula *aponta = l1->prox;  
   
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
*/