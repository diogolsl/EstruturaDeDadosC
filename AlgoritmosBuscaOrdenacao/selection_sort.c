#include <stdio.h>

int main(void) {
    // Selection Sort
    int vetor[5];
    for (int i = 0; i < sizeof(vetor) / sizeof(vetor[0]); i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }
    for (int i = 0; i < (sizeof(vetor) / sizeof(vetor[0])) - 1; i++) {
        for (int j = i + 1; j < sizeof(vetor) / sizeof(vetor[0]); j++) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
    for (int i = 0; i < sizeof(vetor) / sizeof(vetor[0]); i++) {
        printf("vetor[%d] : %d\n", i, vetor[i]);
    }
}

