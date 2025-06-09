//
// Created by c.maeso.2017 on 19/10/2023.
//
#include "fakenews.h"
#include "stdlib.h"
#include "stdio.h"
#include "listaEnlazadaPunteroPrinyFin.h"
#include "string.h"


// Crear asignar elemento

void asignarElemento (tNoticia* dest, tNoticia origen){
    strcpy(dest->titulo, origen.titulo);
    dest->fecha= origen.fecha;
    strcpy(dest->medio, origen.medio);
    dest->visionados= origen.visionados;
}

int igualElemento(tNoticia n1, tNoticia n2){
    if ((strcmp(n1.titulo, n2.titulo)==0) && (strcmp(n1.medio, n2.medio)==0)  && (n1.fecha.dia==n2.fecha.dia) && (n1.fecha.mes==n2.fecha.mes) && (n1.fecha.anyo==n2.fecha.anyo)){ //ignoramos los visionados ya que si inicializan a 0.
        return 1;
    }
    else {
        return 0;
    }
}


void crearNoticia(tNoticia* destino){

    printf("Dime el título de la noticia:");
    fflush(stdin);
    fgets(destino->titulo, sizeof (destino->titulo), stdin);
    destino->titulo[strcspn(destino->titulo, "\n")]='\0';


    printf("Dime el día de la fecha:");
    scanf("%i",&destino->fecha.dia);

    printf("Dime el mes de la fecha:");
    scanf("%i",&destino->fecha.mes);

    printf("Dime el año de la fecha:");
    scanf("%i",&destino->fecha.anyo);

    printf("Dime el medio de la noticia:");
    fflush(stdin);
    fgets(destino->medio, sizeof (destino->medio), stdin);
    destino->medio[strcspn(destino->medio, "\n")]='\0';
    //fgets(destino->medio,sizeof (destino->medio),stdin);

    destino->visionados=0;


}


void mostrarElemento(tElemento *noticia){
    printf("Título: %s; fecha: %i/%i/%i; medio: %s; visionados: %i \n \n", noticia->titulo,noticia->fecha.dia,noticia->fecha.mes,noticia->fecha.anyo, noticia->medio, noticia->visionados);
    noticia->visionados++;
}

int visionadosTotales(tLista * lista){
    int vis=0;
    if (lista==NULL){
        printf("No hay noticias.");
        vis=0;
    }
    else {
        tNodo *aux= lista->p;
        while (aux->sig!=NULL){
            vis+=aux->elem.visionados;
            aux= aux->sig;
        }
        vis+=aux->elem.visionados;
    }
    return vis;

}

