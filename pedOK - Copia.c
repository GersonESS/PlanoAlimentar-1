#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Alimento
typedef struct {
    char nome[51];
    float quantidade;
    char g[1];
    char Kcal[6];
} Alimento;

// Função para imprimir o plano alimentar
void imprimirPlanoAlimentar(Alimento refeicoes[][6], char *titulos[], int numRefeicoes, int numAlimentos[]) {
    FILE *arquivoCSV = fopen("saida.csv", "w");
    FILE *arquivoTXT = fopen("saida.txt", "w");

    if (arquivoCSV == NULL || arquivoTXT == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return;
    }

    float totalCaloriasGeral = 0;

    for (int i = 0; i < numRefeicoes; i++) {
        fprintf(arquivoTXT, "%s\n", titulos[i]);
        fprintf(arquivoCSV, "%s\n", titulos[i]);
        float totalCalorias = 0;

        for (int j = 0; j < numAlimentos[i]; j++) {
            Alimento a = refeicoes[i][j];
            fprintf(arquivoTXT, "  %s %.0fg %s\n", a.nome, a.quantidade, a.Kcal);
            fprintf(arquivoCSV, "%s,%.0f,%s,%s\n", a.nome, a.quantidade, a.g, a.Kcal);

            totalCalorias += atof(a.Kcal); // Convertendo Kcal para float e somando
        }
        totalCaloriasGeral += totalCalorias;

        fprintf(arquivoTXT, "  Cal %.0f Kcal\n\n", totalCalorias);
        fprintf(arquivoCSV, "Cal,%.0f Kcal\n\n", totalCalorias);
    }

    fprintf(arquivoTXT, "Calo %.0f Kcal\n", totalCaloriasGeral);
    fprintf(arquivoCSV, "Calo,%.0f Kcal\n", totalCaloriasGeral);

    fclose(arquivoCSV);
    fclose(arquivoTXT);
}

// Função para imprimir a lista de compras
void listaDeCompras(Alimento alimentos[], int numAlimentos) {
    FILE *arquivoCSV = fopen("lista.csv", "w");
    FILE *arquivoTXT = fopen("lista.txt", "w");

    if (arquivoCSV == NULL || arquivoTXT == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return;
    }

    for (int i = 0; i < numAlimentos; i++) {
        Alimento a = alimentos[i];
        fprintf(arquivoTXT, "%s %.0fg %s\n", a.nome, a.quantidade, a.Kcal);
        fprintf(arquivoCSV, "%s,%.0f,%s,%s\n", a.nome, a.quantidade, a.g, a.Kcal);
    }

    fclose(arquivoCSV);
    fclose(arquivoTXT);
}

int main() {
    // Títulos das refeições
    char *titulos[] = {"12:00 - Dejejum", "14:00 - Almoço", "18:30 - Lanche da tarde", "22:00 - Ceia"};

    // Dados das refeições
    Alimento refeicoes[4][6] = {
        {{"Banana", 125, "g", "124"}, {"Aveia em flocos", 30, "g", "118"}, {"Coco", 20, "g", "71"}, {"Whey 3 Protein", 30, "g", "126"}, {"yakult", 100, "g", "51"}},
        {{"Arroz branco", 125, "g", "160"}, {"Feijao carioca", 90, "g", "68"}, {"Cenour", 50, "g", "43"}, {"Tomate", 25, "g", "4"}, {"Carne Bife", 150, "g", "186"}},
        {{"Tapioca de goma", 15, "g", "37"}, {"Ovo", 3, "u", "189"}, {"Patinho moida", 120, "g", "160"}, {"Tomate", 25, "g", "4"}, {"Mussarela", 30, "g", "85"}},
        {{"Banana", 125, "g", "124"}, {"Chocolate 70%", 25, "g", "245"}, {"Whey 3 Protein", 30, "g", "126"}, {"Coco", 20, "g", "71"}, {"Castanha", 5, "g", "77"}}
    };

    int numAlimentosPorRefeicao[4] = {5, 5, 5, 5};

    // Chamar a função para imprimir o plano alimentar
    imprimirPlanoAlimentar(refeicoes, titulos, 4, numAlimentosPorRefeicao);

    // Lista de compras (todos os alimentos únicos)
    Alimento listaCompras[] = {
        {"Banana", 375, "g", "372"}, {"Aveia em flocos", 30, "g", "118"}, {"Coco", 40, "g", "142"}, {"Whey 3 Protein", 60, "g", "252"},
        {"yakult", 100, "g", "51"}, {"Arroz branco", 125, "g", "160"}, {"Feijao carioca", 90, "g", "68"}, {"Cenour", 50, "g", "43"},
        {"Tomate", 50, "g", "8"}, {"Carne Bife", 150, "g", "186"}, {"Tapioca de goma", 15, "g", "37"}, {"Ovo", 3, "u", "189"},
        {"Patinho moida", 120, "g", "160"}, {"Mussarela", 30, "g", "85"}, {"Chocolate 70%", 25, "g", "245"}, {"Castanha", 5, "g", "77"}
    };

    // Chamar a função para imprimir a lista de compras
    listaDeCompras(listaCompras, 16);

    return 0;
}
