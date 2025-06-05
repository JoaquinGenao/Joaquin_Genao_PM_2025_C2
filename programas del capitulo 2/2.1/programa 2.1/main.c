#include <stdio.h>
/*promedio curso.
El progrma, al resibir como dato el promedio de un alumno en un curso
universitario, escribe aprobado si su promedio es mayor o igula a 6
PRO: variable de tipo real.*/
void main (void)
{
    float PRO;
    printf("ingrese el promedio del alumno:");
    scanf("%f", &PRO);
    if (PRO >=6)
    printf("\nAprobado");

}
