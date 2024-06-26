#include <stdio.h>

// Estructura del primer nivel
typedef struct {
    int numero1;
    int numero2;
    int numero3;
} EstructuraNivel1;

// Estructura del segundo nivel
typedef struct {
    float decimal1;
    float decimal2;
    float decimal3;
} EstructuraNivel2;

// Estructura del tercer nivel
typedef struct {
    EstructuraNivel1 nivel1;
    EstructuraNivel2 nivel2;
} EstructuraNivel3;

void main() {
    // Asigna valores a los miembros
    EstructuraNivel3 instancia;
    instancia.nivel1.numero1 = 10;
    instancia.nivel1.numero2 = 20;
    instancia.nivel1.numero3 = 30;
    instancia.nivel2.decimal1 = 1.1;
    instancia.nivel2.decimal2 = 2.2;
    instancia.nivel2.decimal3 = 3.3;
    
    // Imprime los valores de los miembros
    printf("Miembros de nivel 1:\n");
    printf("numero1: %d\n", instancia.nivel1.numero1);
    printf("numero2: %d\n", instancia.nivel1.numero2);
    printf("numero3: %d\n\n", instancia.nivel1.numero3);
    
    printf("Miembros de nivel 2:\n");
    printf("decimal1: %.2f\n", instancia.nivel2.decimal1);
    printf("decimal2: %.2f\n", instancia.nivel2.decimal2);
    printf("decimal3: %.2f\n\n", instancia.nivel2.decimal3);

}
