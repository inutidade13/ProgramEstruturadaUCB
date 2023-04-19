#include<stdio.h>


float celsiosfahrenheit (float celsios)
{
    return (9 * celsios/5) + 32;
}

float fahrenheitCelsios(float fahrenheit)
{
 return (fahrenheit - 32) + 5/9;
}

float celsiosreaumur(float reaumur)
{
    return reaumur * 4/5;
}

float kelvinCelsios(float kelvin, float fahrenheit)
{
    return kelvin - fahrenheit + 273.15;
}

int main ()
{
    float celsios , fahrenheit, reaumur, kelvin;
    int escolha, retorno;
    

do{
    printf("Selecione a coversao:\n ");
    printf("fahrenheit para Celsios (1)\n ");
    printf("Celsios para fahrenheit(2)\n ");
    printf("Celsios para reaumur(3)\n ");
    printf("Celsios para reaumur(4)\n ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
    {
        printf("digite a temperatura:");
        scanf("%f", &celsios);
        printf( "%0.1f\n", celsiosfahrenheit(celsios));
         break;
    }

    case 2 : 
    {
        printf("digite a temperatura:");
        scanf("%f", &fahrenheit);
        printf( "%0.1f\n", fahrenheitCelsios(fahrenheit));
        break;
    }

    case 3 :
    {
        printf("digite a temperatura:");
        scanf("%f", &fahrenheit);
        printf( "%0.1lf\n", fahrenheitCelsios(fahrenheit));
        break;
    }

    case 4 : 
     {
        printf("digite a temperatura:");
        scanf("%f%f", &kelvin, &fahrenheit);
        printf( "%0.1f\n", kelvinCelsios(kelvin, fahrenheit));
        break;
    }
    default:
        printf("invalido");
        break;
    }
     
    printf("deseja retornar ao inicio? sim(1) ou nao(0)?");
    scanf("%d",  &retorno);

    system("cls");

}while(retorno == 1);

}