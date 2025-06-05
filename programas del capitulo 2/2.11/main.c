#include <stdio.h>
/* Billete de ferrocaril.
El programa calcula el costo de un billete de ferrocaril teniendo en cuenta en
cuanta distacia entre las dos ciudades y el tiempo de permanecia
del pasajero.
DIS y TIE: variables de tipo entero.
BIL: variables de tipo real. */
void main (void)
{
    int DIS, TIE;
    float BIL;
    printf("Ingrese la distancia entre ciudades y el tiempo de estancia:");
    scanf("%d %d", & DIS, &TIE);
    if ((DIS*2 > 500) &&(TIE > 10))

    BIL=  DIS *2 * 0.19* 0.8;
    else
        BIL = DIS* 2 *0.19;
    printf("\n\n Costo del billete: %7.2f" , BIL);

}
