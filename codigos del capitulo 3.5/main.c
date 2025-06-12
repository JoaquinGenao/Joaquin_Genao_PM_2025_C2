#include <stdio.h>
#include <stdlib.h>
/*Suma pagos.
El programa obtiene la suma de los pagos realiados el ultimo mes.
PAG y SPA: variables de tipos real.*/
void main(void)
{
    float PAG, SPA= 0;
    printf("Ingrese  el primer pago:\t");
    scanf("%f", &PAG);
    /*Obser que al utiliar la estructura do while al menos se necesita un pago.*/
    do
    {
        SPA= SPA + PAG;
        printf("Ingrese el primer pago:\t");
        scanf ("%f", &PAG);
    {
        SPA = SPA + PAG;
        printf("Ingrese el siguiente pago -0 para terminar:\t");
        scanf("%f", &PAG);
    {
    while(PAG);
    printf("\nEl total de pagos del mes es: %.2f", SPA);
    scanf("%f", &PAG );
    }
    }


