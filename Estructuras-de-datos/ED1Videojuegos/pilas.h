//
// Created by c.maeso.2017 on 10/06/2024.
//

#ifndef ED1VIDEOJUEGOSOK_PILAS_H
#define ED1VIDEOJUEGOSOK_PILAS_H
#include "videojuegos.h"

typedef struct NodoP {
    tElemento elem;
    struct NodoP* sig;
    struct NodoP* ant;
} tNodoP;

typedef tNodoP *tPila;

void pop(tPila * pila);
void push(tPila *pila, tElemento  elemento);
void mostrarPila (tPila *pila);
int esPilaVacia(tPila*pila);
void cima(tPila *pila, tElemento * destino);


void crearPilaVacia(tPila *pila);

#endif //ED1VIDEOJUEGOSOK_PILAS_H
