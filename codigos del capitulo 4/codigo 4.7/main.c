#include <stdio.h>

/* Prueba de par�metros por valor. */
int f1(int); /* Prototipo de funci�n. El par�metro es por valor y de tipo entero. */

int main(void) // Corregido de void main a int main
{
    int I, K = 4;

    // El resultado que arroja el programa es el siguiente:
    // (Este comentario estaba mal ubicado en el c�digo original)

    for (I = 1; I <= 3; I++)
    {
        printf("\n\nValor de K antes de llamar a la funci�n: %d", ++K);
        printf("\nValor de K despu�s de llamar a la funci�n: %d", f1(K));
        /* Llamada a la funci�n f1. Se pasa una copia de la variable K. */
    }
    return 0;
}

       int f1(int R)
{
           R += R;
          return R;
}
