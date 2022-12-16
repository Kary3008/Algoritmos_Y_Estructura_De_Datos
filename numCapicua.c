#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
#define maxSize 10

typedef struct 
{
	int tope; //último elemento que entra
	int num[maxSize];
} stack;

void CrearPila(stack *Pila);
int isEmpty(stack *Pila);
int isFull(stack *Pila);
void add(stack *Pila, int n);
void Delete(stack *Pila);
int ultimo(stack *Pila);


int main()
{
	char *numeroC = "1234321";
	
	int x = 0, l = strlen(numeroC), y = 0;
	char capicua[l];
	
	stack Pila;
	CrearPila(&Pila);
	
	for(x = 0; x < l; x++)
	{
		add(&Pila, numeroC[x]);
	}
	
	while(!isEmpty(&Pila))
	{
		capicua[y] = Pila.num[Pila.tope];
		y++;
		Delete(&Pila);
	}
	
	if(strcmp(numeroC, capicua) == 0)
		printf("Es un numero capicua");
	else
		printf("No es un numero capicua");
			
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
	if(Pila->tope == maxSize - 1)
		return true;
	else
		return false;
}

void add(stack *Pila, int n)
{
	if(!isFull(Pila))
	{
		Pila->tope++;
		Pila->num[Pila->tope] = n;
		printf("Se ha metido  el elemento: %c\n", Pila->num[Pila->tope]);
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
		printf("Se extrajo el elemento %c \n", Pila->num[tmp]);
	}
}

int ultimo(stack *Pila)
{
		return Pila->num[Pila->tope];
}