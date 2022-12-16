#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//agregar el nodo

struct nodo
{
    int  numero; //char num
    struct nodo *sig;
} nodo;

// Todo comienza con el nodo superior
struct nodo *superior = NULL;

//está vacía
int isEmpty(){
    return superior == NULL;
}

// Operación push //agregar elementos a la pila
void push(int numero) {
        printf("Agregando %d\n", numero);
        // El que se agregará; reservamos memoria
        struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
        // Le ponemos el dato
        nuevoNodo->numero = numero;
        // Y ahora el nuevo nodo es el superior, y su siguiente
        // es el que antes era superior
        nuevoNodo->sig = superior;
        superior = nuevoNodo;
    
}

// Operación pop, eliminar el de hasta arriba
void pop(void) {
    printf("Eliminando el ultimo\n");
    if (superior != NULL) {
        // Para liberar la memoria más tarde debemos
        // tener la referencia al que vamos a eliminar
        struct nodo *temporal = superior;
        // Ahora superior es a lo que apuntaba su siguiente
        superior = superior->sig;
        // Liberar memoria que estaba ocupando el que eliminamos
        free(temporal);
    }
    else
        printf("Underflow\n");
}

void imprimir(void) {
    printf("Imprimiendo...\n");
    struct nodo *temporal = superior;
    while (temporal != NULL) {
        printf("%d\n", temporal->numero);
        temporal = temporal->sig;
    }
}

int tamanio(void){
    int contador = 0;
    if(superior == NULL) return contador;
    struct nodo *temporal = superior;
    while (temporal != NULL) {
		contador++;
        temporal = temporal->sig;
    }
    return contador;
}

//se lee el último de la pila
int ultimo(){
    if(superior == NULL) return -1;
    return superior->numero;
}

int main() {
	int eleccion;
	int numero;
	while(eleccion != -1){
		printf("\n--BIENVENIDO--\n1.- Agregar\n2.- Eliminar\n3.- Imprimir pila\n4.- Imprimir tamanio\n5.- Comprobar si esta vacia\n6.- Mostrar ultimo elemento\n-1.- Salir\n\n\tElige: ");
		scanf("%d", &eleccion);
		switch(eleccion){
			case 1:
				printf("Ingresa el numero que agregaremos:\n");
				scanf("%d", &numero);
				push(numero);
			break;
			case 2:
				pop();
			break;
			case 3:
				imprimir();
			break;
			case 4:
				printf("La pila mide %d\n", tamanio());
			break;
			case 5:
				if(isEmpty()){
					printf("La pila esta vacia\n");
				}else{
					printf("La pila NO esta vacia\n");
				}
			break;
			case 6:
				printf("El ultimo elemento es: %d\n", ultimo());
			break;
		}
	}
}