#include<stdio.h>
#include<ctime>

struct Cliente {
    char nome[100];
    int diaNasc, mesNasc, anoNasc, idade;
    char sexo[2];

    void calcIdade() {
        time_t timer;
        struct tm *horarioLocal;

        time(&timer);
        horarioLocal = localtime(&timer);

        int diaAtual = horarioLocal->tm_mday;
        int mesAtual = horarioLocal->tm_mon + 1;
        int anoAtual = horarioLocal->tm_year + 1900;

        idade = anoAtual - anoNasc;
    }

    void ler() {
        printf("Nome: ");
        scanf(" %[^\n]", nome);
        printf("Data de Nascimento: ");
        printf("\nDia: ");
        scanf("%d", &diaNasc);
        printf("Mes: ");
        scanf("%d", &mesNasc);
        printf("Ano (AAAA): ");
        scanf("%d", &anoNasc);
        calcIdade();
        printf("Sexo (M ou F): ");
        scanf(" %s", sexo);
    }

    void imprimir() {
        printf("Nome: %s\n", nome);
        printf("Data de Nascimento: %d/%d/%d\n", diaNasc, mesNasc, anoNasc);
        printf("Idade: %d\n", idade);
        printf("Sexo: %s\n", sexo);
    }
};

int main() {
    Cliente clientes[50];
    int qtdClientes = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                if (qtdClientes < 50) {
                    clientes[qtdClientes].ler();
                    qtdClientes++;
                } else {
                    printf("Limite de clientes atingido.\n");
                }
                break;
            case 2:
                for (int i = 0; i < qtdClientes; i++) {
                    clientes[i].imprimir();
                }
                break;
            case 3:
                printf("     Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}
