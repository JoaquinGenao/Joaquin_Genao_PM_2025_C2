#include <stdio.h>
/* Promedio curso.
universitario, escribe aprobrado si su promedio es mayor o igual a 6, o
reprobado en caso contrario.
PRO: variable de tipo real. */
void main (void)
{
    float PRO;
    printf("Ingrese el promedio del alumno:");
    scanf("%f", &PRO);
    if (PRO >= 6.0)
    printf("n\Aprobado");
    else
        printf("\nReprobado");


}
