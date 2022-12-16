#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
#define max 30

typedef struct 
{
	int tope; //último elemento que entra
	char vector[max];
} stack;

void CrearPila(stack *Pila);
int isEmpty(stack *Pila);
int isFull(stack *Pila);
void add(stack *Pila, char n);
void Delete(stack *Pila);
int ultimo(stack *Pila);


int main()
{
	char *palabra = "natan";
	
	int x = 0, l = strlen(palabra), y = 0;
	char paludismo[l];
	
	stack Pila;
	CrearPila(&Pila);
	
	for(x = 0; x < l; x++)
	{
		add(&Pila, palabra[x]);
	}
	
	while(!isEmpty(&Pila))
	{
		paludismo[y] = Pila.vector[Pila.tope];
		y++;
		Delete(&Pila);
	}
	
	if(strcmp(palabra, paludismo) == 0)
		printf("Si es palindromo");
	else
		printf("No es palindromo");
			
	return true;
}

void CrearPila(stack *Pila)
{
	Pila->tope = -1;
}

int isEmpty(stack *Pila)
{
	if(Pila->tope == -1)
		return true;
	else
		return false;
}

int isFull(stack *Pila)
{
	if(Pila->tope == max - 1)
		return true;
	else
		return false;
}

void add(stack *Pila, char n)
{
	if(!isFull(Pila))
	{
		Pila->tope++;
		Pila->vector[Pila->tope] = n;
		printf("Se ha metido  el elemento: %c\n", Pila->vector[Pila->tope]);
	}
	else
		printf("La pila esta llena");
}

//elimina cuando no está vacía
void Delete(stack *Pila)
{
	if(!isEmpty(Pila))
	{
		int tmp = Pila->tope;
		Pila->tope--;
		printf("Se extrajo el elemento %c \n", Pila->vector[tmp]);
	}
}

int ultimo(stack *Pila)
{
		return Pila->vector[Pila->tope];
}

