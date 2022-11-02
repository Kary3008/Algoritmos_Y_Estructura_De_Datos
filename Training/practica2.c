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
#include <string.h>
#define MaxCad 50

void indexedSearch(int arr[], int n, int key);
void seqSearch(int arr[], int start, int end , int key);
void cadena(int arr[], int n);

int main()
{
	int arr[]={1,2,3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31}; //nombres
	int n = sizeof(arr)/sizeof(arr[0]);
	int key;
	
	//Imprime matriz
	cadena(arr, n);
	
	/*Imprime matriz
	printf("Array elements are below\n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);*/
		
	//Buscar un número aleatorio
	srand(time(NULL)); //generar diferentes números.
	int num; //almacenar los numeros
	int numbers[30]; //seguimiento de nums. repetidos.
	bool unique; //otorga un valor único
	
	for (int i = 0; i < 30; i++)
	{
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
		//printf("number %i: %i \n", i + 1, key);
	}
	key = num; //el numero ganador es el valor que se debe buscar 
	printf("\n\nnumber win: %i \n", num);
	
	indexedSearch(arr, n, key);
	//seqSearch(arr, 0, n-1, key);
}

void cadena(int arr[], int n)
{
	//Imprime matriz
	//printf("Array elements are below\n");
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

void indexedSearch(int arr[], int n, int key)
{
	int index[30], i;
	int j = 0, x = 0, start, end;
	int bs = 5;
	
	for(i=0; i<n; i=i+bs)
		index[x++]=i;
		
	if(key<arr[index[0]] || key>arr[index[x-1]])
	{
		printf("key is not found in array");
		exit(0);
	}
	else
	{
		for(i=1; i<=x; i++)
			if(key<=arr[index[i]])
			{
				start=index[i-1];
				end= start+bs;
				break; 
			}
	}
	seqSearch(arr, start, end, key);
}

void seqSearch(int arr[], int start, int end , int key)
{
	int i, flag = 0;
	for(i = start; i < end; i++)
	{
		if(key == arr[i])
		{			
			flag=1;
			break;
		}
	}
	if(flag == 1)
		printf("key is found at position number %d", i + 1); //i+1
	else
	printf("Key is not found in array");
}