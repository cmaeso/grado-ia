//
// Created by c.maeso.2017 on 24/10/2023.
//
#include "listaEnlazadaSimple.h"
#include "stdio.h"
#include "stdlib.h"

void crearVacia(tLista* lista) {
    *lista = NULL;}


void insertarCabecera(tLista *lista, tElemento elem){
    tNodo* aux= (tNodo*) malloc(1* sizeof (tNodo)); // Puntero a un struct
    asignarElemento(&aux->elem,elem);
    //asignarElemento((*aux).elem,elem);
    //void asignarElemento (tElemento* dest, tElemento origen);
    aux-> sig= *lista;
    *lista=aux;
}

void eliminarElemento (tLista *lista, tElemento elem){
    tNodo * aux= *lista;
    tNodo * ant= NULL;
    int encontrado=0;
    while (!encontrado && aux != NULL){
        encontrado= igualElemento (aux->elem, elem);
        if (encontrado==0){
            ant=aux;
            aux = aux -> sig;
        }
        else {
            if (ant==NULL){
                (*lista)= aux->sig;
            }
            else{
                ant-> sig = aux->sig;
            }
            free(aux);
        }
    }
}

