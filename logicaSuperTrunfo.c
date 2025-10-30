#include <stdio.h>
#include <string.h>

// Definição da estrutura para representar uma Carta do Super Trunfo
typedef struct {
    char estado[3];         // Ex: SP, RJ (2 caracteres + '\0')
    char codigo_carta[5];   // Ex: A1, B2 (4 caracteres + '\0')
    char nome_cidade[50];   // Nome completo da cidade
    int populacao;          // População em número inteiro
    float area;             // Área em km^2 (float)
    float pib;              // PIB em bilhões de R$ (float)
    int pontos_turisticos;  // Número de pontos turísticos

    // Atributos Calculados
    float densidade_populacional; // População / Área
    float pib_per_capita;         // PIB / População
} Carta;

// Função para exibir os dados de uma carta
void exibir_carta(Carta c) {
    printf("\n--- Dados da Carta: %s (%s) ---\n", c.nome_cidade, c.estado);
    printf("  Código da Carta: %s\n", c.codigo_carta);
    printf("  População: %d habitantes\n", c.populacao);
    printf("  Área: %.2f km²\n", c.area);
    printf("  PIB: R$ %.2f bilhões\n", c.pib);
    printf("  Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km²\n", c.densidade_populacional);
    printf("  PIB Per Capita: R$ %.2f (milhares)\n", c.pib_per_capita);
    printf("---------------------------------------\n");
}

// Função para cadastrar e calcular atributos de uma carta
// Simplificação: a função recebe todos os dados, simulando a entrada/cadastro.
Carta cadastrar_e_calcular_carta(const char* estado, const char* codigo, const char* nome, int pop, float area, float pib, int pts) {
    Carta nova_carta;

    // 1. Receber os dados da carta (simulação de cadastro)
    strncpy(nova_carta.estado, estado, 3);
    nova_carta.estado[2] = '\0'; // Garantir terminação de string
    strncpy(nova_carta.codigo_carta, codigo, 5);
    nova_carta.codigo_carta[4] = '\0';
    strncpy(nova_carta.nome_cidade, nome, 50);
    nova_carta.nome_cidade[49] = '\0';
    nova_carta.populacao = pop;
    nova_carta.area = area;
    nova_carta.pib = pib;
    nova_carta.pontos_turisticos = pts;

    // 2. Calcular Densidade Populacional e PIB per capita
    if (area > 0) {
        // Cálculo da Densidade Populacional: População / Área
        nova_carta.densidade_populacional = (float)pop / area;
    } else {
        nova_carta.densidade_populacional = 0.0;
    }

    if (pop > 0) {
        // Cálculo do PIB per capita: (PIB * 1.000.000.000) / População.
        // O valor é dividido por 1000 para ser exibido em "milhares de R$" para simplificação.
        nova_carta.pib_per_capita = (nova_carta.pib * 1000000000.0f) / (float)pop / 1000.0f;
    } else {
        nova_carta.pib_per_capita = 0.0;
    }

    return nova_carta;
}

