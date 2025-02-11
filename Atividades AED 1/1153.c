#include <stdio.h>
 
int main() {
    int x,n = 1;
    scanf("%d", &x);
    for(int i = 1; i<=x;i++)
    {
        n *= i;
    }
    printf("%d\n", n);
    return 0;
}
