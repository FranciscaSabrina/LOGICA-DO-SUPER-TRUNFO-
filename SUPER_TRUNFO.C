#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} CartaCidade;

// Função para ler os dados de uma carta
void lerCarta(CartaCidade *carta, int indice) {
    printf("=== Cadastro da Carta %d ===\n", indice + 1);

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); // lê com espaços

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcula a densidade populacional e o PIB per capita
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0;

    if (carta->populacao > 0)
        carta->pibPerCapita = carta->pib * 1000000000 / carta->populacao; // PIB convertido para reais
    else
        carta->pibPerCapita = 0;

    printf("\n");
}

// Função para exibir os dados de uma carta
void exibirCarta(CartaCidade carta, int indice) {
    printf("=== Carta %d ===\n", indice + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", carta.pibPerCapita);
    printf("\n");
}

int main() {
    CartaCidade carta1, carta2;

    // Cadastro das duas cartas
    lerCarta(&carta1, 0);
    lerCarta(&carta2, 1);

    // Exibição das cartas cadastradas
    printf("=== Cartas Cadastradas ===\n\n");
    exibirCarta(carta1, 0);
    exibirCarta(carta2, 1);

    // ================================
    // Escolha do atributo para comparar:
    // 1 - População
    // 2 - Área
    // 3 - PIB
    // 4 - Densidade Populacional (menor vence)
    // 5 - PIB per capita
    // ================================
    int atributo = 1; // <<< Mude esse número para escolher outro atributo

    printf("=== Comparação de Cartas (Atributo: ");

    // Lógica de comparação
    if (atributo == 1) {
        printf("População) ===\n");
        printf("Carta 1 - %s: %d habitantes\n", carta1.nomeCidade, carta1.populacao);
        printf("Carta 2 - %s: %d habitantes\n", carta2.nomeCidade, carta2.populacao);

        if (carta1.populacao > carta2.populacao)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (carta2.populacao > carta1.populacao)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }
    else if (atributo == 2) {
        printf("Área) ===\n");
        printf("Carta 1 - %s: %.2f km²\n", carta1.nomeCidade, carta1.area);
        printf("Carta 2 - %s: %.2f km²\n", carta2.nomeCidade, carta2.area);

        if (carta1.area > carta2.area)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (carta2.area > carta1.area)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }
    else if (atributo == 3) {
        printf("PIB) ===\n");
        printf("Carta 1 - %s: R$ %.2f bilhões\n", carta1.nomeCidade, carta1.pib);
        printf("Carta 2 - %s: R$ %.2f bilhões\n", carta2.nomeCidade, carta2.pib);

        if (carta1.pib > carta2.pib)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (carta2.pib > carta1.pib)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }
    else if (atributo == 4) {
        printf("Densidade Populacional) ===\n");
        printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadePopulacional);
        printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadePopulacional);

        if (carta1.densidadePopulacional < carta2.densidadePopulacional)
            printf("Resultado: Carta 1 (%s) venceu! (menor densidade)\n", carta1.nomeCidade);
        else if (carta2.densidadePopulacional < carta1.densidadePopulacional)
            printf("Resultado: Carta 2 (%s) venceu! (menor densidade)\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }
    else if (atributo == 5) {
        printf("PIB per Capita) ===\n");
        printf("Carta 1 - %s: R$ %.2f\n", carta1.nomeCidade, carta1.pibPerCapita);
        printf("Carta 2 - %s: R$ %.2f\n", carta2.nomeCidade, carta2.pibPerCapita);

        if (carta1.pibPerCapita > carta2.pibPerCapita)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (carta2.pibPerCapita > carta1.pibPerCapita)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }
    else {
        printf("Atributo inválido!\n");
    }

    return 0;
}
