#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Alimento
typedef struct {
    char nome[51];
    float quantidade;
    char kcal[6];
} Alimento;

// Função para imprimir plano alimentar e calcular total de calorias
int imprimirPlanoAlimentar(FILE *arquivo, Alimento refeicao[], int tamanho) {
    int totalCalorias = 0;
    
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%s,%.2f,%s\n", refeicao[i].nome, refeicao[i].quantidade, refeicao[i].kcal);
        totalCalorias += atoi(refeicao[i].kcal);
    }
    fprintf(arquivo, "Total Calorias,%d Kcal\n\n", totalCalorias);
    return totalCalorias;
}

int main() {
    // Definindo os alimentos
    Alimento dejejum[] = {
        {"Banana", 125, "124"},
        {"Aveia em flocos", 30, "118"},
        {"Coco", 20, "71"},
        {"Whey 3 Protein", 30, "126"},
        {"Yakult", 100, "51"}
    };

    Alimento almoco[] = {
        {"Arroz branco", 125, "160"},
        {"Feijao carioca", 90, "68"},
        {"Cenoura", 50, "43"},
        {"Tomate", 25, "4"},
        {"Carne Bife", 150, "186"}
    };

    Alimento lanche[] = {
        {"Tapioca de goma", 15, "37"},
        {"Ovo", 2, "129"},
        {"Patinho moida", 120, "160"},
        {"Tomate", 25, "4"}
    };

    Alimento ceia[] = {
        {"Banana", 125, "124"},
        {"Chocolate 70%", 25, "245"},
        {"Whey 3 Protein", 30, "126"},
        {"Coco", 20, "71"},
        {"Castanha", 5, "77"}
    };

    // Abrir os arquivos CSV e TXT para escrita
    FILE *arquivoCSV = fopen("saida.csv", "w");
    FILE *arquivoTXT = fopen("saida.txt", "w");

    if (arquivoCSV == NULL || arquivoTXT == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    int totalCaloriasGeral = 0;

    // Imprimir detalhes das refeições nos arquivos
    fprintf(arquivoCSV, "12:00 - Dejejum\n");
    fprintf(arquivoTXT, "12:00 - Dejejum\n");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, dejejum, sizeof(dejejum) / sizeof(dejejum[0]));
    imprimirPlanoAlimentar(arquivoTXT, dejejum, sizeof(dejejum) / sizeof(dejejum[0]));

    fprintf(arquivoCSV, "14:00 - Almoco\n");
    fprintf(arquivoTXT, "14:00 - Almoco\n");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, almoco, sizeof(almoco) / sizeof(almoco[0]));
    imprimirPlanoAlimentar(arquivoTXT, almoco, sizeof(almoco) / sizeof(almoco[0]));

    fprintf(arquivoCSV, "18:30 - Lanche da tarde\n");
    fprintf(arquivoTXT, "18:30 - Lanche da tarde\n");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, lanche, sizeof(lanche) / sizeof(lanche[0]));
    imprimirPlanoAlimentar(arquivoTXT, lanche, sizeof(lanche) / sizeof(lanche[0]));

    fprintf(arquivoCSV, "22:00 - Ceia\n");
    fprintf(arquivoTXT, "22:00 - Ceia\n");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, ceia, sizeof(ceia) / sizeof(ceia[0]));
    imprimirPlanoAlimentar(arquivoTXT, ceia, sizeof(ceia) / sizeof(ceia[0]));

    // Imprimir total geral de calorias
    fprintf(arquivoCSV, "Total Calorias Geral,%d Kcal\n", totalCaloriasGeral);
    fprintf(arquivoTXT, "Total Calorias Geral,%d Kcal\n", totalCaloriasGeral);

    // Fechar os arquivos
    fclose(arquivoCSV);
    fclose(arquivoTXT);

    printf("Plano alimentar escrito em saida.csv e saida.txt com sucesso.\n");

    return 0;
}
