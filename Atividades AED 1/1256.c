#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char aviao[10];
    struct Item *prox;
} Item;

typedef struct Lista {
    Item *topo;
    Item *fim;
} Lista;

void init(Lista *p) {
    p->topo = NULL;
    p->fim = NULL;
}

void push(Lista *p, char *aviao) {
    Item *novo = (Item *)malloc(sizeof(Item));
    strcpy(novo->aviao, aviao);
    novo->prox = NULL;

    if (p->fim == NULL) {
        p->topo = novo;
        p->fim = novo;
    } else {
        p->fim->prox = novo;
        p->fim = novo;
    }
}

char *pop(Lista *p) {
    if (p->topo == NULL) {
        return NULL;
    }

    Item *temp = p->topo;
    char *aviao = (char *)malloc(10 * sizeof(char));
    strcpy(aviao, temp->aviao);
    p->topo = p->topo->prox;

    if (p->topo == NULL) {
        p->fim = NULL;
    }

    free(temp);
    return aviao;
}

void liberarLista(Lista *p) {
    Item *atual = p->topo;
    while (atual != NULL) {
        Item *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    p->topo = NULL;
    p->fim = NULL;
}

void printar(Lista *p) {
    Item *atual = p->topo;
    while (atual != NULL) {
        printf("%s ", atual->aviao);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Lista fila;
    init(&fila);

    push(&fila, "A1");
    push(&fila, "A2");
    push(&fila, "A3");

    printf("Fila atual:\n");
    printar(&fila);

    char *removido = pop(&fila);
    printf("Removido: %s\n", removido);
    free(removido);

    printf("Fila após remoção:\n");
    printar(&fila);

    liberarLista(&fila);
    return 0;
}
