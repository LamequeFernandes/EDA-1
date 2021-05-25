#include <stdio.h>
//#include <stdlib.h>

int main(){
   int num, restantes;
   scanf("%d", &num);
   if(num<2)
      return 0;
   int pilhaCartas[num+1], lixo[num-1];

   for(int j=1; j <= num; j++){
      pilhaCartas[j-1] = j;
   }

   for(int j=0, restantes=num; restantes>1; j++, restantes--){
      int k=0;
      int aux=pilhaCartas[1];
      lixo[j]=pilhaCartas[0];

   for(;k < 2;k++){
      for(int i=0; i<restantes; i++)
         pilhaCartas[i]=pilhaCartas[i+1];
   }
      
   pilhaCartas[restantes-2]=aux;
   if(restantes-2 == 1){
      lixo[j+1] = pilhaCartas[0];
      pilhaCartas[0] = pilhaCartas[1];
      break;
      }
   }

   printf("Cartas descartadas:");
      for(int j = 0; j < num - 2; j++)
         printf(" %d,", lixo[j]);
   printf(" %d\n", lixo[num - 2]);
   printf("Carta restante: %d\n", pilhaCartas[0]);   

}