#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

typedef struct {
    int clave;
    char nombre[MAX_NOMBRE];
    int existencia;
    float precio;
} PRODUCTO;

int buscarProducto(PRODUCTO inv[], int n, int clave) {
    // Búsqueda binaria porque el arreglo está ordenado por clave
    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (inv[medio].clave == clave)
            return medio;
        else if (inv[medio].clave < clave)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1; // No encontrado
}

void imprimirInventario(PRODUCTO inv[], int n) {
    printf("\nINVENTARIO COMPLETO\n");
    printf("Clave\tNombre\t\tExistencia\tPrecio Unitario\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-15s\t%d\t\t$%.2f\n",
               inv[i].clave, inv[i].nombre, inv[i].existencia, inv[i].precio);
    }
}

int insertarProducto(PRODUCTO inv[], int *n, PRODUCTO nuevo) {
    if (*n >= MAX_PRODUCTOS) {
        printf("Inventario lleno. No se pueden agregar más productos.\n");
        return 0;
    }

    // Buscar posición para insertar manteniendo orden por clave
    int pos = *n;
    for (int i = 0; i < *n; i++) {
        if (inv[i].clave == nuevo.clave) {
            printf("La clave %d ya existe en inventario.\n", nuevo.clave);
            return 0; // No inserta producto repetido
        }
        if (inv[i].clave > nuevo.clave) {
            pos = i;
            break;
        }
    }

    // Mover elementos para abrir espacio
    for (int i = *n; i > pos; i--) {
        inv[i] = inv[i - 1];
    }

    // Insertar nuevo producto
    inv[pos] = nuevo;
    (*n)++;
    printf("Producto con clave %d agregado correctamente.\n", nuevo.clave);
    return 1;
}

void moduloVentas(PRODUCTO inv[], int *n) {
    int clave, cantidad;
    float totalVenta = 0.0;
    printf("\n*** Módulo Ventas ***\n");
    printf("Ingrese clave del producto a vender (0 para terminar): ");
    scanf("%d", &clave);

    while (clave != 0) {
        int idx = buscarProducto(inv, *n, clave);
        if (idx == -1) {
            printf("Producto con clave %d no encontrado.\n", clave);
        } else {
            printf("Ingrese cantidad a vender de %s: ", inv[idx].nombre);
            scanf("%d", &cantidad);
            if (cantidad > inv[idx].existencia) {
                printf("No hay suficiente existencia. Solo quedan %d unidades.\n", inv[idx].existencia);
            } else {
                inv[idx].existencia -= cantidad;
                float monto = cantidad * inv[idx].precio;
                totalVenta += monto;
                printf("Venta registrada: %d unidades de %s por $%.2f\n", cantidad, inv[idx].nombre, monto);
            }
        }
        printf("Ingrese clave del producto a vender (0 para terminar): ");
        scanf("%d", &clave);
    }

    printf("Total de la venta del cliente: $%.2f\n", totalVenta);
}

void moduloReabastecimiento(PRODUCTO inv[], int n) {
    int clave, cantidad;
    printf("\n*** Módulo Reabastecimiento ***\n");
    printf("Ingrese clave del producto para reabastecer (0 para terminar): ");
    scanf("%d", &clave);

    while (clave != 0) {
        int idx = buscarProducto(inv, n, clave);
        if (idx == -1) {
            printf("Producto con clave %d no encontrado.\n", clave);
        } else {
            printf("Ingrese cantidad a agregar para %s: ", inv[idx].nombre);
            scanf("%d", &cantidad);
            if (cantidad < 0) {
                printf("Cantidad inválida.\n");
            } else {
                inv[idx].existencia += cantidad;
                printf("Existencia actualizada: %d unidades.\n", inv[idx].existencia);
            }
        }
        printf("Ingrese clave del producto para reabastecer (0 para terminar): ");
        scanf("%d", &clave);
    }
}

void moduloNuevosProductos(PRODUCTO inv[], int *n) {
    PRODUCTO nuevo;
    int clave;
    printf("\n*** Módulo Nuevos Productos ***\n");
    printf("Ingrese clave del nuevo producto (0 para terminar): ");
    scanf("%d", &clave);

    while (clave != 0) {
        nuevo.clave = clave;
        getchar(); // limpiar buffer
        printf("Ingrese nombre del producto: ");
        fgets(nuevo.nombre, MAX_NOMBRE, stdin);
        // Quitar salto de línea si hay
        nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';

        printf("Ingrese existencia inicial: ");
        scanf("%d", &nuevo.existencia);
        printf("Ingrese precio unitario: ");
        scanf("%f", &nuevo.precio);

        insertarProducto(inv, n, nuevo);

        printf("Ingrese clave del nuevo producto (0 para terminar): ");
        scanf("%d", &clave);
    }
}

int main() {
    PRODUCTO inventario[MAX_PRODUCTOS];
    int n = 0; // número actual de productos
    int opcion;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Registrar Venta\n");
        printf("2. Reabastecimiento\n");
        printf("3. Nuevos Productos\n");
        printf("4. Mostrar Inventario\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                moduloVentas(inventario, &n);
                break;
            case 2:
                moduloReabastecimiento(inventario, n);
                break;
            case 3:
                moduloNuevosProductos(inventario, &n);
                break;
            case 4:
                imprimirInventario(inventario, n);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }

    } while(opcion != 0);

    return 0;
}
