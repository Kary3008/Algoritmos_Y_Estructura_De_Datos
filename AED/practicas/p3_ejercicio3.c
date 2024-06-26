#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float alto;
    float ancho;
    char titulo[50];
    char tipoFuente[20];
} Hoja;

void swap(Hoja *a, Hoja *b) {
    Hoja temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Hoja arr[], int n, char atributo, char orden) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (atributo == 'a') { // Ordenar por alto
                if (orden == 'a') { // Ascendente
                    if (arr[j].alto > arr[j+1].alto)
                        swap(&arr[j], &arr[j+1]);
                } else if (orden == 'd') { // Descendente
                    if (arr[j].alto < arr[j+1].alto)
                        swap(&arr[j], &arr[j+1]);
                }
            } else if (atributo == 't') { // Ordenar por título
                if (orden == 'a') {
                    if (strcmp(arr[j].titulo, arr[j+1].titulo) > 0)
                        swap(&arr[j], &arr[j+1]);
                } else if (orden == 'd') {
                    if (strcmp(arr[j].titulo, arr[j+1].titulo) < 0)
                        swap(&arr[j], &arr[j+1]);
                }
            } else if (atributo == 'w') { // Ordenar por ancho
                if (orden == 'a') {
                    if (arr[j].ancho > arr[j+1].ancho)
                        swap(&arr[j], &arr[j+1]);
                } else if (orden == 'd') {
                    if (arr[j].ancho < arr[j+1].ancho)
                        swap(&arr[j], &arr[j+1]);
                }
            } else if (atributo == 'f') { // Ordenar por tipo de fuente
                if (orden == 'a') {
                    if (strcmp(arr[j].tipoFuente, arr[j+1].tipoFuente) > 0)
                        swap(&arr[j], &arr[j+1]);
                } else if (orden == 'd') {
                    if (strcmp(arr[j].tipoFuente, arr[j+1].tipoFuente) < 0)
                        swap(&arr[j], &arr[j+1]);
                }
            }
        }
    }
}

void mostrarLibros(Hoja arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Libro %d:\n", i+1);
        printf("Alto: %.2f\n", arr[i].alto);
        printf("Ancho: %.2f\n", arr[i].ancho);
        printf("Titulo: %s\n", arr[i].titulo);
        printf("Tipo de Fuente: %s\n\n", arr[i].tipoFuente);
    }
}

int main() {
    int n;
    printf("Ingrese el numero de libros: ");
    scanf("%d", &n);

    Hoja *libros = (Hoja*)malloc(n * sizeof(Hoja));

    for (int i = 0; i < n; i++) {
        printf("Ingrese los datos del Libro %d:\n", i+1);
        printf("Alto: ");
        scanf("%f", &libros[i].alto);
        printf("Ancho: ");
        scanf("%f", &libros[i].ancho);
        printf("Titulo: ");
        getchar(); // Limpiar el buffer del teclado
        fgets(libros[i].titulo, sizeof(libros[i].titulo), stdin);
        libros[i].titulo[strlen(libros[i].titulo)-1] = '\0'; // Eliminar el salto de linea
        printf("Tipo de Fuente: ");
        fgets(libros[i].tipoFuente, sizeof(libros[i].tipoFuente), stdin);
        libros[i].tipoFuente[strlen(libros[i].tipoFuente)-1] = '\0'; // Eliminar el salto de linea
        printf("\n");
    }

    char atributo, orden;
    printf("Ingrese el atributo de orden (a - alto, t - titulo, w - ancho, f - tipo fuente): ");
    scanf(" %c", &atributo);
    printf("Ingrese el orden (a - ascendente, d - descendente): ");
    scanf(" %c", &orden);

    bubbleSort(libros, n, atributo, orden);

    mostrarLibros(libros, n);

    free(libros);

    return 0;
}
