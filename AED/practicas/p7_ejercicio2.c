#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la lista simplemente enlazada
typedef struct Nodo {
    int data;
    struct Nodo* sig;
} Nodo;

// Definición de la estructura de un nodo de la lista doblemente enlazada
typedef struct DNodo {
    int data;
    struct DNodo* ant;
    struct DNodo* sig;
} DNodo;

// Función para insertar un nodo al final de una lista simplemente enlazada
void insertarNodo(Nodo** nodo, int data) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = data;
    nuevoNodo->sig = NULL;

    if (*nodo == NULL) {
        *nodo = nuevoNodo;
    } else {
        Nodo* actual = *nodo;
        while (actual->sig != NULL) {
            actual = actual->sig;
        }
        actual->sig = nuevoNodo;
    }
}

// Función para insertar un nodo al final de una lista doblemente enlazada
void insertarNodoD(DNodo** nodo, int data) {
    DNodo* nuevoNodo = (DNodo*)malloc(sizeof(DNodo));
    nuevoNodo->data = data;
    nuevoNodo->ant = NULL;
    nuevoNodo->sig = NULL;

    if (*nodo == NULL) {
        *nodo = nuevoNodo;
    } else {
        DNodo* actual = *nodo;
        while (actual->sig != NULL) {
            actual = actual->sig;
        }
        actual->sig = nuevoNodo;
        nuevoNodo->ant = actual;
    }
}

// Función para eliminar un nodo de una lista simplemente enlazada
void eliminarNodo(Nodo** nodo, Nodo* borrarNodo) {
    if (*nodo == NULL || borrarNodo == NULL) {
        return;
    }

    if (*nodo == borrarNodo) {
        *nodo = borrarNodo->sig;
    } else {
        Nodo* actual = *nodo;
        while (actual->sig != NULL && actual->sig != borrarNodo) {
            actual = actual->sig;
        }
        if (actual->sig != NULL) {
            actual->sig = borrarNodo->sig;
        }
    }

    free(borrarNodo);
}

// Función para mezclar las dos listas simplemente enlazadas y eliminar duplicados
DNodo* mezclarListas(Nodo* l1, Nodo* l2) {
    DNodo* mezclar = NULL;
    Nodo* act1 = l1;
    Nodo* act2 = l2;

    while (act1 != NULL && act2 != NULL) {
        if (act1->data < act2->data) {
            insertarNodoD(&mezclar, act1->data);
            act1 = act1->sig;
        } else if (act2->data < act1->data) {
            insertarNodoD(&mezclar, act2->data);
            act2 = act2->sig;
        } else { // Los nodos tienen el mismo valor, se elimina uno de ellos
            act2 = act2->sig;
        }
    }

    // Agregar los nodos restantes de la primera lista
    while (act1 != NULL) {
        insertarNodoD(&mezclar, act1->data);
        act1 = act1->sig;
    }

    // Agregar los nodos restantes de la segunda lista
    while (act2 != NULL) {
        insertarNodoD(&mezclar, act2->data);
        act2 = act2->sig;
    }

    return mezclar;
}

// Función para imprimir una lista doblemente enlazada
void imprimirListaD(DNodo* nodo) {
    DNodo* act = nodo;
    while (act != NULL) {
        printf("%d", act->data);
        if (act->sig != NULL) {
            printf(" <-> ");
        } else {
            printf(" -> NULL");
        }
        act = act->sig;
    }
}

int main() {
    // Crear las listas simplemente enlazadas ordenadas
    Nodo* lista1 = NULL;
    insertarNodo(&lista1, 1);
    insertarNodo(&lista1, 2);
    insertarNodo(&lista1, 2);

    Nodo* lista2 = NULL;
    insertarNodo(&lista2, 1);
    insertarNodo(&lista2, 7);
    insertarNodo(&lista2, 9);

    // Mezclar las listas
    mezclarListas(lista1, lista2);
    imprimirListaD(mezclarListas(lista1, lista2));
}