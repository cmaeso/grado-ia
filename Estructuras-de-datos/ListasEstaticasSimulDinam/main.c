#include <stdio.h>
#define MAX 100

typedef struct {
    int info;
    int sig;
} tNodo;


typedef struct {
    tNodo almacen[100];
    int primOcupada;
    int primLibre;
} tLista;


void construir(tLista* lista, int e) {

    (lista-> almacen[lista->primLibre].info)=e;
    int aux= lista->almacen[lista->primLibre].sig;
    lista->almacen[lista->primLibre].sig= lista->primOcupada;
    lista->primOcupada= lista->primLibre;
    lista->primLibre;
}

void crearListaVacia(tLista * lista){
    lista->primLibre=0;
    lista->primOcupada=-1;

    for (int i = 0; i < (MAX-1);  i++){
        tNodo nodo;
        lista->almacen[i].sig= i+1;
    }

    lista->almacen[MAX-1].sig= 100+1;
}


void imprimirLista(tLista lista){
    int pos= lista.primOcupada;
    while (pos !=-1){
        //NO HACER PRINTF hehe
        mostrarElemento(lista.almacen[pos].info);
        pos=lista.almacen[pos].sig;
    }
}


 void main() {
    tLista  lista;
    int e; //tElemento



    return 0;
}
