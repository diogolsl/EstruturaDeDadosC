#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No *proximo;
} No;

No* criarNo(int numero, No *proximo) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->numero = numero;
    novo->proximo = proximo;
    return novo;
}


// Politica da fila: FIFO ( First in - First Out)
typedef struct Fila {
    No *cabeca;
} Fila;

Fila* criarFila() {
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->cabeca = NULL;
    return fila;
}

void entrar(int numero, Fila *fila) {
    fila->cabeca = criarNo(numero, fila->cabeca);
}

void sair(int numero, Fila *fila) {
    // caso facil : fila vazia
    if (fila->cabeca == NULL) {
        return;
    }

    // caso medio : 1 nó na fila
    if (fila->cabeca->proximo == NULL) {
        printf("%p\n", fila->cabeca->proximo);
        free(fila->cabeca);
        fila->cabeca = NULL;
        return;
    }

    // caso dificil: fila nao vazia
    No *penultimo = fila->cabeca;
    while (penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
    }
    printf("%d\n", penultimo->proximo->numero);
    free(penultimo->proximo);
    penultimo->proximo = NULL;
}


// Politica da pilha: FILO ( First in - Last Out)
typedef struct Pilha {
    No *cabeca;
} Pilha;

Pilha* criarPilha() {
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->cabeca = NULL;
    return pilha;
}

void push (int numero, Pilha *pilha) {
    pilha->cabeca = criarNo(numero, pilha->cabeca);
}

void pop (int numero, Pilha *pilha) {
    // caso muito facil: pilha vazia
    if (pilha->cabeca == NULL) {
        return;
    }

    // caso facil: excluir ultimo que entrou
    No *remover = pilha->cabeca;
    printf("%d\n", remover->numero);
    pilha->cabeca = remover->proximo;
    free(remover);
}


int main(void) {
    Fila *obj_fila = criarFila();
    Pilha *obj_pilha = criarPilha();

    for (int i = 0; i <= 50000; i++) {
        entrar(i, obj_fila);
    }

    for (int i = 0; i <= 50000; i++) {
        sair(i, obj_fila);
    }

    for (int i = 0; i <= 100000; i++) {
        push(i, obj_pilha);
    }

    for (int i = 0; i <= 100000; i++) {
        pop(i, obj_pilha);
    }

    free(obj_fila);
    free(obj_pilha);

    return 0;
}
