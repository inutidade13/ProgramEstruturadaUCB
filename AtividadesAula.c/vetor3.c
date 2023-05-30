#include <stdio.h>
#include <string>

int main()
{
   int vetor[6], i, buscaNumero, count = 0, vetor2[6];
   char opcao;

    do{
    printf("Digite uma valor\n");
    scanf("%d", vetor[i]);
    i++;
    printf("deseja incluir mais um nuemro sim ou não");
    gets(opcao);
    }while(strcmp(opcao, "sim") == 0);


   for(i=0; i<6; i++){
    printf("digite um numero");
    scanf("%d", &vetor[i]);
    //vetor[i] = i * 5; prenchimemto automatico do for;
   }

   printf("Digite o numero");
   scanf("%d", &buscaNumero)

   for(i=0; i<6; i++)
   {
        if(buscaNumero == vetor[i]){
            vetor2[i][count] = i;
            count++;
        }
   }
    if(count == 0){
     printf("Quantidade de vezes que o numero %d aparece %d", buscaNumero, count);

    for(i = 0 ; i < count; i++)
    {
        printf("%d", vetor2);
    }
    }
    else
    {
        printf("nenhum numero aparece!");
    }
}
    






   
