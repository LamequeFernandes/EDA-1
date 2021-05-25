#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
   char expressao;
   struct pilha *prox;
}pilha;

int empilha (pilha *p, char x){
   pilha *novo = malloc(sizeof(pilha));
   if(novo == NULL)
      return 0;
   else{
 //     strcpy(novo->expressao, x);
      novo -> expressao = x;
      novo -> prox = p -> prox;
      p -> prox = novo;
      return 1;
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
   char exp[500];
   pilha *p = malloc(sizeof(pilha));
//   pilha *p2 = malloc(sizeof(pilha));
//   pilha *p3 = malloc(sizeof(pilha));

   p->prox = NULL;

   scanf("%s", exp);
   for(int i = 0; exp[i] != '\0'; i++){
      if(exp[i] == '('){
         empilha(p, exp[i]);
      }
      else if(exp[i] == ')'){
         if(p->prox == NULL)
            empilha(p, exp[i]);  
         else if(p->prox->expressao == '(')
            desempilha(p);
      }
/////////////////////////////////////////////////////////////////////
      else if(exp[i] == '['){
            empilha(p, exp[i]);
      }
      else if(exp[i] == ']'){
         if(p->prox == NULL)
            empilha(p, exp[i]);  
         else if(p->prox->expressao == '[')
            desempilha(p);
      }
//////////////////////////////////////////////////////////////////
      else if(exp[i] == '{'){
         empilha(p, exp[i]);
      }
      else if(exp[i] == '}'){
         if(p->prox == NULL)
            empilha(p, exp[i]);
         else if(p->prox->expressao == '{')
            desempilha(p);
      }
   }

   if(p->prox == NULL /*&& p2->prox == NULL && p3->prox == NULL*/)
      printf("sim\n");
   else
      printf("nao\n");

   return 0;
}
