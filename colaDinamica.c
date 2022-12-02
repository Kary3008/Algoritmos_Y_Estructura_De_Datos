#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int elemento;
#include "pila_din.c"
int main(){
    int i;
    int aux1, aux2;
    int m, sum, acarreo=0;
    Nodo *pila; //pila que vamos a ocupar
    Nodo *pila2;
    Nodo *pila3;
    char numero1[50];
    char numero2[50];
    create(&pila);
    create(&pila2);
    create(&pila3);
    printf("Ponga su primer numero: ");
    scanf("%s",numero1);
    printf("Ponga su segundo numero: ");
    scanf("%s",numero2);
    for(i=0;numero1[i]!='\0';i++){
      //  m=atoi(numero1[i]);
        m=(int)numero1[i]-48;  //el código ascii de los digitos del 0 al 9, va del 48 al 57, con esa resta ya convertimos a su entero correspondiente
        push(&pila,m);
    }
    for(i=0;numero2[i]!='\0';i++){
        //m=atoi(numero2[i]);
         m=(int)numero2[i]-48;
        push(&pila2,m);
    }
    while(!is_empty(pila)||!is_empty(pila2)){
        aux1=pop(&pila);
        aux2=pop(&pila2);
        sum=aux1+aux2+acarreo;
        if(sum>9){
            sum=sum%10;
            acarreo=1;
        }else
            acarreo=0;
        push(&pila3,sum);
    }
    if(acarreo==1)
     push(&pila3,acarreo);
    while(!is_empty(pila3)){
        printf("%d",pop(&pila3));
    }




	return 0;
}