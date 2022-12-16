#include "pila.h"

//funciones
void create(stack *S)
{
    S->top = -1;
}

int is_full(stack S)
{
    if(S.top == MAXSIZE - 1)
        return true;
    else 
        return false;
}

int is_empty(stack S)
{
    if(S.top == 1)
        return true;
    else 
        return false;
}

elemento pop(stack *S)
{
    if(is_empty(*S))
    {
        printf("Underflow\n");
        return 0;
    }
    else{
        S->top--;
        return S->S[S->top+1];
    }
}

void push(stack *S, elemento e)
{
    if(!is_full(*S))
    {
        S->top++;
        S->S[S->top]=e;
    }
    else
        printf("Overflow");
}

void show(stack S)
{
    int i;
    if(!is_empty(S))
    {
        i = S.top;
        printf("Los elementos de la pila son. \n");
        while (i >= 0)
        {
            printf("\t%d\n", S.S[i]);
            i--;
        }
    }
    else
        printf("\nLa pila esta vacia");
}