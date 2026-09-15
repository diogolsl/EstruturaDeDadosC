#include <stdio.h>
#include <stdlib.h>

// Estrutura para os nós da lista horizontal
typedef struct No {
    int numero;
    struct No *proximo;
} No;

// Estrutura para os diretores da lista vertical
typedef struct Diretor {
    int resto;
    No *proximoNo;
    struct Diretor *proximoDiretor;
} Diretor;

// Estrutura principal da Matriz Esparsa
typedef struct MatrizEsparsa {
    Diretor *cabeca;
    int modulo;
} MatrizEsparsa;

// Inicializa a matriz esparsa
MatrizEsparsa* criarMatriz(int modulo) {
    MatrizEsparsa *matriz = (MatrizEsparsa*) malloc(sizeof(MatrizEsparsa));
    matriz->cabeca = NULL;
    matriz->modulo = modulo;
    return matriz;
}

// Procura diretor, se não existir, cria
Diretor* procurarDiretor(MatrizEsparsa *matriz, int numero) {
    int resto = numero % matriz->modulo;
    if (resto < 0) resto += matriz->modulo;

    Diretor *ponteiro = matriz->cabeca;
    while (ponteiro != NULL && ponteiro->resto != resto) {
        ponteiro = ponteiro->proximoDiretor;
    }

    // Retorna o diretor se encontrado
    if (ponteiro != NULL) {
        return ponteiro;
    }

    // Diretor não encontrado: cria um novo e insere na cabeça da lista de diretores
    Diretor *novoDiretor = (Diretor*) malloc(sizeof(Diretor));
    novoDiretor->resto = resto;
    novoDiretor->proximoNo = NULL;
    novoDiretor->proximoDiretor = matriz->cabeca;
    matriz->cabeca = novoDiretor;

    return novoDiretor;
}

// Insere um elemento no início da lista horizontal do diretor correspondente
void inserir(MatrizEsparsa *matriz, int numero) {
    Diretor *diretor = procurarDiretor(matriz, numero);

    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->numero = numero;
    novoNo->proximo = diretor->proximoNo;
    diretor->proximoNo = novoNo;
}

// Remove um número específico e libera o ponteiro de memória
void excluir(MatrizEsparsa *matriz, int numero) {
    Diretor *diretor = procurarDiretor(matriz, numero);

    if (diretor->proximoNo == NULL) {
        return;
    }

    // Caso o elemento a ser removido seja o primeiro da lista horizontal
    if (diretor->proximoNo->numero == numero) {
        No *noParaRemover = diretor->proximoNo;
        diretor->proximoNo = diretor->proximoNo->proximo;
        free(noParaRemover);
        return;
    }

    // Percurso para buscar o nó anterior ao que será removido
    No *atual = diretor->proximoNo;
    while (atual->proximo != NULL && atual->proximo->numero != numero) {
        atual = atual->proximo;
    }

    // Se encontrou o nó, ajusta os ponteiros e desaloca
    if (atual->proximo != NULL) {
        No *noParaRemover = atual->proximo;
        atual->proximo = noParaRemover->proximo;
        free(noParaRemover);
    }
}

void imprimir(MatrizEsparsa *matriz) {
    Diretor *ponteiroDiretor = matriz->cabeca;

    printf("\nResto \t Números\n");
    while (ponteiroDiretor != NULL) {
        printf("%d \t ", ponteiroDiretor->resto);

        No *ponteiroNo = ponteiroDiretor->proximoNo;
        while (ponteiroNo != NULL) {
            printf("%d, ", ponteiroNo->numero);
            ponteiroNo = ponteiroNo->proximo;
        }
        printf("\n");
        ponteiroDiretor = ponteiroDiretor->proximoDiretor;
    }
}

void liberarMatriz(MatrizEsparsa *matriz) {
    if (matriz == NULL) return;

    Diretor *dirAtual = matriz->cabeca;
    while (dirAtual != NULL) {
        No *noAtual = dirAtual->proximoNo;
        while (noAtual != NULL) {
            No *noTemp = noAtual;
            noAtual = noAtual->proximo;
            free(noTemp);
        }
        Diretor *dirTemp = dirAtual;
        dirAtual = dirAtual->proximoDiretor;
        free(dirTemp);
    }
    free(matriz);
}

int main() {
    MatrizEsparsa *objMatrizEsparsa = criarMatriz(3);

    for (int i = 0; i < 50; i++) {
        inserir(objMatrizEsparsa, i);
    }

    imprimir(objMatrizEsparsa);

    excluir(objMatrizEsparsa, 47);
    excluir(objMatrizEsparsa, 2);
    excluir(objMatrizEsparsa, 46);
    excluir(objMatrizEsparsa, 4);
    excluir(objMatrizEsparsa, 42);
    excluir(objMatrizEsparsa, 6);

    imprimir(objMatrizEsparsa);

    liberarMatriz(objMatrizEsparsa);
    return 0;
}
