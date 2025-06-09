//
// Created by c.maeso.2017 on 23/11/2023.
//

#ifndef ED1ARBOLBIN_ARBOLESNARIOS_H
#define ED1ARBOLBIN_ARBOLESNARIOS_H

typedef struct nodoL {
    struct nodoArbol*hijo;
    struct nodoL *sig;
} tNodoLista;

typedef tNodoLista * tLista;

typedef struct nodoArbol{
    tElemento info;
    tLista hijos;
}tNodoArbol;
typedef tNodoArbol* tArbol;

;
#endif //ED1ARBOLBIN_ARBOLESNARIOS_H
