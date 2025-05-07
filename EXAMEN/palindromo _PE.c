#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
#define max_array 20 //maximo de elementos en la pila

typedef struct
{
    short int tope; //+ultimo elemento que entra
    char vector[max_array]; //vector de elementos
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
    if (Pila->tope == max_array - 1) //si el tope es igual a max - 1
        return true; //la pila esta llena
    else
        return false; //la pila no esta llena
}

//agregar elemento a la pila
void apilar(stack *Pila, char elemento) //recibe una direccion de memoria, una puntero o sea PILA y un elemento
{
    if (pilaLlena(Pila)) //si la pila esta llena
        printf("Pila llena\n"); //imprime que la pila esta llena
    else
    {
        Pila->tope++; //incrementa el tope
        Pila->vector[Pila->tope] = elemento; //agrega el elemento al vector en la posicion del tope
        printf("Se ha metido %c\n", Pila->vector[Pila->tope]); //imprime el elemento que se ha metido
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
        printf("Se ha sacado %c\n", aux); //imprime el elemento que se ha sacado
        Pila->tope--; //decrementa el tope
    }
}


int main()
{
    
    char *palabra = "amor a roma";
    short int x = 0, l = strlen(palabra), y = 0; //longitud de la palabra
    char paludismo[l]; //almacenar un string de  la misma longitud que la palabra
    stack Pila;
    crearPila(&Pila); //crea la pila
    for (x = 0 ; x < l ; x++) //recorre la palabra
    {
        apilar(&Pila, palabra[x]); //apila cada letra de la palabra
    }

    while (!pilaVacia(&Pila)) //mientras la pila no este vacia
    {
        paludismo[y] = Pila.vector[Pila.tope]; //guarda el elemento en la posicion x de la palabra
        y++; //incrementa y
        desapilar(&Pila); //desapila el elemento
    }

    if (strcmp(palabra, paludismo) == 0) //compara la palabra con el paludismo
        printf("Es un palindromo\n"); //imprime que es un palindromo
    else
        printf("No es un palindromo\n"); //imprime que no es un palindromo

    return true;
}