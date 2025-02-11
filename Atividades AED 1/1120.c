#include <stdio.h>
#include <string.h>

int main() {
    int D;
    char N[101];

    while (1) {
        scanf("%d %s", &D, N);

        if (D == 0 && N[0] == '0') {
            break;
        }

        char result[101]; 
        int idx = 0;
        
        for (int i = 0; N[i] != '\0'; i++) {
            if (N[i] - '0' != D) {
                result[idx++] = N[i];
            }
        }
        
        result[idx] = '\0'; 
        
        if (idx == 0) {
            printf("0\n");
        } else {
            printf("%s\n", result);
        }
    }

    return 0;
}