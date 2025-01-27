#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int main(){
    int len, high;
    char mapa[MAX][MAX];
    bool visitados[MAX][MAX] = {false};
    

    scanf("%d", &len);
    scanf("%d", &high);
    for (int i = 0; i < len; i++) {
        scanf("%s", mapa[i]);
    }
    int x = 0, y = 0;
    while (true) {

        if (x < 0 || x >= high|| y < 0 || y >= len) {
            printf("!\n");
            return 0;
        }
        if (visitados[x][y]) {
            printf("!\n");
            return 0;
        }
        visitados[x][y] = true;
        char simbolo = mapa[x][y];
        if (simbolo == '*') { 
            printf("*\n");
            return 0;
        } else if (simbolo == '>') { 
            y++;
        } else if (simbolo == '<') { 
            y--;
        } else if (simbolo == 'v') {
            x++;
        } else if (simbolo == '^') { 
            x--;
        } else if (simbolo == '.') {
        }

    }
}

