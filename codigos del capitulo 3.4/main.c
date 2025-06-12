#include <stdio.h>
#include <math.h>
/* Suma cuadrados.
El progrma, recibir como datos un datos de enteros ositivos, obtenidos el
cuadrado de los mismos y la suma correspondiente al dicho cuadrados.*/
void main (void)
{


int NUM ;
long CUA, SUC = 0;
printf("\n Ingrese un numero entero -0 para terminar -:\t");
scanf("%d", &NUM);
while (NUM)
    /*Obseva que la condicion es verdadera mientras el entero es diferente a cero.*/
{
    CUA = pow (NUM,2);
    printf ("%d al cubo es %ld", NUM, CUA);
    SUC = SUC + CUA;
    printf(" \nIngrese un numero entero -0 par");
    scanf("%d", & NUM);
}
printf("\n La suma de los cuadros es %ld", SUC);
}
