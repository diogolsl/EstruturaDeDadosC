#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10000000

int main(void) {
    int *vetor = (int *)malloc(TAMANHO * sizeof(int));
    int parametroPesquisa = 0;

    if (vetor == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = ((long long)rand() * rand()) % TAMANHO;
    }

    do {
        printf("Digite um parametro de pesquisa (ou -1 para sair): ");
        scanf("%d", &parametroPesquisa);

        if (parametroPesquisa == -1) {
            break;
        }


        for (int i = 0; i < TAMANHO; i++) {
            if (parametroPesquisa == vetor[i]) {
                printf("ACHEI !!!! Na posicao: %d\n", i);
                break;
            }
        }
    } while (parametroPesquisa != -1);

    free(vetor);
    return 0;
}
