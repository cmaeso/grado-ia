//
// Created by c.maeso.2017 on 10/06/2024.
//
#include "stdio.h"
#include "pilas.h"
#include "stdlib.h"
#include "videojuegos.h"

void crearPilaVacia(tPila *pila){
    *pila=NULL;
}

void push(tPila *pila, tElemento elemento){
    tNodoP *nuevoNodo= malloc( sizeof (tNodoP));
    asignarElemento(&nuevoNodo->elem, elemento);
    nuevoNodo->sig=*pila;
    *pila=nuevoNodo;
}
// pila= &nuevoNodo;

void pop(tPila * pila){
    tNodoP *aux= *pila;
    *pila= aux->sig;
    free(aux);
}

int esPilaVacia(tPila*pila){
    return (*pila==NULL);
}
void cima(tPila *pila, tElemento * destino) {
    if (!esPilaVacia(pila)){
        tNodoP * nodo=*pila;
        asignarElemento(destino, nodo->elem);
    }
}

void mostrarPila (tPila *pila){
    tNodoP * nodoAct= *pila; // IMP poner *pila!!!
    int count=0;
    while (nodoAct->sig!=NULL){
        count++;
        mostrarElemento(&nodoAct->elem);
        nodoAct= nodoAct->sig;
    }
    if (nodoAct->sig==NULL){count++;
        mostrarElemento(&nodoAct->elem);}

    if (count==0){
        printf("No hay ningún videojuego gratis para descargar actualmente. ");
    }
}



