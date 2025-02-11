#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct no *prox;
}no;
typedef struct lista{
    no *topo;
}lista;

