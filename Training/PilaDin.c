#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct nodo {
    int info; //datos de información
    struct nodo *sig; //puntero que apunta a otro registro
};

//variable global que apunta al primer nodo de la lista
struct nodo *raiz=NULL; //raiz de tipo struct nodo, si tiene null la pila está vacía

void insertar(int x);
void imprimir();
int extraer();
void liberar();

int main()
{
    insertar(10);
    insertar(40);
    insertar(5);
    insertar(3);
    imprimir();
    printf("Extraemos de la pila:%i\n",extraer());
    imprimir();
    liberar();
    getch();
    return 0;
}

//INSERTAR 
void insertar(int x)
{
    struct nodo *nuevo; //definir un puntero de tipo nodo
    nuevo = malloc(sizeof(struct nodo)); //reservar espacio -- sizeof devuelve cuantos bytes requiere de memoria
    nuevo->info = x; //guardar la información del nodo
    if (raiz == NULL) 
    {
        raiz = nuevo; //raiz apunta al nodo que acabamos de crear
        nuevo->sig = NULL; 
    }
    else //como ya hay una raíz apuntado al nodo pasa al else
    {
        nuevo->sig = raiz; 
        raiz = nuevo; //raiz deja de apuntar al nodo que está apuntado actualmente
        //apunta al nodo que se acaba de insertar
    }
}

void imprimir()
{
    struct nodo *reco=raiz; //un puntero que lo inicializamos con raiz
    printf("Lista completa.\n");
    while (reco!=NULL) //mientras reco sea distinto a NULL
    {
        printf("%i ",reco->info); //imprime info
        reco=reco->sig; //y se modifica con el siguiente nodo
    }
    printf("\n");
}

int extraer()
{
    if (raiz != NULL) //si la raiz no está vacía
    {
        int informacion = raiz->info; //se guarda en una variable local la información del primer nodo
        struct nodo *bor = raiz; //puntero auxiliar para borrar la raiz
        raiz = raiz->sig;
        free(bor); //libera espacio que no va a utilizar
        return informacion; //retorna la informacion
    }
    else
    {
        return -1; //si está vacía retorna un -1
    }
}

//Liberar los elementos que tengo en la lista e irlos eliminandi
void liberar()
{
    struct nodo *reco = raiz; //se inicializa con el primer nodo de la lista
    struct nodo *bor; 
    while (reco != NULL) //mientras sea diferente de NULL
    {
        bor = reco; //bor apunta a siguiente
        reco = reco->sig; //reco lo avanza con siguiente, hasta que sea NULL
        free(bor); //liberamos el que está siendo apuntado por bor
    }
}