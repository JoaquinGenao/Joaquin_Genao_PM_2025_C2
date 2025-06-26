#include <stdio.h>
/* Nomina de profesores.
El progrma \, al recibir como datos de salarios de los profesores de una
universidad, obtiene la nomina y el promedio de los salarios.

I: variable de tipo entero.
SAL, NOM,y PRO: variable de tipo real.*/
void main(void)
{
    int I= 0;
    float SAL, PRO, NOM = 0;
    printf("Ingrese el salario del profesor:\t");
    /*observa que el menos se necesita ingresar el salario de un profesor para que
    no ocurra un error de ojecucion del progrma. */
    scanf("%f", &SAL);
    do
    {
        NOM = NOM + SAL ;
        I=I+1;
        printf("Ingrese el saliro del profesor 0 para terminar : \t");
        scanf("%f", &SAL);


    }
while (SAL);
    PRO = NOM / I ;
printf("\nNomina: %.2f\t Promedio de salarios:%.2f",NOM, PRO);

}
