#include <stdio.h>
#include <stdlib.h>  // Para atof()

int main() {
    char cadena[10];     // Cadena de 10 caracteres m�ximo
    char respuesta;      // Para preguntar si desea ingresar otro n�mero
    float suma = 0.0;
    int contador = 0;

    do {
        printf("�Deseas ingresar un n�mero (S/N)? ");
        scanf(" %c", &respuesta);  // Espacio antes de %c para ignorar saltos de l�nea

        if (respuesta == 'S' || respuesta == 's') {
            printf("Introduce un n�mero real como cadena (m�x. 9 caracteres): ");
            scanf("%s", cadena);  // Lee la cadena

            float numero = atof(cadena);  // Convierte cadena a float
            suma += numero;
            contador++;
        }

    } while (respuesta == 'S' || respuesta == 's');

    // Mostrar resultados
    if (contador > 0) {
        float promedio = suma / contador;
        printf("\nCantidad de datos: %d\n", contador);
        printf("Suma total: %.2f\n", suma);
        printf("Promedio: %.2f\n", promedio);
    } else {
        printf("\nNo se ingresaron datos.\n");
    }

    return 0;
}
