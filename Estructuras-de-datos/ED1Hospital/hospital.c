//
// Created by c.maeso.2017 on 03/11/2023.


#include "stdio.h"
#include "hospital.h"
#include "stdlib.h"
#include "string.h"

void crearColaVacia(tHospital *hospital){
    hospital->p=NULL;
    hospital->f=NULL;
}

void asignarElemento(tNodo * dest, tElemento orig){
    dest->paciente=orig;
}
/*
void insertarPaciente (tHospital *hospital, tElemento elem){
    tNodo* nuevoNodo= malloc(sizeof (tNodo));
    asignarElemento(nuevoNodo, elem);
    int insertado=0;

    //Vacia
    if (hospital->p==NULL){
        hospital->p=nuevoNodo;
        hospital->f=nuevoNodo;
        insertado=1;
        //Hay 1 y hay q insertar por cabecera
    } else if (hospital->p == hospital->f && nuevoNodo->paciente.prioridad < hospital->p->paciente.prioridad){
            hospital->p= nuevoNodo;
            nuevoNodo->ant=NULL;
            hospital->f->ant=nuevoNodo;
            nuevoNodo->sig= hospital->f;
            insertado=1;
    } else {
        tNodo *aux= hospital->p;

        while (aux!=NULL && !insertado){
            // Insertar por el medio después del aux
            if (aux->paciente.prioridad == nuevoNodo->paciente.prioridad ||
            (aux->paciente.prioridad > nuevoNodo->paciente.prioridad && nuevoNodo->paciente.prioridad < aux->sig->paciente.prioridad)){
                nuevoNodo->sig= aux->sig;
                aux->sig->ant=nuevoNodo;
                aux->sig=nuevoNodo;
                nuevoNodo->ant= aux;
                insertado=1;
            } else {
                aux=aux->sig;
            }

        }

        if (!insertado){
            aux->sig=nuevoNodo;
            hospital->f= nuevoNodo;
            nuevoNodo->ant=aux;
            nuevoNodo->sig=NULL;
        }
    }
}



 void insertarPaciente (tHospital *hospital, tElemento elem) {
    tNodo *nuevoNodo = malloc(sizeof(tNodo));
    asignarElemento(nuevoNodo, elem);
    int insertado = 0;

    if (hospital->f == NULL) {
        hospital->p = nuevoNodo;
        hospital->f = nuevoNodo;
    } else {
        tNodo *aux = hospital->f;

        while (aux->ant != NULL && !insertado) {
            if (aux->paciente.prioridad > elem.prioridad) {
                aux = aux->ant;
            } else {
                    nuevoNodo->ant = aux;
                    nuevoNodo->sig = aux->sig;

                    if (aux->sig != NULL) {
                        aux->sig->ant = nuevoNodo; //insertas en medio

                    } else { //es el ult
                        hospital->f = nuevoNodo;
                    }
                }
                insertado=1;


        }
        if (aux->ant == NULL) {
            nuevoNodo->sig = hospital->p;
            nuevoNodo->ant = NULL;
            aux->ant = nuevoNodo;
            hospital->p = nuevoNodo;
        }
    }
}



 void insertarPaciente (tHospital *hospital, tElemento elem) {
    tNodo *nuevoNodo = malloc(sizeof(tNodo));
    asignarElemento(nuevoNodo, elem);
    int insertado = 0;

    if (hospital->f == NULL) {
        hospital->p = nuevoNodo;
        hospital->f = nuevoNodo;
    } else {
        tNodo *aux = hospital->f;

        while (aux->ant != NULL && (aux->paciente.prioridad > elem.prioridad)) {
            aux = aux->ant;
        }
        if (aux == NULL) {
            nuevoNodo->sig = hospital->p;
            nuevoNodo->ant = NULL;
            aux->ant = nuevoNodo;
            hospital->p = nuevoNodo;
        } else {
            nuevoNodo->ant = aux;
            nuevoNodo->sig = aux->sig;

            if (aux->sig != NULL) {
                aux->sig->ant = nuevoNodo; //insertas en medio
            } else {
                hospital->f = nuevoNodo;
            }

            aux->sig = nuevoNodo;
        }
    }

 }



void insertarPaciente (tHospital *hospital, tElemento elem) {
    tNodo *nuevoNodo = malloc(sizeof(tNodo));
    asignarElemento(nuevoNodo, elem);
    int insertado = 0;

    if (hospital->f == NULL) {
        hospital->p = nuevoNodo;
        hospital->f = nuevoNodo;
    } else {
        tNodo *aux = hospital->f;

        while (aux->ant != NULL && (aux->paciente.prioridad > elem.prioridad)) {
            aux = aux->ant;
        }
        if (aux->paciente.prioridad <= elem.prioridad) {
            nuevoNodo->sig = aux->sig;
            nuevoNodo->ant = aux;
            if (aux->sig!=NULL){
                aux->sig->ant=nuevoNodo;
            } else {
                hospital->f= nuevoNodo;
            }
        } else {
            nuevoNodo->ant = aux;
            nuevoNodo->sig = aux->sig;

            if (aux->sig != NULL) {
                aux->sig->ant = nuevoNodo; //insertas en medio
            } else {
                hospital->f = nuevoNodo;
            }

            aux->sig = nuevoNodo;
        }
    }

}
*/
void insertarPaciente(tHospital *hospital, tElemento elem) {
    tNodo *nuevoNodo = malloc(sizeof(tNodo));
    asignarElemento(nuevoNodo, elem);
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;

    if (hospital->p == NULL) {
        // Cola vacía, insertar al principio
        hospital->p = nuevoNodo;
        hospital->f = nuevoNodo;
    } else {
        tNodo *aux = hospital->p;

        while (aux != NULL && aux->paciente.prioridad <= elem.prioridad) {
            // Cambiamos la condición a >= para incluir las prioridades iguales
            aux = aux->sig;
        }

        if (aux == NULL) {
            // Insertar al principio
            nuevoNodo->sig=hospital->p;
            hospital->p->ant= nuevoNodo;
            hospital->p=nuevoNodo;
        } else {
            // Insertar en medio o al principio de la cola
            nuevoNodo->sig = aux->sig;
            nuevoNodo->ant = aux;

            if (aux->sig != NULL) {
                aux->sig->ant = nuevoNodo;
            } else {
                hospital->f = nuevoNodo; // Nuevo uñt en la cola
            }

            aux->sig = nuevoNodo;
        }
    }
}




