#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int *dado;
  int topo;
} pilha;

void inicializa(pilha *p, int n){
    p -> topo = 0;
    p -> dado = malloc(n * sizeof(int));
    if(p == NULL) 
        exit(EXIT_FAILURE);
}

void empilha (pilha *p, int x){
    p ->dado[p->topo] = x;
    p->topo++;
}

int desempilha (pilha *p){
    int y = p -> dado[p->topo - 1];
    p->topo--;
    return y;
}

void enfileira(pilha *p){
    int ultimo = p->dado[p->topo - 1];
    for(int i = p-> topo; i > 0; i--){
        p->dado[i] = p->dado[i-1];
    }
    p->dado[0] = ultimo;
}    

int main(){

    int n;
    scanf("%d", &n);

    pilha *p = malloc(sizeof(pilha));
    inicializa(p, n);
    int *lixo = malloc((n-1) * sizeof(int));
    
    
	for(int i = n; i > 0; i--)
        empilha(p, i);

    for(int i = 0, j = n; j > 1; i++, j--){       
	    lixo[i] = desempilha(p);
        enfileira(p);
    }
    
    printf("Cartas descartadas:");
    for(int j = 0; j < n - 2; j++)
            printf(" %d,", lixo[j]);
    printf(" %d\n", lixo[n - 2]);
    printf("Carta restante: %d\n", p -> dado[0]);


    return 0;
}