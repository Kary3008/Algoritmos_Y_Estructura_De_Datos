#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seleccion(int arr[], int n);

void main() {
    int i;
    int arr[10000];

    srand(time(0));

    // Generar 10,000 números aleatorios entre 0 y 459,565
    for (i = 0; i < 10000; i++) {
        arr[i] = rand() % 459566;
    }

    // Ordenar los números pares de menor a mayor utilizando el algoritmo de selección
    seleccion(arr, 10000);

    // Imprimir los números ordenados
    printf("Numeros pares ordenados:\n");
    for (i = 0; i < 10000; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d\n", arr[i]);
        }
    }

}


void seleccion(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] % 2 == 0 && (arr[j] < arr[min_idx] || arr[min_idx] % 2 != 0)) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

