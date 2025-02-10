#include <stdio.h>
#include <string.h>

void construirPostfixo(char* prefixo, char* infixo, int inicio, int fim) {
    if (inicio > fim) return;
    char raiz = prefixo[0];
    int posRaiz = -1;
    for (int i = inicio; i <= fim; i++) {
        if (infixo[i] == raiz) {
            posRaiz = i;
            break;
        }
    }

    construirPostfixo(prefixo + 1, infixo, inicio, posRaiz - 1);
    construirPostfixo(prefixo + 1 + (posRaiz - inicio), infixo, posRaiz + 1, fim);
    printf("%c", raiz);
}
int main() {
    char prefixo[27], infixo[27];

    while (scanf("%s %s", prefixo, infixo) != EOF) {
        int n = strlen(prefixo);
        construirPostfixo(prefixo, infixo, 0, n - 1);
        printf("\n");
    }

    return 0;
}