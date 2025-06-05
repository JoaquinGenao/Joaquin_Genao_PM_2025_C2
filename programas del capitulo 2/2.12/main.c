#include <stdio.h>
# include < math.h>

/* Igualdad de expreciones.
El programa, al recibir como datos T,P y N comprueba la igualdad de
una exprecion determinada.
T,P y N : variabnles de tipo entero*/
void main(void)
{
    int T, P, N
    printf("Ingrese los valores de T, P y N:");
    scanf(" %d %d %d", &T, &P, &N);
    if (P != 0)
        if (pow(T/ P, N) == (pow(T, N) / pow (P,N))
            printf("\ nSe comprueba la igualdad");
    else
        printf("\ No se comprueba la igualdad");
}
else
    printf(" \nP tiene que ser diferente a cero");

}
