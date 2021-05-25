#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("*");
        while (i!= n-1)
        {
            printf("*");      
        }
         
        
    }
    


    return 0;
}