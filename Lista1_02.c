#include<stdio.h>
#include<math.h>

float eixos (float x1, float x2, float y1, float y2)
{
    return sqrt(pow((x2 - x1) , 2) + pow((y2 - y1), 2));


}

int main()
{

float x1, y1, x2, y2, resultado;

    printf("Digite 4 numeros: ");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

   printf("Resultado: %.4f", eixos(x1, y1, x2, y2));

}