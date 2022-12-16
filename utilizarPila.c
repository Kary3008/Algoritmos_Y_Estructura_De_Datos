#include <stdio.h>
typedef int elemento;
#include "pila.c"

int main()
{
    stack pila;
    elemento numero;
    int opc = 1;
    create(&pila);

    while (opc != 4)
    {
        printf("Menu");
        printf("\n\t1. Insertar un dato");
        printf("\n\t2. Quitar un dato");
        printf("\n\t3. Ver Pila");
        printf("\n\t4. Salir");
        printf("\n\tescoge una opcion: ");
        scanf("%i", &opc);
        switch(opc)
        {
            case 1:
                printf("Ingresa un numero: ");
                scanf("%d", &numero);
                push(&pila, numero);
            break;
            case 2:
                numero = pop(&pila);
                printf("El valor que se quito de la pila es: %d\n", numero);
            break;
            case 3:
                show(pila);
        }
    }

    return 0;
    
}