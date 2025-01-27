#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int cont;
    struct Lista *seg;
    
}list;
int main(){
    list *lst;
    lst = malloc (sizeof (list));
    lst->seg = NULL;

}
list *busca(int x, list *lst){
    list *p;
    p = lst->seg;
    while (p != NULL && p->cont != x){
        p= p->seg;
    }
    return p;
}

int min(list *lst, int x){
    list *p;
    p= lst->seg;
    if(p !=NULL && p->cont>p->seg){
        x = cont;
    }
    else:{
        return min(int x);
    }
    free(lst);
}

