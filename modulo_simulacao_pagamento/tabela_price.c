#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#define MAX 80


float calculoPrice(float valorFinanciado,float taxaJuros, int numParcelas)
{
    return valorFinanciado / (((pow(1.0+(taxaJuros/100),numParcelas)) - 1.0) / ((pow(1.0+(taxaJuros/100),numParcelas)) * (taxaJuros/100)));
}

int price()
{
    float vlImovel, vlEntrada, valorFinanciado, taxaJuros, vlParcelasPorMes, amort, vlPorcInicial;
    float totalJuros=0, totalAmort=0;
    int numParcelas;
    char iniciar;
    char tabDet;


    setlocale(LC_ALL,"");

    do
    {
        sleep(1);
        system("cls");
       
        printf("Deseja fazer uma nova simulação de financiamento no modelo Price?\n\n[s]SIM\n[n]NAO\n\n");
        scanf(" %c",&iniciar);
        getchar();
        if(iniciar=='n' || iniciar=='N')
        {
            return 0;   
        }
        if (iniciar != 's' && iniciar != 'S' && iniciar != 'n' && iniciar != 'N')
        {
            printf("Opção incorreta! Digite 's' para SIM e 'n' para NÃO\n\n");
            sleep(1);
            system("cls");
        }
        else
        {
            if(iniciar=='s' || iniciar=='S')
            {
                sleep(1);
                system("cls");
               
                printf("TABELA PRICE");
                printf("\n\n");
                
                printf("Digite o valor do imóvel: R$");
                scanf("%f",&vlImovel);

                printf("Digite o valor de entrada: R$");
                scanf("%f",&vlEntrada);
                printf("\n");

                valorFinanciado = vlImovel - vlEntrada;
                printf("Valor a ser financiado: R$ %.2f\n", valorFinanciado);

                printf("Digite a taxa de juros(%%): ");
                scanf("%f",&taxaJuros);

                printf("Digite o número de parcelas: ");
                scanf("%i",&numParcelas);

                printf("\n");

                vlParcelasPorMes = calculoPrice(valorFinanciado, taxaJuros, numParcelas);

                
                printf("Valor do financiamento:R$ %.2f reais.\n",valorFinanciado);
                printf("Valor fixo das parcelas: R$ %.2f reais.\n",vlParcelasPorMes);
                printf("Números de parcelas: %i vezes\n", numParcelas);
                printf("Taxa de juros(%%): %.2f%% a.m.\n\n",taxaJuros);

                printf("Valor fixo das parcelas: R$ %.2f reais.\n",vlParcelasPorMes);

                vlPorcInicial = valorFinanciado * (taxaJuros/100);

                amort = vlParcelasPorMes - vlPorcInicial;

                printf("Valor do juros no primeiro mês: R$ %.2f reais.\n",vlPorcInicial);
                printf("Valor da amortização no primeiro mês: R$ %.2f reais.\n\n",amort);
                getchar();

                do
                {
                    
                    printf("DETALHES - SAC");
                    printf("\n\n");

                    printf("Deseja ver tabela detalhada?\n\n[s]SIM\n[n]NÃO\n\n\n");
                    scanf("%c",&tabDet);
                    getchar();
                    if(tabDet != 's' && tabDet != 'S' && tabDet != 'n' && tabDet != 'N')
                    {
                        printf("Opção incorreta! Digite 's' para SIM e 'n' para NÃO\n\n");
                        sleep(1);
                        system("cls");
                    }
                    else
                    {
                        if(tabDet=='s' || tabDet=='S')
                        {
                            sleep(1);
                            printf("\n");
                            
                            printf("DETALHES DE SIMULAÇÃO - PRICE");
                            
                            printf("\n\n");

                            printf("Valor do financiamento:R$ %.2f reais.\n",valorFinanciado);
                            printf("Valor fixo das parcelas: R$ %.2f reais.\n",vlParcelasPorMes);
                            printf("Números de parcelas: %i vezes\n", numParcelas);
                            printf("Taxa de juros(%%): %.2f%% a.m.\n\n",taxaJuros);

                            
                            printf("TABELA DETALHADA - PRICE");
                            printf("\n\n");

                            printf("Valor fixo das parcelas: R$ %.2f reais.\n",vlParcelasPorMes);

                            vlPorcInicial = valorFinanciado * (taxaJuros/100);

                            amort = vlParcelasPorMes - vlPorcInicial;

                            printf("Valor do juros no primeiro mês: R$ %.2f reais.\n",vlPorcInicial);
                            printf("Valor da amortização no primeiro mês: R$ %.2f reais.\n\n",amort);

                            for(int i=2; i<=numParcelas; i++)
                            {
                                valorFinanciado-=amort;
                                vlPorcInicial = valorFinanciado * (taxaJuros/100);
                                amort = vlParcelasPorMes - vlPorcInicial;
                                totalJuros+=vlPorcInicial;
                                totalAmort+=amort;

                                printf("%i%c mes - Parcela fixa de R$ %.2f reais\n", i, 248, vlParcelasPorMes);

                                if(valorFinanciado<0 && vlPorcInicial<0)
                                {
                                    printf("Valor atualizado da amortização: R$ %.2f reais\n",amort);
                                    printf("Valor atualizado do juros: SEM JUROS.\n");
                                    printf("Valor atualizado do saldo devedor: R$ %.2f reais\n\n",valorFinanciado);

                                }
                                else
                                {
                                    printf("Valor atualizado da amortização: R$ %.2f reais\n",amort);
                                    printf("Valor atualizado do juros: R$ %.2f reais\n",vlPorcInicial);
                                    printf("Saldo devedor: R$ %.2f reais\n\n",valorFinanciado);

                                }
                            }
                            break;

                        }
                    }

                }
                while(tabDet != 'n' && tabDet != 'N');
                printf("Pressione ENTER para retornar.");
                getchar();

            }
        }

    }
    while(1);  //loop enquanto não for 'n' ou 'N'

}
