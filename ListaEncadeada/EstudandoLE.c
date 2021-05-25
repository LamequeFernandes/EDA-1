#include <stdio.h>
#include <stdlib.h>

typedef struct no{
   int dado;
   struct no *prox;   
} no;

//criar lista encadeada
no *cria_lista () {
    no *le = malloc (sizeof(no));    // criado um ponteiro le do tipo no, ou seja, aloca no no cabeça
    le -> prox = NULL;               // o prox que esta dentro da lista aponta para o NULL,      ou seja é o ultimo item da lista
    return le;
}

//insere no a lista encadeada
int insere(no *elem, int x){        // declara ponteiro de elem do tipo no e int x.
    no *novo = malloc(sizeof(no));   // cria um ponteiro novo do tipo no e coloca com malloc     ou seja, criando o novo no
    if(novo == NULL) return 0;       // verificando se o malloc deu certo ou n
    novo -> dado = x;                // o dado q esta presente na struct de novo recebe um inteiro x.
    novo->prox = elem->prox;         // o prox q esta em no recebe o prox q esta em elem         ou seja, vai receber o null
    elem->prox = novo;               // e o prox q esta em elem recebe a referencia de novo     ou seja, vai apontar para o novo
    return 1;
}

//remove um no da lista
int remover(no *elem, int *y){
    no *lixo = elem -> prox;         // declara ponteiro para lixo(no q sera apagado) e atribui o endereço do prox elem a ele
    if(lixo == NULL) return 0;        // para caso o no que for apagodo seja o ultimo termo
    elem -> prox = lixo -> prox;     // fala q o proximo do ele sera o proximo do lixo, como lixo sera apagado elem tem q apontar para oq o lixo apontava
    *y = lixo -> dado;               // guardando os dados do no q sera deletado para caso o usuario deseje utiliza o mesmo
    free(lixo);                      // libera a memoria do no deletado
    return 1;                        // demonstra q tudo deu ceerto com a funçao 
}

//imprime os elementos da lista 
void imprime(no *le){
    no *elem = le -> prox;           
    while(elem != NULL){                    
        printf("%d -> ", elem -> dado); 
        elem = elem -> prox;         //elem é um ponteiro q percorre cada elemento da lista ate chegar no null
    }
    printf("NULL\n");
}

void imprime_rec(no *le){
    if(le != NULL){        
        printf("%d -> ", le->dado);
        imprime_rec(le->prox);            
           
    }else
        printf("NULL\n");
}

void imprimir_menu(int *op){
    printf ("\n\nSelecione uma opção: \n");
    printf ("1 - Criar lista \n");
    printf ("2 - Inserir elemento no inicio \n");
    printf ("3 - Remover primeiro elemento \n");
    printf ("4 - Imprimir lista \n");
    printf ("5 - Imprimir de modo recusivo\n");
    printf ("0 - Sair\n");
    printf ("Digite sua opcao: \n");
    scanf("%d", op);
}

int main(){
    int dado, op;
    no *le;

    imprimir_menu (&op);
    while(op != 0){
        switch (op) {
            case 1:
                le = cria_lista();
                break;

            case 2:
                printf("Digite o novo dado: ");
                scanf ("%d", &dado);
                if(insere (le, dado))
                    printf("Elemento inserido com sucesso.\n");
                else{
                    printf("Problema na hora de inserir.\n");
                    return 1;
                }
                break;

            case 3:
                if(remover (le, &dado))                          // remove o primeiro elemento q vem depois do no que é passado como argumento
                    printf("Elemento removido: %d.\n", dado);    // nesse caso ele vai apagar o primeiro elemento q vem dps do no cabeça
                else
                    printf("A lista esta vazia.\n");
                break;

            case 4:
                imprime(le);
                break;
            
            case 5:
                imprime_rec(le->prox);
                break;
/*
            case 5:
                le = destroi_lista(le);
                break;
*/
        }

        imprimir_menu(&op);
    }

    return 0;
}