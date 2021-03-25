#include <stdio.h>

void contrarioString(char *string){
  if(*string){
    contrarioString(string+1);
    putchar(*string);
  }
}

int main(){

  char string[501];

  scanf("%s",string);
  contrarioString(string);
  printf("\n");

  return 0;
}
