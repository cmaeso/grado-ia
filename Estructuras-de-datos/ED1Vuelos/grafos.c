//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

void crearGrafoVacio(tGrafo *g) {
    *g = NULL;
}

void crearListaAdyVacia(tListaAdy *l) {
    *l = NULL;
}

void crearListaDestVacia(tListaVuelos *l) {
    *l = NULL;
}

int esGrafoVacio(tGrafo g) {
    return g == NULL;
}

int esListaAdyVacia(tListaAdy l) {
    return l == NULL;
}

int esListaDestVacia(tListaVuelos l) {
    return l == NULL;
}

int perteneceOrigen(tGrafo g, char *ciudad) {
    while (g != NULL) {
        if (strcmp(g->ciudad, ciudad) == 0) {
            return 1;
        }
        g = g->sig;
    }
    return 0;
}

int perteneceDestino(tListaAdy l, char *ciudad) {
    while (l != NULL) {
        if (strcmp(l->destino, ciudad) == 0) {
            return 1;
        }
        l = l->sig;
    }
    return 0;
}

void insertarVertice(tGrafo *g, char *ciudad) {
    if (perteneceOrigen(*g, ciudad)) {
        return;
    }
    tNodoPrincipal *aux = (tNodoPrincipal *)malloc(sizeof(tNodoPrincipal));
    if (aux == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    strcpy(aux->ciudad, ciudad);
    aux->sig = (*g);
    aux->listaAdy = NULL;
    (*g) = aux;
}

void insertarDestino(tGrafo g, tElemento e2) {
    tNodoPrincipal *aux = g;
    while (aux != NULL && strcmp(aux->ciudad, e2.origen) != 0) {
        aux = aux->sig;
    }
    if (aux != NULL && strcmp(aux->ciudad, e2.origen) == 0) {
        if (!perteneceDestino(aux->listaAdy, e2.dest)) {
            tNodoListaAd *nuevoNodo = (tNodoListaAd *)malloc(sizeof(tNodoListaAd));
            if (nuevoNodo == NULL) {
                printf("Error al asignar memoria.\n");
                return;
            }
            strcpy(nuevoNodo->destino, e2.dest);
            nuevoNodo->listaVuelos = NULL;
            nuevoNodo->sig = aux->listaAdy;
            aux->listaAdy = nuevoNodo;
        }
    }
}

void insertarVuelo(tGrafo *g, tElemento e2) {
    tNodoPrincipal *aux = *g;
    while (aux != NULL && strcmp(aux->ciudad, e2.origen) != 0) {
        aux = aux->sig;
    }
    if (aux != NULL && strcmp(aux->ciudad, e2.origen) == 0) {
        tNodoListaAd *auxDest = aux->listaAdy;
        while (auxDest != NULL && strcmp(auxDest->destino, e2.dest) != 0) {
            auxDest = auxDest->sig;
        }
        if (auxDest != NULL && strcmp(auxDest->destino, e2.dest) == 0) {
            tNodoListaVuelos *nuevoNodo = (tNodoListaVuelos *)malloc(sizeof(tNodoListaVuelos));
            if (nuevoNodo == NULL) {
                printf("Error al asignar memoria.\n");
                return;
            }
            asignarVuelo(&nuevoNodo->e, e2);
            nuevoNodo->sig = auxDest->listaVuelos;
            auxDest->listaVuelos = nuevoNodo;
        }
    }
}

void mostrarVertices(tGrafo g) {
    while (g != NULL) {
        printf("Ciudad: %s\n", g->ciudad);
        tNodoListaAd *ady = g->listaAdy;
        while (ady != NULL) {
            printf("  Destino: %s\n", ady->destino);
            tNodoListaVuelos *vuelo = ady->listaVuelos;
            while (vuelo != NULL) {
                printf("    Compañía: %s, Tiempo: %d, Precio: %d\n",
                       vuelo->e.compania, vuelo->e.tiempo, vuelo->e.precio);
                vuelo = vuelo->sig;
            }
            ady = ady->sig;
        }
        g = g->sig;
    }
}

void mostrarDestinos(tGrafo g, char *ciudad) {
    tNodoPrincipal *nodo = g;
    while (nodo != NULL && strcmp(nodo->ciudad, ciudad) != 0) {
        nodo = nodo->sig;
    }

    if (nodo == NULL) {
        printf("La ciudad %s no se encontró en el grafo.\n", ciudad);
        return;
    }

    printf("Destinos desde %s:\n", ciudad);
    tNodoListaAd *ady = nodo->listaAdy;
    while (ady != NULL) {
        printf("  Destino: %s\n", ady->destino);
        tNodoListaVuelos *vuelo = ady->listaVuelos;
        while (vuelo != NULL) {
            printf("    Compañía: %s, Tiempo: %d, Precio: %d\n",
                   vuelo->e.compania, vuelo->e.tiempo, vuelo->e.precio);
            vuelo = vuelo->sig;
        }
        ady = ady->sig;
    }
}
