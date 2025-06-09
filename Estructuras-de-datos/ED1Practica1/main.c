#include <stdio.h>
#include "stdlib.h"
// Práctica 1: Memoria


void subprogramaArray(int arr[], int num);
void subprogramaPuntero(int *ptr, int num);

void subprogramaArray(int arr[], int num) {
    if (num <= 0) {
        return;
    }

    int nuevoArray[20000]; // Crear un nuevo array en el stack
    for (int i = 0; i < 20000; i++) {
        nuevoArray[i] = arr[i]; // Copiar los valores del array original
    }

    printf("subprogramaArray: llamada recursiva %d\n", num);
    subprogramaArray(nuevoArray, num - 1);
}

void subprogramaPuntero(int *ptr, int num) {
    if (num <= 0) {
        return;
    }

    int *nuevoPtr = (int *)malloc(20000 * sizeof(int)); // Reservar memoria en el heap
    if (nuevoPtr == NULL) {
        printf("No se pudo asignar memoria\n");
        return;
    }

    for (int i = 0; i < 20000; i++) {
        nuevoPtr[i] = i; // Inicializar el array con valores
    }

    printf("subprogramaPuntero: llamada recursiva %d\n", num);
    subprogramaPuntero(nuevoPtr, num - 1);

    //free(nuevoPtr); // Liberar memoria antes de salir de la función
}




int main() {
    int numLlamadas = 6000

            ; // Ajusta este número según lo necesites para probar los límites
    int array[20000];

    //printf("Llamando a subprogramaArray...\n");
    //subprogramaArray(array, numLlamadas);

    printf("Llamando a subprogramaPuntero...\n");
    subprogramaPuntero(NULL, numLlamadas);
    return 0;
}

