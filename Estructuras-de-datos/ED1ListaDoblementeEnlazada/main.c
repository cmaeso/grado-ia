#include <stdio.h>
#include "listaDoblementeEnlazada.h"


int main() {
    tListaDE lista1;

    crearVacia(&lista1);

    for (int i = 1; i < 5; ++i) {
        insertar(&lista1, i);
    }

    mostrarLista(&lista1);

    tListaDE lista2;

    crearVacia(&lista2);

    for (int i = 0; i < 4; ++i) {
        insertar(&lista2, i);
    }

    mostrarLista(&lista2);


}