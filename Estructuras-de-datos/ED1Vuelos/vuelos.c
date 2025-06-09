//
// Created by c.maeso.2017 on 13/06/2024.
//
//
#include "vuelos.h"
#include "string.h"

void asignarVuelo(tElemento *dest, tElemento origen) {
    strcpy(dest->origen, origen.origen);
    strcpy(dest->dest, origen.dest);
    strcpy(dest->compania, origen.compania);
    dest->tiempo = origen.tiempo;
    dest->precio = origen.precio;
}
void asignarOrigen(char *dest, tElemento origen){
    strcpy(dest, origen.origen);
}
