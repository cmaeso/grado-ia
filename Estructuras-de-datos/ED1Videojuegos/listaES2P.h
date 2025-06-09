//
// Created by c.maeso.2017 on 10/06/2024.
//

#ifndef ED1VIDEOJUEGOSOK_LISTAES2P_H
#define ED1VIDEOJUEGOSOK_LISTAES2P_H
#include "videojuegos.h"

typedef struct Nodo{
    tElemento elem;
    struct Nodo* sig;
} tNodo;

typedef struct lista{
    tNodo * p;
    tNodo *f;
}tLista;

//CONSTRUCTORAS GENERADORAS
void crearVacia(tLista * lista);

//OBSERVADORAS SELECTORAS
tNodo *primero(tLista *lista);

tLista *resto(tLista*lista);

//OBSERVADORAS NO SELECTORAS

int esVacia(tLista * lista);
int longitud(tLista*lista);

//CONSTRUCTORAS NO GENERADORAS
void insertarPrincipio(tLista*lista, tElemento elem);
void insertarFinal(tLista*lista, tElemento elem);
void eliminarElemento(tLista*lista, tElemento elem);
void mostrarLista(tLista * lista);
void unique (tLista *lista);
void uniqueCarmen (tLista *lista);
void criba(tLista *lista, int salto);
#endif //ED1VIDEOJUEGOSOK_LISTAES2P_H
