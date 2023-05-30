#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define quantidadeUsuarios 3
#define quantidadecaracteres 150

void removerNovaLinha(char *string)
{
    int tamanho = strlen(string);
    if (string[tamanho - 1] == '\n') {
        string[tamanho - 1] = '\0';
    }
}

void cadastrarUsuario(char nome[][quantidadecaracteres], char email[][quantidadecaracteres], char sexo[][quantidadecaracteres], char endereco[][quantidadecaracteres], double altura[], int vacina[])
{
    int i, validacao;


    for (i = 0; i < quantidadeUsuarios; i++)
    {
        printf("\n========== CADASTRO ==========\n");
        printf("\nDigite o nome do usu�rio %d:", i + 1);
        fgets(nome[i], quantidadecaracteres, stdin);
        removerNovaLinha(nome[i]);


        printf("Por favor %s, digite o seu E-mail:", nome[i]);
        fgets(email[i], quantidadecaracteres, stdin);
        removerNovaLinha(email[i]);

        do
        {
            printf("Por favor %s, digite o seu sexo (masculino/feminino/indiferente):", nome[i]);
            fgets(sexo[i], quantidadecaracteres, stdin);
            removerNovaLinha(sexo[i]);

            if (strcmp(sexo[i], "masculino") == 0 || strcmp(sexo[i], "feminino") == 0 || strcmp(sexo[i], "indiferente") == 0)
            {
                validacao = 1;
            }
            else
            {
                printf("Caracteres invalidos! Tente novamente.\n");
                validacao = 0;
            }

        } while (validacao == 0);

        printf("Por favor %s, digite seu endereco:", nome[i]);
        fgets(endereco[i], quantidadecaracteres, stdin);
        removerNovaLinha(endereco[i]);

        do
        {
            printf("Por favor %s, digite a sua altura:", nome[i]);
            scanf("%lf", &altura[i]);
            getchar(); 

            if (altura[i] < 1.0 || altura[i] > 2.0)
            {
                printf("Altura invalida! Digite um valor entre 1.0 e 2.0.\n");
            }

        } while (altura[i] < 1.0 || altura[i] > 2.0);

        printf("%s, você esta vacinado? (1 - sim / 2 - nao):", nome[i]);
        scanf("%d", &vacina[i]);
        getchar(); 
    }
}

void mostrarInformacoesUsuario(char nome[][quantidadecaracteres], char email[][quantidadecaracteres], char sexo[][quantidadecaracteres], char endereco[][quantidadecaracteres], double altura[], int vacina[])
{
    int i;

    for (i = 0; i < quantidadeUsuarios; i++)
    {
        printf("\n=== Informacoes do usuario %d ===\n", i + 1);
        printf("Nome: %s\n", nome[i]);
        printf("E-mail: %s\n", email[i]);
        printf("Sexo: %s\n", sexo[i]);
        printf("Endereco: %s\n", endereco[i]);
        printf("Altura: %.2lf\n", altura[i]);

        if (vacina[i] == 1)
        {
            printf("%s esta vacinado!\n", nome[i]);
        }
        else
        {
            printf("%s nao esta vacinado!\n", nome[i]);
        }
    }
}

void editarUsuario(char nome[][quantidadecaracteres], char email[][quantidadecaracteres], char sexo[][quantidadecaracteres], char endereco[][quantidadecaracteres], double altura[], int vacina[])
{
    int i, posicao, validacao;
    char buscaEmail[quantidadecaracteres];

    printf("Por favor digite o email do usuario que deseja editar:");
    fgets(buscaEmail, quantidadecaracteres, stdin);
    removerNovaLinha(buscaEmail);

    for (i = 0; i < quantidadeUsuarios; i++)
    {
        if (strcmp(buscaEmail, email[i]) == 0)
        {
            posicao = i;
            break;      
        }
    }

    if (i == quantidadeUsuarios)
    {
        printf("Usuario nao encontrado!\n");
        return; 
    }

    printf("\nDigite o nome do usuario %d:", posicao + 1);
    fgets(nome[posicao], quantidadecaracteres, stdin);
    removerNovaLinha(nome[posicao]);

    printf("Por favor %s, digite o seu E-mail:", nome[posicao]);
    fgets(email[posicao], quantidadecaracteres, stdin);
    removerNovaLinha(email[posicao]);

    do
    {
        printf("Por favor %s, digite o seu sexo (masculino/feminino/indiferente):", nome[posicao]);
        fgets(sexo[posicao], quantidadecaracteres, stdin);
        removerNovaLinha(sexo[posicao]);

        if (strcmp(sexo[posicao], "masculino") == 0 || strcmp(sexo[posicao], "feminino") == 0 || strcmp(sexo[posicao], "indiferente") == 0)
        {
            validacao = 1;
        }
        else
        {
            printf("Caracteres invalidos! Tente novamente.\n");
            validacao = 0;
        }

    } while (validacao == 0);

    printf("Por favor %s, digite seu endereco:", nome[posicao]);
    fgets(endereco[posicao], quantidadecaracteres, stdin);
    removerNovaLinha(endereco[posicao]);

    do
    {
        printf("Por favor %s, digite a sua altura:", nome[posicao]);
        scanf("%lf", &altura[posicao]);
        getchar(); 

        if (altura[posicao] < 1.0 || altura[posicao] > 2.0)
        {
            printf("Altura invalida! Digite um valor entre 1.0 e 2.0.\n");
        }

    } while (altura[posicao] < 1.0 || altura[posicao] > 2.0);

    printf("%s, voce esta vacinado? (1 - sim / 2 - não):", nome[posicao]);
    scanf("%d", &vacina[posicao]);
    getchar(); 
}

