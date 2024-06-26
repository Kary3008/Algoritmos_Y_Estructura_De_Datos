#include <stdio.h>
#include <stdlib.h>

void insercion(int arr[], int n);

void main() {
    int n = 10000;
    int arr[n];
    int i;

    // Generar números aleatorios entre 0 y 459,565
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 459566;
    }

    // Ordenar los números impares de mayor a menor utilizando el algoritmo de inserción
    insercion(arr, n);

    // Imprimir los números impares ordenados
    printf("Números impares ordenados de mayor a menor:\n");
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d\n", arr[i]);
        }
    }
}

void insercion(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

