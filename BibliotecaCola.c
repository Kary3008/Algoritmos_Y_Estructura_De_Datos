#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct nodo {
    int info;
    struct nodo *sig;
};

struct nodo *raiz=NULL;
struct nodo *fondo=NULL;

int vacia();
void insertar(int x);
int extraer();
void imprimir();
void liberar();

void main()
{
    insertar(5);
    insertar(10);
    insertar(50);
    imprimir();
    printf("Extraemos uno de la cola: %i\n", extraer());
    imprimir();
    liberar();
    getch();
    return 0;
}

int vacia()
{
    if (raiz == NULL)
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
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else
    {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

int extraer()
{
    if (!vacia())
    {
        int informacion = raiz->info;
        struct nodo *bor = raiz;
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else
        {
            raiz = raiz->sig;
        }
        free(bor);
        return informacion;
    }
    else
        return -1;
}

void imprimir()
{
    struct nodo *reco = raiz;
    printf("Listado de todos los elementos de la cola.\n");
    while (reco != NULL)
    {
        printf("%i - ", reco->info);
        reco = reco->sig;
    }
    printf("\n");
}


void liberar()
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