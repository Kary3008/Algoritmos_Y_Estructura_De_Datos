//definir una estructura para almacenar 10 personas
//y pedir al usuario únicamente sus nombres

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 10

typedef struct{ //typeder redefinir cualquier tipo de dato
	char persona[10];
}Personas;

int main()
{
	Personas personas;
	//Personas* p=&personas; //envía solo una dirección de memoria. 
	//Personas* personas = calloc(10,sizeof(Personas));
	
	printf("Ingrese los nombres de las 10 personas: \n");
	for(int i = 0; i<tam; i++)
	{
		scanf("%s", personas[i].persona);
	}
	
	puts("Nombres de las personas:"),
	
	for(int i = 0; i < tam; i++)
	{
		printf("Nombre de las persona %i: %s\n", i+1, personas[i].persona);
	}
}
