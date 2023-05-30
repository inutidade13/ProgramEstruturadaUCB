#include<stdio.h>

struct aluno
{
   char nome[20];
   char telefone[20];
   char cpf[11];
   double todoDinheiroDisponivel;
};

struct professor
{
   char nome[20];
   char telefone[20];
   char cpf[11];
   double todoDinheiroDisponivelParaMim;
};



int main()
{
    struct aluno aluno1[2];
    struct professor professor1[2];
    int i;

    printf("Digite o nome do aluno:");
    scanf("%d", &aluno1.nome[i]);

    printf("Digite o telefone:");
    scanf("%s", &aluno1.telefone[i]);

    printf("Digite o cpf:");
    scanf("%d", &aluno1.cpf[i]);

    printf("Digite a quantidade de dinheiro:");
    scanf("%d", &aluno1.todoDinheiroDisponivel[i]);



}