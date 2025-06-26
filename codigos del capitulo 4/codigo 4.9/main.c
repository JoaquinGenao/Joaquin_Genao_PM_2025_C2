#include <stdio.h>
/* Paso de una funci�n como par�metro por referencia. */

    int Suma(int X, int Y)
    /* La funci�n Suma regresa la suma de los par�metros de tipo entero X y Y. */
{
           return (X + Y);
}

int Resta(int X, int Y)
/* Esta funci�n regresa la resta de los par�metros de tipo entero X y Y. */
{
    return (X - Y);
}

   int Control(int (*apf)(int, int), int X, int Y)
/* Esta funci�n recibe como par�metro un apuntador a funci�n. */
{
         int RES;
      RES = (*apf)(X, Y); // Llama a Suma o Resta dependiendo del par�metro
    return (RES);
}

int main(void) // Corregido de void main a int main
{
  int R1, R2;
      R1 = Control(Suma, 15, 5);   // Llama a Suma(15, 5)
      R2 = Control(Resta, 10, 4);  // Llama a Resta(10, 4)

    printf("\nResultado 1: %d", R1);
    printf("\nResultado 2: %d", R2);

    return 0;
}
