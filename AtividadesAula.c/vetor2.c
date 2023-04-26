#include<stdio.h>


int main()
{

    int num1[10], num2[10], soma[10];
    int i, count = 1;

  for (i = 0; i < 10; i++)
    {
        printf("insira dois numeros :");
        scanf("%d%d", &num1[i], &num2[i]);
        

        soma[i] = (num1[i] + num2[i]);

        

    }

      for (i = 0; i < 10; i++)
      {
        if (soma[i] % 2 == 0)
        {
            printf("%d Par\n", soma[i]);
        }
        
        else
        {
            printf("%d Impar\n", soma[i]);
        }
      }


}