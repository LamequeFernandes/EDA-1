#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no *prox;
} No;

No* criar_no(){
    No *no =(No*)malloc(sizeof(No));
    return no;
}

No* inserir_elem_fim(No *Lista, int dado){
    No *no = criar_no();
    no -> num = dado; 

    if(Lista == NULL){
        no->prox=NULL;
        Lista = no;
    } 
    else{
        No* aux = Lista;
        while (aux-> prox != NULL){
            aux = aux->prox;
        }
        no->prox = NULL;
        aux->prox = no;      
    }
    return Lista;
}

void imp(No* Lista){
    No* aux = Lista;
    while (aux != NULL){
        printf("%d ", aux->num);
        aux = aux -> prox;
        }   
    printf("\n");      
}

void imp_rec(No* Lista){
    if(Lista != NULL){
        printf("%d ", Lista -> num);
        imp_rec(Lista -> prox);
    }     
}

int main(){

    No* lista=NULL;
    lista = inserir_elem_fim(lista, 1);
    lista = inserir_elem_fim(lista, 2);
    lista = inserir_elem_fim(lista, 3);
    
    imp(lista);
    imp_rec(lista);

    return 0;
}
