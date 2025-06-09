//
// Created by c.maeso.2017 on 20/11/2023.
//

#ifndef ED1ARBOLES_DIOSES_H
#define ED1ARBOLES_DIOSES_H

typedef struct {
    char nombre[50];
    char descripcion[200];
}tElemento;

void crearElemento(char nombre[50],char descripcion[200], tElemento elem);

#endif //ED1ARBOLES_DIOSES_H
