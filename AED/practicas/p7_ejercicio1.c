#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int data;
    struct Nodo* ant;
    struct Nodo* sig;
} Nodo;

Nodo* crearNodo(int data) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = data;
    nuevoNodo->ant = NULL;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final de la lista
void insertarNodo(Nodo** nodo, int data) {
    Nodo* nuevoNodo = crearNodo(data);
    if (*nodo == NULL) {
        *nodo = nuevoNodo;
    } else {
        Nodo* aux = *nodo;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevoNodo;
        nuevoNodo->ant = aux;
    }
}

// Función para invertir el contenido de la lista
void invertirLista(Nodo** nodo) {
    if (*nodo == NULL || (*nodo)->sig == NULL) {
        return;
    }
    
    Nodo* actual = *nodo;
    Nodo* aux = NULL;
    
    while (actual != NULL) {
        aux = actual->ant;
        actual->ant = actual->sig;
        actual->sig = aux;
        actual = actual->ant;
    }
    
    if (aux != NULL) {
        *nodo = aux->ant;
    }
}

// Función para imprimir la lista en orden
void imprimeLista(Nodo* nodo) {
    if (nodo == NULL) {
        printf("Lista vacia\n");
        return;
    }
    
    while (nodo != NULL) {
        printf("%d ", nodo->data);
        nodo = nodo->sig;
    }
    printf("\n");
}

void main() {
    Nodo* nodo = NULL;
    
    insertarNodo(&nodo, 1);
    insertarNodo(&nodo, 2);
    insertarNodo(&nodo, 3);
    insertarNodo(&nodo, 4);
    
    printf("Lista original: ");
    imprimeLista(nodo);
    
    invertirLista(&nodo);
    
    printf("Lista invertida: ");
    imprimeLista(nodo);
}
