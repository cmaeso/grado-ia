#include <stdio.h>
#include "competiciones.h"
#include "arbolBinBus.h"

int main() {

        tArbol arbol;
        crearArbolVacio(&arbol);

        int opcion = 0;
        int aux = 0;

        do {
            if (aux != 0) {
                printf("Valor introducido erróneo. Por favor, introduce un valor válido del 1 al 4.\n");
            }
            printf("\n ¿Qué desea hacer?\n"
                   " 1) Añadir competicion \n"
                   " 2) Mostrar competiciones en orden ascendente \n"
                   " 3) Competición premio mas bajo \n"
                   " 4) Eliminar competición dado premio \n"
                   " 5) Comprobar si el árbol es AVL \n"
                   " 6) Cerrar programa. \n"
                   "\n Introduzca el número:");

            scanf("%i", &opcion);
            aux++;

            if (opcion == 1) {
                tElemento e;
                crearElemento(&e);
                insertarABB(e,&arbol);
                opcion = 0;
                aux = 0;
            } else if (opcion == 2) {
                imprimirInOrder(arbol);
                opcion = 0;
                aux = 0;
            } else if (opcion == 3) {
                mostrarElemento(minimo(arbol));
                opcion = 0;
                aux = 0;

            } else if (opcion == 4) {
                tElemento e2;
                crearElemento(&e2);
                eliminarABB(&arbol, e2);
                opcion = 0;
                aux = 0;
            } else if (opcion==5){
                int avl= esAVL(arbol);
                if (avl){
                    printf("El árbol es AVL.\n");
                } else {
                    printf("No es AVL.\n");
                }
                opcion = 0;
                aux = 0;
            } else if (opcion==6){
                return 0;
            }
        } while (opcion > 5 || opcion < 1);
    return 0;

}
