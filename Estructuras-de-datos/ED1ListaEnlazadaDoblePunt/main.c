#include <stdio.h>
#include "listaEnlazadaPunteroPrinyFin.h"


int main() {
    tLista lista;
    crearVacia(&lista);

    for (int i = 0; i < 3; ++i) {
        insertarFinal(&lista,4);

    }
    insertarPrincipio(&lista,0);
    for (int i = 0; i < 4; ++i) {
        insertarPrincipio(&lista,4);

    }

    mostrarLista(&lista);
    criba(&lista,2);
    mostrarLista(&lista);




    return 0;
}
