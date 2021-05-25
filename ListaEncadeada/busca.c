#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x)
{
    celula *p;
    if(le == NULL){
        return le;
    }
    else{
        p = le->prox;
        while (p != NULL && p->dado != x){
            p = p->prox; 
        }
    return p;
    }
}

celula *busca_rec (celula *le, int x)
{
    if (le == NULL){ 
        return le;
    }
    else{  
        if(le -> dado == x){
            return le;
        }
        else{
            return busca_rec (le->prox, x);
        }
    }
}
