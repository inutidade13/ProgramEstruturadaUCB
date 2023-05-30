#include<stdio.h>


void preenchervetor( double *vetor1)
{
    int i;

     for(i = 0; i < 5; i++){
        printf("digite um numero");
        scanf("%lf", &vetor1[i]);
     }
}

void imprimirvetor( double *vetor1)
{
    int i;
    
    for(i = 0; i < 5; i++)
    {
        printf("quaquer coisa %.1lf\n" , vetor1[i]);
    }



}

int main()
{
   
    double vetor1[5];

    preenchervetor(vetor1);
    imprimirvetor(vetor1);

}