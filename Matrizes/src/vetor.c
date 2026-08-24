#include <stdio.h>
#include "vetor.h"

void vetor_preencher(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor do indice %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

void vetor_imprimir(const int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
}

void vetor_inverter(const int *origem, int *destino, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[tamanho -1 - i] = origem[i];
    }
}



