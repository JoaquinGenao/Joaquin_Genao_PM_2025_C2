#include <stdio.h>
/* Serie.
El programa imprime los terminos y obtiene la suma de una determinada serie.
I, SSE y CAM: variables de tipo entero. */
void main (void)
{
    int I = 2, CAM = 1;
    long SSE = 0 ;
    while (I<= 2500)
    {
        SSE = SSE + I ;
        printf("\t %d", I);
        if (CAM)
        {
            I+= 5 ;
            CAM--;

        }
        else
        {
            I+= 3;
            CAM ++;
        }
    }
}
