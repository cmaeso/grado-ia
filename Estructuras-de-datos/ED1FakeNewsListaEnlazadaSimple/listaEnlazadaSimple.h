//
// Created by c.maeso.2017 on 24/10/2023.
//

#ifndef ED1LISTAS_LISTAENLAZADASIMPLE_H
#define ED1LISTAS_LISTAENLAZADASIMPLE_H
#include "fakenews.h"

typedef struct Nodo {
    tElemento elem;
    struct Nodo* sig;
} tNodo;

typedef tNodo * tLista;

void crearVacia(tLista* lista);
void insertarCabecera(tLista *lista, tElemento elem);
void insertarFinal(tLista *lista, tElemento elem);
void eliminarElemento(tLista *lista, tElemento elem);
void mostrarLista(tLista * lista);
void insertarFinal(tLista* lista, tElemento elem);
void obtenerPrimero(tLista* lista, tElemento elem);
void obtenerResto(tLista* lista);
int esListaVacia (tLista* lista);
int longitud (tLista* lista);




/*
 * Concatenar 2 listas
 * Ver si una lista contiene un elem --> devuelve integer
 */

#endif //ED1LISTAS_LISTAENLAZADASIMPLE_H
