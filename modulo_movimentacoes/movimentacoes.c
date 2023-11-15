#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARQ_VENDAS "Data/Vendas.txt"

char* selecaoTipoImovel() {
	int opcao;
	char* opcaoRetorno = NULL;
	printf("[1]Casa\n[2]Apartamento\n[3]Terreno\n\nEscolha: ");
	scanf("%d", &opcao);

	switch (opcao) {
		case 1:
			opcaoRetorno = strdup("Casa");
			break;
		case 2:
			opcaoRetorno = strdup("Apartamento");
			break;
		case 3:
			opcaoRetorno = strdup("Terreno");
			break;
		default:
			printf("Opção inválida!!\n");
			break;
	}

	return opcaoRetorno;
}

void registraVendaArq(int idImovel, int idCliente, const char* endereco, char* acao, const char* tipo, float valor) {
	FILE* vendas = fopen(ARQ_VENDAS, "a+");
	if (vendas == NULL) {
		printf("Erro ao abrir o arquivo de vendas.\n");
		return;
	}

	fprintf(vendas, "%d %d %s %s %s %.2f\n", idImovel, idCliente, endereco, acao, tipo, valor);
	fclose(vendas);
}

void registraVenda() {
	int idImovel, idCliente, continua;
	char endereco[100], acao[100];
	float valor;

	printf("Digite o ID do imóvel: ");
	scanf("%d", &idImovel);

	printf("Digite o ID do cliente: ");
	scanf("%d", &idCliente);

	printf("Digite o valor do imóvel: ");
	scanf("%f", &valor);

	printf("Digite o endereço do imóvel: ");
	scanf(" %[^\n]s", endereco);

	printf("Digite a ação feita (venda/compra): ");
	scanf(" %[^\n]s", acao);

	char* tipo = selecaoTipoImovel();

	if (tipo != NULL) {
		registraVendaArq(idImovel, idCliente, endereco, acao, tipo, valor);
		printf("Movimentação registrada com sucesso!\n");
		free(tipo);
	} else {
		printf("Erro ao selecionar o tipo.\n");
	}
}

void menuMovimentacao() {
	int continua;

	do {
		system("cls");

		printf("REGISTRO DE MOVIMENTAÇÕES");
		printf("\n\n");

		registraVenda();

		printf("\nDeseja continuar?\n\n[1] SIM\n[0] NAO\n");
		scanf("%d", &continua);

		sleep(0.5);
		system("cls");

	} while (continua == 1);
}

