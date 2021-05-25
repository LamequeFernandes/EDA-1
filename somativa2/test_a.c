#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
  int dado;
  struct celula *prox;
}celula;

void insere(celula *le, int x){
  celula *p;
  celula *nova = malloc(sizeof(celula));
  nova->dado = x;
  for(p=le; p->prox!=NULL; p=p->prox);
  nova->prox = p->prox;
  p->prox = nova;
}
void *imprime(celula *le){
  if(le==NULL)
    printf("NULL\n");
  else{
    for(celula *p=le->prox; p!=NULL; p=p->prox)
      printf("%d -> ",p->dado);
    printf("NULL\n");
  }
}

void divide_lista(celula *l, celula *l1, celula *l2){
  celula *p= l->prox;
  while(p!=NULL){
    if(p->dado % 2 == 0){
      l2->prox = p;
      p = p->prox;
      l2->prox->prox = NULL;
      l2 = l2->prox;
    }
    else{
      l1->prox = p;
      p = p->prox;
      l1->prox->prox = NULL;
      l1 = l1->prox;
    }
  }
}

int main(){
  int x;
  celula *l, *l1, *l2;
  l = malloc(sizeof(celula));
  l1 = malloc(sizeof(celula));
  l2 = malloc(sizeof(celula));
  l->prox = NULL;
  l1->prox = NULL;
  l2->prox = NULL;
  for(int i=0; i<6; i++){
    scanf("%d",&x);
    insere(l,x);
  }
  printf("\nl -> ");
  imprime(l);
  divide_lista(l,l1,l2);
  printf("\nl1 -> ");
  imprime(l1);
  printf("\nl2 -> ");
  imprime(l2);
  return 0;
}
