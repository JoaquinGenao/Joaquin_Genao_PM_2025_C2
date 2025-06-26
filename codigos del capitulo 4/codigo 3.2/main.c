#include <stdio.h>
/* Conflicto de variables con el mismo nombre. */
void f1(void); /* Prototipo de función. */
int K = 5; /* Variable global. */

int main(void)
{
    int I;
    for (I = 1; I <= 3; I++)
        f1();
    return 0;
}

void f1(void)
{
    int k_local = 2; // Esta es una variable local a f1
    k_local += k_local; // k_local = 2 + 2 = 4

    printf("\n\nEl valor de la variable local es: %d", k_local);

    K = K + k_local; // Se usa la variable global K
    printf("\nEl valor de la variable global es: %d", K);
}


