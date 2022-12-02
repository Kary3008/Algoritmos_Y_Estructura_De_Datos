#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct nodo {
    char elemento;
    struct nodo *sig;
};

//variable global que apunta al primer nodo de la lista
struct nodo *raiz=NULL;
//FUNCIONES
void push(char x);
void imprimir();
char extraer();
void delet();
//int cantidad();
int is_empty();
void Formula(char *formula);
int verificarBalanceo(char * formula);

//PRINCIPAL
int main()
{
	char formula[100];
	
	//formula[100]={'[1+(2*4)]'};
	Formula(formula);
	
	if(verificarBalanceo(formula))
		printf("La formula si esta equilibrida\n");
	else
		printf("La formula no esta equilibrada\n");
		//printf("Form en", formula);
	imprimir();
	delet();
	getch();
	return 0;
	
	/*if(is_empty()==1)
		printf("La pila esta vacia\n");
	else
		printf("La pila no esta vacia\n");
		
    push(10);
    push(40);
    push(3);
    
    if(is_empty()==1)
		printf("La pila esta vacia\n");
	else
		printf("La pila no esta vacia\n");
		
    imprimir();
    //printf("La cantidad de nodos de la pila es:%i\n",cantidad());
    printf("Extraemos de la pila:%i\n",extraer());
    imprimir();
    //printf("La cantidad de nodos de la pila es:%i\n",cantidad());
    while (is_empty() == 0) //mientras vacia sea igual a 0, va a extraer los nodos de la lista
    {
        printf("Extraemos de la pila:%i\n",extraer());
    }
    //imprimir();
    delet();
    if(is_empty()==1)
	
		printf("La pila esta vacia\n");
		//printf("La cantidad de nodos de la pila es:%i\n",cantidad()); }
	else
	
		printf("La pila no esta vacia\n");
		//printf("La cantidad de nodos de la pila es:%i\n",cantidad()); }
    getch();
    return 0;*/
}

void push(char x)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->elemento = x;
    if (raiz == NULL)
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

void imprimir()
{
    struct nodo *reco=raiz;
    printf("\nFormula: ");
    for(f = 0; f < strlen(formula); f++)
    {
    	printf("%c", reco->elemento);	
	}
   /* while (reco!=NULL)
    {
    	
        printf("%c", reco->elemento);
        reco=reco->sig;
    }*/
    printf("\n");
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

void delet()
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

/*int cantidad()
{
    struct nodo *reco = raiz; //inicializa en raiz
    int cant = 0;
    while (reco != NULL) //mientras sea diferente de NULL
    {
        cant++; //incrementar cant
        reco = reco->sig; //avanzar el puntero a sig
    }
    return cant; //cantidad de nodos
}*/

int is_empty() //si la pila está vacía
{
    if (raiz == NULL) //raíz es igual a NULL
        return 1; //retorna un 1
    else
        return 0; //retorna 0 que no está vacía.
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

