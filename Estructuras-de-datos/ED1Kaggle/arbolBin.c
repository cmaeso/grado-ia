//
// Created by c.maeso.2017 on 12/06/2024.

// Created by c.maeso.2017 on 20/11/2023.
#include "arbolBin.h"
#include "stdio.h"

#include "string.h"
#include "stdlib.h"


void crearArbolVacio (tArbol* a) {
    *a = NULL;
}


void construirArbol (tArbol* arbol, tArbol izq, tArbol der, tElemento elem){
    *arbol= malloc(sizeof (tNodo));
    asignarElemento((&(*arbol)->elem), elem);
    (*arbol)->der=  der;
    (*arbol)->izq= izq;
}

int esArbolVacio(tArbol arbol){
    return(arbol==NULL);
}


void imprimirPreOrden (tArbol arbol){
    if (arbol!=NULL){
        mostrarElemento(arbol->elem);
        imprimirPreOrden(arbol->izq);
        imprimirPreOrden(arbol->der);
    }
}