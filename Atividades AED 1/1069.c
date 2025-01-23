#include <stdio.h>
int main() {
    char n[1001];
    int x, dimas = 0, esq, dir;
    scanf("%d", &x);
    while(x--){
        scanf("%s", &n);
        esq = 0;
        dir = 0;
        for(int j = 0; n[j]!= "\0"; j++){
            if(n[j] == "<"){
                esq++;
            }
            else if(n[j] == ">"){
                dir++;
            
                if(esq >0){
                    esq--;
                    dir--;
                    dimas++;
                }
            }

        }
        printf("%d\n", dimas);
    }
    return 0;
}