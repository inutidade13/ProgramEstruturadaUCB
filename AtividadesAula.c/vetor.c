#include<stdio.h>
#include<math.h>


int main()
{
    float notas1[4], notas2[4], media[4];
    int i, count = 1;

    for (i = 0; i < 4; i++)
    {
        printf("Isira as notas");
        scanf("%f%f", &notas1[i], &notas2[i]);

        media[i] = (notas1[i] + notas2[i]) /2;

        printf("%f\n", media[i]);

    }

    for (i = 0; i < 4; i++)
    {
        printf("Medias Aluno%d:%.1f\n", count , media[i]);
        count++;

    }
     

        





}