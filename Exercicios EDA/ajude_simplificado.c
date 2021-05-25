#include<stdio.h>

int main(){
    int C1, C2, C3, T;
    scanf("%d %d %d", &C1, &C2, &C3);
    scanf("%d", &T);

    if (C1>=1 && C1<=100 && C2>=1 && C2<=100 && C3>=1 && C3<=100)
    {
        if (T >=1 && T<= 5000)
        {
            if (C1+C2+C3 == T)
            {
                printf("Acertou\n");
            }
            else
            {
                printf("Errou\n");
            }           
            
        }
        
    }

    return 0;
}