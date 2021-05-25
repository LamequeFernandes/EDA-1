#include<stdio.h>

int main(){
    int totalTrilhas, totalPontos, subidaEsqDir,menorTrilha, menorSubidaTrilha, 
    subidaDirEsq, subidaTrilha, alturaAnterior, alturaAtual;
    
    scanf("%d", &totalTrilhas);
    for (int i = 0; i < totalTrilhas; i++){
        subidaEsqDir = subidaDirEsq = 0;
        scanf("%d", &totalPontos);
        scanf("%d", &alturaAnterior);
        for (int j = 1; j < totalPontos; j++){
            scanf("%d", &alturaAtual);
            if (alturaAtual > alturaAnterior)
                subidaEsqDir += (alturaAtual - alturaAnterior);
            else
                subidaDirEsq += (alturaAnterior - alturaAtual);       

            alturaAnterior = alturaAtual; 
        }

        if (subidaEsqDir < subidaDirEsq)
            subidaTrilha = subidaEsqDir;
        else 
            subidaTrilha = subidaDirEsq;        

        if (subidaTrilha < menorSubidaTrilha || i==0) {
            menorTrilha = i+1;
            menorSubidaTrilha = subidaTrilha;
        }
    }
    
    printf("%d\n", menorTrilha);

    return 0;
}