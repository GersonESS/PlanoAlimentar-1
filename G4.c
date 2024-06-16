#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // Abrir o arquivo CSV para escrita (append mode)
    FILE *file = fopen("saida.csv", "a");
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        exit(1);
    }

    // Escrever os dados dos produtos no CSV
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "%d,%s,%.2f,%s,%.2f,%d,%d\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].unidade, produtos[i].valor, produtos[i].posicaox, produtos[i].posicaoy);
    }

    // Fechar o arquivo
    fclose(file);
    printf("Dados gravados com sucesso em saida.csv\n");
}

void escreverTXT(struct produto produtos[], int quantidade) {
    // Abrir o arquivo TXT para escrita
    FILE *file = fopen("saida.txt", "w");
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        exit(1);
    }

    // Escrever os dados dos produtos no TXT
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "Codigo: %d\nNome: %s\nQuantidade: %.2f\nUnidade: %s\nValor: %.2f\nPosicao X: %d\nPosicao Y: %d\n\n",
                produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].unidade, produtos[i].valor, produtos[i].posicaox, produtos[i].posicaoy);
    }

    // Fechar o arquivo
    fclose(file);
    printf("Dados gravados com sucesso em saida.txt\n");
}

int lerCSV(struct produto produtos[]) {
    FILE *file = fopen("saida.csv", "r");
    if (file == NULL) {
        return 0; // Arquivo nao existe
    }

    char linha[256];
    int quantidadeProdutos = 0;
    
    // Ignorar a primeira linha (cabecalho)
    fgets(linha, sizeof(linha), file);

    // Ler os dados do CSV
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d,%50[^,],%f,%5[^,],%f,%d,%d",
               &produtos[quantidadeProdutos].codigo,
               produtos[quantidadeProdutos].nome,
               &produtos[quantidadeProdutos].quantidade,
               produtos[quantidadeProdutos].unidade,
               &produtos[quantidadeProdutos].valor,
               &produtos[quantidadeProdutos].posicaox,
               &produtos[quantidadeProdutos].posicaoy);
        quantidadeProdutos++;
    }

    fclose(file);
    return quantidadeProdutos;
}

int main() {
    struct produto produtos[200];  // Supondo um maximo de 200 produtos para simplificar
    int quantidadeProdutos = 0;

    // Ler o arquivo CSV existente, se houver
    quantidadeProdutos = lerCSV(produtos);

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
        if (quantidadeProdutos >= 200) {
            printf("Numero maximo de produtos atingido.\n");
            break;
        }
    }

    // Escrever os dados nos arquivos CSV e TXT
    escreverCSV(produtos, quantidadeProdutos);
    escreverTXT(produtos, quantidadeProdutos);

    return 0;
}
