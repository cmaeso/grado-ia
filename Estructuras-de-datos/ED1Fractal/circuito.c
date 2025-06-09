//
// Created by c.maeso.2017 on 07/06/2024.
//
#include "circuito.h"
#include "complejos.h"
#include "math.h"

tComplejo ImpedanciaR(float R){
    return CrearComplejo(R, 0);
}
tComplejo ImpedanciaL(float L, float w){
    return CrearComplejo(0, L*w);
}
tComplejo ImpedanciaC(float C, float w){
    return CrearComplejo(0, -1/(C*w));
}
tComplejo ImpedanciaTotal(tComplejo ZR, tComplejo ZL, tComplejo ZC){
    tComplejo Z1= Sumar(ZR, ZL);
    return Sumar(Z1,ZC);
}
float FrecuenciaAngular(float v){
    return 2* M_PI *v;
}

tComplejo Intensidad(tComplejo V, tComplejo Z) {
    tComplejo I;
    I= Cociente(V,Z);
    return I;
}

tComplejo CaidaPotencial(tComplejo I, tComplejo Z) {
    return Multiplicar(I, Z);
}

