#include <stdio.h>

float potenciacao(float a, float b){
  float resultado;
  if (b == 0)
    resultado = 1;
  else if (b < 0)
    resultado = (1/a)*potenciacao(a, b+1);
  else
    resultado = a*potenciacao(a, b-1);

  return resultado;
}
int main() {
  int a, b;
  float resultado;
  scanf("%d %d", &a, &b);

  if (a == 0 && b <= 0) {
    printf("indefinido\n");
  }
  else{
  resultado = potenciacao(a, b);
  printf("%.3f\n", resultado);
  }

  return 0;
}
