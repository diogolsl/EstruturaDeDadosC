#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int numero;
    struct No *proximo;
    struct No *anterior;
} No;

No *criarNo(int numero,No *proximo,No *anterior) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->numero = numero;
    novo->proximo = proximo;
    novo->anterior = anterior;
    return novo;
}

typedef struct Lista {
    No *cabeca;
} Lista;

Lista *criarLista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->cabeca = NULL;
    return lista;
}

void inserir(Lista *lista, int numero) {
    // lista vazia
    if (lista->cabeca == NULL) {
        lista->cabeca = criarNo(numero, NULL, NULL);
        lista->cabeca->proximo = lista->cabeca;
        lista->cabeca->anterior = lista->cabeca;
        return;
    }
    // lista nao vazia e inserindo no final
    No *ultimo = lista->cabeca->anterior;
    No *novo = criarNo(numero, lista->cabeca, ultimo);

    ultimo->proximo = novo;
    lista->cabeca->anterior = novo;
}

bool excluir(Lista *lista, int numero) {
    if (lista->cabeca == NULL) {
        return false;
    }

    No *atual = lista->cabeca;
    do {
        if (atual->numero == numero) {
            // Se for o unico
            if (atual->proximo == atual) {
                lista->cabeca = NULL;
                free(atual);
                return true;
            }

            No *anterior = atual->anterior;
            No *proximo = atual->proximo;

            anterior->proximo = proximo;
            proximo->anterior = anterior;

            // Verifica se eh a cabeca ANTES de dar o free
            if (atual == lista->cabeca) {
                lista->cabeca = proximo;
            }
            free(atual);

            return true;
        }
        atual = atual->proximo;
    } while (atual != lista->cabeca);

    return false; // elemento nao encontrado
}

void imprimir(Lista *lista) {
    if (lista->cabeca == NULL) {
        return;
    }
    No *ponteiro= lista->cabeca;
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