// Função principal
int main() {
    // ---------------------------------------------------------------------
    // 1. Receber os dados de duas cartas (Simulação de cadastro)
    // ---------------------------------------------------------------------

    // Carta 1: Exemplo de uma cidade grande
    Carta carta1 = cadastrar_e_calcular_carta(
        "SP",             // Estado
        "C1",             // Código da carta
        "São Paulo",      // Nome da cidade
        12325232,         // População (aprox. 12.3 milhões)
        1521.1f,          // Área (aprox. 1521 km²)
        763.8f,           // PIB (aprox. 763.8 bilhões R$)
        120               // Pontos Turísticos
    );

    // Carta 2: Exemplo de uma capital com menor população
    Carta carta2 = cadastrar_e_calcular_carta(
        "RJ",             // Estado
        "C2",             // Código da carta
        "Rio de Janeiro", // Nome da cidade
        6718903,          // População (aprox. 6.7 milhões)
        1200.0f,          // Área (aprox. 1200 km²)
        350.0f,           // PIB (aprox. 350.0 bilhões R$)
        150               // Pontos Turísticos
    );

    // Exibir as cartas cadastradas com seus cálculos
    printf("--- Cadastro das Cartas ---\n");
    exibir_carta(carta1);
    exibir_carta(carta2);

    // ---------------------------------------------------------------------
    // 2. Comparar um atributo escolhido (Fixo no código)
    // ---------------------------------------------------------------------

    // Variáveis para armazenar o atributo de comparação
    // ESCOLHA O ATRIBUTO AQUI: 1=População, 2=Área, 3=PIB, 4=Densidade, 5=PIB Per Capita
    const int ATRIBUTO_ESCOLHIDO = 4; // Comparação fixada em Densidade Populacional

    float valor1 = 0.0f;
    float valor2 = 0.0f;
    char nome_atributo[50];
    int carta_vencedora = 0; // 1 = Carta 1, 2 = Carta 2, 0 = Empate
    int menor_valor_vence = 0; // 1 = Sim, 0 = Não (maior valor vence)

    printf("\n============================================\n");

    // Estrutura de decisão (if-else if-else) para selecionar os valores
    switch (ATRIBUTO_ESCOLHIDO) {
        case 1: // População
            strcpy(nome_atributo, "População");
            valor1 = (float)carta1.populacao;
            valor2 = (float)carta2.populacao;
            menor_valor_vence = 0; // Maior População vence
            printf("Comparação de cartas (Atributo: %s - Maior valor vence):\n", nome_atributo);
            break;
        case 2: // Área
            strcpy(nome_atributo, "Área (km²)");
            valor1 = carta1.area;
            valor2 = carta2.area;
            menor_valor_vence = 0; // Maior Área vence
            printf("Comparação de cartas (Atributo: %s - Maior valor vence):\n", nome_atributo);
            break;
        case 3: // PIB
            strcpy(nome_atributo, "PIB (R$ Bilhões)");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            menor_valor_vence = 0; // Maior PIB vence
            printf("Comparação de cartas (Atributo: %s - Maior valor vence):\n", nome_atributo);
            break;
        case 4: // Densidade Populacional
            strcpy(nome_atributo, "Densidade Populacional (hab/km²)");
            valor1 = carta1.densidade_populacional;
            valor2 = carta2.densidade_populacional;
            menor_valor_vence = 1; // **Menor** Densidade Populacional vence
            printf("Comparação de cartas (Atributo: %s - Menor valor vence):\n", nome_atributo);
            break;
        case 5: // PIB per capita
            strcpy(nome_atributo, "PIB Per Capita (R$ Milhares)");
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            menor_valor_vence = 0; // Maior PIB Per Capita vence
            printf("Comparação de cartas (Atributo: %s - Maior valor vence):\n", nome_atributo);
            break;
        default:
            printf("ERRO: Atributo de comparação não reconhecido.\n");
            return 1;
    }

    // ---------------------------------------------------------------------
    // 3. Determinar a carta vencedora e exibir o resultado
    // ---------------------------------------------------------------------

    // Exibir os valores para o atributo escolhido
    printf("  Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, valor1);
    printf("  Carta 2 - %s (%s): %.2f\n", carta2.nome_cidade, carta2.estado, valor2);

    // Lógica de Comparação usando if / if-else
    if (menor_valor_vence) {
        // Regra para Densidade Populacional (o menor valor vence)
        if (valor1 < valor2) {
            carta_vencedora = 1; // Carta 1 vence
        } else if (valor2 < valor1) {
            carta_vencedora = 2; // Carta 2 vence
        } else {
            carta_vencedora = 0; // Empate
        }
    } else {
        // Regra para todos os outros atributos (o maior valor vence)
        if (valor1 > valor2) {
            carta_vencedora = 1; // Carta 1 vence
        } else if (valor2 > valor1) {
            carta_vencedora = 2; // Carta 2 vence
        } else {
            carta_vencedora = 0; // Empate
        }
    }

    // Exibir o resultado final da comparação
    if (carta_vencedora == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta_vencedora == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    printf("============================================\n");

    return 0;
}
