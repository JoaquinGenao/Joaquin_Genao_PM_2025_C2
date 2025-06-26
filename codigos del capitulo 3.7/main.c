#include <stdio.h>
/* Lanamiento de martillo.
El progrma, al recibir como datos N lanamientos de martillo, calcula el promedio
de los lansamientos de la atleta cubana.

I, N: variables de tipo entero.
LAN, SLA: variables de tipo real.*/
void main (void)
{
    int I,N;
    float LAN , SLA= 0;
    do
    {
        printf("Ingrese el numero de lanamientos :\t");
        scanf("%d", &N);

    }
    while (N<1||N>11);
    /* se utilisa la estructura do- while para verificar que el valor de
    n sea correcto. */
    for (I = 1; I<=N;I++)
    {
        printf("\nIngrese el lansamiento %d:", I);
        scanf("%f", &LAN );
        SLA = SLA + LAN ;

    }
SLA = SLA / N ;
printf("\nEl promedio de lanamiento es : %.2f", SLA);

}
