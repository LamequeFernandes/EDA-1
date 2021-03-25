#include <stdio.h>

int main (){
  int n, i = -2147483648;
  
  while(scanf ("%d", &n) != EOF){    
   if (n > i)
   {
     i = n;
   }   
    
  }


    printf("%d\n", i);

  return 0; 
}

