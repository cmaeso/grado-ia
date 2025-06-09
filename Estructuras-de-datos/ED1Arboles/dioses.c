//
// Created by c.maeso.2017 on 20/11/2023.
//
#include "arboles.h"
#include "string.h"
//

void asignarElemento(tElemento * destino, tElemento origen){
    strcpy(destino->nombre,origen.nombre);
    strcpy(destino->descripcion, origen.descripcion);
}

