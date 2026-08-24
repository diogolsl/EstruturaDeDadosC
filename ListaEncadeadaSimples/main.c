#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No *proximo;
} No;

// construtor para a estrutura do Nó
No* criarNo(int numero, No *proximo) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->numero = numero;
    novo->proximo = proximo;
    return novo;
}

typedef struct Lista {
    No *cabeca;
} Lista;

// construtor para a estrutura da Lista
Lista* criarLista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->cabeca = NULL;
    return lista;
}

void inserir(Lista *lista, int numero) {
    // lista vazia
    if (lista->cabeca == NULL) {
        lista->cabeca = criarNo(numero, NULL);
        return;
    }
    // lista não vazia
    No *ponteiro = lista->cabeca;
    while (ponteiro->proximo != NULL) {
        ponteiro = ponteiro->proximo;
    }
    ponteiro->proximo = criarNo(numero, NULL);
}

void exlcuir(Lista *lista, int numero) {
    // lista vazia
    if (lista->cabeca == NULL) {
        return;
    }
    // excluir primeiro nó da lista
    if (lista->cabeca->numero == numero) {
        No *temp = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
        free(temp); // jogar o fora o nó excluido
        return;
    }
    // excluir no meio ou fim da lista
    No *anterior = lista->cabeca;
    while (anterior->proximo != NULL && anterior->proximo->numero != numero) {
        anterior = anterior->proximo;
    }
    // numero nao encontrado
    if (anterior->proximo == NULL) {
        return;
    }

    No *temp = anterior->proximo;
    anterior->proximo = anterior->proximo->proximo;
    free(temp); // desaloca nó excluido
}

void imprimir(Lista *lista) {
    No *ponteiro = lista->cabeca;
    while (ponteiro != NULL) {
        printf("%d\n", ponteiro->numero);
        ponteiro = ponteiro->proximo;
    }
}
// liberar lista da memória por inteiro
void destroiLista(Lista *lista) {
    No *temp = lista->cabeca;
    while (temp != NULL) {
        No *proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }
    free(lista);
}

int main(void) {
    printf("\n");

    Lista *objlista = criarLista();
    for (int i = 1; i <= 10; i++) {
        inserir(objlista, i);
    }

    exlcuir(objlista, 10);
    imprimir(objlista);

    destroiLista(objlista);

    return 0;
}
