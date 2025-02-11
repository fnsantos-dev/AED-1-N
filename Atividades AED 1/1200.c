#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char valor;
    struct Node *esq, *dir;
} Node;

Node* criarNo(char valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->esq = novo->dir = NULL;
    return novo;
}

Node* inserir(Node* raiz, char valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void infixa(Node* raiz, int *primeiro) {
    if (raiz) {
        infixa(raiz->esq, primeiro);
        if (*primeiro) *primeiro = 0;
        else printf(" ");
        printf("%c", raiz->valor);
        infixa(raiz->dir, primeiro);
    }
}

void prefixa(Node* raiz, int *primeiro) {
    if (raiz) {
        if (*primeiro) *primeiro = 0;
        else printf(" ");
        printf("%c", raiz->valor);
        prefixa(raiz->esq, primeiro);
        prefixa(raiz->dir, primeiro);
    }
}

void posfixa(Node* raiz, int *primeiro) {
    if (raiz) {
        posfixa(raiz->esq, primeiro);
        posfixa(raiz->dir, primeiro);
        if (*primeiro) *primeiro = 0;
        else printf(" ");
        printf("%c", raiz->valor);
    }
}

int buscar(Node* raiz, char valor) {
    if (raiz == NULL) return 0;
    if (raiz->valor == valor) return 1;
    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}

void liberarArvore(Node* raiz) {
    if (raiz) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    Node* raiz = NULL;
    char comando[10];
    char valor;
    
    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        } else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &valor);
            if (buscar(raiz, valor))
                printf("%c existe\n", valor);
            else
                printf("%c nao existe\n", valor);
        }
    }
    liberarArvore(raiz);
    return 0;
}