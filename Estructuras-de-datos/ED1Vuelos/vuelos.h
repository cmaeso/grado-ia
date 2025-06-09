//
// Created by c.maeso.2017 on 13/06/2024.
//

#ifndef ED1VUELOS2_VUELOS_H
#define ED1VUELOS2_VUELOS_H
#ifndef ED1VUELOS_VUELOS_H
#define ED1VUELOS_VUELOS_H
typedef struct vuelo{
    char origen[20];
    char dest[20];
    char compania[20];
    int tiempo;
    int precio;
}tElemento ;


void asignarVuelo (tElemento *dest, tElemento origen);
void asignarOrigen(char *dest, tElemento origen);

#endif //ED1VUELOS_VUELOS_H

#endif //ED1VUELOS2_VUELOS_H
