#include <stdio.h>
 
int main() {
    int total=0;
    int x,y,z,w,b;
    scanf("%d" ,&x );
    scanf("%d" ,&y );
    scanf("%d" ,&z );
    scanf("%d" ,&w );
    scanf("%d" ,&b );
    total = x*300+y*1500+z*600+w*1000+b*150 + 225;
    printf("%d\n", total);
    
    return 0;
}