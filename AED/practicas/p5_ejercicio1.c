#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura de nodo de la pila
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Prototipos de funciones
void push(Nodo** pila, int dato);
int pop(Nodo** pila);
int evaluarExpresionPosfija(char* expresion);
void liberarPila(Nodo* pila);

int main() {
    FILE* archivo;
    char expresion[100];

    // Abrir el archivo
    archivo = fopen("expresion.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leer la expresión del archivo
    fgets(expresion, sizeof(expresion), archivo);

    // Remover el salto de línea del final de la expresión
    expresion[strcspn(expresion, "\n")] = '\0';

    // Cerrar el archivo
    fclose(archivo);

    // Evaluar la expresión posfija y mostrar el resultado
    int resultado = evaluarExpresionPosfija(expresion);
    printf("Resultado de la evaluacion: %d\n", resultado);

    return 0;
}

// Función para insertar un elemento en la pila
void push(Nodo** pila, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

// Función para remover y devolver el elemento superior de la pila
int pop(Nodo** pila) {
    if (*pila == NULL) {
        printf("Error: la pila está vacía.\n");
        exit(1);
    }

    int dato = (*pila)->dato;
    Nodo* nodoEliminado = *pila;
    *pila = (*pila)->siguiente;
    free(nodoEliminado);

    return dato;
}

// Función para evaluar una expresión posfija
int evaluarExpresionPosfija(char* expresion) {
    Nodo* pila = NULL;

    for (int i = 0; expresion[i] != '\0'; i++) {
        if (isdigit(expresion[i])) {
            // Si el caracter es un dígito, lo agregamos a la pila como un número entero
            push(&pila, expresion[i] - '0');
        } else {
            // Si el caracter es un operador, realizamos la operación con los dos elementos superiores de la pila
            int segundoOperand = pop(&pila);
            int primerOperand = pop(&pila);

            switch (expresion[i]) {
                case '+':
                    push(&pila, primerOperand + segundoOperand);
                    break;
                case '-':
                    push(&pila, primerOperand - segundoOperand);
                    break;
                case '*':
                    push(&pila, primerOperand * segundoOperand);
                    break;
                case '/':
                    push(&pila, primerOperand / segundoOperand);
                    break;
                default:
                    printf("Error: operador inválido.\n");
                    liberarPila(pila);
                    exit(1);
            }
        }
    }

    // El resultado final estará en el elemento superior de la pila
    int resultado = pop(&pila);

    // Liberar la memoria de la pila
    liberarPila(pila);

    return resultado;
}

// Función para liberar la memoria de la pila
void liberarPila(Nodo* pila) {
    Nodo* nodoActual = pila;

    while (nodoActual != NULL) {
        Nodo* nodoEliminado = nodoActual;
        nodoActual = nodoActual->siguiente;
        free(nodoEliminado);
    }
}
