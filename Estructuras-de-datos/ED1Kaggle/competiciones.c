//
// Created by c.maeso.2017 on 12/06/2024.
//
#include "competiciones.h"

int igualElemento (tElemento e1, tElemento e2){
    //(strcmp(e1.nombre, e2.nombre)==0) &&
    return e1.premio==e2.premio;
};

void crearElemento(tElemento *e){
    printf("Dime el nombre:");
    fflush(stdin);
    fgets(e->nombre,sizeof(e->nombre),stdin);
    e->nombre[strcspn(e->nombre,"\n")]='\0';

    printf("Dime el premio:");
    scanf("%i", &e->premio);
}

void asignarElemento(tElemento * dest, tElemento orig){
    (*dest)=orig;
}


void mostrarElemento(tElemento e){
    printf("%s ; %i; \n", e.nombre,e.premio);
}

