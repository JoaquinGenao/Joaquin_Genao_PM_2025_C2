#include <stdio.h>
/* Inviete datos
El programa,al recibir como datos un conjunto de datos de entrada, invierte el
orden de los mismos cuando los imprime.
A, B, C, y D: variable de tipo entero.*/
void main(void)
{
    int A, B, C, D;
    printf("Ingrese cuatro datos de tipo entero:");
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("\n %d %d %d %d", D, C, B, A);
}
