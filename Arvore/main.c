#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int numero;
    struct No *filhos[5];
} No;

No* criar_no(int numero) {
    No *novo_no = (No*) malloc(sizeof(No));
    if (novo_no != NULL) {
        novo_no->numero = numero;
        for (int i = 0; i < 5; i++) {
            novo_no->filhos[i] = NULL;
        }
    }
    return novo_no;
}

No* inserir(No *raiz, int numero) {
    // arvore vazia
    if (raiz == NULL) {
        return criar_no(numero);
    }

    // arvore nao vazia
    int sorteio = rand() % 5;
    raiz->filhos[sorteio] = inserir(raiz->filhos[sorteio], numero);

    return raiz;
}

void imprimir(No *raiz, int nivel) {
    if (raiz == NULL) return;

    for (int i = 0; i < nivel; i++) {
        printf("---");
    }
    printf("%d\n", raiz->numero);
    for (int i = 0; i < 5; i++) {
        imprimir(raiz->filhos[i], nivel + 1);
    }
}

void liberar(No *raiz) {
    if (raiz == NULL) return;
    for (int i = 0; i < 5; i++) {
        liberar(raiz->filhos[i]);
    }
    free(raiz);
}

int main() {
    srand((unsigned int)time(NULL));

    No *raiz = NULL;
    for (int i = 0; i < 100000; i++) {
        raiz = inserir(raiz, i);
    }

    imprimir(raiz, 0);
    liberar(raiz);
    
    return 0;
}
