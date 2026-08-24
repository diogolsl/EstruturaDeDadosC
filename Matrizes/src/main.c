#include <stdio.h>
#include "vetor.h"
#include "matriz.h"

int main(void) {
    printf("PREENCHIMENTO DE VETOR\n");
    int v1[5];
    vetor_preencher(v1, 5);
    vetor_imprimir(v1, 5);

    printf("INVERSAO DE VETOR\n");
    int v_orig[5];
    int v_inv[5];
    vetor_preencher(v_orig, 5);
    vetor_inverter(v_orig, v_inv, 5);
    printf("\nVetor Invertido:\n");
    vetor_imprimir(v_inv, 5);

    printf("MATRIZ TRANSPOSTA\n");

    int mat_origem[2][3];
    int mat_transposta[3][2];
    matriz_preencher(2, 3, mat_origem, "Original");
    matriz_transposta(2, 3, mat_origem, mat_transposta);
    matriz_imprimir(2, 3, mat_origem, "Matriz Original");
    matriz_imprimir(3, 2, mat_transposta, "Matriz Transposta");

    printf("MULTIPLICACAO DE MATRIZES\n");
    int ma[3][2];
    int mb[2][3];
    int mab[3][3];

    matriz_preencher(3, 2, ma, "1");
    matriz_preencher(2, 3, mb, "2");
    matriz_multiplicar(3, 2, 3, ma, mb, mab);
    matriz_imprimir(3, 3, mab, "Matriz Resultante (A x B)");

    return 0;
}
