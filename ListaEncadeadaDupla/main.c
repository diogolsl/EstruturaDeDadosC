#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No *anterior;
    struct No *proximo;
} No;

// construtor Nó
No* criarNo(int numero, No* anterior, No* proximo) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    novo->numero = numero;
    novo->anterior = anterior;
    novo->proximo = proximo;
    return novo;
}

typedef struct Lista {
    No* cabeca;
} Lista;

// construtor para a lista
Lista *criarLista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->cabeca = NULL;
    return lista;
}

// inserindo pela cabeca
void inserir(Lista *lista, int numero) {
    No* novo = criarNo(numero, NULL, lista->cabeca);
    // Atualiza a referência do anterior no elemento antigo que era a cabeça
    if (lista->cabeca != NULL) {
        lista->cabeca->anterior = novo;
    }
    lista->cabeca = novo;
}
// excluindo por valor
void excluir(Lista *lista, int numero) {
    // lista vazia
    if (lista->cabeca == NULL) {
        return;
    }
    // excluir cabeca
    if (lista->cabeca->numero == numero) {
        No *temp = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
        if (lista->cabeca != NULL) { // caso de nao ser o unico
            lista->cabeca->anterior = NULL;
        }
        free(temp);
        return;
    }
    // buscar elemento restante na lista
    No *ponteiro = lista->cabeca;
    while (ponteiro != NULL && ponteiro->numero != numero) {
        ponteiro = ponteiro->proximo;
    }
    // nao encontrou o numero
    if (ponteiro == NULL) {
        return;
    }
    // reencadeamento dos ponteiros
    if (ponteiro->anterior != NULL) {
        ponteiro->anterior->proximo = ponteiro->proximo;
    }
    if (ponteiro->proximo != NULL) {
        ponteiro->proximo->anterior = ponteiro->anterior;
    }
    free(ponteiro);
}

void imprimir(Lista *lista) {
    No *ponteiro = lista->cabeca;
    while (ponteiro != NULL) {
        printf("%d\n", ponteiro->numero);
        ponteiro = ponteiro->proximo;
    }
}

// liberar memoria alocada
void liberarLista(Lista *lista) {
    No *temp = lista->cabeca;
    while (temp != NULL) {
        No *proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }
    free(lista);
}

int main(void) {
    Lista *objLista = criarLista();
    int opcao = 0;
    int numero = 0;

    while (opcao != 5) {
        printf("\nMenu de Opcoes\n");
        printf("1 - Inserir\n");
        printf("2 - Excluir\n");
        printf("3 - Imprimir\n");
        printf("4 - Cem Milhoes\n");
        printf("5 - Sair\n");

        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite um numero para incluir: ");
            scanf("%d", &numero);
            inserir(objLista, numero);
        } else if (opcao == 2) {
            printf("Digite um numero para excluir: ");
            scanf("%d", &numero);
            excluir(objLista, numero);
            imprimir(objLista);
        } else if (opcao == 3) {
            imprimir(objLista);
        } else if (opcao == 4) {
            for (int i = 0; i < 100000; i++) {
                inserir(objLista, i);
                imprimir(objLista);
            }
        }
    }
    liberarLista(objLista);
    return 0;
}


