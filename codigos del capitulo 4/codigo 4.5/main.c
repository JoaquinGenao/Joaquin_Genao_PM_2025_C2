#include <stdio.h>
/* Cubo-3.
El programa calcula el cubo de los 10 primeros n�meros naturales con la
ayuda de una funci�n y utilizando par�metros por valor.
*/

int cubo(int); /* Prototipo de funci�n. El par�metro es de tipo entero. */

int main(void) // Corregido de void main a int main
{
    int I;
    for (I = 1; I <= 10; I++)
        printf("\nEl cubo de I es: %d", cubo(I));
    return 0; // A�adido para funci�n main
}

int cubo(int K) /* K es un par�metro por valor de tipo entero. */
/* La funci�n calcula el cubo del par�metro K. */
{
    return (K * K * K);
}
