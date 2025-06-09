#include <stdio.h>
#include "string.h"
#include "arboles.h"
#include "dioses.h"

int main() {

    tElemento cronos = {"Cronos", "Dios del tiempo"};
    tElemento zeus = {"Zeus", "Dios supremo, líder de los 12 dioses olímpicos"};
    tElemento hera = {"Hera", "Diosa del matrimonio, las mujeres, el cielo y las estrellas"};
    tElemento ares = {"Ares", "Dios de la guerra, de la brutalidad y los horrores de las batallas"};
    tElemento hefeso = {"Hefeso", "Dios de la forja y del fuego, de los herreros, de los artesanos y los escultores"};
    tElemento poseidon = {"Poseidón", "Dios de los mares y de los terremotos"};
    tElemento atenea = {"Atenea", "Diosa de la civilización, la sabiduría, la razón, la inteligencia y la estrategia de combate"};
    tElemento pegaso = {"Pegaso", "Caballo alado, portador del rayo y del trueno"};
    tElemento dedalo = {"Dédalo", "Brillante inventor, técnico y arquitecto"};
    tElemento teseo = {"Teseo", "Fundador de Atenas"};

    tArbol vacio, arbol1, arbol2, arbol3, arbol4;
    crearArbolVacio(&arbol1);  crearArbolVacio(&arbol2);  crearArbolVacio(&vacio);
    crearArbolVacio(&arbol3);   crearArbolVacio(&arbol4);

    int n= esArbolVacio(arbol1);
    printf("%i",n);
    construirArbol(&arbol1, vacio,vacio, dedalo);
    construirArbol(&arbol2, arbol1, vacio,atenea);

    construirArbol(&arbol3, vacio, vacio, pegaso);
    construirArbol(&arbol4, vacio, vacio, teseo);

    construirArbol(&arbol1, arbol3, arbol4, poseidon);

    construirArbol(&arbol3, arbol2, arbol1, zeus);

    construirArbol(&arbol1, vacio, vacio, hefeso);
    construirArbol(&arbol2, vacio, vacio, ares);
    construirArbol(&arbol4, arbol1, arbol2, hera);

    construirArbol(&arbol1, arbol3, arbol4, cronos);
    int p= esProgenitor(arbol1, atenea, dedalo );
    printf("%i", p);
    imprimirPreOrden(arbol1);


}

