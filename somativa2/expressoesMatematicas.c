#include<stdio.h>

int main () {
    //variaveis de entrada para a equacao
    int AColchete = 0, AChaves = 0, AParenteses= 0, i = 0; //A abre
    int FColchete = 0, FChaves= 0, FParenteses = 0; //F fecha
    char exp[520]; //expresssao
    //recebendo a expressao
    scanf("%c", &exp[0]);
    //processando os parentesis da equacao
    while (exp[i] != '\n' && exp[i] != '\0') {
        //adiciona todos os simbolos de abre e fecha da equacao, possibilitando a separacao
        if (exp[i] == '(') AParenteses++;
        if (exp[i] == '[') AColchete++;
        if (exp[i] == '{') AChaves++;
        if (exp[i] == ')') FParenteses++;
        if (exp[i] == ']') FColchete++;
        if (exp[i] == '}') FChaves++;
        //interpretamos a relacao de prioridade entre todos
        if (FParenteses > AParenteses || FColchete > AColchete || FChaves > AChaves){
            printf ("Nao1\n");
            break;
        }
         
        i++;
        scanf("%c", &exp[i]);

        //se houver ou nao a equacao ou quando chegar o fim
        if (exp[i] == '\n' || exp[i] == '\0') {
            if (AParenteses != FParenteses || AColchete != FColchete || AChaves != FChaves) {
                printf("Nao2\n");
            }
            else printf("Sim\n");
        }
    }
}