#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definición del nodo del árbol
typedef struct nodo {
    int prioridad;
    char expresion[100];
    struct nodo* izquierda;
    struct nodo* derecha;
} Nodo;

// Definición de la pila
typedef struct pila {
    char operador;
    struct Pila* siguiente;
} Pila;

// Prototipos de funciones
Nodo* crearNodo();
void insertarNodo(Nodo** raiz, Nodo* nuevoNodo);
void imprimirArbolEnOrdenAscendente(Nodo* raiz);
void imprimirArbolEnPreOrden(Nodo* raiz);
void imprimirArbolEnPosOrden(Nodo* raiz);
int evaluarExpresionPosfija(char* expresion, int prioridad);
void push(Pila** pila, char operador);
char pop(Pila** pila);
int prioridadOperador(char operador);
int esOperador(char caracter);

int main() {
    // Solicitar cantidad de expresiones
    int cantidadExpresiones;
    printf("Ingrese la cantidad de expresiones a resguardar (entre 1 y 18): ");
    scanf("%d", &cantidadExpresiones);

    // Validar cantidad de expresiones
    if (cantidadExpresiones < 1 || cantidadExpresiones > 18) {
        printf("Error: La cantidad de expresiones debe estar entre 1 y 18\n");
        return 1;
    }

    // Crear raíz del árbol
    Nodo* raiz = NULL;

    // Solicitar expresiones al usuario
    for (int i = 1; i <= cantidadExpresiones; i++) {
        printf("Ingrese la expresion %d: ", i);
        // Crear un nuevo nodo con prioridad aleatoria
        Nodo* nuevoNodo = crearNodo();
        // Leer la expresión del usuario
        scanf("%s", nuevoNodo->expresion);
        // Insertar el nuevo nodo en el árbol
        insertarNodo(&raiz, nuevoNodo);
    }

    // Elegir el orden de evaluación de las expresiones
    int opcion;
    printf("\nElija el orden de evaluacion de las expresiones:\n");
    printf("1. Ejecutar en orden ascendente las evaluaciones\n");
    printf("2. Ejecutar en pre-orden las evaluaciones\n");
    printf("3. Ejecutar en pos-orden las evaluaciones\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    // Evaluar las expresiones según el orden elegido
    printf("\nResultados de las evaluaciones:\n");
    switch (opcion) {
        case 1:
            imprimirArbolEnOrdenAscendente(raiz);
            break;
        case 2:
            imprimirArbolEnPreOrden(raiz);
            break;
        case 3:
            imprimirArbolEnPosOrden(raiz);
            break;
        default:
            printf("Opcion invalida\n");
            break;
    }

    return 0;
}

// Función para crear un nodo con prioridad aleatoria
Nodo* crearNodo() {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->prioridad = rand() % 15 + 1;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo en el árbol BST
void insertarNodo(Nodo** raiz, Nodo* nuevoNodo) {
    if (*raiz == NULL) {
        *raiz = nuevoNodo;
    } else {
        if (nuevoNodo->prioridad <= (*raiz)->prioridad) {
            insertarNodo(&(*raiz)->izquierda, nuevoNodo);
        } else {
            insertarNodo(&(*raiz)->derecha, nuevoNodo);
        }
    }
}

// Función para imprimir el árbol en orden ascendente
void imprimirArbolEnOrdenAscendente(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirArbolEnOrdenAscendente(raiz->izquierda);
        printf("Prioridad: %d\n", raiz->prioridad);
        printf("Expresion: %s\n", raiz->expresion);
        imprimirArbolEnOrdenAscendente(raiz->derecha);
    }
}

// Función para imprimir el árbol en pre-orden
void imprimirArbolEnPreOrden(Nodo* raiz) {
    if (raiz != NULL) {
        printf("Prioridad: %d\n", raiz->prioridad);
        printf("Expresion a evaluar: %s\n", raiz->expresion);
        
        printf("Resultado: %d\n", evaluarExpresionPosfija(raiz->expresion, raiz->prioridad));
        imprimirArbolEnPreOrden(raiz->izquierda);
        imprimirArbolEnPreOrden(raiz->derecha);
    }
}

// Función para imprimir el árbol en posorden
void imprimirArbolEnPosOrden(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirArbolEnPosOrden(raiz->izquierda);
        imprimirArbolEnPosOrden(raiz->derecha);
        printf("Prioridad: %d\n", raiz->prioridad);
        printf("Expresion a evaluar: %s\n", raiz->expresion);
        
        printf("Resultado: %d\n", evaluarExpresionPosfija(raiz->expresion, raiz->prioridad));
    }
}

// Función para evaluar una expresión posfija
int evaluarExpresionPosfija(char* expresion, int prioridad) {
    Pila* pila = NULL;
    for (int i = 0; i < strlen(expresion); i++) {
        char caracter = expresion[i];
        if (isdigit(caracter)) {
            push(&pila, caracter);
        } else if (esOperador(caracter)) {
            int operando2 = pop(&pila) - '0';
            int operando1 = pop(&pila) - '0';
            int resultado;
            switch (caracter) {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
            }
            push(&pila, resultado + '0');
        }
    }
    int resultado_final = pop(&pila) - '0';
    return resultado_final;
}

// Función para agregar un operador a la pila
void push(Pila** pila, char operador) {
	if(*pila == NULL)
	{
		return '\0';
	} 
	else
	{
    	Pila* nuevoNodo = (Pila*)malloc(sizeof(Pila));
    	nuevoNodo->operador = operador;
    	nuevoNodo->siguiente = *pila;
    	*pila = nuevoNodo;
	}
}

// Función para obtener y eliminar un operador de la pila
char pop(Pila** pila) {
    if (*pila == NULL) {
        return '\0';
    }
    Pila* nodoTemporal = *pila;
    char operador = nodoTemporal->operador;
    *pila = (*pila)->siguiente;
    free(nodoTemporal);
    return operador;
}

// Función para obtener la prioridad de un operador
int prioridadOperador(char operador) {
    switch (operador) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Función para verificar si un caracter es un operador
int esOperador(char caracter) {
    if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') {
        return 1;
    }
    return 0;
}

