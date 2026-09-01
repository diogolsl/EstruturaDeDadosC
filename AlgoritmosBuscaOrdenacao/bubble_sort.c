#include <stdbool.h>
#include <stdio.h>

int main(void) {
    // Bubble Sort
    int vetor[5];
    for (int i = 0; i < sizeof(vetor) / sizeof(vetor[0]); i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    bool continuar = true;
    while (continuar) {
        continuar = false;
        for (int i = 0; i < sizeof(vetor) / sizeof(vetor[0]); i++) {
            if (vetor[i] > vetor[i + 1]) {
                int temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                continuar = true;
            }
        }
    }

    for (int i = 0; i < sizeof(vetor) / sizeof(vetor[0]); i++) {
        printf("vetor[%d] : %d\n", i, vetor[i]);
    }
}
