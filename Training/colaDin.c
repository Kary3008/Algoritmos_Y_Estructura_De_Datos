#include <stdio.h>
#include <stdlib.h>

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
		return 1;
	else 
		return 0;
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
		return -1;
	}
}

//Recorrer la cola
void imprimir()
{
	struct nodo *reco=primer;
	printf("Listado completo de la Cola\n");
	while(reco!=NULL)
	{
		printf("%i", reco->dato);
		reco=reco->siguiente;
	}
	printf("\n");
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
	printf("Menú\n");
	printf("\n1.Ingresar un elemento en la cola.");
	printf("\n2.Extraer un elemento en la cola.");
	printf("\n3.Recorrer y listar la cola.");
	printf("\n0.Salir.");
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
			printf("Ingrese un numero para la cola: ");
			scanf("%d", &info);
			insertar(info);
			imprimir();
		}
		if(opc == 2)
		{
			printf("Extraer el elemento %d de la cola: ", extraer());
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