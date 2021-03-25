#include <stdio.h>

int main(){

    int numPartidas, contadorUm = 0, contadorDois = 0, contadorTres = 0, numUm = 0, numDois = 0, soma = 0;
    char vencedor[numPartidas];
    char nomeUm[11], nomeDois[11];

    while (1){
        scanf("%d", &numPartidas);
        
        if (numPartidas == 0)
            break;

        else{    
            contadorTres = numPartidas;

            while (contadorDois < numPartidas) {
                scanf("%d %d", &numUm, &numDois);
                
                if (numUm < 0 && numUm > 5 && numDois < 0 && numDois > 5) {
                    soma = numUm + numDois;
                    
                    if ((soma % 2) == 0)
                        vencedor[numPartidas] = nomeUm[11];
                    else
                        vencedor[numPartidas] = nomeDois[11];        
                }
                else
                    break;
                
                contadorDois++;
            }
        }
    }

    return 0;
}