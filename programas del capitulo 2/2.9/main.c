#include <stdio.h>
#include <math.h>
/* Exprecion.
El programa. al recibir como datos tres valores entreos, establece si los
mismos satisfacen una exprecion dterminada.
R, T y Q : variables de tipo entero.
RES: variables de tipo real.*/
void main (void)
{
    float  RES;
    int R,T,Q;
    printf("ingrese los valores de R,T, Q:");
    scanf("%d %d %d" , &R, &T, &Q);
    RES = pow (R, 4)- pow (T, 3)+4 * pow (Q, 2);
    if (RES< 820)
        printf("\nR= %dtT = %d\t Q = ", R, T, Q);
}
