//
// Created by c.maeso.2017 on 30/11/2023.
#include "stdio.h"
#include "tweets.h"
#include "stdlib.h"
#include "string.h"

//
void crearArbolVacio(tArbol * arbol){
    *arbol=NULL;
}

int esArbolVacio (tArbol a){
    return a==NULL;
}

int esMayor(char tweet1[141], char tweet2[141]){
    int r= strcmp(tweet1,tweet2);
    if (r<0){return 0;}
    else if (r>0){return 1;}
}


int pertenece(tArbol arbol, char ht[141]){
    if(!esArbolVacio(arbol)){
        return 0;
    } else{
        if (strcmp(arbol->hashtag, ht)==0){
            return 1;
        } else {
            return pertenece(arbol->izq, ht) || pertenece(arbol->der, ht);
        }
    }
}

void insertarNodo(tArbol* a, char hashtag[141]) {
    if (esArbolVacio(*a)){ //se insertará cuando sea vacio :) (insertamos al final)
        *a= (tArbol) malloc(sizeof (tNodo));
        strcpy((*a)->hashtag, hashtag);
        (*a)->izq=NULL;
        (*a)->der=NULL;
    } else {
        // raiz
        if (strcmp((*a)->hashtag, hashtag)==0){
            return;
        } else {
            if(esMayor((*a)->hashtag,hashtag)) {
                insertarNodo(&(*a)->izq, hashtag);
            } else {
                insertarNodo(&(*a)->der, hashtag);
                }
            }
        }
    }

void imprimirElemento(char ht[141]){
    printf("%s \n", ht);
}


void imprimirArbol(tArbol a){
    if (!esArbolVacio(a)){
        imprimirArbol(a->izq);
        imprimirElemento(a->hashtag);
        imprimirArbol(a->der);
    }
}
