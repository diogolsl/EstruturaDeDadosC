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

typedef struct Lista {
    No *cabeca;
} Lista;

Lista* criarLista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->cabeca = NULL;
    return lista;
}

void inserir(Lista *lista, int numero) {
    // lista vazia
    if (lista->cabeca == NULL) {
        lista->cabeca = criarNo(numero, NULL);
        lista->cabeca->proximo = lista->cabeca; // evita que ponteiro aponte para Nulo
    }
    // lista nao vazia
    No *ultimo = lista->cabeca;
    while (ultimo->proximo != lista->cabeca) {
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = criarNo(numero, lista->cabeca);
}

void excluir(Lista *lista, int numero) {
    // lista vazia
    if (lista->cabeca == NULL) {
        return;
    }

    No *temp = NULL;

    // excluir unico
    if ((lista->cabeca->numero == numero) &&
        (lista->cabeca->proximo == lista->cabeca)) {
        temp = lista->cabeca;
        lista->cabeca = NULL;
        free(temp);
        return;
    }

    // excluir o primeiro
    if (lista->cabeca->numero == numero) {
        temp = lista->cabeca;
        No *ultimo = lista->cabeca;
        while (ultimo->proximo != lista->cabeca) {
            ultimo = ultimo->proximo;
        }
        lista->cabeca = lista->cabeca->proximo;
        ultimo->proximo = lista->cabeca;
        free(temp);
    }

    // excluir no meio ou fim
    No *anterior = lista->cabeca;
    while ((anterior->proximo != lista->cabeca) &&
           (anterior->proximo->numero != numero)) {
        anterior = anterior->proximo;
    }
    if (anterior->proximo == lista->cabeca) { // nao encontrei o numero
        return;
    }
    temp = anterior->proximo;
    anterior->proximo = temp->proximo;
    free(temp);
}

void imprimir(Lista *lista) {
    if (lista->cabeca == NULL) {
        return;
    }
    No *ponteiro = lista->cabeca;
    do {
        printf("%d\n", ponteiro->numero);
        ponteiro = ponteiro->proximo;
    } while (ponteiro != lista->cabeca);
}

void liberarLista(Lista *lista) {
    if (lista == NULL) return;

    if (lista->cabeca != NULL) {
        No *atual = lista->cabeca;
        No *proximo;
        do {
            proximo = atual->proximo;
            free(atual);
            atual = proximo;
        } while (atual != lista->cabeca);
    }
    free(lista);
}

int main(void) {
    Lista *lista = criarLista();
    int opcao = 0;
    int numero;
    while (opcao != 5) {
        printf("Opcoes\n");
        printf("1 - Inserir\n");
        printf("2 - excluir\n");
        printf("3 - Imprimir\n");
        printf("4 - Cem mil\n");
        printf("5 - Sair\n");
        printf("Digite sua opcao:  ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero: ");
                scanf("%d", &numero);
                inserir(lista, numero);
                break;
            case 2:
                printf("Digite o numero: ");
                scanf("%d", &numero);
                excluir(lista, numero);
                break;
            case 3:
                imprimir(lista);
                break;
            case 4:
                for (int i = 0; i < 100000; i++) {
                    inserir(lista, i);
                    printf("%d\n", i);
                }
                break;
            case 5:
                printf("Saindo");
                liberarLista(lista);
                break;
        }
    }
    return 0;
}
