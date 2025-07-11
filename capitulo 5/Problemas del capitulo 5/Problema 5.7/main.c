#include <stdio.h>

int main(void) {
    float COS[12];  // Arreglo para las toneladas cosechadas cada mes
    const char *meses[] = {
        "Enero", "Febrero", "Marzo", "Abril",
        "Mayo", "Junio", "Julio", "Agosto",
        "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    float suma = 0.0, promedio;
    int i, superiores = 0, mes_max = 0;

    // Lectura de las toneladas cosechadas
    for (i = 0; i < 12; i++) {
        printf("Ingrese las toneladas cosechadas en %s: ", meses[i]);
        scanf("%f", &COS[i]);
        suma += COS[i];
    }

    // Cálculo del promedio
    promedio = suma / 12;

    // Determinar cuántos meses superan el promedio y cuál es el mes con mayor cosecha
    for (i = 0; i < 12; i++) {
        if (COS[i] > promedio) {
            superiores++;
        }
        if (COS[i] > COS[mes_max]) {
            mes_max = i;
        }
    }

    // Resultados
    printf("\n--- Resultados ---\n");
    printf("a) Promedio anual de toneladas cosechadas: %.2f\n", promedio);
    printf("b) Meses con cosecha superior al promedio: %d\n", superiores);
    printf("c) Mayor cosecha: %.2f toneladas en %s\n", COS[mes_max], meses[mes_max]);

    return 0;
}
