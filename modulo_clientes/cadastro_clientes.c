#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CLIENTE_ARQ "./Data/clientes.txt"

int gerarNovoIDCliente() {
    FILE *arquivo = fopen(CLIENTE_ARQ, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    int numRegistros = 0;
    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numRegistros++;
    }

    fclose(arquivo);

    return numRegistros + 1;
}

void cadastrarClienteArq(int idCliente, char nome[50], char telefone[15], char cpf[11], char email[50]) {
    FILE *arquivo = fopen(CLIENTE_ARQ, "a+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arquivo, "%i %s %s %s %s\n", idCliente, nome, telefone, cpf, email);

    fclose(arquivo);
}

void cadastrarCliente() {
    int idCliente;
    char nome[50];
    char telefone[15];
    char cpf[11];
    char email[50];

    fflush(stdin);  // Limpar o buffer de entrada

    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    fflush(stdin);

    printf("Digite o telefone do cliente: ");
    scanf("%s", telefone);

    fflush(stdin);

    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);

    fflush(stdin);

    printf("Digite o email do cliente: ");
    scanf("%s", email);

    idCliente = gerarNovoIDCliente();

    cadastrarClienteArq(idCliente, nome, telefone, cpf, email);

    printf("Cliente cadastrado com sucesso!\n");
    sleep(1);
}

void exibirClientes() {
    FILE *arquivo = fopen(CLIENTE_ARQ, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\nClientes cadastrados:\n");
    int idCliente;
    char nome[50];
    char telefone[15];
    char cpf[11];
    char email[50];

    fflush(stdin);

    while (fscanf(arquivo, "%i %s %s %s %s", &idCliente, nome, telefone, cpf, email) != EOF) {
        printf("ID: %i\n", idCliente);
        printf("Nome: %s\n", nome);
        printf("Telefone: %s\n", telefone);
        printf("CPF: %s\n", cpf);
        printf("Email: %s\n\n", email);
    }
    printf("Pressione ENTER para continuar.\n");
    getchar();

    fclose(arquivo);
}

int menuCliente() {
    int escolha;

    do {
        system("cls");
        printf("CLIENTES");
        printf("\n\n");

        printf("[1] Cadastrar Cliente.\n");
        printf("[2] Exibir Clientes.\n");
        printf("[0] Retornar.\n\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                exibirClientes();
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!!\n");
        }
    } while (escolha != 0);
    return 0;
}