#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int cont;
    struct Lista *seg;
    
};
typedef struct Lista list;

int main(){
    list *lst;
    lst = malloc (sizeof (list));
    lst->seg = NULL;

}
list *busca(int x, list *lst){
    list *p;
    p = lst->seg;
    while (p =! NULL && p->cont =! x){
        p= p->seg;
    }
    return p;
}

