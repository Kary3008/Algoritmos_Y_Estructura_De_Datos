#include<stdio.h>
//crear una función de inserción vacía
void insertion_sort(int a[], int length); //length: longitud de esa matriz como argumento

int main()
{
	int a[] = {8, 4, 9, 5, 7, 6, 3, 2}; //definimos la matriz
	insertion_sort(a,8); //llamamos a la función
	//Bucle para imprimir los elementos de la matriz	
	for(int i = 0; i < 8; i++)
	{
		printf("a[%i] = %i\n", i, a[i]);
	}
	
	return 0;
}

void insertion_sort(int a[], int length)
{
	for(int i = 1; i < length; i++) //analizamos desde el índice 1
	{
		int key = a[i]; //realiza un seguimiento de un elemento en el array
		int j = i - 1; //mirar de adelante a la derecha
		/*ejemplo:
			estamos en el 5, entonces analizaremos el 8, 4, 9
		*/
		
		//Bucle interno que realiza el cambio
		while (j >=0 && a[j] > key) //mientras a[j] sea mayor que el key, va a hacer el cambio
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key; //aquí decimos que el elemento ya va ordenado
	}
	
}
