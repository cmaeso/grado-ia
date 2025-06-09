//
// Created by c.maeso.2017 on 12/06/2024.
//

#ifndef ED1KAGGLE_ARBOLBINBUS_H
#define ED1KAGGLE_ARBOLBINBUS_H
#include "arbolBin.h"


int mayor(tElemento e1, tElemento e2);
int pertenece(tElemento e, tArbol arbol);
void insertarABB(tElemento e, tArbol*arbol);
tElemento minimo(tArbol a);
void imprimirInOrder(tArbol a);
void eliminarABB(tArbol *a , tElemento e);
tElemento *buscar(tArbol a,tElemento e);
int altura(tArbol a);
int balance(tArbol a);
int esAVL(tArbol);

#endif //ED1KAGGLE_ARBOLBINBUS_H
