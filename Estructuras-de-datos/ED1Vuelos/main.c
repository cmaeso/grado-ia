#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelos.h"
#include "grafos.h"

int main() {
    tGrafo g;
    crearGrafoVacio(&g);
    char linea[100];
    int num_lineas = 0;
    FILE *fichero = fopen("R:/Desktop/ED1Vuelos/vuelos.txt", "r");
    if (fichero == NULL) {
        printf("Error de apertura\n");
        return 1; // Salir con un código de error
    }

    tElemento vuelo;

    while (fgets(linea, sizeof(linea), fichero) != NULL) {
        linea[strcspn(linea, "\n")] = 0; // Eliminar el salto de línea
        switch (num_lineas % 5) {
            case 0:
                strcpy(vuelo.origen, linea);
                break;
            case 1:
                strcpy(vuelo.dest, linea);
                break;
            case 2:
                strcpy(vuelo.compania, linea);
                break;
            case 3:
                vuelo.tiempo = atoi(linea);
                break;
            case 4:
                vuelo.precio = atoi(linea);

                // Insertar ciudades si no están ya en el grafo
                if (!perteneceOrigen(g, vuelo.origen)) {
                    insertarVertice(&g, vuelo.origen);
                }
                if (!perteneceOrigen(g, vuelo.dest)) {
                    insertarVertice(&g, vuelo.dest);
                }

                // Insertar destino en la ciudad de origen si no existe
                insertarDestino(g, vuelo);

                // Insertar el vuelo en el grafo
                insertarVuelo(&g, vuelo);

                break;
        }
        num_lineas++;
    }

    fclose(fichero);

    // Mostrar los vertices y sus vuelos
//mostrarVertices(g);

    // Ejemplo de uso de mostrarDestinos
    mostrarDestinos(g, "Roma");

    return 0;
}
