#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo {
    int valor; // O char valor; si sólo aceptamos caracteres
    struct Nodo* sig;
} Nodo;

void agregarElemento(Nodo** n, int valor) { // O char valor; si sólo aceptamos caracteres
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->sig = NULL;
    
    if (*n == NULL) {
        *n = nuevoNodo;
        nuevoNodo->sig = *n;
    } else {
        nuevoNodo->sig = (*n)->sig;
        (*n)->sig = nuevoNodo;
        *n = nuevoNodo;
    }
}

int esPalindromo(Nodo* n) {
    if (n == NULL) {
        return 1; // Si la lista está vacía, se considera palíndromo
    }
    
    Nodo* actual = n->sig;
    Nodo* anterior = n;
    
    while (actual != n) {
        if (actual->valor != anterior->valor) {
            return 0; // Si se encuentra una diferencia de valores, no es palíndromo
        }
        
        actual = actual->sig;
        anterior = anterior->sig;
    }
    
    return 1; // Si se recorrió toda la lista sin encontrar diferencias, es palíndromo
}

void main() {
    Nodo* n = NULL;
    
    agregarElemento(&n, 1);
    agregarElemento(&n, 1);
    agregarElemento(&n, 3);
    agregarElemento(&n, 2);
    agregarElemento(&n, 1);
    
    if (esPalindromo(n)) {
        printf("Es palíndromo\n");
    } else {
        printf("No es palíndromo\n");
    }
    
}