void buscarUsuario(char nome[][quantidadecaracteres], char email[][quantidadecaracteres], char sexo[][quantidadecaracteres], char endereco[][quantidadecaracteres], double altura[], int vacina[])
{
    int i, posicao;
    char buscaEmail[quantidadecaracteres];

         setlocale(LC_ALL, "pt_BR.UTF-8");

        printf("Por favor digite o email do usuario que deseja buscar:");
        fgets(buscaEmail, quantidadecaracteres, stdin);
        removerNovaLinha(buscaEmail);

         for (i = 0; i < quantidadeUsuarios; i++)
        {

            if (strcmp(buscaEmail, email[i]) == 0)
            {
                posicao = i; 
                break;
            }

            if (i == quantidadeUsuarios)
            {
                printf("Usuario nao encontrado!\n");
                return;
            }
        }
  
        if (strcmp(buscaEmail, email[i]) == 0)
        {
            printf("Nome: %s\n", nome[posicao]);
            printf("E-mail: %s\n", email[posicao]);
            printf("Sexo: %s\n", sexo[posicao]);
            printf("Endereco: %s\n", endereco[posicao]);
            printf("Altura: %.2lf\n", altura[posicao]);

            if (vacina[i] == 1)
            {
                printf("%s esta vacinado!\n", nome[posicao]);
            }
            else
            {
                printf("%s nao esta vacinado!\n", nome[posicao]);
            }
        }
            system("pause");
            system("cls");
        
    
}

void excluirUsuario(char nome[][quantidadecaracteres], char email[][quantidadecaracteres], char sexo[][quantidadecaracteres], char endereco[][quantidadecaracteres], double altura[], int vacina[])
{
    int i, posicao;
    char buscaEmail[quantidadecaracteres];

    printf("Por favor digite o email do usuario que deseja excluir:");
    fgets(buscaEmail, quantidadecaracteres, stdin);
    removerNovaLinha(buscaEmail);

    for (i = 0; i < quantidadeUsuarios; i++)
    {
        if (strcmp(buscaEmail, email[i]) == 0)
        {
            posicao = i; 
            break;      
        }
    }

    if (i == quantidadeUsuarios)
    {
        printf("Usuario nao encontrado!\n");
        return; 
    }
    if(strcmp(buscaEmail, email[i]) == 0)
    {
        strcpy(nome[posicao], "Dado excluído!");
        strcpy(email[posicao], "Dado excluído!");
        strcpy(sexo[posicao], "Dado excluído!");
        strcpy(endereco[posicao], "Dado excluído!");
        altura[posicao] = 0.0;
        vacina[posicao] = 0;

        printf("Informações do usuário excluídas:\n");
        printf("Nome: %s\n", nome[posicao]);
        printf("E-mail: %s\n", email[posicao]);
        printf("Sexo: %s\n", sexo[posicao]);
        printf("Endereço: %s\n", endereco[posicao]);
        printf("Altura: %.2lf\n", altura[posicao]);
        printf("Vacina: %d\n", vacina[posicao]);
    }
}


int main()
{
    char nome[quantidadeUsuarios][quantidadecaracteres];
    char email[quantidadeUsuarios][quantidadecaracteres];
    char sexo[quantidadeUsuarios][quantidadecaracteres];
    char endereco[quantidadeUsuarios][quantidadecaracteres];
    double altura[quantidadeUsuarios];
    int vacina[quantidadeUsuarios];
    int escolha, escolha2;

     setlocale(LC_ALL, "");

    cadastrarUsuario(nome, email, sexo, endereco, altura, vacina);

    system("cls");

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1 - Buscar usuarios\n");
        printf("2 - Mostrar informacoes dos usuarios\n");
        printf("3 - Excluir dados de um usuario\n");
        printf("4 - Editar usuarios\n");
        printf("5 - Sair\n");
        printf("==========================\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &escolha);
        getchar(); 

        system("cls");

        switch (escolha)
        {
        case 1:
            buscarUsuario(nome, email, sexo, endereco, altura, vacina);
            system("pause");
            system("cls");
            break;
        case 2:
            mostrarInformacoesUsuario(nome, email, sexo, endereco, altura, vacina);
            system("pause");
            system("cls");
            break;
        case 3:
            excluirUsuario(nome, email, sexo, endereco, altura, vacina);
            system("pause");
            system("cls");
            break;
         case 4:
            editarUsuario(nome, email, sexo, endereco, altura, vacina);
            mostrarInformacoesUsuario(nome, email, sexo, endereco, altura, vacina);
            system("pause");
            system("cls");
            break;
        case 5:
            printf("\nEncerrando o programa...\n");
            break;
        case 6: 
            printf("========One Piece Ep: 83 min: 17:03.========");
            system("pausse");
            system("cls");
            break;
        default:
            printf("\nOpção invalida! Tente novamente.\n");
        }

        if (escolha != 4)
        {
            printf("\nDeseja retornar ao menu? (1 - Sim / 0 - Não): ");
            scanf("%d", &escolha2);
            getchar(); 

             system("cls");

            if (escolha2 != 1)
            {
                printf("\nEncerrando o programa...\n");
            }
        }

    } while (escolha != 10 && escolha2 == 1);

    return 0;
}