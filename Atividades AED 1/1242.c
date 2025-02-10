#include <stdio.h>
#include <string.h>

#define MAX_LEN 300

int contar_ligacoes(const char *fita) {
    char pilha[MAX_LEN];
    int topo = -1;
    int ligacoes = 0;
    
    for (int i = 0; fita[i] != '\0'; i++) {
        char base = fita[i];
        char par;
        
        if (base == 'B'){
            par = 'S';
        }
        else if (base == 'S'){
            par = 'B';
        }
        else if (base == 'C'){
            par = 'F';
        }
        else if (base == 'F') {
            par = 'C';
        }
        else continue;
        
        if (topo >= 0 && pilha[topo] == par) {
            ligacoes++;
            topo--;
        } else {
            pilha[++topo] = base;
        }
    }
    
    return ligacoes;
}

int main() {
    char fita[MAX_LEN + 1];
    
    while (scanf("%s", fita) != EOF) {
        printf("%d\n", contar_ligacoes(fita));
    }
    
    return 0;
}