/*
void insertarPaciente (tHospital *hospital, tElemento elem){
    //leemos por cabecera
    tNodo *nuevoNodo= malloc(sizeof(tNodo));
    crearNodo(nuevoNodo, elem);

    if (hospital->p ==NULL ){
        hospital->p=nuevoNodo;
        hospital->f=nuevoNodo;
    } else {

        tNodo*aux= hospital->p;
        int insertado=0;
        while (aux!=NULL && !insertado){
            //1 es la máxima prioridad
            if (elem.prioridad < aux->paciente.prioridad){
                if (aux==hospital->p){
                    hospital->p=nuevoNodo;
                    nuevoNodo->ant=NULL;
                } else {
                    aux->ant->sig= nuevoNodo;
                    nuevoNodo->ant= aux->ant;
                }
                nuevoNodo->sig= aux;
                insertado=1;

            } else {
                aux->ant = nuevoNodo;
                aux= aux->sig;
            }

        }

        if (!insertado){ //es el ult
            nuevoNodo->ant= hospital->f;
            hospital->f->sig=nuevoNodo;
            hospital->f=nuevoNodo;
        }


    }

}*/

void crearPaciente(tPaciente *paciente){
    printf("Dime el nombre:");
    fflush(stdin);
    fgets(paciente->nombre,sizeof(paciente->nombre),stdin);
    paciente->nombre[strcspn(paciente->nombre,"\n")]='\0';

    printf("Dime la prioridad:");
    scanf("%i", &paciente->prioridad);
}

void mostrarPaciente(tPaciente *paciente){
    printf("Nombre paciente: %s ; prioridad: %i \n", paciente->nombre, paciente->prioridad);
}

void mostrarHospital (tHospital *hospital){
    tNodo * aux= hospital->p;

    while (aux!=NULL){
        mostrarPaciente(&aux->paciente);
        aux=aux->sig;
        }
    }



/*

void eliminarPrimero (tHospital *hospital);
tNodo* consultarPrimero (tHospital *hospital);
void crearPaciente(tPaciente paciente);

*/

