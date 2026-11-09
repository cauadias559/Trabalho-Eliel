#include <stdio.h>

int main() {
    int senha_cadastrada, senha_digitada, opcao;
    float saldo = 500.00, maior_deposito = 0.0;
    
    printf("Crie sua senha numerica de 4 digitos: ");
    scanf("%d", &senha_cadastrada);

    do {
        printf("\n============================\n");
        printf("       MENU DO BANCO        \n");
        printf("============================\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Consultar Saldo e Estatisticas\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                float valor_deposito;
                printf("Digite o valor do deposito: R$ ");
                scanf("%f", &valor_deposito);

                if (valor_deposito <= 0) {
                    printf("Valor inválido!\n");
                } else {
                    saldo += valor_deposito;
                    printf("Deposito de R$ %.2f realizado com sucesso!\n", valor_deposito);

                    if (valor_deposito > maior_deposito) {
                        maior_deposito = valor_deposito;
                    }
                }
                break;
            }
            case 2: {
                printf("Digite a senha de 4 digitos para autorizar o saque: ");
                scanf("%d", &senha_digitada);

                if (senha_digitada != senha_cadastrada) {
                    printf("Senha Incorreta! Operação cancelada.\n");
                } else {
                    float valor_saque;
                    printf("Digite o valor do saque: R$ ");
                    scanf("%f", &valor_saque);

                    if (valor_saque <= 0) {
                        printf("Valor de saque inválido!\n");
                    } else if (valor_saque > saldo) {
                        printf("Saldo Insuficiente!\n");
                    } else {
                        saldo -= valor_saque;
                        printf("Saque de R$ %.2f realizado com sucesso!\n", valor_saque);
                    }
                }
                break;
            }
            case 3:
                printf("Saldo atual: R$ %.2f\n", saldo);
                printf("Maior deposito realizado: R$ %.2f\n", maior_deposito);
                break;
            case 4:
                printf("Obrigado por usar nosso banco!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
