#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char **alunos = (char **)malloc(N * sizeof(char *));
    if (alunos == NULL) {
        fprintf(stderr, "Erro ao alocar memoria.\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        alunos[i] = (char *)malloc(21 * sizeof(char));
        if (alunos[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memoria.\n");
            return 1;
        }
        scanf("%s", alunos[i]);
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(alunos[j], alunos[j + 1]) > 0) {
                char *temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    printf("%s\n", alunos[K - 1]);
    for (int i = 0; i < N; i++) {
        free(alunos[i]);
    }
    free(alunos);
    return 0;
}
