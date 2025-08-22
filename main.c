#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"
#include <stdio.h>
#include <stdlib.h>

// Convertir a escala de grises
void convertirAGris(unsigned char *img, int ancho, int alto, int canales) {
    for (int i = 0; i < ancho * alto * canales; i += canales) {
        int r = img[i];
        int g = img[i + 1];
        int b = img[i + 2];

        // fórmula promedio ponderado (luminosidad)
        unsigned char gris = (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);

        img[i] = gris;
        img[i + 1] = gris;
        img[i + 2] = gris;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s entrada.png salida.png\n", argv[0]);
        return 1;
    }

    int ancho, alto, canales;
    unsigned char *img = stbi_load(argv[1], &ancho, &alto, &canales, 0);
    if (img == NULL) {
        printf("Error al cargar la imagen %s\n", argv[1]);
        return 1;
    }

    printf("Imagen cargada: %dx%d, %d canales\n", ancho, alto, canales);

    convertirAGris(img, ancho, alto, canales);

    if (!stbi_write_png(argv[2], ancho, alto, canales, img, ancho * canales)) {
        printf("Error al guardar la imagen %s\n", argv[2]);
        stbi_image_free(img);
        return 1;
    }

    printf("Imagen guardada en escala de grises: %s\n", argv[2]);

    stbi_image_free(img);
    return 0;
}
