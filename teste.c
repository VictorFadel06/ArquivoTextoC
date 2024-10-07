#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMEROS 40  // Define um tamanho máximo para o vetor

int main() {
    FILE *arquivo;
    FILE *estatisticas;
    FILE *distintos;
    FILE *ordenado;
    FILE *distintos_ordenado;
    int vetor[MAX_NUMEROS];
    int vetor_distintos[MAX_NUMEROS];
    int tamanho = 0;
    int tamanho_distinto = 0;
    int i = 0, numero;

    // Abre o arquivo para leitura
    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Ignora o primeiro número (número de elementos)
    fscanf(arquivo, "%d", &tamanho);

    if (tamanho > MAX_NUMEROS) {
      return 1;
    } else {
      // Lê os números do arquivo e armazena no vetor
    while (fscanf(arquivo, "%d", &numero) != EOF && i < MAX_NUMEROS) {
        vetor[i] = numero;
        i++;
    }
    tamanho = i;  // Atualiza o tamanho real do vetor

    // Fecha o arquivo
    fclose(arquivo);

    

    // Exibe os números lidos
    printf("Números lidos do arquivo:\n");
    for (int j = 0; j < tamanho; j++) {
        printf("%d ", vetor[j]);
    }
    printf("\n");

    // Cria o arquivo "estatisticas.txt"
    estatisticas = fopen("estatisticas.txt", "w");
    if (estatisticas == NULL) {
        printf("Erro ao abrir o arquivo 'estatisticas.txt'!\n");
        return 1;
    }

    int positivos = 0, negativos = 0, zero = 0, pares = 0, impares = 0;

    for (int k = 0; k < tamanho; k++) {
        if (vetor[k] > 0) positivos++;
        else if (vetor[k] < 0) negativos++;
        else zero++;

        if (vetor[k] % 2 == 0) pares++;
        else impares++;
    }

    fprintf(estatisticas, "Total de números POSITIVOS: %d\n", positivos);
    fprintf(estatisticas, "Total de números NEGATIVOS: %d\n", negativos);
    fprintf(estatisticas, "Total de números IGUAIS A ZERO: %d\n", zero);
    fprintf(estatisticas, "Total de números PARES: %d\n", pares);
    fprintf(estatisticas, "Total de números ÍMPARES: %d\n", impares);

    fclose(estatisticas);

    // Cria o arquivo "distintos.txt"
    distintos = fopen("distintos.txt", "w");
    if (distintos == NULL) {
        printf("Erro ao abrir o arquivo 'distintos.txt'!\n");
        return 1;
    }

    fprintf(distintos, "Números distintos: ");

    // Encontrar os números distintos
    for (int i = 0; i < tamanho; i++) {
        bool distinto = true;

        // Verificar se o número já está no vetor de distintos
        for (int j = 0; j < tamanho_distinto; j++) {
            if (vetor[i] == vetor_distintos[j]) {
                distinto = false;
                break;
            }
        }

        // Adicionar o número ao vetor de distintos apenas se for realmente distinto
        if (distinto) {
            vetor_distintos[tamanho_distinto] = vetor[i];
            tamanho_distinto++;
        }
    }

    // Escreve os números distintos no arquivo
    for (int i = 0; i < tamanho_distinto; i++) {
        fprintf(distintos, "%d ", vetor_distintos[i]);
    }

    fclose(distintos);

    // Cria o arquivo "ordenado.txt"
    ordenado = fopen("ordenado.txt", "w");
    if (ordenado == NULL) {
        printf("Erro ao abrir o arquivo 'ordenado.txt'!\n");
        return 1;
    }

    // Ordena o vetor original
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[i]) {
                int aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }

    // Escreve o vetor ordenado no arquivo
    for (int k = 0; k < tamanho; k++) {
        fprintf(ordenado, "%d ", vetor[k]);
    }

    fclose(ordenado);

    // Cria o arquivo "distintos_ordenado.txt"
    distintos_ordenado = fopen("distintos_ordenado.txt", "w");
    if (distintos_ordenado == NULL) {
        printf("Erro ao abrir o arquivo 'distintos_ordenado.txt'!\n");
        return 1;
    }

    // Ordena o vetor de distintos
    for (int i = 0; i < tamanho_distinto; i++) {
        for (int j = i + 1; j < tamanho_distinto; j++) {
            if (vetor_distintos[j] < vetor_distintos[i]) {
                int aux = vetor_distintos[j];
                vetor_distintos[j] = vetor_distintos[i];
                vetor_distintos[i] = aux;
            }
        }
    }

    // Escreve os números distintos e ordenados no arquivo
    for (int k = 0; k < tamanho_distinto; k++) {
        fprintf(distintos_ordenado, "%d ", vetor_distintos[k]);
    }

    fclose(distintos_ordenado);

    return 0;
    }
}
