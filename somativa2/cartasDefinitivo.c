#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
   int *dados;
   int N, p, u;
}celula;

celula *cria_fila(celula *f){
//   celula *f = malloc(sizeof(celula));
   f->dados = malloc(10*sizeof(int));
   f->N = 10;
   f->p = 0;
   f->u = 0;
   return f;
}

int redimensiona(celula *f){
   f->dados = realloc(f->dados, f->N * sizeof(celula));
   if(f->dados == NULL)
      return 0;
   if(f->p == 0 && f->u == f->N-1)
      f->dados[f->N - 1] = f->dados[f->p];
   else if(f->u < f->p){
      if(f->u - 1 < (f->N - f->p)){
         for(int i = 0, j = f->N; i<f->u; i++, j++)
            f->dados[j] = f->dados[i];
         f->u += f->N;
      }
      else{
         for(int i=f->p, j = f->N + f->p; i < f->N; i++, j++)
            f->dados[j] = f->dados[i];
         f->p += f->N;
      }
   }
   f->N *= 2;
   return 1;
} 

int fila_cheia(celula *f){
   if(f->p == 0 && f->u == f->N-1 || f->p == f-> u+1)
      return 1;
   else
      return 0;
}

int enfileira(celula *f, int x){
   if(fila_cheia(f))
      if(!redimensiona(f))
         return 0;
   f->dados[f->u] = x;
   f->u = (f->u+1) % f->N;
   return 1;
}

int desenfileira(celula *f, int *y){
   if(f->p == f->u)
      return 0;
   *y = f->dados[f->p];
   f->p = (f->p+1) % f->N;
   return 1;
}

int main() {
   int num;
   int count = 0;
   int valor;
   int temp;


   celula *f = malloc(sizeof(celula));
   cria_fila(f);

   scanf("%d",&num);
   int i = 1;
   while (i <= num){
      enfileira(f, i);
      i++;
   }

   printf("Cartas descartadas: ");

   while (count < num - 2) {
      desenfileira(f, &valor);
      printf("%d, ",valor);
      desenfileira(f, &temp);
      enfileira(f, temp);
      count++;
   }
   desenfileira(f, &valor);
   printf("%d\n",valor);
   desenfileira(f, &valor);
   printf("Carta restante: %d\n",valor);
}