Graph inicializa(int v){
    Graph novo = (Graph *)malloc(sizeof(novo));
    novo->v = v;
    novo->a = NULL;
    novo->adj = matrizinit( v , v , 0);
    return novo;
}