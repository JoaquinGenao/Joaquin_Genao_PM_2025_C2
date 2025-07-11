#include <stdio.h>

int main(void) {
    int VENTAS[12][15] = {0};  // Matriz para ventas por mes y producto
    int mes, producto, cantidad;

    printf("Ingrese las transacciones (mes, producto, cantidad). Finalice con -1 -1 -1.\n");

    while (1) {
        printf("Transacción (mes producto cantidad): ");
        scanf("%d %d %d", &mes, &producto, &cantidad);

        if (mes == -1 && producto == -1 && cantidad == -1)
            break;

        // Validar datos
        if (mes < 1 || mes > 12 || producto < 1 || producto > 15 || cantidad < 0) {
            printf("Datos inválidos. Intente nuevamente.\n");
            continue;
        }

        // Acumular ventas
        VENTAS[mes - 1][producto - 1] += cantidad;
    }

    // Mostrar ventas por mes y producto
    printf("\n--- Reporte de ventas ---\n");
    for (mes = 0; mes < 12; mes++) {
        printf("\nMes %d:\n", mes + 1);
        for (producto = 0; producto < 15; producto++) {
            if (VENTAS[mes][producto] > 0) {
                printf("  Producto %d: %d unidades vendidas\n", producto + 1, VENTAS[mes][producto]);
            }
        }
    }

    return 0;
}
