#include <stdio.h>
#include "pila.h"

int main()
{
	Pila *p; //regresa un apuntador
	p = crear();
	if(is_empty(*p)) //mandamos el contenido de la pila
		printf("La pila esta vacia\n"); //como apenas se creo está vacía
	
	if(is_full(*p))
		printf("La pila esta llena\n");
	else
		printf("La pila no esta llena\n");
		
	if(push(p,4))
		printf("Elemento ingresado\n");	
	else
		printf("La pila esta llena\n");
	
	if(push(p,5))
		printf("Elemento ingresado\n");	
	else
		printf("La pila esta llena\n");
		
	if(push(p,1))
		printf("Elemento ingresado\n");	
	else
		printf("La pila esta llena\n");
		
	if(!is_empty(*p)) //sino está vacía
	{
		//int dato=pop(p); 
		//printf("El dato que sale: %d", dato); //indica el ultimo dato tiene que ser el uno
		printf("El dato que sale: %d\n", pop(p));
		printf("El dato que sale: %d\n", pop(p));
		printf("El dato que sale: %d\n", pop(p));
	}
		
	return 0;
	
}