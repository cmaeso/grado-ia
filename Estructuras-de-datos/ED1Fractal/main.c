#include <stdio.h>
#include "complejos.h"
#include "Bitmap.h"
#define MAXITER 300

int calcularEscape( tComplejo c){
    int numIts=0;
    tComplejo z= CrearComplejo(0,0);

    for (int i = 0; i < MAXITER; ++i) {
        z = Sumar(Multiplicar(z, z), c);
        numIts++;
        if (CalcularModulo(z) > 2.0) {
            return numIts; //Diverge
        }
    }
    return numIts; // No Diverge

}

int main()  {
    int i, j;
    int ancho = 640;
    int alto = 480;
    Bitmap mandelbrot1 = createBitmap("mandelbrot1.bmp", ancho, alto, 3);
    for(i = 0; i < ancho; i++) {
        for(j = 0; j < alto; j++) {
            float real= ((float)i / 160.0f) - 2.5f;
            float img= ((float)j / 160.0f) - 1.5f;
            tComplejo c= CrearComplejo(real,img);
            int escape= calcularEscape(c);
            int color= (escape*255/  MAXITER);
            putPixel(&mandelbrot1, i, j, color);

        }
    }
    saveBitmap(&mandelbrot1);
    return 0;
}
