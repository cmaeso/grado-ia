//
// Created by c.maeso.2017 on 03/11/2023.
//

#include "stdio.h"
#include "stdlib.h"

#include "listaDoblementeEnlazada.h"

void crearVacia(tListaDE*lista){
    *lista=NULL;
}

void mostrarLista(tListaDE*lista){
    tNodo *aux= *lista;
    if (*lista==NULL){
        printf("La lista está vacía");
    } else {
        while (aux!=NULL){
            printf("%i ",aux->elem);
            aux=aux->sig;
        }
        printf("\n");

    }
}


void asignarElemento( tElemento * dest, tElemento elem){
    *dest=elem;
}

int igual(tElemento * e1, tElemento e2){
    return (*e1==e2);
}

void insertar( tListaDE*lista, tElemento elemento){
    tNodo *nuevoNodo= malloc(sizeof (tNodo));
    asignarElemento(&nuevoNodo->elem,elemento);

    if(*lista==NULL){
        *lista=nuevoNodo;
        nuevoNodo->ant=NULL;
    }  else{
        tNodo *aux= *lista;
        while (aux->sig!=NULL){
            aux=aux->sig;
        }
        nuevoNodo->ant=aux;
        aux->sig=nuevoNodo;
    }
    nuevoNodo->sig=NULL;
}

void insertarAntesDe (tListaDE*  a, tElemento e1, tElemento e2){
    tListaDE act=*a;
    tListaDE ant=NULL;
    int encontrado=0;


    while (act!=NULL && !encontrado){
        if (igual(&act->elem, e1)){
            if (act==*a){
                insertar(a, e2);
            }
            tNodo *nuevoNodo=malloc(sizeof (tNodo));
            asignarElemento(&nuevoNodo->elem, e2);
            nuevoNodo->ant=act;
            nuevoNodo->sig=act->sig;
            act->sig=nuevoNodo;
            encontrado=1;
        }
        else {
            ant= act;
            act=act->sig;

        }

    }
}
