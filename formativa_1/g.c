#include <stdio.h>

int main (){

  int n;
  scanf("%d", &n);
  int c = 0;
  int i = 0, l=n-1, k = 1;
 
  for(int j = 0; j < n; j++) {
    
    for(int ii = 0; ii < l; ii++)
      printf(" ");
      
    for(i = 0; i < k; i++)
      printf("*");
      
      printf("\n");
      k += 2;
      l -= 1;        
    
  }

  return 0;
}
