#include <stdio.h>
#include "pila.h"

int main()
{
	Pila *p; //regresa un apuntador
	p = crear();
	if(is_empty(*p)==1) //mandamos el contenido de la pila
		printf("La pila esta vacia"); //como apenas se creo está vacía
	
	if(is_full(*p)==1)
		printf("La pila esta llena");
	else
		printf("La pila no esta llena");
	return 0;
	
}