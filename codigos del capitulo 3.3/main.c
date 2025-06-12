#include <stdio.h>
/*Suma pagos.
El programa. al recibir como datos un conjunto de pagos realiado en el ultimo
mmes, obtiene la suma de los mismos.

PAG y SPA: variables de tipo real. */
void main (void)
{
    float PAG, SPA;
    SPA= 0;
    printf("Ingrese e primer pago:\t");
    scanf("%f", &PAG);
    while (PAG)
        /* Observa que la condicion es verdadera mientras el pago es diferente de cero.*/
    {
        SPA= SPA + PAG;
        printf("Ingrese el siguiente pago: \t");
        scanf("%f", &PAG);
        while (PAG)
            /*oBSERVA QUE ;A CONDICION ES VERDADERA MIENTRAS EL PAGO ES DIFERENTE DE CERO.*/

  {
      SPA = SPA + PAG;
      printf("Ingrese el siguiente pago:\t");
      scanf("%f", &PAG);
      /*Observa que la proposicion que modifica la condicion es una lectura.*/
  }
  printf("\nEL total de pagos del mes es : %.2f",SPA);
  }


}

