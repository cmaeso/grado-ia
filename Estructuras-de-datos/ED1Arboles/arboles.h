//
// Created by c.maeso.2017 on 20/11/2023.
//
#include "dioses.h"
#ifndef ED1ARBOLES_ARBOLES_H
#define ED1ARBOLES_ARBOLES_H



typedef struct Nodo{
    tElemento elem;
    struct Nodo*izq;
    struct Nodo*der;
} tNodo;


typedef tNodo* tArbol;

// *Constructoras generadoras*
int esArbolVacio (tArbol a);
void crearArbolVacio (tArbol* a);
void construirArbol (tArbol* arbol, tArbol izq, tArbol der, tElemento elem);
void asignarElemento(tElemento * destino, tElemento origen);

int diosExiste(tArbol arbol, tElemento dios);
int esProgenitor(tArbol arbol, tElemento diosProge, tElemento diosHijo);
void imprimirPreOrden (tArbol arbol);
void imprimirNombre(tElemento dios);
// *Constructoras generadoras*


//Observadoras no selectoras

// *Constructoras no generadoras*


#endif //ED1ARBOLES_ARBOLES_H
