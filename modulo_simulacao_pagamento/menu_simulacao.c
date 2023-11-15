#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include "tabela_sac.c"
#include "tabela_price.c"
#define MAX 80

void MenuSimulacao() { 
	int op;

	setlocale(LC_ALL,"");

	do {
		sleep(1);
		system("cls");

		printf("SIMULAÇÃO DE FINANCIAMENTO");
		printf("\n\n");

		printf("Selecione o modelo de simulação de financiamento:\n\n[1]Tabela SAC.\n[2]Tabela PRICE.\n[0]Retornar.\n\nEscolha: ");
		scanf("%i",&op);
		switch(op) {
			case 1:
				sac();
				break;
			case 2:
				price();
				break;
			case 0:
				sleep(1);
				system("cls");
				break;
			default:
				printf("Opção inválida!!\n");
				sleep(1);
				system("cls");
				break;
		}
	} while(op != 0);

}
