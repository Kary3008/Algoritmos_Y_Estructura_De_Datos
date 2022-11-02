/*
	Name: Práctica 2 - Búsqueda indexada
	Copyright: @Kary3008	
	Author: Karina Bautista Bautista
	Date: 01/11/22 17:14
	Description: Generar un número sorteado de una rifa 
	de manera aleatoria, usar la búsqueda indexada y con una búsqueda lineal o binaria.
*/


#include <stdio.h>
#include <stdlib.h> //generar números aleatorios.
#include <time.h>//tiempo
#include <stdbool.h> //variable tipo booleano

int main()
{
	srand(time(NULL)); //generar diferentes números.
	int num; //almacenar los numeros
	int numbers[30]; //seguimiento de nums. repetidos.
	bool unique;
	
	for (int i = 0; i < 30; i++)
	{
		/*num = (rand()%59)+1;
		printf("number %d: %d \n", i+1, num);*/
		do
		{
			num = (rand()%30) + 1; //generar el num. aleatorio 
			//se agrega un +1 porque sólo llega de 0 a 29 siendo de 1 a 30
			unique = true; //asumiremos que hay valores únicos.
			for (int j = 0; j < i; j++)
				if(numbers[j] == num) //siempre que no sea único entonces se genera un número único otra vez
					unique = false;
		} while(!unique); //siempre y cuando no sea el valor único entonces seguirá el ciclo.
		numbers[i] = num;
		printf("number %i: %i \n", i + 1, num);
	}
}