//
// Created by c.maeso.2017 on 19/10/2023.
//

#ifndef ED1FAKENEWS_FAKENEWS_H
#define ED1FAKENEWS_FAKENEWS_H
#define MAX 100
// NOOO #include "listaEnlazadaSimple.h"



typedef struct {
    int dia;
    int mes;
    int anyo;
} tFecha;

typedef struct {
    char titulo[MAX];
    tFecha fecha;
    char medio[MAX];
    int visionados;
} tNoticia;

typedef tNoticia tElemento;

void asignarElemento (tNoticia* dest, tNoticia origen);

// NOO typedef tNodo* tLista;


int igualElemento(tNoticia n1, tNoticia n2);
void crearNoticia(tNoticia* destino);
void mostrarElemento(tElemento *noticia);
struct Nodo;
int visionadosTotales(struct Nodo * lista);


#endif //ED1FAKENEWS_FAKENEWS_H
