//
// Created by c.maeso.2017 on 05/10/2023.
//
#include "complejos.h"
#include <math.h>

tComplejo CrearComplejo(float r, float i){
    tComplejo complejo;
    complejo.real=r;
    complejo.imaginaria=i;
    return complejo;
}

float ObtenerReal(tComplejo complejo){
    return complejo.real;
}

float ObtenerImaginaria(tComplejo complejo){
    return complejo.imaginaria;
}

float CalcularModulo(tComplejo complejo){
    return pow((pow(complejo.real,2) + pow(complejo.imaginaria,2)),0.5);
}

tComplejo Sumar(tComplejo c1, tComplejo c2){
    tComplejo suma;
    suma.imaginaria= c1.imaginaria + c2.imaginaria;
    suma.real= c1.real + c2.real;
    return suma;
}

tComplejo Restar(tComplejo c1, tComplejo c2) {
    tComplejo resta;
    resta.imaginaria = c1.imaginaria - c2.imaginaria;
    resta.real = c1.real - c2.real;
    return resta;
}

tComplejo Multiplicar (tComplejo c1, tComplejo c2) {
    tComplejo multiplicacion;
    multiplicacion.imaginaria = c1.real * c2.imaginaria + c1.imaginaria * c2.real;
    multiplicacion.real = c1.real * c2.real - c1.imaginaria * c2.imaginaria;
    return multiplicacion;
}

tComplejo Cociente(tComplejo c1, tComplejo c2) {
    tComplejo div;
    float denom = c2.real * c2.real + c2.imaginaria * c2.imaginaria;
    div.real = (c1.real * c2.real + c1.imaginaria * c2.imaginaria) / denom;
    div.imaginaria = (c1.imaginaria * c2.real - c1.real * c2.imaginaria) / denom;
    return div;
}




