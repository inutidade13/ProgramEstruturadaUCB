#include<stdio.h>

int main ()
{
    

    int i, repeticao1, repeticao2;

    printf("Insira um numero:");
    scanf("%d", &repeticao1);

    printf("Insira um numero:");
    scanf("%d", &repeticao2);



    for ( i = repeticao1; i < repeticao2; i++)
    {
        if ( i % 2 == 1)
        {
            printf("%d\n", i);
        }
       
    }
    
}