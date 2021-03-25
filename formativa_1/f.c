#include <stdio.h>

int main()
{
    int n, c=1;
    scanf("%d", &n);

    if (n >=1 && n < 100){    
    
        for (int li = 0; li < n; li++){
            for (int lj = 0; lj <= li; lj++){
                if (c < 10)                
                    printf("0%d ", c);                
                else
                    printf("%d ", c);
            }
            
            c++;
            printf("\n");
        }
        
        printf("\n");

        c = 1;

        for (int li = 0; li < n; li++){   
            c =0;     
            for (int lj = 0; lj <= li; lj++){
                c++;
                if (c < 10)
                    printf("0%d ", c);
                else
                    printf("%d ", c);
            }
            printf("\n");
        }
    }

    return 0;
}