#include <stdio.h>

int contaSete(long int num)
{
  int resultado;
  if ( num == 0 )
    resultado = 0;
  else
    resultado = ( num % 10 == 7) + contaSete( num / 10);

    return resultado;
}

int main(){
  long int num, resultado;
  scanf("%ld", &num);

  if(num >= 0){
  resultado = contaSete(num);
  printf("%ld\n", resultado);
  }

  return 0;
}
