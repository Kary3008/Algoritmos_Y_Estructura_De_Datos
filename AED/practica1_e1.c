#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3
#define TAM 25

typedef struct 
{
	int clave;
	char nombre[TAM];
} Persona;
typedef Persona Elemento;

typedef int posicion;
typedef struct 
{
	Elemento elementos[MAX];
	posicion ult;
}Lista;

void inicializador();
void imprimir();

int main()
{
	inicializador();
	imprimir();
}

int Posicion;
Persona Alumno;
Persona Alumno2;
Persona Alumno3;
Lista MiLista;



void inicializador()
{
	Alumno.clave=100;
	strcpy(Alumno.nombre, "Kary");
	Alumno.clave=200;
	strcpy(Alumno2.nombre, "Oscar");
	Alumno.clave=300;
	strcpy(Alumno3.nombre, "Alan");
	
	MiLista.elementos[0] = Alumno;
	MiLista.elementos[1] = Alumno2;
	MiLista.elementos[2] = Alumno3;
}

void imprimir()
{
	int i;
	for (i = 0; i < MAX -1 ; i++)
	{
		printf("ELEMENTOS[%d]: \n", i);
		printf("CLAVE = %d\n", MiLista.elementos[i].clave);
		printf("NOMBRE = %S\n", MiLista.elementos[i].nombre);
	}
}
