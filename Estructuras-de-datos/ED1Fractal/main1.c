//
// Created by c.maeso.2017 on 07/06/2024.
//
#include <stdio.h>
#include "complejos.h"
#include "circuito.h"
int main2() {
    // Valores de ejemplo
    float V0 = 220.0;  // Voltaje de la fuente
    float f = 50.0;    // Frecuencia en Hz
    float C = 1.2e-6;  // Capacitancia en Faradios
    float L = 3e-3;    // Inductancia en Henrios
    float R = 5000.0;  // Resistencia en Ohmios

    // Cálculo de frecuencia angular
    float w = FrecuenciaAngular(f);

    // Creación de números complejos para las impedancias
    tComplejo ZR = ImpedanciaR(R);
    tComplejo ZL = ImpedanciaL(L, w);
    tComplejo ZC = ImpedanciaC(C, w);

    // Cálculo de la impedancia total
    tComplejo ZT = ImpedanciaTotal(ZR, ZL, ZC);

    // Creación del número complejo para el voltaje
    tComplejo V = CrearComplejo(V0, 0);

    // Cálculo de la intensidad
    tComplejo I = Intensidad(V, ZT);

    // Cálculo de las caídas de potencial
    tComplejo VR = CaidaPotencial(I, ZR);
    tComplejo VL = CaidaPotencial(I, ZL);
    tComplejo VC = CaidaPotencial(I, ZC);

    // Impresión de resultados
    printf("Caida de potencial en R: %.2f + %.2fj\n", VR.real, VR.imaginaria);
    printf("Caida de potencial en L: %.2f + %.2fj\n", VL.real, VL.imaginaria);
    printf("Caida de potencial en C: %.2f + %.2fj\n", VC.real, VC.imaginaria);

    return 0;
}
