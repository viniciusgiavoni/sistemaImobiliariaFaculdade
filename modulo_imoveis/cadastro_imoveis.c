#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#define IMOVEL_ARQ "./Data/imoveis.txt"

int gerarNovoIDImovel() {
    FILE *arquivo = fopen(IMOVEL_ARQ, "r");

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

void cadastrarImovelArq(int idImovel, char endereco[100], char tipo[50], float preco) {
	FILE *arquivo = fopen(IMOVEL_ARQ, "a+");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo!\n");
		return;
	}

	fprintf(arquivo, "%i %s %s %.2f\n", idImovel, endereco, tipo, preco);

	fclose(arquivo);
}

void cadastrarImovel() {
	int idImovel;
	float preco;
	char endereco[100], tipo[50];

	fflush(stdin);  // Limpar o buffer de entrada

	printf("Digite o tipo do imóvel: ");
	scanf("%s", tipo);

	fflush(stdin);

	printf("Digite o endereço do imóvel: ");
	scanf("%s", endereco);

	fflush(stdin);

	printf("Digite o valor do imóvel: ");
	scanf("%f", &preco);

	fflush(stdin);

	idImovel = gerarNovoIDImovel();

	cadastrarImovelArq(idImovel, endereco, tipo, preco);

	printf("Imóvel cadastrado com sucesso!\n");
	sleep(1);
}

void listarImoveis() {
	FILE *arquivo = fopen(IMOVEL_ARQ, "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo %s\n", IMOVEL_ARQ);
		return;
	}

	printf("\nLista de Imóveis:\n");

	fflush(stdin);

	while (!feof(arquivo)) {
		int idImovel;
		char endereco[100], tipo[50], preco[20];

		fscanf(arquivo, "%i %s %s %s", &idImovel, endereco, tipo, preco);
		if (!feof(arquivo)) {
			printf("ID: %i\n", idImovel);
			printf("Endereço: %s\n", endereco);
			printf("Tipo: %s\n", tipo);
			printf("Preço: %s\n\n", preco);
		}
	}
	printf("Pressione ENTER para continuar.\n");
	getchar();

	fclose(arquivo);
}

int menuImovel() {
	int escolha;

	do {
		system("cls");
		printf("IMÓVEIS");
		printf("\n\n");

		printf("[1] Cadastrar imóveis.\n");
		printf("[2] Listar imóveis.\n");
		printf("[0] Retornar.\n\n");
		printf("Escolha: ");
		scanf("%d", &escolha);

		switch (escolha) {
			case 1:
				cadastrarImovel();
				break;
			case 2:
				listarImoveis();
				break;
			case 0:
				break;
			default:
				printf("Opção inválida!!\n");
		}
	} while (escolha != 0);

	return 0;
}
