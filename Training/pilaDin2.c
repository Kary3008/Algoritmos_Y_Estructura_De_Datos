#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct nodo {
    int info;
    struct nodo *sig;
};

//variable global que apunta al primer nodo de la lista
struct nodo *raiz=NULL;

void insertar(int x)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info = x;
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
    printf("Lista completa.\n");
    while (reco!=NULL)
    {
        printf("%i ",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}

int extraer()
{
    if (raiz != NULL)
    {
        int informacion = raiz->info;
        struct nodo *bor = raiz;
        raiz = raiz->sig;
        free(bor);
        return informacion;
    }
    else
    {
        return -1;
    }
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

int cantidad()
{
    struct nodo *reco = raiz; //inicializa en raiz
    int cant = 0;
    while (reco != NULL) //mientras sea diferente de NULL
    {
        cant++; //incrementar cant
        reco = reco->sig; //avanzar el puntero a sig
    }
    return cant; //cantidad de nodos
}

int vacia() //si la pila está vacía
{
    if (raiz == NULL) //raíz es igual a NULL
        return 1; //retorna un 1
    else
        return 0; //retorna 0 que no está vacía.
}



int main()
{
	if(vacia()==1)
		printf("La pila esta vacia\n");
	else
		printf("La pila no esta vacia\n");
		
    insertar(10);
    insertar(40);
    insertar(3);
    
    if(vacia()==1)
		printf("La pila esta vacia\n");
	else
		printf("La pila no esta vacia\n");
		
    imprimir();
    printf("La cantidad de nodos de la pila es:%i\n",cantidad());
    printf("Extraemos de la pila:%i\n",extraer());
    imprimir();
    printf("La cantidad de nodos de la pila es:%i\n",cantidad());
    while (vacia() == 0) //mientras vacia sea igual a 0, va a extraer los nodos de la lista
    {
        printf("Extraemos de la pila:%i\n",extraer());
    }
    //imprimir();
    liberar();
    if(vacia()==1){
	
		printf("La pila esta vacia\n");
		printf("La cantidad de nodos de la pila es:%i\n",cantidad()); }
	else{
	
		printf("La pila no esta vacia\n");
		printf("La cantidad de nodos de la pila es:%i\n",cantidad()); }
    getch();
    return 0;
}