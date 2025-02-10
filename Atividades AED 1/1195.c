#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    int valor;
    struct arvore *esq;
    struct arvore *dir;
} arvore;

arvore* init(int x) {
    arvore *novo = (arvore*)malloc(sizeof(arvore));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void insert(arvore **p, int x) {
    if (*p == NULL) {
        *p = init(x);
    } else if (x < (*p)->valor) {
        insert(&((*p)->esq), x);
    } else {
        insert(&((*p)->dir), x);
    }
}

void prefixo(arvore *p) {
    if (p != NULL) {
        printf(" %d", p->valor);
        prefixo(p->esq);
        prefixo(p->dir);
    }
}


void emordem(arvore *p) {
    if (p != NULL) {
        emordem(p->esq);
        printf(" %d", p->valor);
        emordem(p->dir);
    }
}


void posfixo(arvore *p) {
    if (p != NULL) {
        posfixo(p->esq);
        posfixo(p->dir);
        printf(" %d", p->valor);
    }
}

void libera(arvore *p) {
    if (p != NULL) {
        libera(p->esq);
        libera(p->dir);
        free(p);
    }
}

int main() {
    int c, n, y;
    arvore *raiz = NULL;

    scanf("%d", &c);

    for (int i = 1; i <= c; i++) {
        scanf("%d", &n);

        raiz = NULL; 

        for (int j = 0; j < n; j++) {
            scanf("%d", &y);
            insert(&raiz, y);
        }
        printf("Case %d:\n", i);

        printf("Pre.:");
        prefixo(raiz);
        printf("\n");

        printf("In..:");
        emordem(raiz);
        printf("\n");

        printf("Post:");
        posfixo(raiz);
        printf("\n");

        libera(raiz);
        printf("\n");
    }

    return 0;
}
