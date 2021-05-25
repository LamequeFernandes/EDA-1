#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
   char dado;
   int N, topo;
} pilha;

int desempilha(pilha *p){  
   if(p -> topo == NULL)
      return 0;
   else{      
      p -> topo--;
      return 1;
   }   
}

int empilha (pilha *p, int x){
   if(p -> topo == p -> N){
      p -> dado = realloc(p -> dado, 2 * p -> N * sizeof(int));
      if(p -> dado == NULL)
         return 0;
      p -> N *= 2;
   }
  
   p -> dado = x;
   p -> topo++;
   
   return 1;
}

int pilhavazia(pilha *p){
    if (p->topo == NULL)
        return 0;
    else
        return 1;
}

int balance(char *caractere, pilha *q){
    pilha *p = q;
    int i;
    int conta = 0;

    for (i = 0; i < strlen(caractere); i++){
        p = q;
        switch (caractere[i]){
        case '(':
            empilha(p, caractere[i]);
            conta++;
            break;

        case '{':
            empilha(p, caractere[i]);
            conta++;
            break;

        case '[':
            empilha(p, caractere[i]);
            conta++;
            break;

        case ')':
            if (p->topo == '('){
                desempilha(p);
                conta--;
                break;
            }

        case ']':
            if (p->topo == '['){
                desempilha(p);
                conta--;
                break;
            }

        case '}':
            if (p->dado == '{'){
                //printf("\n valor Desempilhado %c \n", p->final->dado);
                desempilha(p);
                conta--;
                break;
            }
        }
    }
    if (pilhavazia(p) == 0){
        return 0;
    }
    else{
        return conta;
    }
}

int main(){
   pilha *pilhadeeq;
   char eq[500];
   pilhadeeq = criapilha();
   gets(eq);
   int aux = balance(eq, pilhadeeq);
   if (aux == 0){
      printf("sim\n");
   }
   else if (aux != 0){
      printf("nao\n");
   }
   return 0;
}