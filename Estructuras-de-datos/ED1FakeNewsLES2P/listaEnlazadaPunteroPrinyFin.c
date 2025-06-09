//
// Created by c.maeso.2017 on 24/10/2023.
//
#include "listaEnlazadaPunteroPrinyFin.h"
#include "stdio.h"
#include "stdlib.h"
#include "fakenews.h"

//CONSTRUCTORAS GENERADORAS
void crearVacia(tLista * lista){
lista->p=NULL;
lista->f=NULL;
}

//OBSERVADORAS SELECTORAS
tNodo *primero(tLista *lista){
    return lista->p;
}

tLista *resto(tLista*lista) {
    //Comprobamos si está vacía
    if(esVacia(lista)) {
        return lista;

    } else {
        //Eliminamos el primero, copiamos lista->p en un aux y luego asignamo aux->sig a lista->p y liberamos el aux;
        tNodo *aux = lista->p;
        lista->p = aux->sig;
        free(aux);
        return lista;
    }

}

//OBSERVADORAS NO SELECTORAS

int esVacia(tLista * lista){
    return (lista->p==NULL || lista==NULL);
}

int longitud(tLista*lista){
    if (esVacia(lista)){
        return 0;
    } else{
        tNodo *aux= lista->p;
        int longitud=1;
        while (aux->sig!=NULL){
            longitud++;
            aux=aux->sig;
        }
        return longitud;
    }
}
void mostrarLista(tLista * lista){
    tNodo *aux= lista->p;
    while (aux!=NULL){
        mostrarElemento(&aux->elem);
        aux=aux->sig;
    }
}

//CONSTRUCTORAS NO GENERADORAS
void insertarPrincipio(tLista *lista, tElemento elem){
    tNodo * nuevoNodo= malloc(sizeof (tNodo));
    asignarElemento(&nuevoNodo->elem, elem);
    nuevoNodo->sig=lista->p;

    if (esVacia(lista)){
        lista->f=nuevoNodo;
    }
    lista->p= nuevoNodo;
}

void insertarFinal(tLista *lista, tElemento elem){
    tNodo * nuevoNodo=malloc(sizeof (tNodo));
    asignarElemento(&nuevoNodo->elem, elem);
    nuevoNodo->sig=NULL;

    if (esVacia(lista)){
        lista->p=nuevoNodo;
        lista->f=nuevoNodo;
    }
    else {
        lista->f->sig=nuevoNodo;
        lista->f=nuevoNodo;

    }
}

void eliminarElemento(tLista*lista, tElemento elem){
    if (esVacia(lista)){
        printf("La lista está vacía");
    }
    else {
        tNodo *aux= lista->p;
        tNodo *ant=NULL;
        int encontrado=0;
        while (aux!=NULL && !encontrado){
            if (igualElemento(aux->elem, elem)){
                encontrado=1;
            } else {
                ant=aux;
                aux= aux->sig;

            }
        }
        if (encontrado){
            if (aux==lista->p){
                lista->p=aux->sig;

            } else if (aux==lista->f){
                lista->f=ant;
                ant->sig=NULL;
            } else {
                ant->sig=aux->sig;
            }
            free(aux);
        } else {
            printf("No se ha encontrado");
        }
    }
}