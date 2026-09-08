#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *proximo;
} no;

typedef struct deque {
    no *fila_normal;
    no *fila_preferencial;
    int contador;
} deque;

no* criar_no(int numero, no*proximo) {
    no *novo_no = (no*) malloc(sizeof(no));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    novo_no->numero = numero;
    novo_no->proximo = proximo;
    return novo_no;
}

void inicializar_deque(deque *d) {
    d->fila_normal = NULL;
    d->fila_preferencial = NULL;
    d->contador = 0;
}

// remove no final da fila (FIFO)
no* sair(no* fila) {
    // fila vazia
    if (fila == NULL) {
        return NULL;
    }

    // nó unico na fila
    if (fila->proximo == NULL) {
        printf("%d\n", fila->numero);
        free(fila);
        return NULL;
    }

    // mais de um nó na fila
    no* penultimo = fila;
    while (penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
    }
    printf("%d\n", penultimo->proximo->numero);
    free(penultimo->proximo);
    penultimo->proximo = NULL;
    return fila;
}

// inserindo no inicio
void entrar(deque *d, int numero, bool normal) {
    if (normal) {
        d->fila_normal = criar_no(numero, d->fila_normal);
    } else {
        d->fila_preferencial = criar_no(numero, d->fila_preferencial);
    }
}

// baseado na regra de prioridade 1x3
void atender(deque *d) {
    // ambas filas vazias
    if (d->fila_preferencial == NULL && d->fila_normal == NULL) {
        printf("Va tomar um cafe!\n");
        d->contador = 0;
        return;
    }

    // fila normal tem gente e preferencial vazia
    if (d->fila_preferencial == NULL) {
        d->fila_normal = sair(d->fila_normal);
        d->contador = 0;
        return;
    }

    // fila preferencial tem gente e normal vazia
    if (d->fila_normal == NULL) {
        d->fila_preferencial = sair(d->fila_preferencial);
        d->contador = 0;
        return;
    }

    // ambas filas tem gente
    if (d->contador < 3) {
        d->fila_preferencial = sair(d->fila_preferencial);
        d->contador++;
    } else {
        d->fila_normal = sair(d->fila_normal);
        d->contador = 0;
    }
}

int main() {
    deque deque;
    inicializar_deque(&deque);

    printf("Atender com filas vazias\n");
    atender(&deque);

    // inserindo 5 preferenciais
    for (int i = 1; i <= 5; i++) {
        entrar(&deque, i * 100, false);
    }

    // Inserindo 2 normais
    for (int i = 1; i <= 2; i++) {
        entrar(&deque, i, true);
    }

    printf("\nAtendimento alternando prioridades\n");
    for (int i = 0; i < 8; i++) {
        printf("Atendimento %d: ", i + 1);
        atender(&deque);
    }
    return 0;
}
