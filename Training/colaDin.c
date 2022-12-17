#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//estructura de la cola
struct nodo
{
	int dato;
	struct nodo *siguiente;
};

struct nodo *primer = NULL;
struct nodo *ultimo = NULL;

// saber si la cola está vacía
int vacia()
{
	if(primer == NULL)
		return true;
	else 
		return false;
}

/*insertar elemento en la cola*/
void insertar(int x)
{
	struct nodo *nuevo;
	nuevo = malloc(sizeof(struct nodo));
	nuevo->dato=x;
	nuevo->siguiente=NULL;
	if(vacia())
	{
		primer=nuevo;
		ultimo=nuevo;
	}
	else
	{
		ultimo->siguiente=nuevo;
		ultimo=nuevo;
	}
}

//extraer elemento de la cola
int extraer()
{
	if(!vacia())
	{
		int informacion=primer->dato;
		struct nodo *aux=primer;
		if(primer==ultimo)
		{
			primer=NULL;
			ultimo=NULL;
		}
		else
		{
			primer=primer->siguiente;
		}
		free(aux);
		return informacion;
	}
	else
	{
		printf("\nUnderflow\n");
		return -1;
	}
}

//Recorrer la cola
void imprimir()
{
	struct nodo *reco=primer;
	if(!vacia())
	{
		printf("\nListado completo de la Cola\n");
		while(reco!=NULL)
		{
			printf("%i\n", reco->dato);
			reco=reco->siguiente;
		}
		printf("\n");
	}
	else
		printf("\nLa pila esta vacia\n");
}

//liberar elementos de la Cola
void liberar()
{
	struct nodo *reco=primer;
	struct nodo *aux;
	while(reco!=NULL)
	{
		aux=reco;
		reco=reco->siguiente;
		free(aux);
	}
}

//menu
int menu()
{
	int op;
	printf("\t\nMenu\n\n");
	printf("\n1.Ingresar un elemento en la cola.");
	printf("\n2.Extraer un elemento en la cola.");
	printf("\n3.Recorrer y listar la cola.");
	printf("\n0.Salir.\n");
	printf("Ingrese la opcion: ");
	scanf("%d", &op);
	return op;
}

int main()
{
	int opc, info;
	opc=menu();
	while(opc!=0)
	{
		if(opc==1)
		{
			printf("\nIngrese un numero para la cola: ");
			scanf("%d", &info);
			insertar(info);
			imprimir();
		}
		if(opc == 2)
		{
			printf("\nExtraer el elemento %d de la cola\n", extraer());
			imprimir();
		}
		if(opc == 3)
		{
			imprimir();
		}
		opc=menu();
	}
	liberar();
	
	return 0;
}