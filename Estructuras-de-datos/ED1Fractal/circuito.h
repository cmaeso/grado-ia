//
// Created by c.maeso.2017 on 07/06/2024.
//
#include "complejos.h"
#ifndef ED1FRACTAL_CIRCUITO_H
#define ED1FRACTAL_CIRCUITO_H
tComplejo ImpedanciaR(float R);
tComplejo ImpedanciaL(float L, float w);
tComplejo ImpedanciaC(float C, float w);
tComplejo ImpedanciaTotal(tComplejo ZR, tComplejo ZL, tComplejo ZC);
float FrecuenciaAngular(float f);
tComplejo Intensidad(tComplejo V, tComplejo Z);
tComplejo CaidaPotencial(tComplejo I, tComplejo Z);

#endif //ED1FRACTAL_CIRCUITO_H
