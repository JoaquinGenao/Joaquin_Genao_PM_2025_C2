#include <stdio.h>
#include <stdlib.h>
/* Sp.
EL programa, al recibir datos el tipo de tratamento, la edad y el
numero de dias de interacion de un cliente en un spa, calcula el costo
total del tratament.
TRA, EDA, DIA: variables de tipo entero.
COS cariable de tipo rea. */
void main (void)
{
    int TRA, EDA, DIA ;
    float COS;
    printf("Ingrese tipo de tratamiento, edad y dios:");
    scanf("%d %d" , &TRA, & EDA, &DIA);
    switch (TRA)
    {
        case 1 : COS = DIA * 2800; break;
        case 2 : COS = DIA * 1950; break;
        case 3 :COS = DIA * 2500 ; break;
        case 4 :COS = DIA * 1150; break;
        default : COS = -1; break ;


}
if ('COS ! = -1')
{
    if ("EDA >= 60 ")
        COS = COS * 0.75;
    else
        if ("EDA< = 25")
        COS = COS * 0.85;
    printf("\nClave tratamento : %d\t Dias : %\t Costo total: %8.2f"),
    TRA, DIA, COS) ;

}
else printf("\nLa clave del tratamiento es incorrecta");

}

