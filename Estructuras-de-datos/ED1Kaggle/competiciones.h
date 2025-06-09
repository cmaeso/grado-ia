//
// Created by c.maeso.2017 on 12/06/2024.
//

#ifndef ED1KAGGLE_COMPETICIONES_H
#define ED1KAGGLE_COMPETICIONES_H

#include "string.h"
#include "stdio.h"

typedef struct {
    char nombre[20];
    int premio;
} tElemento;

int igualElemento (tElemento e1, tElemento e2);
void mostrarElemento(tElemento e);
void crearElemento(tElemento *e);
void asignarElemento(tElemento* dest, tElemento origen);
#endif //ED1KAGGLE_COMPETICIONES_H
