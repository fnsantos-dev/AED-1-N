#include <stdio.h>
#define TAMANHO 9
//VER = VERIFICAR
int ver_linha(int sudoku[TAMANHO][TAMANHO], int linha) {
    int numeros[TAMANHO + 1] = {0};
    for (int i = 0; i < TAMANHO; i++) {
        int num = sudoku[linha][i];
        if (num < 1 || num > 9 || numeros[num] == 1)
            return 0;
        numeros[num] = 1;
    }
    return 1;
}
int ver_coluna(int sudoku[TAMANHO][TAMANHO], int coluna) {
    int numeros[TAMANHO + 1] = {0};
    for (int i = 0; i < TAMANHO; i++) {
        int num = sudoku[i][coluna];
        if (num < 1 || num > 9 || numeros[num] == 1)
            return 0;
        numeros[num] = 1;
    }
    return 1;
}
int regiao(int sudoku[TAMANHO][TAMANHO], int linha_inicio, int coluna_inicio) {
    int numeros[TAMANHO + 1] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = sudoku[linha_inicio + i][coluna_inicio + j];
            if (num < 1 || num > 9 || numeros[num] == 1)
                return 0;
            numeros[num] = 1;
        }
    }
    return 1;
}
int ver_sudoku(int sudoku[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        if (!ver_linha(sudoku, i) || !ver_coluna(sudoku, i))
            return 0;
    }
    for (int i = 0; i < TAMANHO; i += 3) {
        for (int j = 0; j < TAMANHO; j += 3) {
            if (!regiao(sudoku, i, j))
                return 0;
        }
    }
    return 1;
}
int main() {
    int n, instancia = 1;
    scanf("%d", &n);
    while (n--) {
        int sudoku[TAMANHO][TAMANHO];
        
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }
        printf("Instancia %d\n", instancia++);
        if (ver_sudoku(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }
    return 0;
}