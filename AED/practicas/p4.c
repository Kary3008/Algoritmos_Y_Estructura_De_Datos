#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Estructura para almacenar información de los países
typedef struct {
    char pais[MAX_SIZE];
    int poblacion;
    char idioma[MAX_SIZE];
} Pais;

// Función para asignar los índices de búsqueda
void asignarIndices(Pais paises[], int numPaises, int* idxPais[], int* idxPoblacion[], int* idxIdioma[]) {
    int i;

    // Inicializar los índices de búsqueda
    for (i = 0; i < MAX_SIZE; i++) {
        idxPais[i] = NULL;
        idxPoblacion[i] = NULL;
        idxIdioma[i] = NULL;
    }

    // Asignar los índices de búsqueda para los campos País, Población e Idioma
    for (i = 0; i < numPaises; i++) {
        // Índice para el campo País
        idxPais[paises[i].pais[0]-'A'] = &paises[i];

        // Índice para el campo Población
        if (idxPoblacion[paises[i].poblacion] == NULL) {
            idxPoblacion[paises[i].poblacion] = &paises[i];
        }

        // Índice para el campo Idioma
        for (int j = 0; j < strlen(paises[i].idioma); j++) {
            idxIdioma[paises[i].idioma[j]-'A'] = &paises[i];
        }
    }
}

// Función para buscar el país de origen del usuario y mostrar información
void buscarPaisOrigen(Pais paises[], int* idxPais[]) {
    char paisOrigen[MAX_SIZE];

    printf("Ingrese el país de origen: ");
    fgets(paisOrigen, MAX_SIZE, stdin);

    // Quitar el salto de línea del final de la cadena ingresada
    paisOrigen[strcspn(paisOrigen, "\n")] = '\0';

    // Buscar el país de origen en el índice correspondiente
    if (idxPais[paisOrigen[0]-'A'] != NULL && strcmp(paises[idxPais[paisOrigen[0]-'A']]->pais, paisOrigen) == 0) {
        // Mostrar idioma y población del país de origen
        printf("Idioma: %s\n", paises[idxPais[paisOrigen[0]-'A']]->idioma);
        printf("Población: %d\n", paises[idxPais[paisOrigen[0]-'A']]->poblacion);
    } else {
        printf("El país de origen no fue encontrado.\n");
    }
}

// Función para buscar países por idioma y mostrar información
void buscarPaisesPorIdioma(Pais paises[], int* idxIdioma[]) {
    char idioma[MAX_SIZE];

    printf("Ingrese el idioma: ");
    fgets(idioma, MAX_SIZE, stdin);

    // Quitar el salto de línea del final de la cadena ingresada
    idioma[strcspn(idioma, "\n")] = '\0';

    // Buscar los países en el índice correspondiente
    for (int i = 0; i < strlen(idioma); i++) {
        if (idxIdioma[idioma[i]-'A'] != NULL && strchr(paises[idxIdioma[idioma[i]-'A']]->idioma, idioma[i]) != NULL) {
            // Mostrar el país y su idioma
            printf("País: %s\n", paises[idxIdioma[idioma[i]-'A']]->pais);
            printf("Idioma: %s\n", paises[idxIdioma[idioma[i]-'A']]->idioma);
        }
    }
}

// Función para mostrar la cantidad total de población que habla un idioma
void mostrarPoblacionIdioma(Pais paises[], int* idxIdioma[]) {
    char idioma[MAX_SIZE];
    int totalPoblacion = 0;

    printf("Ingrese el idioma: ");
    fgets(idioma, MAX_SIZE, stdin);

    // Quitar el salto de línea del final de la cadena ingresada
    idioma[strcspn(idioma, "\n")] = '\0';

    // Calcular la cantidad total de población que habla el idioma
    for (int i = 0; i < strlen(idioma); i++) {
        if (idxIdioma[idioma[i]-'A'] != NULL && strchr(paises[idxIdioma[idioma[i]-'A']]->idioma, idioma[i]) != NULL) {
            totalPoblacion += paises[idxIdioma[idioma[i]-'A']]->poblacion;
        }
    }

    // Mostrar la cantidad total de población que habla el idioma
    printf("La población que habla %s es: %d\n", idioma, totalPoblacion);
}

int main() {
    int numPaises;
    Pais paises[MAX_SIZE];
    int* idxPais[MAX_SIZE];
    int* idxPoblacion[MAX_SIZE];
    int* idxIdioma[MAX_SIZE];

    printf("Ingrese el número de países: ");
    scanf("%d", &numPaises);
    getchar();

    // Leer información de los países
    for (int i = 0; i < numPaises; i++) {
        printf("País %d:\n", i+1);
        printf("Nombre: ");
        fgets(paises[i].pais, MAX_SIZE, stdin);
        paises[i].pais[strcspn(paises[i].pais, "\n")] = '\0';
        printf("Población: ");
        scanf("%d", &paises[i].poblacion);
        getchar();
        printf("Idioma: ");
        fgets(paises[i].idioma, MAX_SIZE, stdin);
        paises[i].idioma[strcspn(paises[i].idioma, "\n")] = '\0';
    }

    // Asignar los índices de búsqueda
    asignarIndices(paises, numPaises, idxPais, idxPoblacion, idxIdioma);

    // Mostrar menú de opciones
    int opcion;
    do {
        printf("\n----- Menú de opciones -----\n");
        printf("1. Buscar país de origen\n");
        printf("2. Buscar países por idioma\n");
        printf("3. Mostrar población que habla un idioma\n");
        printf("0. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                buscarPaisOrigen(paises, idxPais);
                break;
            case 2:
                buscarPaisesPorIdioma(paises, idxIdioma);
                break;
            case 3:
                mostrarPoblacionIdioma(paises, idxIdioma);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}