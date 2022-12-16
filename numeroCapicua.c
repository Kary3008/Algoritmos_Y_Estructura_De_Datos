#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ESTRUCTURAS
typedef struct num
{
    char capicua[10];
} Num;

typedef struct nodo
{
    Num *dato; //informacion
    struct nodo *sig; //apunta al otro nodo
} Nodo;

typedef struct pila
{
    Nodo *tope;
    int total;
} Pila;

//FUNCIONES
Num* crearNum(char capicua[10]);
Nodo* crearNodo(Num *num);
Pila* crearPila();
int isEmpty(Pila *pila);
void push(Pila *pila, Nodo *nodo); //nodo
void show(Pila *pila);
Nodo* pop(Pila *pila);
void vaciarPila(Pila *pila);


int main()
{

    //Pila *p;
    //Nodo *aux;
    //p = crearPila();

    char *numeroC = "1234321";
    int a, b;
    a = strlen(numeroC);
    char capi[a];

    Pila *p;
    Nodo *aux;
    p = crearPila();

    push(p, crearNodo(crearNum(numeroC)));
    
    //int a, b;
    //a = strlen(numeroC), b = 0;
    //char capicua[a];

    if(strcmp(numeroC, capi) == 0)
		printf("Es un numero capicua\n");
	else
		printf("No es un numero capicua\n");    
    

    /*while (a != 0)
    {
        b = a%10;
        a = a/10;
        c = c*10 + b;
    }
    if(c == a)
        printf("El numero es capicua\n");
    else    
        printf("El numero no es capicua\n");*/
    
    

    push(p, crearNodo(crearNum("D3008")));
    show(p);
    printf("\n\n");
    aux = pop(p);
    printf("El nodo que salio de la pila es: %s\n", aux->dato->capicua);
    free(aux); //liberar memoria
    show(p);
    vaciarPila(p);
    show(p);
    return 0;
}

Num* crearNum(char capicua[10])
{
    Num *aux = (Num*)malloc(sizeof(Num)); //tamaño
    strcpy(aux->capicua, capicua);
    //aux->modelo = modelo;
    return aux;
}

Nodo* crearNodo(Num *num)
{
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = num;
    aux->sig = NULL;
    return aux;
}

Pila* crearPila()
{
    Pila *aux = (Pila*)malloc(sizeof(Pila));
    aux->tope = NULL;
    aux->total = 0;

    return aux;
}

int isEmpty(Pila *pila)
{
    if(pila->total == 0)
        return 1;
    else 
        return 0;
}

void push(Pila *pila, Nodo *aux)
{
    if(isEmpty(pila))
    {
        pila->tope = aux;
    }
    else
    {
        aux->sig = pila->tope;
        pila->tope = aux;
    }
    pila->total++;
}

void show(Pila *pila)
{
    Nodo *aux = pila->tope;
    Num *c;
    if(!isEmpty(pila))
    {
        while(aux != NULL)
        {
            c = aux->dato;
            printf("El nodo en la pila es: %s\n", c->capicua);
            aux = aux->sig;
        }
    }
    else
        printf("La pila esta vacia");
}

Nodo* pop(Pila *pila)
{
    Nodo *aux = NULL;
    if(!isEmpty(pila))
    {
        aux = pila->tope;
        pila->tope = pila->tope->sig; //eliminar un nodo
        pila->total--;  
    }
       return aux;
}

void vaciarPila(Pila *pila)
{
    Nodo *aux;
    aux = pop(pila);
    while (aux != NULL)
    {
        free(aux);
        aux = pop(pila);
    }
}
