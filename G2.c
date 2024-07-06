#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura produto
struct produto {
    int codigo;
    char nome[51];
    float quantidade;
    char unidade[6];
    float valor;
    int posicaox;
    int posicaoy;
};

void escreverCSV(struct produto produtos[], int quantidade) {
    // Abrir o arquivo CSV para escrita
    FILE *file = fopen("saida.csv", "w");
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        exit(1);
    }
    

    // Escrever o cabecalho do CSV
    fprintf(file, "codigo,nome,quantidade,unidade,valor,posicaox,posicaoy\n");

    // Escrever os dados dos produtos no CSV
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "%d,%s,%.2f,%s,%.2f,%d,%d\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].unidade, produtos[i].valor, produtos[i].posicaox, produtos[i].posicaoy);
    }

    // Fechar o arquivo
    fclose(file);
    printf("Dados gravados com sucesso em saida.csv\n");
}

int main() {
    struct produto produtos[100];  // Supondo um maximo de 100 produtos para simplificar
    int quantidadeProdutos = 0;

    while (1) {
        printf("Digite os dados do produto %d:\n", quantidadeProdutos + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[quantidadeProdutos].codigo);
        
        if (produtos[quantidadeProdutos].codigo == 999) {
            break;
        }

        printf("Nome: ");
        scanf(" %[^\n]%*c", produtos[quantidadeProdutos].nome);  // Le ate nova linha
        printf("Quantidade: ");
        scanf("%f", &produtos[quantidadeProdutos].quantidade);
        printf("Unidade: ");
        scanf("%s", produtos[quantidadeProdutos].unidade);
        printf("Valor: ");
        scanf("%f", &produtos[quantidadeProdutos].valor);
        printf("Posicao X: ");
        scanf("%d", &produtos[quantidadeProdutos].posicaox);
        printf("Posicao Y: ");
        scanf("%d", &produtos[quantidadeProdutos].posicaoy);

        quantidadeProdutos++;
        if (quantidadeProdutos >= 100) {
            printf("Numero maximo de produtos atingido.\n");
            break;
        }
    }

    // Escrever os dados no arquivo CSV
    escreverCSV(produtos, quantidadeProdutos);

    return 0;
}
