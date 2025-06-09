#include <stdio.h>
#include "pilas.h"
#include "videojuegos.h"
#include "listaES2P.h"


int main() {
    int opcion=0;
    int aux=0;
    tLista lista;
    crearVacia(&lista);

    do {
        if (aux != 0) {
            printf("Valor introducido erróneo. Por favor, introduce un valor válido del 1 al 2.\n");
        }
        printf("\n ¿Qué desea hacer?\n"
               " 1) Añadir videojuego \n"
               " 2) Mostrar ofertas gratuitas\n"
               " 3) Cerrar programa\n\n"
               " Introduzca una opción:");

        scanf("%i", &opcion);
        aux++;

        if (opcion==1) {
            tElemento elemento;
            crearElemento(&elemento);
            insertarFinal(&lista, elemento);
            opcion=0;
            aux=0;
        }

        else if (opcion==2){
            tPila pila;
            crearPilaVacia(&pila);
            tNodo* nodoAux= lista.p;

            while (nodoAux!=NULL){
                push(&pila,nodoAux->elem);
                nodoAux=nodoAux->sig;
            }

            tNodoP * nodoAux2= pila;
            while (nodoAux2!=NULL){
                tElemento elem;
                cima(&pila,&elem);
                mostrarElemento(&elem);
                nodoAux2=nodoAux2->sig;
                pop(&pila);
            }

            opcion=0;
            aux=0;
        }

        else if (opcion==3){
            printf("Cerrando programa... \n");


        }

    }while (opcion<1 || opcion>3);

}

