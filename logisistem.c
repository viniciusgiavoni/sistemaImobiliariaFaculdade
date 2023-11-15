#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include "modulo_simulacao_pagamento\menu_simulacao.c"
#include "modulo_movimentacoes\movimentacoes.c"
#include "modulo_imoveis\cadastro_imoveis.c"
#include "modulo_clientes\cadastro_clientes.c"

#define ARQ_USUARIOS "Data/Users.txt"


int addUserFile(char username[30], char password[30]) {
	FILE *file = fopen(ARQ_USUARIOS, "a+");

	// validação de erro no arquivo
	if (file == NULL) {
		return 0;
	} else {
		// grava informações no arquivo
		fprintf(file, "%s %s\n", username, password);
		fclose(file);
		return 1;
	}
}

int validaUsuario() {
	FILE *userFile = fopen(ARQ_USUARIOS, "r");
	char usuario[30];
	char senha[30];

	printf("Digite seu nome de usuário: ");
	scanf("%29s", usuario);
	getchar();

	printf("Digite sua senha: ");
	scanf("%29s", senha);
	getchar();

	while(!feof(userFile)) {
		char usuarioFile[30];
		char senhaFile[30];

		fscanf(userFile, "%s %s", usuarioFile, senhaFile);

		if (strcmp(usuarioFile, usuario) == 0 && strcmp(senhaFile, senha) == 0) {
			fclose(userFile);
			return 1;
		}
	}
	fclose(userFile);
	return 0;
}

void registroUsuario() {
	FILE *userFile = fopen(ARQ_USUARIOS, "a+");
	char usuario[30];
	char senha[30];
	char confirmacaoSenha[30];

	printf("Digite seu nome de usuário: ");
	scanf("%29s", usuario);
	do {
		printf("Crie sua senha: ");
		scanf("%29s", senha);

		printf("Confirme sua senha: ");
		scanf("%29s", confirmacaoSenha);

		if (strcmp(senha, confirmacaoSenha) != 0) {
			printf("As senhas não coincidem. Tente novamente.\n\n");
		} else if (strlen(senha) < 8) {
			printf("A senha deve ter pelo menos 8 caracteres. Tente novamente.\n\n");
		}
	} while (strcmp(senha, confirmacaoSenha) != 0 || strlen(senha) < 8);

	int validacaoUsuario = addUserFile(usuario, senha); // função para adicionar usuários no arquivo

	if (validacaoUsuario == 1) {
		printf("Usuário cadastrado com sucesso!!\n");
		printf("Agora você pode logar no sistema!!\n");
	} else {
		printf("Erro ao cadastrar usuário!!\n");
	}

	sleep(0.7);
	system("cls");
}

void MenuPrincipal() {
	bool continua = true;
	int usuarioEncontrado;
	int escolha;
	while (continua) {

		printf("LOGISISTEM");
		printf("\n\n");

		printf("O que deseja fazer?\n\n[1]Módulo Imoveis.\n[2]Módulo Clientes.\n[3]Módulo Simulação Pagamento\n[4]Módulo Movimentações.\n[0]Sair.\n\nEscolha: ");
		scanf("%i", &escolha);
		switch(escolha) {
			case 1:
				menuImovel();
				break;
			case 2:
				menuCliente();
				break;
			case 3:
				MenuSimulacao();
				break;
			case 4:
				menuMovimentacao();
				break;
			case 0:
				exit(EXIT_FAILURE);
				break;
			default:
				printf("Opção inválida");
				sleep(1);
				system("cls");
				break;
		}

	}
}
void menuLogin() {
	bool continua = true;
	int usuarioEncontrado;// recebe um valor caso usuario seja encontrado
	int escolha;

	while (continua) {
		
		system("cls");
		printf("LOGISISTEM");
		printf("\n\n");

		printf("O que deseja fazer?\n\n[1]Entrar na minha conta.\n[2]Criar nova conta.\n[0]Sair.\n\nEscolha: ");
		scanf("%i", &escolha);

		switch (escolha) {
			case 1:
				usuarioEncontrado = validaUsuario();
				if (usuarioEncontrado == 1) {
					printf("Usuário encontrado, entrando no sistema.\n");
					sleep(3);
					system("cls");
					MenuPrincipal(); // Chama menu principal
				} else {
					printf("Usuário não encontrado.");
					sleep(3);
					system("cls");
				}
				break;
			case 2:
				registroUsuario();
				break;
			case 0:
				continua = false;
				break;
			default:
				printf("Opção inválida!!\n");
				sleep(1);
				system("cls");
				break;
		}
	}
}

int main() {
	menuLogin();
	return 0;
}
