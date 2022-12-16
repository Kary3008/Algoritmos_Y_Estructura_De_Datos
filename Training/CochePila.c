#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ESTRUCTURAS
typedef struct coche
{
    char matricula[10];
    int modelo;
    int color;
    int marca;
} Coche;

typedef struct nodo
{
    Coche *dato; //informacion
    struct nodo *sig; //apunta al otro nodo
} Nodo;

typedef struct pila
{
    Nodo *tope;
    int total;
} Pila;

Coche* crearCoche(char matricula[10], int modelo, int color, int marca)
{
    Coche *aux = (Coche*)malloc(sizeof(Coche)); //tamaño
    strcpy(aux->matricula, matricula);
    aux->modelo = modelo;
    aux->color = color;
    aux->marca = marca;
    return aux;
}

Nodo* crearNodo(Coche *coche);
Pila* crearPila();
int isEmpty(Pila *pila);
void push(Pila *pila, Nodo *nodo); //nodo
void show(Pila *pila);
Nodo* pop(Pila *pila);
void vaciarPila(Pila *pila);

//FUNCIONES
int main()
{
    Pila *p;
    Nodo *aux;
    //Coche *c1;
    //Nodo *n;
    p = crearPila();
    //c1 = crearCoche("AB1", 2022, 1, 1);
    //n = crearNodo(c1);
    //push(p, n); //ingresa el primer nodo AB1
    push(p, crearNodo(crearCoche("CD9", 2022, 2, 1)));
    push(p, crearNodo(crearCoche("D3008", 2021, 1, 1)));
    show(p);
    printf("\n\n");
    //pop(p);
    aux = pop(p);
    printf("El nodo que salio de la pila es: %s\n", aux->dato->matricula);
    free(aux); //liberar memoria
    show(p);
    vaciarPila(p);
    show(p);
    return 0;
}

Nodo* crearNodo(Coche *coche)
{
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = coche;
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
    Coche *c;
    if(!isEmpty(pila))
    {
        while(aux != NULL)
        {
            c = aux->dato;
            printf("%s %d %d % d \n", c->matricula, c->modelo, c->color, c->marca);
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
