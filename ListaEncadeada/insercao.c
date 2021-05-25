//#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void insere_inicio(celula *le, int x){        // declara ponteiro de elem do tipo no e int x.
    celula *novo = malloc(sizeof(celula));   // cria um ponteiro novo do tipo no e coloca com malloc     ou seja, criando o novo no
    novo -> dado = x;                // o dado q esta presente na struct de novo recebe um inteiro x.
    novo->prox = le->prox;         // o prox q esta em no recebe o prox q esta em elem         ou seja, vai receber o null
    le->prox = novo;               // e o prox q esta em elem recebe a referencia de novo     ou seja, vai apontar para o novo
   
}

void insere_antes(celula *le, int x, int y) {
    celula *nova = malloc(sizeof(celula));
    nova -> dado = x;
    celula *p;
    for(p = le; p -> prox != NULL && p -> prox -> dado != y; p = p -> prox);
    nova -> prox = p -> prox;
    p -> prox = nova;
}
