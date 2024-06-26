#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define NUM_RECORDS 38

typedef struct {
    char pais[MAX_LENGTH];
    int poblacion;
    char idioma[MAX_LENGTH];
} Registro;

typedef struct {
    char clave[MAX_LENGTH];
    int numRegistro;
} Indice;

void cargarIndices(Indice *indices, FILE *archivo, int n);
void buscarPaisPorIdioma(Indice *indicesPais, Indice *indicesIdioma, FILE *archivoPaises, FILE *archivoIdiomas);
void buscarPaisesPorIdioma(Indice *indicesPais, Indice *indicesIdioma, FILE *archivoPaises);
void mostrarPoblacionPorIdioma(Indice *indicesIdioma, FILE *archivoIdiomas);

void cargarIndices(Indice *indices, FILE *archivo, int n) {
    for (int i = 0; i < n; i++) {
        fscanf(archivo, "%s %d %s", indices[i].clave, &indices[i].numRegistro, indices[i].clave);
    }
}

void buscarPaisPorIdioma(Indice *indicesPais, Indice *indicesIdioma, FILE *archivoPaises, FILE *archivoIdiomas) {
    char idiomaUsuario[MAX_LENGTH];
    printf("Ingrese el idioma: ");
    scanf("%s", idiomaUsuario);
    
    int indiceIdioma = -1;
    for (int i = 0; i < NUM_RECORDS; i++) {
        if (strcmp(indicesIdioma[i].clave, idiomaUsuario) == 0) {
            indiceIdioma = indicesIdioma[i].numRegistro;
            break;
        }
    }
    
    if (indiceIdioma != -1) {
        int indicePais = -1;
        for (int i = 0; i < NUM_RECORDS; i++) {
            if (indicesPais[i].numRegistro == indiceIdioma) {
                indicePais = i;
                break;
            }
        }
        
        if (indicePais != -1) {
            Registro pais;
            fseek(archivoPaises, sizeof(Registro) * indicesPais[indicePais].numRegistro, SEEK_SET);
            fread(&pais, sizeof(Registro), 1, archivoPaises);
            printf("Pais: %s, Idioma: %s, Poblacion: %d\n", pais.pais, pais.idioma, pais.poblacion);
        } else {
            printf("No se encontraron paises que hablen ese idioma.\n");
        }
    } else {
        printf("No se encontraron registros con ese idioma.\n");
    }
}

void buscarPaisesPorIdioma(Indice *indicesPais, Indice *indicesIdioma, FILE *archivoPaises) {
    char idiomaUsuario[MAX_LENGTH];
    printf("Ingrese el idioma: ");
    scanf("%s", idiomaUsuario);
    
    int indiceIdioma = -1;
    for (int i = 0; i < NUM_RECORDS; i++) {
        if (strcmp(indicesIdioma[i].clave, idiomaUsuario) == 0) {
            indiceIdioma = indicesIdioma[i].numRegistro;
            break;
        }
    }
    
    if (indiceIdioma != -1) {
        printf("Paises que hablan %s:\n", idiomaUsuario);
        for (int i = 0; i < NUM_RECORDS; i++) {
            if (indicesPais[i].numRegistro == indiceIdioma) {
                Registro pais;
                fseek(archivoPaises, sizeof(Registro) * indicesPais[i].numRegistro, SEEK_SET);
                fread(&pais, sizeof(Registro), 1, archivoPaises);
                printf("Pais: %s, Idioma: %s, Poblacion: %d\n", pais.pais, pais.idioma, pais.poblacion);
            }
        }
    } else {
        printf("No se encontraron registros con ese idioma.\n");
    }
}

void mostrarPoblacionPorIdioma(Indice *indicesIdioma, FILE *archivoIdiomas) {
    char idiomaUsuario[MAX_LENGTH];
    printf("Ingrese el idioma: ");
    scanf("%s", idiomaUsuario);
    
    int indiceIdioma = -1;
    for (int i = 0; i < NUM_RECORDS; i++) {
        if (strcmp(indicesIdioma[i].clave, idiomaUsuario) == 0) {
            indiceIdioma = indicesIdioma[i].numRegistro;
            break;
        }
    }
    
    if (indiceIdioma != -1) {
        Registro idioma;
        fseek(archivoIdiomas, sizeof(Registro) * indicesIdioma[indiceIdioma].numRegistro, SEEK_SET);
        fread(&idioma, sizeof(Registro), 1, archivoIdiomas);
        printf("Idioma: %s, Poblacion: %d\n", idioma.idioma, idioma.poblacion);
	}
	else
	{
		printf("No se encontraron registros con ese idioma.\n");
	}
	
}