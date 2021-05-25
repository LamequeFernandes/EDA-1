#include<stdio.h>

int main(){
    char frase[10001], procura[41, substitui[41]];
    int posProcura;

    scanf(" %[^\n]", frase);
    scanf(" %s", procura);
    scanf(" %s", substitui);

    // o rato roeu a roupa do rei de roma
    //          rato 
    // o esquilo ro
    
    posProcura = 0;
    for(int i = 0; frase [i] != '\0'; i++) {
        if (procura[posProcura] == frase[i]) posProcura++;
        else {
            if(posProcura>0) {
                if(procura[posProcura] == '\0'){

                }
                else {
                    while(posProcura>0){
                        printf("%c", frase[i-posProcura]);
                        posProcura--;
                    }
                }
            }
            printf("%c", frase[i]);
        }
    }
    return 0;
}