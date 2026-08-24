#include <stdio.h>
#include "matriz.h"

void matriz_preencher(int linhas, int cols, int matriz[linhas][cols], const char *nome_matriz) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Digite o elemento da linha %d e coluna %d da matriz %s: ", i + 1, j + 1, nome_matriz);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void matriz_imprimir(int linhas, int cols, const int matriz[linhas][cols], const char *titulo) {
    printf("\n%s\n", titulo);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void matriz_transposta(int linhas, int cols, const int origem[linhas][cols], int destino[cols][linhas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < cols; j++) {
            destino[j][i] = origem[i][j];
        }
    }
}

void matriz_multiplicar(int r1, int c1, int c2,
                        const int A[r1][c1],
                        const int B[c1][c2],
                        int C[r1][c2]) {

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
