//
// Created by c.maeso.2017 on 03/11/2023.
//

#ifndef ED1HOSPITAL_HOSPITAL_H
#define ED1HOSPITAL_HOSPITAL_H

typedef struct paciente{
    char nombre[20];
    int prioridad;
} tPaciente;

typedef tPaciente tElemento;

typedef struct nodo{
    tElemento paciente;
    struct nodo* sig;
    struct nodo* ant;
} tNodo;

typedef int tPrioridad;

typedef struct hospital{
    tNodo * p;
    tNodo * f;
}tHospital;


void asignarElemento (tNodo* dest, tElemento orig);
void crearColaVacia(tHospital *hospital);
void insertarPaciente (tHospital *hospital, tElemento elem );
void eliminarPrimero (tHospital *hospital);
tNodo* consultarPrimero (tHospital *hospital);
void crearPaciente(tPaciente* paciente);
void mostrarHospital (tHospital *hospital);
#endif //ED1HOSPITAL_HOSPITAL_H
