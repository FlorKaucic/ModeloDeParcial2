#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>

#define TODO_BIEN 1
#define TODO_MAL 0

typedef struct
{
    char clave[9];
    int cant;
}t_info;

typedef struct s_nodo
{
    t_info info;
    struct s_nodo * sig;
}t_nodo;

typedef t_nodo * t_lista;

void crearLista(t_lista *);
int agregarNodo(t_lista *, const t_info *);
int agregarNodo(t_lista *, t_info *);

#endif // LISTA_H_INCLUDED
