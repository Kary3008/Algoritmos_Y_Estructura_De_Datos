#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
	int valor;
	struct Nodo* sig;
} Nodo;

typedef struct Pila {
	int tam;
	struct Nodo* cima;
} Pila;

Pila* crear_Pila();
void push(Pila* pila, int valor);
void imprimir(Pila* pila);

int main()
{
	Pila* pila = crear_Pila();
	push(pila, 15);
	push(pila, 20);
	push(pila, 25);
	imprimir(pila);
	
}

Pila* crear_Pila()
{
	Pila* pila = (Pila*)malloc(sizeof(Pila));
	pila->tam  = 0;
	pila->cima = NULL;
}

void push(Pila* pila, int valor)
{
	Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
	nodo->valor = valor;
	if(pila->tam == 0)
	{
		nodo->sig = NULL;
		pila->cima = nodo;
	} else
	{
		nodo->sig = pila->cima;
		pila->cima = nodo;
	}
	pila->tam = pila->tam+1;
}

void imprimir(Pila* pila)
{
	//imprimir valores
	struct Nodo* actual= pila->cima;
	while(actual != NULL)
	{
		printf("valor: %d\n", actual->valor);
		actual = actual->sig;
	}
}