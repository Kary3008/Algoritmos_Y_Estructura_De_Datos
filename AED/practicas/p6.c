#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Nodo
{
    char nombre[50];
    struct Nodo* sig;
} Nodo;


typedef struct Bicola
{
    Nodo* izq;
    Nodo* der;
} Bicola;

void inicializarBicola(Bicola* bicola);
void ingresarPorDer(Bicola* bicola, char nombre[]);
void ingresarPorIzq(Bicola* bicola, char nombre[]);
void mostrarPrimerNodo(Bicola bicola);
void mostrarTodosNodos(Bicola bicola);
int contarNodos(Bicola bicola);
void eliminarPrimerNodo(Bicola* bicola);
void eliminarBicola(Bicola* bicola);
void enviarArchivos(Bicola* bicola);


void main()
{
    Bicola bicola;
    int opc;
    char archivo[50];
    
    inicializarBicola(&bicola);

    do{
        printf("1. Ingresar archivo por derecha.\n");
        printf("2. Ingresar archivo por izquierda.\n");
        printf("3. Mostrar primer nodo.\n");
        printf("4. Mostrar todos los nodos.\n");
        printf("5. Contar todos los nodos.\n");
        printf("6. Eliminar primer nodo.\n");
        printf("7. Eliminar bicola.\n");
        printf("8. Salir.\n");
        printf("ELIGE UNA OPCION:");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
                printf("Ingrese el nombre del archivo a ingresar: ");
                scanf("%s", archivo);
                ingresarPorDer(&bicola, archivo);
            break;
        case 2:
                printf("Ingrese el nombre del archivo a ingresar: ");
                scanf("%s", archivo);
                ingresarPorIzq(&bicola, archivo);
            break;
        case 3:
                mostrarPrimerNodo(bicola);
            break;
        case 4:a
                mostrarTodosNodos(bicola);
            break;
        case 5:
                printf("Numero de nodos: %d\n", contarNodos(bicola));
            break;
        case 6:
                eliminarPrimerNodo(&bicola);
            break;
        case 7:
                eliminarBicola(&bicola);
            break;
        case 8:
                eliminarBicola(&bicola);
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
    } while (opc != 8);

    
    enviarArchivos(&bicola);
}


void inicializarBicola(Bicola* bicola)
{
    bicola->izq=NULL;
    bicola->der=NULL;
}

void ingresarPorDer(Bicola* bicola, char nombre[])
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->sig = NULL;

    if(bicola->izq == NULL)
        bicola->izq = nuevoNodo;
    if(bicola->der != NULL)
        bicola->der->sig = nuevoNodo;
    
    bicola->der = nuevoNodo;
}

void ingresarPorIzq(Bicola* bicola, char nombre[])
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->sig = bicola->izq;
    if(bicola->der == NULL)
        bicola->der = nuevoNodo;
    
    bicola->izq = nuevoNodo;
}

void mostrarPrimerNodo(Bicola bicola)
{
    if(bicola.izq != NULL)
        printf("Primer nodo%s\n", bicola.izq->nombre);
    else
        printf("La bicola esta vacia\n");
}

void mostrarTodosNodos(Bicola bicola)
{
    Nodo* nodoActual = bicola.izq;

    while(nodoActual != NULL)
    {
        printf("%s\n", nodoActual->nombre);
        nodoActual = nodoActual->sig;
    }
}

int contarNodos(Bicola bicola)
{
    int cont = 0;
    Nodo* nodoActual = bicola.izq;
    while(nodoActual != NULL)
    {
        cont++;
        nodoActual = nodoActual->sig;
    }
    return cont;
}

void eliminarPrimerNodo(Bicola* bicola)
{
    if(bicola->izq != NULL)
    {
        Nodo* eliminarNodo = bicola->izq;
        bicola->izq = bicola->izq->sig;

        if(bicola->der == eliminarNodo)
            bicola->der = NULL;

        free(eliminarNodo);
    }
}

void eliminarBicola(Bicola* bicola)
{
    while(bicola->izq != NULL)
    {
        eliminarPrimerNodo(bicola);
    }

    bicola->der = NULL;
}

void enviarArchivos(Bicola* bicola) {
    while (contarNodos(*bicola) > 0) {
        if (bicola->izq != NULL) {
            printf("Enviando archivo: %s\n", bicola->izq->nombre);
            printf("Exito\n");
            eliminarPrimerNodo(bicola);
        } else {
            printf("Nada que enviar\n");
        }
        sleep(3);
    }
}