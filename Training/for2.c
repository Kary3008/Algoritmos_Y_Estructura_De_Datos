//suma de los primeros 10 números pares.

#include<stdio.h>
 void main(void)
 {
 	int i, suma = 0;
 	
 	for(i=1; i<=10; i++) //aumentar en 2: i+=2 -> (i=i+2)
 	{
 		if(i%2==0)//si se divide entre dos y el residuo es cero, el resultado es par.
 		{
 			suma += i; //suma= suma+i
		}
	}
	printf("\n La suma de los numeros pares es: %i", suma);
 }
