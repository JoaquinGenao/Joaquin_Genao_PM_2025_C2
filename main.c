#include <stdio.h>
#include <stdlib.h>


#define SIZE 8


// Función para imprimir el tablero
void imprimirTablero(char tablero[SIZE][SIZE]) {
printf("\n A B C D E F G H\n");
printf(" +---+---+---+---+---+---+---+---+\n");
for (int i = 0; i < SIZE; i++) {
printf("%d |", 8 - i); // Números de filas (8-1 hasta 1)
for (int j = 0; j < SIZE; j++) {
printf(" %c |", tablero[i][j]);
}
printf(" %d\n", 8 - i);
printf(" +---+---+---+---+---+---+---+---+\n");
}
printf(" A B C D E F G H\n\n");
}


// Inicializar tablero
void inicializarTablero(char tablero[SIZE][SIZE]) {
char piezas[SIZE][SIZE] = {
{'r','n','b','q','k','b','n','r'},
{'p','p','p','p','p','p','p','p'},
{' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' '},
{'P','P','P','P','P','P','P','P'},
{'R','N','B','Q','K','B','N','R'}
};


for (int i = 0; i < SIZE; i++) {
for (int j = 0; j < SIZE; j++) {
tablero[i][j] = piezas[i][j];
}
}
}


// Convertir letras (A-H) a índices
int columnaAIndice(char c) {
if (c >= 'A' && c <= 'H') return c - 'A';
if (c >= 'a' && c <= 'h') return c - 'a';
return -1;
}


int main() {
char tablero[SIZE][SIZE];
inicializarTablero(tablero);


char origenCol, destinoCol;
int origenFila, destinoFila;


while (1) {
imprimirTablero(tablero);


printf("Mover pieza (ejemplo: E2 E4) o X para salir: ");
char entrada[10];
fgets(entrada, sizeof(entrada), stdin);


if (entrada[0] == 'X' || entrada[0] == 'x') {
printf("Saliendo del juego...\n");
break;
}
