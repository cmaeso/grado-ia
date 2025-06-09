//
// Created by c.maeso.2017 on 03/11/2023.
//

#ifndef ED1LISTADOBLEMENTEENLAZADA_LISTADOBLEMENTEENLAZADA_H
#define ED1LISTADOBLEMENTEENLAZADA_LISTADOBLEMENTEENLAZADA_H

typedef int tElemento;
typedef struct nodo {
    tElemento elem;
    struct nodo * sig;
    struct nodo*ant;
} tNodo;

typedef tNodo * tListaDE;
void crearVacia(tListaDE*lista);
void mostrarLista(tListaDE*lista);



void asignarElemento( tElemento * dest, tElemento elem);



int igual(tElemento * e1, tElemento e2);
void insertar( tListaDE*lista, tElemento elemento);


void insertarAntesDe (tListaDE * list, tElemento e1, tElemento e2);


#endif //ED1LISTADOBLEMENTEENLAZADA_LISTADOBLEMENTEENLAZADA_H
