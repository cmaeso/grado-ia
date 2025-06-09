//
// Created by c.maeso.2017 on 10/06/2024.
//
//

//
#include "videojuegos.h"
#include "string.h"
#include "stdio.h"

void asignarElemento(tElemento * destino, tElemento origen){
    strcpy(destino->titulo,origen.titulo);
    strcpy(destino->genero, origen.genero);
    destino->precio= origen.precio;
    destino->puntuacion= origen.puntuacion;
}


void mostrarElemento(tElemento* elemento) {
    if (elemento->precio == 0.0){
        printf("Título: %s; género:%s;  puntuación: %i, precio %f\n", elemento->titulo,elemento->genero,elemento->puntuacion,elemento->precio);
    }
}

void crearElemento(tElemento *elemento){
    printf("Dime el título del videojuego:");
    fflush(stdin);
    fgets(elemento->titulo, sizeof (elemento->titulo), stdin);
    elemento->titulo[strcspn(elemento->titulo, "\n")]='\0';

    printf("Dime el género del videojuego: ");
    fflush(stdin);
    fgets(elemento->genero, sizeof (elemento->genero), stdin);
    elemento->genero[strcspn(elemento->genero, "\n")]='\0';

    printf("Dime la puntuación del videojuego del 1 al 10:");
    scanf("%i",&elemento->puntuacion);

    printf("Dime el precio del videojuego:");
    scanf("%f", &elemento->precio);
}

