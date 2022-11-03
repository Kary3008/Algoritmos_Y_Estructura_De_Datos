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
#define MaxCad 30

void indexedSearch(int arr[], int n, int key);
void seqSearch(int arr[], int start, int end , int key);
int numAleatorio(int numbers[]);
//void cadenaNum(char* arr[], int n);
//void cadenaNombre(char nombres[][MaxCad], int n);

int main()
{
	int i=0;
	int j=0;
	/*char nombres[31][MaxCad] = 
	{
		"Kary", "Diego", "Alan", "Oscar", "SA" , "Jos", "Alonso", "SA", "SA", 
		"Ana Maria", "SA", "SA", "SA", "SA", "Alfredo", "Mariel", "SA", 
		"Omar", "SA", "Katy", "Natalia", "Sofia", "SA", "Sandra", "SA", 
		"Sarita", "Danna Paola", "SA", "Angel", "Kevin", "SA"
	};*/
	
	int arrN[]={1,2,3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}; //nombres
	int n = sizeof(arrN)/sizeof(arrN[0]);
	int key;
	
	char* arr[MaxCad];
	arr[0]="SA";
	arr[1]="Alan";
	arr[2]="DIego";	
	arr[3]="Anya";
	arr[4]="Oscar";	
	arr[5]="SA";
	arr[6]="SA";
	arr[7]="SA";
	arr[8]="Jos";
	arr[9]="Alonso"; 
	arr[10]="SA"; 
	arr[11]="SA";
	arr[12]="Alfredo";
	arr[13]="Mariel";
	arr[14]="SA"; 
	arr[15]="Omar"; 
	arr[16]="SA";
	arr[17]="Katy";
	arr[18]="Natalia";
	arr[19]="Sofia"; 
	arr[20]="SA";
	arr[21]="Sandra"; 
	arr[22]="SA";
	arr[23]="Sarita";
	arr[24]="Danna Paola";
	arr[25]="SA";
	arr[26]="Angel";
	arr[27]="Kevin";
	arr[28]="SA";
    arr[29]="Kary";
	    
	//Imprime matriz	
	for(i=0; i<MaxCad; i++)
	{
		printf("%s\n", arr[i]);
	}     

	//Buscar un número aleatorio
	/*srand(time(NULL)); //generar diferentes números.
	int num; //almacena los numeros
	int numbers[30]; //seguimiento de nums. repetidos.
	bool unique; //otorga un valor único
	
	for (i = 0; i < 30; i++)
	{
		do
		{
			num = (rand()%31); //generar el num. aleatorio 
			//se agrega un +1 porque sólo llega de 0 a 29 siendo de 1 a 30
			unique = true; //asumiremos que hay valores únicos.
			for (int j = 0; j < i; j++)
				if(numbers[j] == num) //siempre que no sea único entonces se genera un número único otra vez
					unique = false;
		} while(!unique); //siempre y cuando no sea el valor único entonces seguirá el ciclo.
		numbers[i] = num;
		//printf("number %i: %i \n", i + 1, key);
	}*/
	
	//int num;
	int numbers[0];
	//num = (rand()%31);
	//numAleatorio(num, numbers);
	//printf("\n\nnumber win: %i \n", num);
	
	/*int num;
	num = (rand()%31);
	key = numAleatorio(num); //el numero ganador es el valor que se debe buscar  */

	//int n = MaxCad;
	
	//indexedSearch(arrN, n, key);
	int numA;
	numA =numAleatorio(numbers);
	printf("\n\nnumber win: %i \n", numA);
	key=numA;
	
	char* a;
	for(j=0; j<=key; j++)
		a=arr[key];
		if(a!="SA")
		{
			indexedSearch(arrN, n, key);
			printf("\nEL ganador es:%s ", a);
		}
		else{
			numAleatorio(numbers);
		}	
	//seqSearch(arr, 0, n-1, key);
}

int numAleatorio(int numbers[])
{
	int num;
	//Buscar un número aleatorio
	srand(time(NULL)); //generar diferentes números.
	//int num; //almacena los numeros
	//int numbers[30]; //seguimiento de nums. repetidos.
	bool unique; //otorga un valor único
	
	for (int i = 0; i < 30; i++)
	{
		do
		{
			num = (rand()%31); //generar el num. aleatorio 
			//se agrega un +1 porque sólo llega de 0 a 29 siendo de 1 a 30
			unique = true; //asumiremos que hay valores únicos.
			for (int j = 0; j < i; j++)
				if(numbers[j] == num) //siempre que no sea único entonces se genera un número único otra vez
					unique = false;
		} while(!unique); //siempre y cuando no sea el valor único entonces seguirá el ciclo.
		numbers[i] = num;
		//printf("number %i: %i \n", i + 1, key);
	}

	//printf("\n\nnumber win: %i \n", num);
}


/*void cadenaNombre(char nombres[][MaxCad], int n)
{
	int i; // max = 0, imax = 0;
	
	for(i = 0; i < n; i++)
		printf("%s | ", nombres[i]);
}*/

/*void cadenaNum(int arr[], int n)
{
	//Imprime matriz
	for(int i = 0; i < n; i++)
		printf("%s | ", arr[i]);
}*/


void indexedSearch(int arr[], int n, int key)
{
	int index[31], i;
	int j = 0, x = 0, start, end;
	int bs = 2;
	
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