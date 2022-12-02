#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo
{
	int info;
	struct nodo *sig;
};

struct nodo *raiz = NULL;
struct nodo *fondo = NULL;

int vacia()
{
	if(raiz==NULL)
		return 1;
	else
		return 0; 
}

void insertar(int x)
{
	struct nodo *nuevo;
	nuevo=malloc(sizeof(struct nodo));
	nuevo->info=x;
	nuevo->sig=NULL;
	if(vacia())
	{
		raiz = nuevo;
		fondo=nuevo;
	}
	else
	{
		fondo->sig = nuevo;
		fondo = nuevo;
	}
}

