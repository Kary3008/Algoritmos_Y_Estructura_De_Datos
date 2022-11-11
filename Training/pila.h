#include <stdlib.h>
#define maxSize 10 //definir constante, elementos que tendrá la pila

typedef struct pila 
{
	int indice;
	int total;
	int datos[maxSize]; //arreglo de datos
}Pila;
int is_empty(Pila pila);
 /* PILA *CREAR( )
 1. Apartar espacio para la Pila.
 2. Inicializar los atributos.
 3. Retornar la referencia a la Pila.
 */
Pila *crear()
{
	Pila * p;
	p = (Pila *)malloc(sizeof(Pila)); //casting a Pila (Pila *)
	p->indice=0; //su índice va a valer 0
	p->total=0; //se maneja con flecha para tipo apuntador
	return p;
}

int is_empty(Pila pila) //verifica si la pila está vacía
{
	if(pila.total==0)
		return 1;
	else
		return 0;
}

int is_full(Pila pila)
{
	if(pila.total==maxSize) //cuando el total coincide con el máximo de elementos
	//es porque la pila está llena.
	return 1;
	else 
	return 0;
}