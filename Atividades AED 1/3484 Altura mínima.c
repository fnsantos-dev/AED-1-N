#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int valor;
    struct Item *esq;
    struct Item *dir;
} Item;

typedef Item *arvore;

arvore inicializa(int x) {
    arvore novo = (arvore *)malloc(sizeof(Item));
    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void insere(arvore *p, int valor) {
    if (*p == NULL) {
        *p = inicializa(valor);
    } else if (valor < (*p)->valor) {
        insere(&((*p)->esq), valor);
    } else {
        insere(&((*p)->dir), valor);
    }
}
void libera(arvore p) {
    if (p != NULL) {
        libera(p->esq);
        libera(p->dir);
        free(p);
    }
}
void imprimenor(arvore p) {
    if (p == NULL) {
        return;
    }

    arvore fila[250];
    int inicio = 0, fim = 0;
    int nivelAtual = 0;

    fila[fim++] = p;

    while (inicio < fim) {
        int menor = 300;
        int tamanhoNivel = fim - inicio;

        for (int i = 0; i < tamanhoNivel; i++) {
            arvore atual = fila[inicio++];

            if (atual->valor < menor) {
                menor = atual->valor;
            }

            if (atual->esq != NULL) {
                fila[fim++] = atual->esq;
            }
            if (atual->dir != NULL) {
                fila[fim++] = atual->dir;
            }
        }

        printf("%d %d\n", nivelAtual, menor);
        nivelAtual++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    arvore p = NULL;

    for (int i = 0; i < n; i++) {
        int valor;
        scanf("%d", &valor);
        insere(&p, valor);
    }
    imprimenor(p);
    libera(p);
    return 0;
}