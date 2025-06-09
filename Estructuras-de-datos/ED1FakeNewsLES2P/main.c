#include <stdio.h>
#include "fakenews.h"
#include "listaEnlazadaPunteroPrinyFin.h"
#include "stdlib.h"


int main(){
    tLista lista;
    crearVacia(&lista);

    int opcion=0;
    int aux=0;

    do{
            if (aux!=0){
                printf("Valor introducido erróneo. Por favor, introduce un valor válido del 1 al 4.\n");
            }
            printf("\n ¿Qué desea hacer?\n"
                   " 1) Añadir noticia \n"
                   " 2) Mostrar noticias\n"
                   " 3) Eliminar noticia \n"
                   " 4) Calcular número de lectores totales.\n"
                   " 5) Cerrar programa. \n"
                   "\n Introduzca el número:");

            scanf("%i", &opcion);
            aux++;

            if (opcion==1){
                tNoticia noticia;
                crearNoticia(&noticia);
                insertarPrincipio(&lista,noticia);
                opcion=0;
                aux=0;
            }
            else if (opcion==2){
                mostrarLista(&lista);
                opcion=0;
                aux=0;
            }
            else if (opcion==3){
                mostrarLista(&lista);
                printf("¿Qué noticia quieres borrar?\n");
                tNoticia noticiaCopia;
                crearNoticia(&noticiaCopia);
                eliminarElemento(&lista,noticiaCopia);
                opcion=0;
                aux=0;

            }
            else if (opcion==4)
                {
                int visionados;
                visionados=visionadosTotales(&lista);

                    printf("El número de visionados totales es de %i", visionados);
                }
            else if (opcion==5){
                printf("Cerrando programa...\n");
            }
        } while (opcion>5 || opcion<1);

}


