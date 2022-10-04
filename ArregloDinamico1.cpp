/*
	Name: Arreglo Din�mico
	Copyright: @KarydNa9
	Author: Bautista Bautista Karina
	Date: 02/09/22 16:49
	Description: Crear un arreglo din�mico de tama�o n. El valor de n, p�salo como par�metro en el main o p�delo al usuario.
	Llena tu arreglo con valores aleatorios del 0 al 100,000.
	Realiza una funci�n que ordene el arreglo de forma ascendente. Tu funci�n debe recibir como par�metro tu arreglo.
	
*/

//por seleccion
#include <stdio.h>

main(){
	int i, n, j, k, aux, min;
	printf("\tArreglo Dinamico\n");
	printf("\nIngrese el numero de elementos:");
	scanf("%d",&n);
	int *a = new int[n];  //declara un arreglo din�mico
	
	//bucle para ingresar elementos
	for(i=0;i<n;i++)
	{
		printf("Ingrese arreglo (%d)",i);
		scanf("%d", &a[i]); 
	}
	
	//bucle para recorrer y presentar los elementos originales
	printf("\nLos elementos del arreglo son: \n");
	for(i=0;i<n;i++)
	{
		printf("%d | ", a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		aux=(int) a[i];
		a[i] = a[min];
		a[min] = (int) aux;
		
		/*Bucle para mostrar el anterior*/
		
		printf("\nEl arreglo en la pasada %d:", i+1);
		for (k=0;k<n;k++)
		{
			printf("%d | ",a[k]);
		}
	}
	
	/* Bucle para los elementos ordenados */
	
	printf("\n\nLos elementos del arreglo ordenado son: \n");
	for(i=0;i<n;i++)
	{
		printf("%d | ", a[i]);
	}
}

//delete[] a;
//fflush(atdin);
//getchar();
