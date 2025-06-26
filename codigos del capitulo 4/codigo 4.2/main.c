#include <stdio.h>
/* Cubo-2.
El programa calcula el cubo de los 10 primeros números naturales con la
ayuda de una función. */
int cubo(void); /* Prototipo de función. */
int I; /* Variable global. */

int main(void) // Corregido de void main a int main
{
    int CUB;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo(); /* Llamada a la función cubo. */
        printf("\nEl cubo de %d es: %d", I, CUB); // Corregidas las comillas
    }
    return 0; // Agregado para función int main
}
int cubo(void) /* Declaración de la función. */
/* La función calcula el cubo de la variable local I. */
{
    int I = 2; /* Variable local entera I con el mismo nombre
                que la variable global. */
    return (I *   I * I);
}
