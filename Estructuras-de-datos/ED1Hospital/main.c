#include <stdio.h>
#include "hospital.h"

int main() {

        tHospital colaP;
        crearColaVacia(&colaP);

        int opcion = 0;
        int aux = 0;

        do {
            if (aux != 0) {
                printf("Valor introducido erróneo. Por favor, introduce un valor válido del 1 al 4.\n");
            }
            printf("\n ¿Qué desea hacer?\n"
                   " 1) Añadir paciente \n"
                   " 2) Mostrar hospital (pacientes)\n"
                   " 3) Eliminar primero \n"
                   " 4) Cerrar programa. \n"
                   "\n Introduzca el número:");

            scanf("%i", &opcion);
            aux++;

            if (opcion == 1) {
                tElemento paciente;
                crearPaciente(&paciente);
                insertarPaciente(&colaP, paciente);
                opcion = 0;
                aux = 0;
            } else if (opcion == 2) {
                mostrarHospital(&colaP);
                opcion = 0;
                aux = 0;/*
            } else if (opcion == 3) {
                eliminarPrimero(&colaP);
                opcion = 0;
                aux = 0;*/

            } else if (opcion == 3) {
                printf("Cerrando programa...\n");
            }
        } while (opcion > 3 || opcion < 1);

    }
