//
// Created by c.maeso.2017 on 20/11/2023.
#include "arboles.h"
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

int diosExiste(tArbol arbol, tElemento dios){

    if (arbol==NULL) {
        return 0;
    }
    else if (strcmp(arbol->elem.nombre, dios.nombre)==0){
        return 1;
    }
    return ((diosExiste(arbol->izq, dios)) || diosExiste(arbol->der, dios));

}

int esArbolVacio(tArbol arbol){
    return(arbol==NULL);
}

int esProgenitor(tArbol arbol, tElemento diosProge, tElemento diosHijo) {
    if (esArbolVacio(arbol)) { return 0; }
    else {
        if (strcmp(arbol->elem.nombre, (diosProge.nombre)) == 0) {
            if ((arbol->izq && (strcmp(arbol->izq->elem.nombre, (diosHijo.nombre)) == 0)) ||
            (arbol->der && ((strcmp(arbol->der->elem.nombre, (diosHijo.nombre)) == 0))))
            {
                return 1;
            } else {
                return esProgenitor(arbol->der, diosProge, diosHijo) || esProgenitor(arbol->izq, diosProge, diosHijo);
            }
        }

    }
}

void imprimirNombre(tElemento dios){
    printf("%s ",dios.nombre);
}

void imprimirPreOrden (tArbol arbol){
    if (arbol!=NULL){
        imprimirNombre(arbol->elem);
        imprimirPreOrden(arbol->izq);
        imprimirPreOrden(arbol->der);
    }
}