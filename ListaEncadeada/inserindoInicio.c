#include <stdio.h>
#include <stdlib.h>
/*
typedef struct dataNode{
    int id;
} DataNode;

typedef struct node{
    DataNode data;
    struct node* next;
}Node;

typedef struct list {
    int size;
    Node* head;
} List;

List* createList(){
    List* list = malloc (sizeof(list));
} 
*/

//typedef struct no No;

typedef struct no {
    int num;
    struct  no *prox;   
} No;

No* criar_no(){
    No *novo = (No*)malloc(sizeof(No));
    return novo;
}

No* inserir_no_inicio(No* Lista, int dado){
    No *novo_no = criar_no();
    novo_no -> num = dado;

    if (Lista == NULL){
        Lista = novo_no;
        novo_no -> prox = NULL;
    }else{
        novo_no -> prox = Lista;
        Lista = novo_no;
    }
    return Lista;

}    

void imprimir_lista(No* Lista){
    No *aux = Lista;
    
    while (aux != NULL){
        printf("%d ", aux -> num);
        aux = aux->prox;
    }
    
    
}

int main() {
    
    No *Lista = NULL;
    Lista = inserir_no_inicio(Lista, 10);
    Lista = inserir_no_inicio(Lista, 20);
    imprimir_lista(Lista);
    

}














/*
{

    int valor ;
    
    int *ponteiro = &valor;
    int *ponteiro2;
    *ponteiro = 10;
    printf("Utilizando ponteiros\n\n");
    printf ("Conteudo da variavel valor: %d\n", valor);
    printf ("valor que o ponteiro aponta: %d\n", *ponteiro);
    printf ("Conteudo do ponteiro: %d\n", ponteiro);
    printf ("Endereco da variavel valor: %x \n", &valor);
    return 0;
}
*/