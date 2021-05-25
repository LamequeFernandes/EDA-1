#include <stdlib.h>

typedef struct celula{
   int dado;
   struct celula *prox;
}celula;

int desempilha(celula *p, int *y){
   celula *lixo = p -> prox;
   if(p -> prox == NULL)
      return 0;
   else{   
      *y = lixo -> dado;
      p -> prox = lixo -> prox;
      free(lixo);
      return 1;
   }
}
