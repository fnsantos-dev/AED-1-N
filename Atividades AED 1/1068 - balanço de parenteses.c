#include <stdio.h>
#include <stdlib.h>
#define max 1000
typedef struct Item{
    char valor;
    struct Item *prox;
}Item;
typedef struct {
    Item *topo;
}lista;

int init(lista *p){
    p->topo == NULL;
}

void pop(lista *p, char x){
    Item *novo = (Item *)malloc(sizeof(Item));
    novo->valor = x;
    novo->prox = NULL;
}

int push(lista *p){
    char y;
    Item *temp;
    temp = p->prox;
    y = p->valor;
    p->prox = NULL;
    free(temp);
    return y;
}
int empty(lista *p){
    return p->topo ==NULL;
}

char verificar(char express){
    Item p;
    init(&p);
    for(int i = 0; express[i]!= 0 ;i++){
        if(express[i] == "("){
            pop(&p, "(");
        }
        else if (express[i] == ')') {
            if (pilha_vazia(&p)) {
                return "incorrect";
            }
            pop(&p);
        }
    }
    return empty(&p) ? "correct" : "incorrect" ; 
}
int main(){
    char express;
    while(fgets(express,max, stdin)){
        express[strcspn(express, "\n")] = 0;
        printf("%s\n", verificar(express));
    }
    return 0;
}