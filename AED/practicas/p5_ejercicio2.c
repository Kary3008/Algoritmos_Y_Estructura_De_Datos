#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 1000

// Estructura de la pila
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Función para inicializar la pila
void initialize(Stack* stack) {
    stack->top = -1;
}

// Función para comprobar si la pila está vacía
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Función para comprobar si la pila está llena
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Función para insertar un elemento en la pila
void push(Stack* stack, char element) {
    if (isFull(stack)) {
        printf("Error: la pila está llena\n");
        return;
    }
    stack->data[++stack->top] = element;
}

// Función para obtener el elemento en la parte superior de la pila
char top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: la pila está vacía\n");
        return '\0';
    }
    return stack->data[stack->top];
}

// Función para eliminar y devolver el elemento en la parte superior de la pila
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: la pila está vacía\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Función para verificar el balanceo de los paréntesis en una expresión
bool verificarBalanceo(char* expresion) {
    Stack stack;
    initialize(&stack);
    
    int i = 0;
    while (expresion[i] != '\0') {
        if (expresion[i] == '[' || expresion[i] == '(' || expresion[i] == '{') {
            push(&stack, expresion[i]);
        }
        else if (expresion[i] == ']' || expresion[i] == ')' || expresion[i] == '}') {
            if (isEmpty(&stack)) {
                return false;
            }
            
            char topElement = top(&stack);
            
            if ((expresion[i] == ']' && topElement == '[')
                || (expresion[i] == ')' && topElement == '(')
                || (expresion[i] == '}' && topElement == '{')) {
                pop(&stack);
            } else {
                return false;
            }
        }
        i++;
    }
    
    if (!isEmpty(&stack)) {
        return false;
    }
    
    return true;
}

int main() {
    FILE* archivo = fopen("expresion2.txt", "r");
    char expresion[1000];
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    
    fgets(expresion, sizeof(expresion), archivo);
    
    if (verificarBalanceo(expresion)) {
        printf("Verdadero\n");
    } else {
        printf("Falso\n");
    }
    
    fclose(archivo);
    
    return 0;
}
