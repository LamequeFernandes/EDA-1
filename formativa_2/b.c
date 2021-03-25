#include <stdio.h>

void reguaInglesa(int num) {
  if (num == 1)
    printf(".-\n");
  else{
    reguaInglesa(num-1);

    printf(".");
    for (int contador = 0 ; contador < num; contador++)
      printf("-");
    printf("\n");

    reguaInglesa(num-1);
  }
}

int main() {
  int num;

  scanf("%d", &num);

  if (num > 0) {
    reguaInglesa(num);
  }

  return 0;
}
