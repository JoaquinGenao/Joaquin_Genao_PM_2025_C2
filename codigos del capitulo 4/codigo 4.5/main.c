#include <stdio.h>
/* Cubo-3.
El programa calcula el cubo de los 10 primeros números naturales con la
ayuda de una función y utilizando parámetros por valor.
*/

int cubo(int); /* Prototipo de función. El parámetro es de tipo entero. */

int main(void) // Corregido de void main a int main
{
    int I;
    for (I = 1; I <= 10; I++)
        printf("\nEl cubo de I es: %d", cubo(I));
    return 0; // Añadido para función main
}

int cubo(int K) /* K es un parámetro por valor de tipo entero. */
/* La función calcula el cubo del parámetro K. */
{
    return (K * K * K);
}
