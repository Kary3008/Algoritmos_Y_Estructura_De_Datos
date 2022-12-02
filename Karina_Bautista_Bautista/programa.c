#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define maxSize 10

struct nodo
{
char elemento;
struct nodo *sig;
};

struct nodo *raiz = NULL;
//funciones
void push(char x);
char extraer();
void clean();
int is_empty();
void Frase(char *frase);
int verificar(char *frase);
//char frase1(char *frase);
//char frase2(char *frase);

int main()
{
	char frase[maxSize];
	
	Frase(frase);
	
	int f;
	char frase1, frase2;
	push(frase[f]);
	
		for(f = 0; f <= maxSize; f++){
			printf("%c", frase[f]);
		}
		frase1 = frase[f];
		
		int i=0;
		int j;
		
		push(frase[i]);
	
		while(frase[i] != '\0')
		{
			i++;
		}
		for(j = i-1; j >= 0; j--)
		{
			printf("%c", frase[j]);
			frase2 = frase[j];
		}
		for(f = 0; f < strlen(frase); f++)
		{
			if(frase1 != frase2)
				printf("\nNo es un palindromo");
			else
				printf("\nEs un palindromo");
		}
	
	clean();
	getch();
	return 0;
}

void push(char x)
{
	struct nodo *nuevo;
	nuevo = malloc(sizeof(struct nodo));
	nuevo->elemento = x;
	if(raiz == NULL)
	{
		raiz = nuevo;
		nuevo->sig = NULL;
	}
	else
	{
		nuevo->sig = raiz;
		raiz = nuevo;
	}
}

char extraer()
{
	if (raiz != NULL)
	{
		char informacion = raiz->elemento;
		struct nodo *bor = raiz;
		raiz = raiz->sig;
		free(bor);
		return informacion;
	}
	else
		return -1;
}

void clean()
{
	struct nodo *reco = raiz;
	struct nodo *bor;
	while (reco != NULL)
	{
		bor = reco;
		reco = reco->sig;
		free(bor);
	}
}

int is_empty()
{
	if(raiz == NULL)
		return 1;
	else 
		return 0;
}

void Frase(char *frase)
{
	printf("Ingrese la Frase: ");
	gets(frase);
}
/*
char frase1(char *frase)
{ 	
	int f;
	push(frase[f]);
	
		for(int f=0; f < maxSize; f++){
			printf("%c", frase[f]);
		}
}

char frase2(char *frase)
{
		int i=0;
		int j;
		push(frase[i]);
	
		while(frase[i]!= '\0')
		{
			i++;
		}
		for(j = i-1 ; j >= 0; j--)
		{
			printf("%c", frase[j]);
		}	
}*/

int verificar(char *frase)
{
	int f;
	for(f = 0; f < strlen(frase); f++)
	{
		if(frase[f] != is_empty())		
			push(frase[f]);
		
		int i=0;
		int j;
	
		for(f = 0; f < maxSize; f++){
			printf("%c", frase[f]);
		}
		//frase1 = frase[f];
	
		printf("\n\n");
	
		while(frase[i]!= '\0')
		{
			i++;
		}
		for(j = i-1 ; j >= 0; j--)
		{
			printf("%c", frase[j]);
		}
		
	}
		
	if(is_empty())
		return 1;
	else
		return 0;
}
