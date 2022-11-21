#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

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
void Formula(char *formula);
int verificarBalanceo(char * formula);

int main()
{
	char formula[100];
	
	//formula[100]={'[1+(2*4)]'};
	Formula(formula);
	
	if(verificarBalanceo(formula))
		printf("La formula si esta equilibrida");
	else
		printf("La formula no esta equilibrada");
		//printf("Form en", formula);
	
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

void Formula(char *formula)
{
	printf("Ingrese la formula: ");
	gets(formula);
}

int verificarBalanceo(char *formula)
{
	int f;
	for(f = 0; f < strlen(formula); f++)
	{
		if(formula[f] == '(' || formula[f] == '[' || formula[f] == '{') 
			push(formula[f]);
		else
		{
			if(formula[f] == ')')
			{
				if(extraer() != '(')
					return 0;
			}
			else
			{
				if(formula[f] == ']')
				{
					if(extraer() != '[')
						return 0;
				}
				else
				{
					if(formula[f] == '}')
					{
						if(extraer() != '{')
							return 0;
					}	
				}
			}
		}
	}
	if(is_empty())
		return 1;
	else
		return 0;
}
