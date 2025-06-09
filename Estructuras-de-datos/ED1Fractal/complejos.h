//
// Created by c.maeso.2017 on 05/10/2023.
//

#ifndef ED1PCOMPLEJOS_COMPLEJOS_H
#define ED1PCOMPLEJOS_COMPLEJOS_H

typedef struct {
    float real;
    float imaginaria;
} tComplejo;

tComplejo CrearComplejo(float r, float i);
float ObtenerReal(tComplejo complejo);
float ObtenerImaginaria(tComplejo complejo);
float CalcularModulo(tComplejo complejo);
tComplejo Sumar (tComplejo c1, tComplejo c2);
tComplejo Restar (tComplejo c1, tComplejo c2);
tComplejo Multiplicar (tComplejo c1, tComplejo c2);

tComplejo Cociente (tComplejo c1, tComplejo c2);


#endif //ED1PCOMPLEJOS_COMPLEJOS_H
