#include<stdio.h>
#include<string.h>

void main(void)
{
	char cadena[80], letra;
	int existe, cont, longCadena;
	
	printf("Digite una cadena: ");
	scanf("%s", cadena);
	printf("Digite una letra: ");
	fflush(stdin);
	scanf("%c", letra);
	
	longCadena = strlen(cadena);
	cont = 0;
	existe = 0;
	
	while(cont < longCadena && !existe)
	{
		if(cadena[cont]==letra)
		{
			existe = 1;
			cont ++;
		}
	}
	if(existe)
		printf("\n la letra %c si existe en la cadena: ", letra);
	else
		printf("\n la letra %c no existe en la cadena: ", letra);
}
