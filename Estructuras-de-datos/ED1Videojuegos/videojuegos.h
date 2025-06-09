//
// Created by c.maeso.2017 on 02/11/2023.
//

#ifndef ED1VIDEOJUEGOS_VIDEOJUEGOS_H
#define ED1VIDEOJUEGOS_VIDEOJUEGOS_H
#define MAX 100

typedef struct {
    char titulo[MAX];
    char genero[MAX];
    int puntuacion;
    float precio;
} tVideojuego;

typedef tVideojuego tElemento;

void asignarElemento(tElemento * destino, tElemento origen);
void mostrarElemento(tElemento* elemento);
void crearElemento(tElemento *elemento);


#endif //ED1VIDEOJUEGOS_VIDEOJUEGOS_H
