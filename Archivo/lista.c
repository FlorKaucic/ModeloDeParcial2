#include "lista.h"

void crearLista(t_lista * p)
{
    p = NULL;
}

int agregarNodo(t_lista * p, const t_info * d)
{
    t_nodo * nue = (t_nodo *)malloc(sizeof(t_nodo));
    if(!nue)
        return TODO_MAL;

    nue->info = *d;
    nue->sig = *p;
    *p = nue;

    return TODO_BIEN;
}
