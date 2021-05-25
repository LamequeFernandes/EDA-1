#include <stdio.h>
#include <stdlib.h>

typedef struct celulaPilha {
   int *info;
   int topo;
} celulaPilha;

void criaFila(celulaPilha *p, int n){
    p -> topo = 0;
    p -> info = malloc(n * sizeof(int));
}

void empilhamento (celulaPilha *p, int x){
   p ->info[p->topo] = x;
   p->topo++;
}

int desempilhamento (celulaPilha *p){
   int y = p -> info[p->topo - 1];
   p->topo--;
   return y;
}

void enfileiramento(celulaPilha *p){
   int u = p->info[p->topo - 1];
   int i = p-> topo;
   while(i >= 1){
      p->info[i] = p->info[i-1];
      i--;
   }
   p->info[0] = u;
}

int main(){

   int num;
   scanf("%d", &num);

   if(num<2)
      return 0;

   celulaPilha *p = malloc(sizeof(celulaPilha)); 
   criaFila(p, num);

   int *descarte = malloc((num-1) * sizeof(int));   
    
   int i = num;
	while(i >= 1){
      empilhamento(p, i);
      i--;
   }

   i = 0;
   int j = num;
   while(j >= 2){       
	   descarte[i] = desempilhamento(p);
      int ultimo = p->info[p->topo - 1];
      for(int i = p-> topo; i >= 1; i--){
        p->info[i] = p->info[i-1];
      }
      p->info[0] = ultimo;
      i++;
      j--;
   }
    
   printf("Cartas descartadas: ");
   i = 0;
   while(i < num - 1){
      if(i + 1 != num - 1)
         printf("%d, ", descarte[i]);
      else printf("%d\n", descarte[i]);
      i++;
   }
   printf("Carta restante: %d\n", p->info[0]);

   free(p);
   return 0;
}