#include <stdio.h>
#include "tweets.h"
#include "stdlib.h"

int main() {
    tArbol arbol;
    crearArbolVacio(&arbol);
    char linea[141];

    FILE *fichero = fopen("hashtags.txt", "r");
    if (fichero == NULL) {
        printf("Error de apertura");
    } else {
        while (!feof(fichero)) {
            fscanf(fichero, "%s", linea);
            insertarNodo(&arbol, linea);
        }
    }

    FILE *f_tweets = fopen("tweets.txt", "r");
    if (f_tweets == NULL) {
        printf("Error de apertura");
    } else {
        while (!feof(f_tweets)) {
            fscanf(f_tweets, "%s", linea);
            for (int i = 0; i < linea; ++i) {

            }
            //¿Cómo hago para aquí ir buscando hastaghts?
    }
}
