#include <stdio.h>
#include <stdlib.h>
//Lista enlazada simple

typedef struct Nodo{
    int info;
    struct Nodo*sig; //puntero al siguiente nodo
} tNodo;

typedef struct Elemento {
    int elemento;
} tElemento;

typedef tNodo *tLista;
tLista lista;


void crearVacia(tLista* lista) {
    *lista=NULL;
}

void asignarElemento (tElemento* dest, tElemento origen){

}


void construir(tLista* lista, tElemento elem){
    tNodo* nodo=(tNodo*) malloc(1*sizeof(tNodo));
   // nodo->info=elem nop. no se sabe q es
    asignarElemento(nodo->info, elem)
    nodo->sig= lista;
    lista=nodo;

}
int main() {
    return 0;
}
