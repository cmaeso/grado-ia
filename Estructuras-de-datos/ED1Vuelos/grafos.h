//
// Created by c.maeso.2017 on 13/06/2024.
//

#ifndef ED1VUELOS2_GRAFOS_H
#define ED1VUELOS2_GRAFOS_H
#ifndef ED1VUELOS_GRAFOS_H
#define ED1VUELOS_GRAFOS_H

#include "vuelos.h"

typedef struct listaVuelos {
    tElemento e;
    struct listaVuelos *sig;
} tNodoListaVuelos;

typedef tNodoListaVuelos *tListaVuelos;

typedef struct nodoListaAd {
    char destino[20];
    tListaVuelos listaVuelos; // Lista de vuelos a este destino
    struct nodoListaAd *sig;
} tNodoListaAd;

typedef tNodoListaAd *tListaAdy;

typedef struct nodoPrincipal {
    char ciudad[20];
    struct nodoPrincipal *sig;
    tListaAdy listaAdy;
} tNodoPrincipal;

typedef tNodoPrincipal *tGrafo;

void crearListaAdyVacia(tListaAdy *l);
void crearListaDestVacia(tListaVuelos *l);

int esListaAdyVacia(tListaAdy l);
int esListaDestVacia(tListaVuelos l);
void crearGrafoVacio(tGrafo *g);
int perteneceOrigen(tGrafo g, char *ciudad);
int perteneceDestino(tListaAdy l, char *ciudad);
int esGrafoVacio(tGrafo g);
void insertarVertice(tGrafo *g, char *ciudad);
void insertarDestino(tGrafo g, tElemento e2);
void insertarVuelo(tGrafo *g, tElemento e2);
void mostrarVertices(tGrafo g);
void mostrarDestinos(tGrafo g, char *ciudad);

#endif // ED1VUELOS_GRAFOS_H

#endif //ED1VUELOS2_GRAFOS_H
