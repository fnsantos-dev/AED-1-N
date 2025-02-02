#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    int A, B, C, D, E;
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
    int cont = 0;
    if (T == A){
        cont++;
    }
    if (T == B) {
        cont++;
    }
    if (T == C) {
        cont++;
    }
    if (T == D) {
        cont++;
    }
    if (T == E) {
        cont++;
    }

    printf("%d\n", cont);

    return 0;
}