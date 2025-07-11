#include <stdio.h>

int esPerfecto(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma == num;
}

int main(void) {
    int perfectos[4];  // Solo podemos calcular los primeros 4 con tipos normales
    int contador = 0, numero = 2;

    while (contador < 4) {
        if (esPerfecto(numero)) {
            perfectos[contador] = numero;
            contador++;
        }
        numero++;
    }

    printf("Los primeros 4 números perfectos son:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", perfectos[i]);
    }
    printf("\n");

    return 0;
}
