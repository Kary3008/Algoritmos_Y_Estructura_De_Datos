#include<stdio.h>
#define true 1
#define false 0
#define max 30

typedef struct 
{
	short int tope; //último elemento que entra
	short int vector[max];
} stack;

void CrearPila(stack *Pila)
{
	Pila->tope = -1;
}

int vacia(stack *Pila)
{
	if(Pila->tope == -1)
		return true;
	else
		return false;
}

int Llena(stack *Pila)
{
	if(Pila->tope == max - 1)
		return true;
	else
		return false;
}

void add(stack *Pila, int n)
{
	if(!Llena(Pila))
	{
		Pila->tope++;
		Pila->vector[Pila->tope] = n;
		printf("Se ha metido  el elemento: %i\n", Pila->vector[Pila->tope]);
	}
	else
		printf("La pila esta llena");
}

//elimina cuando no está vacía
void Del(stack *Pila)
{
	if(!vacia(Pila))
	{
		int tmp = Pila->tope;
		Pila->tope--;
		printf("Se extrajo el elemento %i \n", Pila->vector[tmp]);
	}
}

int ultimo(stack *Pila)
{
	//if(!vacia(Pila))
		return Pila->vector[Pila->tope];
	//else 
	//{
	//	printf("Error, la pila esta vacia");
		//return false;
	//}
}

int main()
{
	stack Pila;
	CrearPila(&Pila);
	add(&Pila, 5);
	add(&Pila, 10);
	add(&Pila, 8);
	add(&Pila, 12);
	
	printf("Ultimo: %i \n", ultimo(&Pila));
	
	Del(&Pila);
	printf("Ultimo: %i \n", ultimo(&Pila));
	Del(&Pila);
	printf("Ultimo: %i \n", ultimo(&Pila));
	Del(&Pila);
	printf("Ultimo: %i \n", ultimo(&Pila));
	Del(&Pila);
	printf("Ultimo: %i \n", ultimo(&Pila));
	
		
	return true;
}

