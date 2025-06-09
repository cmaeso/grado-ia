//
// Created by c.maeso.2017 on 12/06/2024.
//
#include "arbolBinBus.h"
#include "stdlib.h"
#include "stdio.h"

int mayor(tElemento e1, tElemento e2){
    return e1.premio>e2.premio;
}

int pertenece(tElemento e, tArbol arbol){
    if (esArbolVacio(arbol)){
    return 0;
    } else {
        if (igualElemento(e, arbol->elem)){
            return 1;
        } else {
            if (mayor(e,arbol->elem)){
                return pertenece(e, arbol->der);
            }
            else  {
                return pertenece(e, arbol->izq); }
        }
    }
}

tElemento minimo (tArbol arbol){
    if (arbol==NULL) {printf("El arbol está vacio\n");
    } else {
        if (arbol->izq==NULL){
            return (arbol->elem);
        } else {
            return minimo(arbol->izq);
        }
    }
}

tElemento maximo (tArbol a){
    if (esArbolVacio(a)){printf("el arbol está vacio");} else {
        if (a->der==NULL){
            return a->elem;
        } else {
            maximo(a->der);
        }
    }
}

void insertarABB(tElemento e, tArbol* arbol){

    if (esArbolVacio(*arbol)){
        *arbol= (tArbol) malloc(sizeof (tNodo));
        asignarElemento(&(*arbol)->elem, e);
        (*arbol)->izq=NULL;
        (*arbol)->der=NULL;
    } else {
        tElemento r;
        asignarElemento(&r, (*arbol)->elem);
        if (!igualElemento(e,r)){
            if (mayor(e,r)){
                insertarABB(e, (&(*arbol)->der));
            } else{
                insertarABB(e, (&(*arbol)->izq));
            }
        }

    }

}


void eliminarABB(tArbol *a , tElemento e){
    if (!esArbolVacio(*a)) {
        if (igualElemento((*a)->elem, e)) {//raiz
            tArbol aux;
            aux = (*a);
            if (esArbolVacio((*a)->izq)) {
                (*a) = (*a)->der;
                free(aux);

            } else if (esArbolVacio((*a)->der)) {
                (*a) = (*a)->izq;
                free(aux);
            } else {
                // tiene dos hijos (por conveniencia se asigna como raiz el minimo del hijo der)
                asignarElemento(&(*a)->elem, minimo((*a)->der));
                eliminarABB(&(*a)->der, minimo((*a)->der));
            }

        } else if (mayor(e, ((*a)->elem))) {
            eliminarABB(&(*a)->der, e);
        } else {
            eliminarABB(&(*a)->izq, e);
        }
    } else {return;}
}

void imprimirInOrder(tArbol a) {
    if (!esArbolVacio(a)) {
        imprimirInOrder(a->izq);
        mostrarElemento(a->elem);
        imprimirInOrder(a->der);
    }
}

tElemento* buscar(tArbol a,tElemento e){
    if (!esArbolVacio(a)){
        if (igualElemento(a->elem, e)){
            return &a->elem;
        } else if (mayor(a->elem, e)){
            return buscar(a->izq, e);
        } else {
            return buscar(a->der,e);
        }
    } else {
        return NULL;
    }
}

int altura(tArbol a){
    if (esArbolVacio(a)){
        return 0;
    } else {
        if (esArbolVacio(a->der)&& esArbolVacio(a->izq)){
            return 1;
        } else{
            if (altura(a->der)> altura(a->izq)){
                return altura(a->der)+1;
            } else {
                altura(a->izq)+1;
            }
        }
    }
}

int balance(tArbol a){
    if (esArbolVacio(a)){
        return 0;
    } else{
        return altura(a->izq)- altura(a->der);
    }
}
int esAVL(tArbol a){
    if (esArbolVacio(a)){
        return 1;
    } else {
        int bal= balance(a);
        if (abs(bal)>1){
            return 0;
        } else {
            return esAVL(a->der)&& (a->izq);
        }
    }
}