#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 1000000

int main(void) {
    // Binary Search
    int *vetor = (int *) malloc(TAMANHO * sizeof(int));
    int valor = 0;

    if (vetor == NULL) {
        printf("Erro ao alocar memoria");
        return 1;
    }

    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = i;
    }

    while (1) {
        int contador = 0;
        int encontrou = 0;
        printf("Digite um valor a ser buscado (ou -1 para sair): ");
        scanf("%d", &valor);

        if (valor == -1) {
            break;
        }
        int inicio = 0;
        int final = TAMANHO - 1;

        while (inicio <= final) {
            int meio = inicio + final / 2;
            contador++;

            if (vetor[meio] == valor) {
                printf("ACHEI !!! Na posicao %d Na tentativa %d\n", meio, contador);
                encontrou = 1;
                break;
            }
            if (vetor[meio] > valor) {
                final = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }
        
        if (encontrou == 0) {
            printf("Valor nao encontrado! (Foram feitas %d tentativas)\n", contador);
        }
    }

    free(vetor);
    return 0;
}