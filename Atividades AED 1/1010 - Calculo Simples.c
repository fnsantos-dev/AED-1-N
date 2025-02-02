#include <stdio.h>
 
int main() {
    int x,n;
    float p,t = 0;
    for(int i = 0; i<2;i++){
        scanf("%d %d %f.2", &x , &n ,&p);
        t = t+ n * p;
    }
    printf("VALOR A PAGAR: R$ %.2f\n", t);
    return 0;
}