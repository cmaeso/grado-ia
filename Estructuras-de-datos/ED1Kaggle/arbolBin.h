//
// Created by c.maeso.2017 on 12/06/2024.
//

#ifndef ED1KAGGLE_ARBOLBIN_H
#define ED1KAGGLE_ARBOLBIN_H

#include "competiciones.h"


typedef struct Nodo{
    tElemento elem;
    struct Nodo*izq;
    struct Nodo*der;
} tNodo,* tArbol;

// *Constructoras generadoras*
int esArbolVacio (tArbol a);
void crearArbolVacio (tArbol* a);
void construirArbol (tArbol* arbol, tArbol izq, tArbol der, tElemento elem);
void asignarElemento(tElemento * destino, tElemento origen);
// *Constructoras generadoras*


//Observadoras no selectoras

// *Constructoras no generadoras*



#endif //ED1KAGGLE_ARBOLBIN_H
