#include <stdio.h>
/* Nomina .
El programa, al recibir los salarios de 15 profesones, obtiene el total de la nomina de la universidad.
I: variable de tipo entero.
SAL y NOM: variable de tipo rela. */
void main (void)
{
    int I ;
    float SAL, NOM ;
    NOM=0;
    for (I=1; I<=15; I++)
    {
        printf("\ Ingrese el salario del profesor%d:\t",I);
        scanf("%f",&SAL);
        NOM= NOM + SAL;

    }
    printf("\nEl total de la nomina es: %.2f", NOM);
}
