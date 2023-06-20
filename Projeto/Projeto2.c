#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USUARIOS 100
#define MAX_CARACTERES 50

struct Usuario {
    char nome[MAX_CARACTERES];
    char email[MAX_CARACTERES];
    char sexo[MAX_CARACTERES];
    char endereco[MAX_CARACTERES];
    double altura;
    int vacina;
};

void removerNovaLinha(char* str) {
    int tamanho = strlen(str);
    if (str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}

void cadastrarUsuario(struct Usuario usuarios[], int quantidadeUsuarios) {
    int i, validacao;

    for (i = 0; i < quantidadeUsuarios; i++) {
        printf("\n========== CADASTRO ==========\n");
        printf("\nDigite o nome do usuário %d: ", i + 1);
        fgets(usuarios[i].nome, MAX_CARACTERES, stdin);
        removerNovaLinha(usuarios[i].nome);

        printf("Por favor, %s, digite o seu E-mail: ", usuarios[i].nome);
        fgets(usuarios[i].email, MAX_CARACTERES, stdin);
        removerNovaLinha(usuarios[i].email);

        do {
            printf("Por favor, %s, digite o seu sexo (masculino/feminino/indiferente): ", usuarios[i].nome);
            fgets(usuarios[i].sexo, MAX_CARACTERES, stdin);
            removerNovaLinha(usuarios[i].sexo);

            if (strcmp(usuarios[i].sexo, "masculino") == 0 || strcmp(usuarios[i].sexo, "feminino") == 0 || strcmp(usuarios[i].sexo, "indiferente") == 0) {
                validacao = 1;
            }
            else {
                printf("Caracteres inválidos! Tente novamente.\n");
                validacao = 0;
            }
        } while (validacao == 0);

        printf("Por favor, %s, digite seu endereço: ", usuarios[i].nome);
        fgets(usuarios[i].endereco, MAX_CARACTERES, stdin);
        removerNovaLinha(usuarios[i].endereco);

        do {
            printf("Por favor, %s, digite a sua altura: ", usuarios[i].nome);
            scanf("%lf", &usuarios[i].altura);
            getchar();

            if (usuarios[i].altura < 1.0 || usuarios[i].altura > 2.0) {
                printf("Altura inválida! Digite um valor entre 1.0 e 2.0.\n");
            }
        } while (usuarios[i].altura < 1.0 || usuarios[i].altura > 2.0);

        printf("%s, você está vacinado? (1 - sim / 2 - não): ", usuarios[i].nome);
        scanf("%d", &usuarios[i].vacina);
        getchar();
    }
}

void mostrarInformacoesUsuario(struct Usuario usuarios[], int quantidadeUsuarios) {
    int i;

    for (i = 0; i < quantidadeUsuarios; i++) {
        printf("\n=== Informações do usuário %d ===\n", i + 1);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("E-mail: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf\n", usuarios[i].altura);

        if (usuarios[i].vacina == 1) {
            printf("%s está vacinado!\n", usuarios[i].nome);
        }
        else {
            printf("%s não está vacinado!\n", usuarios[i].nome);
        }
    }
}

void editarUsuario(struct Usuario usuarios[], int quantidadeUsuarios) {
    int i, posicao, validacao;
    char buscaEmail[MAX_CARACTERES];

    printf("Por favor, digite o email do usuário que deseja editar: ");
    fgets(buscaEmail, MAX_CARACTERES, stdin);
    removerNovaLinha(buscaEmail);

    for (i = 0; i < quantidadeUsuarios; i++) {
        if (strcmp(buscaEmail, usuarios[i].email) == 0) {
            posicao = i;
            break;
        }
    }

    if (i == quantidadeUsuarios) {
        printf("Usuário não encontrado!\n");
        return;
    }

    printf("\nDigite o nome do usuário %d: ", posicao + 1);
    fgets(usuarios[posicao].nome, MAX_CARACTERES, stdin);
    removerNovaLinha(usuarios[posicao].nome);

    printf("Por favor, %s, digite o seu E-mail: ", usuarios[posicao].nome);
    fgets(usuarios[posicao].email, MAX_CARACTERES, stdin);
    removerNovaLinha(usuarios[posicao].email);

    do {
        printf("Por favor, %s, digite o seu sexo (masculino/feminino/indiferente): ", usuarios[posicao].nome);
        fgets(usuarios[posicao].sexo, MAX_CARACTERES, stdin);
        removerNovaLinha(usuarios[posicao].sexo);

        if (strcmp(usuarios[posicao].sexo, "masculino") == 0 || strcmp(usuarios[posicao].sexo, "feminino") == 0 || strcmp(usuarios[posicao].sexo, "indiferente") == 0) {
            validacao = 1;
        }
        else {
            printf("Caracteres inválidos! Tente novamente.\n");
            validacao = 0;
        }

    } while (validacao == 0);

    printf("Por favor, %s, digite seu endereço: ", usuarios[posicao].nome);
    fgets(usuarios[posicao].endereco, MAX_CARACTERES, stdin);
    removerNovaLinha(usuarios[posicao].endereco);

    do {
        printf("Por favor, %s, digite a sua altura: ", usuarios[posicao].nome);
        scanf("%lf", &usuarios[posicao].altura);
        getchar();

        if (usuarios[posicao].altura < 1.0 || usuarios[posicao].altura > 2.0) {
            printf("Altura inválida! Digite um valor entre 1.0 e 2.0.\n");
        }

    } while (usuarios[posicao].altura < 1.0 || usuarios[posicao].altura > 2.0);

    printf("%s, você está vacinado? (1 - sim / 2 - não): ", usuarios[posicao].nome);
    scanf("%d", &usuarios[posicao].vacina);
    getchar();
}

void buscarUsuario(struct Usuario usuarios[], int quantidadeUsuarios) {
    char buscaEmail[MAX_CARACTERES];
    bool encontrado = false;

    printf("Por favor, digite o email do usuário que deseja buscar: ");
    fgets(buscaEmail, MAX_CARACTERES, stdin);
    removerNovaLinha(buscaEmail);

    for (int i = 0; i < quantidadeUsuarios; i++) {
        if (strcmp(buscaEmail, usuarios[i].email) == 0) {
            encontrado = true;
            printf("\n=== Informações do usuário ===\n");
            printf("Nome: %s\n", usuarios[i].nome);
            printf("E-mail: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            if (usuarios[i].vacina == 1) {
                printf("%s está vacinado!\n", usuarios[i].nome);
            } else {
                printf("%s não está vacinado!\n", usuarios[i].nome);
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado!\n");
    }
}

void excluirUsuario(struct Usuario usuarios[], int quantidadeUsuarios, const char buscaEmail[]) {
    int posicao = -1;

    for (int i = 0; i < quantidadeUsuarios; i++) {
        if (strcmp(buscaEmail, usuarios[i].email) == 0) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("Usuário não encontrado!\n");
        return;
    }

    strcpy(usuarios[posicao].nome, "Dado excluído!");
    strcpy(usuarios[posicao].email, "Dado excluído!");
    strcpy(usuarios[posicao].sexo, "Dado excluído!");
    strcpy(usuarios[posicao].endereco, "Dado excluído!");
    usuarios[posicao].altura = 0.0;
    usuarios[posicao].vacina = 0;

    printf("Informações do usuário excluídas:\n");
    printf("Nome: %s\n", usuarios[posicao].nome);
    printf("E-mail: %s\n", usuarios[posicao].email);
    printf("Sexo: %s\n", usuarios[posicao].sexo);
    printf("Endereço: %s\n", usuarios[posicao].endereco);
    printf("Altura: %.2lf\n", usuarios[posicao].altura);
    printf("Vacina: %d\n", usuarios[posicao].vacina);
}

int main() {
    struct Usuario usuarios[MAX_USUARIOS];
    int quantidadeUsuarios;
    int opcao;

    printf("Digite a quantidade de usuários a cadastrar: ");
    scanf("%d", &quantidadeUsuarios);
    getchar();

    cadastrarUsuario(usuarios, quantidadeUsuarios);

    printf("\n========== INFORMAÇÕES DOS USUÁRIOS ==========\n");
    mostrarInformacoesUsuario(usuarios, quantidadeUsuarios);

    do {
        printf("\n========== MENU DE OPÇÕES ==========\n");
        printf("1. Editar um usuário\n");
        printf("2. Buscar um usuário\n");
        printf("3. Excluir um usuário\n");
        printf("4. Sair\n");
        printf("Digite o número da opção desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                editarUsuario(usuarios, quantidadeUsuarios);
                printf("\n========== INFORMAÇÕES DOS USUÁRIOS (APÓS EDIÇÃO) ==========\n");
                mostrarInformacoesUsuario(usuarios, quantidadeUsuarios);
                break;
            case 2:
                buscarUsuario(usuarios, quantidadeUsuarios);
                break;
            case 3:
                char buscaEmail[MAX_CARACTERES];
                 printf("Digite o email do usuário que deseja excluir: ");
                fgets(buscaEmail, MAX_CARACTERES, stdin);
                removerNovaLinha(buscaEmail);
                excluirUsuario(usuarios, quantidadeUsuarios, buscaEmail);
                printf("\n========== INFORMAÇÕES DOS USUÁRIOS (APÓS EXCLUSÃO) ==========\n");
                mostrarInformacoesUsuario(usuarios, quantidadeUsuarios);
                break;
            case 4:
                printf("Encerrando o programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida! Digite um número válido.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
