#include <stdio.h>
#define true 1
#define false 0
#define max 10

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
        int aux = Pila->vector[Pila->tope]; //guarda el elemento que se va a eliminar
        //Pila->tope--; //decrementa el tope
        printf("Se ha sacado %i\n", aux); //imprime el elemento que se ha sacado
        Pila->tope--; //decrementa el tope
    }
}

void cima(stack *pila)
{
    if (pilaVacia(pila)) //si la pila esta vacia
        printf("Pila vacia\n"); //imprime que la pila esta vacia
    else
        printf("El elemento en el tope es %i\n", pila->vector[pila->tope]); //imprime el elemento en el tope de la pila
}
 void ultimaPosicion(stack *pilaLlena)
{
    if (pilaVacia(pilaLlena)) //si la pila esta vacia
        printf("Pila vacia\n"); //imprime que la pila esta vacia
    else
        printf("La ultima posicion es %i\n", pilaLlena->tope); //imprime la ultima posicion de la pila
}

stack copiarPila(stack *pilaLlena) {
    stack pilaCopia;
    crearPila(&pilaCopia);
    for (int i = 0; i <= pilaLlena->tope; i++) {
        apilar(&pilaCopia, pilaLlena->vector[i]);
    }
    return pilaCopia;
}

int main()
{
    stack Pila; //crea una variable de tipo pila
    crearPila(&Pila); //llama a la funcion crearPila y le pasa la direccion de memoria de Pila
    int opc = 0;
    do {
        printf("Ingrese una opcion:\n");
        printf("1. Apilar elementos\n");
        printf("2. Mostrar ultima posicion\n");
        printf("3. Ver cima de la pila\n");
        printf("4. Copiar pila\n");
        printf("5. Desapilar\n");
        printf("Otro numero para salir: ");
        scanf("%d", &opc);

        switch (opc) {
        case 1:
            printf("Pila apilada\n");
            apilar(&Pila, 9);
            apilar(&Pila, 2);
            apilar(&Pila, 6);
            apilar(&Pila, 8);
            break;
        case 2:
            printf("Ultima posicion\n");
            ultimaPosicion(&Pila);
            break;
        case 3:
            printf("Cima de la pila\n");
            cima(&Pila);
            break;
        case 4:
            printf("Copiar pila\n");
            stack pilaCopia = copiarPila(&Pila);
            break;
        case 5:
            printf("Desapilar\n");
            desapilar(&Pila);
            break;
        default:
            break;
        }
    } while (opc >= 1 && opc <= 5);

    return true;
}