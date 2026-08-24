#ifndef MATRIZES_MATRIZ_H
#define MATRIZES_MATRIZ_H

void matriz_preencher(int linhas, int cols, int matriz[linhas][cols], const char *nome_matriz);

void matriz_imprimir(int linhas, int cols, const int matriz[linhas][cols], const char *titulo);

void matriz_transposta(int linhas, int cols, const int origem[linhas][cols], int destino[cols][linhas]);

void matriz_multiplicar(int r1, int c1, int c2,
                        const int A[r1][c1],
                        const int B[c1][c2],
                        int C[r1][c2]);

#endif
