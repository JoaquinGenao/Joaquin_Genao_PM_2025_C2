#include <stdio.h>
#include <string.h>

#define MAX_VENDEDORES 100
#define MAX_NOMBRE 50
#define MAX_BANCO 30
#define MAX_CUENTA 20

// Estructura para domicilio
typedef struct {
    char calle_num[MAX_NOMBRE];
    char colonia[MAX_NOMBRE];
    char cp[MAX_NOMBRE];
    char ciudad[MAX_NOMBRE];
} DOMICILIO;

// Estructura para cuenta bancaria
typedef struct {
    char nombre_banco[MAX_BANCO];
    char cuenta[MAX_CUENTA];
} CUENTA_BANCO;

// Unión para forma de pago
typedef union {
    CUENTA_BANCO banco;
    char ventanilla;  // Solo una letra, por ejemplo 'V'
} FORMA_PAGO;

// Estructura principal del vendedor
typedef struct {
    int numero;
    char nombre[MAX_NOMBRE];
    float ventas[12];
    DOMICILIO domicilio;
    float salario;
    int clave_pago; // 1=cheques, 2=nomina, 3=ventanilla
    FORMA_PAGO pago;
} VENDEDOR;

int main() {
    VENDEDOR vendedores[MAX_VENDEDORES];
    int n, i, j;
    float totalVentas[MAX_VENDEDORES] = {0};

    printf("Ingrese el número de vendedores (máximo 100): ");
    scanf("%d", &n);
    getchar(); // limpiar buffer

    for (i = 0; i < n; i++) {
        printf("\n--- Vendedor %d ---\n", i + 1);
        printf("Número de vendedor: ");
        scanf("%d", &vendedores[i].numero);
        getchar();

        printf("Nombre y apellido: ");
        fgets(vendedores[i].nombre, MAX_NOMBRE, stdin);
        vendedores[i].nombre[strcspn(vendedores[i].nombre, "\n")] = '\0';

        for (j = 0; j < 12; j++) {
            printf("  Ventas del mes %d: ", j + 1);
            scanf("%f", &vendedores[i].ventas[j]);
            totalVentas[i] += vendedores[i].ventas[j];
        }

        getchar(); // limpiar buffer

        printf("Calle y número: ");
        fgets(vendedores[i].domicilio.calle_num, MAX_NOMBRE, stdin);
        vendedores[i].domicilio.calle_num[strcspn(vendedores[i].domicilio.calle_num, "\n")] = '\0';

        printf("Colonia: ");
        fgets(vendedores[i].domicilio.colonia, MAX_NOMBRE, stdin);
        vendedores[i].domicilio.colonia[strcspn(vendedores[i].domicilio.colonia, "\n")] = '\0';

        printf("Código Postal: ");
        fgets(vendedores[i].domicilio.cp, MAX_NOMBRE, stdin);
        vendedores[i].domicilio.cp[strcspn(vendedores[i].domicilio.cp, "\n")] = '\0';

        printf("Ciudad: ");
        fgets(vendedores[i].domicilio.ciudad, MAX_NOMBRE, stdin);
        vendedores[i].domicilio.ciudad[strcspn(vendedores[i].domicilio.ciudad, "\n")] = '\0';

        printf("Salario mensual: ");
        scanf("%f", &vendedores[i].salario);

        printf("Clave forma de pago (1 = cheques, 2 = nómina, 3 = ventanilla): ");
        scanf("%d", &vendedores[i].clave_pago);
        getchar(); // limpiar

        if (vendedores[i].clave_pago == 1 || vendedores[i].clave_pago == 2) {
            printf("Nombre del banco: ");
            fgets(vendedores[i].pago.banco.nombre_banco, MAX_BANCO, stdin);
            vendedores[i].pago.banco.nombre_banco[strcspn(vendedores[i].pago.banco.nombre_banco, "\n")] = '\0';

            printf("Número de cuenta: ");
            fgets(vendedores[i].pago.banco.cuenta, MAX_CUENTA, stdin);
            vendedores[i].pago.banco.cuenta[strcspn(vendedores[i].pago.banco.cuenta, "\n")] = '\0';
        } else {
            printf("Ventanilla (letra): ");
            scanf(" %c", &vendedores[i].pago.ventanilla);
            getchar(); // limpiar
        }
    }

    // a) Ventas anuales
    printf("\n--- Ventas anuales por vendedor ---\n");
    for (i = 0; i < n; i++) {
        printf("Vendedor %d | %s | Ventas anuales: %.2f\n",
               vendedores[i].numero, vendedores[i].nombre, totalVentas[i]);
    }

    // b) Incremento del 5% en salario si supera 1,500,000
    printf("\n--- Incremento de salario para ventas > 1,500,000 ---\n");
    for (i = 0; i < n; i++) {
        if (totalVentas[i] > 1500000) {
            vendedores[i].salario *= 1.05;
            printf("Vendedor %d | %s | Nuevo salario: %.2f\n",
                   vendedores[i].numero, vendedores[i].nombre, vendedores[i].salario);
        }
    }

    // c) Vendedores con ventas < 300,000
    printf("\n--- Vendedores con ventas menores a 300,000 ---\n");
    for (i = 0; i < n; i++) {
        if (totalVentas[i] < 300000) {
            printf("Vendedor %d | %s | Ventas: %.2f\n",
                   vendedores[i].numero, vendedores[i].nombre, totalVentas[i]);
        }
    }

    // d) Empleados con forma de pago por cuenta de cheques
    printf("\n--- Empleados con cuenta de cheques ---\n");
    for (i = 0; i < n; i++) {
        if (vendedores[i].clave_pago == 1) {
            printf("Vendedor %d | Banco: %s | Cuenta: %s\n",
                   vendedores[i].numero,
                   vendedores[i].pago.banco.nombre_banco,
                   vendedores[i].pago.banco.cuenta);
        }
    }

    return 0;
}
