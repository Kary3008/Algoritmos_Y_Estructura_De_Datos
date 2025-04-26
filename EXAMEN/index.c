#include <stdio.h>
#define true 1
#define false 0
#define max 30

typedef struct
{
    short int tope; //+ultimo elemento que entra
    short int vector[max];
}stack;

//crear pila
void crearPila(stack *Pila) //recibe una direcciom de memoria, una puntero o sea PILA
{
    Pila->tope = -1; //inicializa la pila vacia
}

//si esta vacia
int pilaVacia(stack *Pila) //recibe una direccion de memoria, una puntero o sea PILA
{
    if (Pila->tope == -1) //si el tope es igual a -1
        return true; //la pila esta vacia
    else
        return false; //la pila no esta vacia
}

//si esta llena
int pilaLlena(stack *Pila) //recibe una direccion de memoria, una puntero o sea PILA
{
    if (Pila->tope == max - 1) //si el tope es igual a max - 1
        return true; //la pila esta llena
    else
        return false; //la pila no esta llena
}

//agregar elemento a la pila
void apilar(stack *Pila, int elemento) //recibe una direccion de memoria, una puntero o sea PILA y un elemento
{
    if (pilaLlena(Pila)) //si la pila esta llena
        printf("Pila llena\n"); //imprime que la pila esta llena
    else
    {
        Pila->tope++; //incrementa el tope
        Pila->vector[Pila->tope] = elemento; //agrega el elemento al vector en la posicion del tope
        printf("Se ha metido %i\n", Pila->vector[Pila->tope]); //imprime el elemento que se ha metido
    }
}

//eliminar elemento de la pila
void desapilar(stack *Pila) //recibe una direccion de memoria, una puntero o sea PILA
{
    if (pilaVacia(Pila)) //si la pila esta vacia
        printf("Pila vacia\n"); //imprime que la pila esta vacia
    else
    {
        int aux = Pila->tope; //guarda el elemento que se va a eliminar
        Pila->tope--; //decrementa el tope
        printf("Se ha sacado %i\n", aux); //imprime el elemento que se ha sacado
        Pila->tope--; //decrementa el tope
    }
}

int main()
{
    stack Pila; //crea una variable de tipo pila
    crearPila(&Pila); //llama a la funcion crearPila y le pasa la direccion de memoria de Pila

    apilar(&Pila, 5); //llama a la funcion apilar y le pasa la direccion de memoria de Pila y el elemento 1
    apilar(&Pila, 2); //llama a la funcion apilar y le pasa la direccion de memoria de Pila y el elemento 2
    apilar(&Pila, 6); //llama a la funcion apilar y le pasa la direccion de memoria de Pila y el elemento 3
    apilar(&Pila, 8); //llama a la funcion apilar y le pasa la direccion de memoria de Pila y el elemento 4

    printf("\nEl tope es %i\n", Pila.tope); //última posición ocupada por el tope de la pila

    printf("\nEl elemento en el tope es %i\n\n", Pila.vector[Pila.tope]); //imprime el elemento en el tope de la pila

    return true;
}

