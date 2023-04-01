#include<stdio.h>
#include<string.h>

int main()
{
    char cor[20];
    
    printf("Digite uma cor: ");
    gets(cor);

        if (strcmp(cor, "verde") == 0)
        {
             printf("Cor valida!");
        }
        else if(strcmp(cor, "branco") == 0)
        {
            printf("Cor valida!");
        }
        else if(strcmp(cor, "amarelo") == 0)
        {
             printf("Cor valida!");
        }
        else
        {
            printf("Cor invalida!");
        }
        }       

