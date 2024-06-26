#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAISES 100
#define MAX_IDIOMAS 100

typedef struct {
    char pais[50];
    char idioma[50];
    int poblacion;
} Pais;

typedef struct {
    char idioma[50];
    int poblacion;
} Idioma;

Pais paises[MAX_PAISES];
Idioma idiomas[MAX_IDIOMAS];
int numPaises = 0;
int numIdiomas = 0;

void leerPaises() {
    FILE* archivo = fopen("Paises.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo Paises.txt\n");
        exit(1);
    }
    char linea[100];
    while (fgets(linea, sizeof(linea), archivo)) {
        sscanf(linea, "%[^,],%[^,],%d", paises[numPaises].pais, paises[numPaises].idioma, &paises[numPaises].poblacion);
        numPaises++;
    }
    fclose(archivo);
}

void leerIdiomas() {
    FILE* archivo = fopen("Idiomas.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo Idioma.txt\n");
        exit(1);
    }
    char linea[50];
    while (fgets(linea, sizeof(linea), archivo)) {
        sscanf(linea, "%[^,],%d", idiomas[numIdiomas].idioma, &idiomas[numIdiomas].poblacion);
        numIdiomas++;
    }
    fclose(archivo);
}

int buscarPais(char* nombrePais) {
    int i;
    for (i = 0; i < numPaises; i++) {
        if (strcmp(paises[i].pais, nombrePais) == 0) {
            return i;
        }
    }
    return -1;
}

void buscarPaisOrigen() {
    char nombrePais[50];
    printf("Ingrese su país de origen: ");
    scanf("%s", nombrePais);
    int indice = buscarPais(nombrePais);
    if (indice != -1) {
        printf("Idioma: %s\n", paises[indice].idioma);
        printf("Población: %d\n", paises[indice].poblacion);
    } else {
        printf("País no encontrado\n");
    }
}

void buscarPaisesPorIdioma() {
    char idioma[50];
    printf("Ingrese el idioma: ");
    scanf("%s", idioma);
    int i;
    for (i = 0; i < numPaises; i++) {
        if (strcmp(paises[i].idioma, idioma) == 0) {
            printf("%s\n", paises[i].pais);
        }
    }
}

void mostrarPoblacionPorIdioma() {
    char idioma[50];
    printf("Ingrese el idioma: ");
    scanf("%s", idioma);
    int i, poblacionTotal = 0;
    for (i = 0; i < numPaises; i++) {
        if (strcmp(paises[i].idioma, idioma) == 0) {
            poblacionTotal += paises[i].poblacion;
        }
    }
    printf("La población total que habla %s es: %d\n", idioma, poblacionTotal);
}

void ordenarPaisesPorPoblacion() {
    int i, j;
    Pais temp;
    for (i = 0; i < numPaises - 1; i++) {
        for (j = 0; j < numPaises - 1 - i; j++) {
            if (paises[j].poblacion < paises[j + 1].poblacion) {
                temp = paises[j];
                paises[j] = paises[j + 1];
                paises[j + 1] = temp;
            }
        }
    }
    printf("País             Idioma          Población\n");
    printf("-----------------------------------------\n");
    for (i = 0; i < numPaises; i++) {
        printf("%-16s %-15s %d\n", paises[i].pais, paises[i].idioma, paises[i].poblacion);
    }
}

int main() {
    leerPaises();
    leerIdiomas();
    buscarPais("Nicaragua");
    buscarPaisOrigen();



	return 0;
}     