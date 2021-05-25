#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
  int *dados;
  int N, topo;
}pilha;

void inicializa(pilha *p){
  p->N = 10;
  p->dados = malloc(p->N * sizeof(int));
  if(p->dados==NULL)
    exit(EXIT_FAILURE);
  p->topo = 0;
}

int empilha(pilha *p, int x){
  if(p->topo == p->N){
    p->dados = realloc(p->dados, 2 * p->N * sizeof(int));
    if(p->dados == NULL)
      return 0;
    p->N *= 2;
  }
  p->dados[p->topo] = x;
  p->topo++;
  return 1;
}

int desempilha(pilha *p, int *y){
  if(p->topo == 0)
    return 0;
  *y = p->dados[p->topo];
  p->topo--;
  return 1;
}

void imprime(pilha *p){
  printf(" __\n");
  for(int i=p->topo-1; i>=0; i--){
    printf("|");
    printf("%d", p->dados[i]);
    if(p->dados[i]<10)
      printf(" ");
    printf("|\n");
  }
}

void destroi(pilha *p){
  free(p->dados);
}

int main(){
  int x,*y;
  pilha p;
  inicializa(&p);
  empilha(&p,1);
  empilha(&p,2);
  empilha(&p,3);
  desempilha(&p,y);
  imprime(&p);
  destroi(&p);
  return 0;
}