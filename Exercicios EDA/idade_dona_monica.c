#include<stdio.h>
int main(){
    int M, A, B;
    int C=0;
    scanf("%d", &M);
    scanf("%d", &A);
    scanf("%d", &B);

    if (M>=40 && M<=110 && A>=1 && A<M && B>=1 && B<M && A!=B)
    {
        C = M-A-B;
        if (A > B && A> C)
            printf("%d\n", A);
        else if (B > A && B > C)
            printf("%d\n", B);
        else 
            printf("%d\n", C);            
        
    }
    
    return 0;
}