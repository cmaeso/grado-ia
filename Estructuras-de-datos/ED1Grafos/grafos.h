//
// Created by c.maeso.2017 on 28/11/2023.
//

#ifndef ED1GRAFOS_GRAFOS_H
#define ED1GRAFOS_GRAFOS_H

typedef struct NodoAdy{
    tElemento elem;
    struct NodoAdy*sig;
}tNodoAdy;

typedef struct nodoLista{
    tElemento elem;
    struct tNodoAdy* ady;
    struct nodoLista*sig;
}tNodoLista;




#endif //ED1GRAFOS_GRAFOS_H
