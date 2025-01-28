#include <stdio.h>
#include <string.h>

int main() {
    int n; 
    scanf("%d", &n);
    int ledsPorDigito[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    for (int i = 0; i < n; i++) {
        char numero[101]; 
        scanf("%s", numero);

        int totalLeds = 0;


        for (int j = 0; j < strlen(numero); j++) {
            int digito = numero[j] - '0';
            totalLeds += ledsPorDigito[digito];
        }
        printf("%d leds\n", totalLeds);
    }

    return 0;
}