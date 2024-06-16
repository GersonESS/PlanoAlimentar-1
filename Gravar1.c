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
    int quantidadeProdutos;

    // Solicitar o numero de produtos ao usuario
    printf("Digite o numero de produtos: ");
    scanf("%d", &quantidadeProdutos);

    // Alocar memoria para os produtos
    struct produto *produtos = (struct produto *)malloc(quantidadeProdutos * sizeof(struct produto));
    if (produtos == NULL) {
        printf("Nao foi possivel alocar memoria.\n");
        return 1;
    }

    // Ler os dados dos produtos
    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        printf("Nome: ");
        scanf(" %[^\n]%*c", produtos[i].nome);  // Le ate nova linha
        printf("Quantidade: ");
        scanf("%f", &produtos[i].quantidade);
        printf("Unidade: ");
        scanf("%s", produtos[i].unidade);
        printf("Valor: ");
        scanf("%f", &produtos[i].valor);
        printf("Posicao X: ");
        scanf("%d", &produtos[i].posicaox);
        printf("Posicao Y: ");
        scanf("%d", &produtos[i].posicaoy);
    }

    // Escrever os dados no arquivo CSV
    escreverCSV(produtos, quantidadeProdutos);

    // Liberar a memoria alocada
    free(produtos);

    return 0;
}
