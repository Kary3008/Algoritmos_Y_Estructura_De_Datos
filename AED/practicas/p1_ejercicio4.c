#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor1;
    float valor2;
    char valor3;
} TDA;

TDA* crearTDA(int valor1, float valor2, char valor3);
void destruirTDA(TDA* tda);
void imprimirTDA(TDA tda);
void copiarTDA(TDA* tda_destino, TDA tda_original);

void main() {
    TDA* tda1 = crearTDA(10, 3.14, 'A');
    TDA tda2;
    copiarTDA(&tda2, *tda1);
    imprimirTDA(*tda1);
    imprimirTDA(tda2);
    destruirTDA(tda1);
}

TDA* crearTDA(int valor1, float valor2, char valor3) {
    TDA* tda = (TDA*)malloc(sizeof(TDA));
    if (tda == NULL) {
        printf("Error: No se pudo asignar memoria para el TDA.\n");
        exit(1);
    }
    tda->valor1 = valor1;
    tda->valor2 = valor2;
    tda->valor3 = valor3;
    return tda;
}

void destruirTDA(TDA* tda) {
    free(tda);
}

void imprimirTDA(TDA tda) {
    printf("Valor 1: %d\n", tda.valor1);
    printf("Valor 2: %.2f\n", tda.valor2);
    printf("Valor 3: %c\n", tda.valor3);
}

void copiarTDA(TDA* tda_destino, TDA tda_original) {
    tda_destino->valor1 = tda_original.valor1;
    tda_destino->valor2 = tda_original.valor2;
    tda_destino->valor3 = tda_original.valor3;
}