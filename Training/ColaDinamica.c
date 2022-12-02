#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    /*
    *Un puntero void puede almacenar una posición en memoria de cualquier tipo de dato.
    */
    void *proximo;
    char *nombre;
} elemento;

//Variables globales

elemento *primer = NULL;
elemento *ultimo = NULL;

//Declaración explícita de funciones
elemento *extraer();
void agregar(elemento *_elemento);

//Implementación de funciones
void agregar(elemento *_elemento)
{
    _elemento->proximo = NULL;
    if (primer == NULL)
    {
        primer = _elemento;
        ultimo = _elemento;
    }
    else
    {
        ultimo->proximo = _elemento;
        ultimo = _elemento;
    }
}

elemento *extraer()
{
    if (primer == NULL)
    {
        return NULL;
    }
    elemento *elemento_retorno = primer;
    primer = primer->proximo;
    return elemento_retorno;
}

int main()
{
    elemento *uno = malloc(sizeof(elemento));
    elemento *dos = malloc(sizeof(elemento));
    elemento *tres = malloc(sizeof(elemento));

    uno->nombre = "Primer elemento";
    dos->nombre = "Segundo elemento";
    tres->nombre = "Tercer elemento";

    agregar(uno);
    agregar(dos);
    agregar(tres);

    elemento *i = extraer();

    while (i != NULL)
    {
        printf("%s\n", i->nombre);
        i = extraer();
    }

    return 0;
}