#include <stdio.h>

int somaDigitos(long int num){
  int resultado, resto = 0;
  if(num / 10 == num)
    resultado = num;
  else{
    resto = num % 10;
    resultado = somaDigitos(num / 10)+ resto;
  }
  return resultado;
}

int main(){

 long int num;
 long int resultado;
 scanf("%ld", &num);

 if (num >= 0) {
   resultado = somaDigitos(num);
   printf("%ld\n", resultado);
 }

 return 0;
}
