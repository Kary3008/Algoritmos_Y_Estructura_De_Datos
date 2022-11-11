#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	float valor;
	float peso;
	float indice;
} mochila;

int main()
{
	int n, i, max, j, cont;
	float wmax, valmax= 0;
	
	printf("Ingresa el numero de elementos: ");
	scanf("%i", &n);
	mochila elemento[n], aux;
	
	//Ingresan los valores de los elementos de la mochila
	printf("\nIngresar elementos en la mochila\n");
	
	for(i = 0; i < n; i++)
	{
		printf("Valor %i: \n", i+1);
		scanf("%f", &elemento[i].valor);
		printf("Peso %i: ", i+1);
		scanf("%f", &elemento[i].peso);
		elemento[i].indice=elemento[i].valor/elemento[i].peso;
	}
	
	//Se ordena los objetos de mayor a menor según los índices
	for(i=0; i<n; i++)
	{
		max = i;
			for(j = i + 1; j < n; j++)
			{
				if(elemento[j].indice>elemento[max].indice)
				{
					max=j;
				}	
			}
			aux = elemento[i];
			elemento[i] = elemento[max];
			elemento[max] = aux;
	}
	
	printf("\n");
	/*
	//verificamos que se hayan ordenado de mayor a menor.
	for(i = 0; i < n; i++)
	{
		printf("%i: ", i+1);
		printf("%.1f , %.1f, %.1f \n", elemento[i].indice, elemento[i].peso, elemento[i].valor);
	}
	*/
	
	//verifica el peso maximo de la mochila
	printf("Peso maximo de la mochila: \n");
	scanf("%f", &wmax);
	
	//ingresamos los objetos dentro de ella.
	
	i=0;
	
	while(wmax > 0)
	{
		if(wmax>elemento[i].peso)
		{
			wmax = wmax - elemento[i].peso;
			valmax = valmax + elemento[i].valor;
		}
		else
		{
			valmax = valmax + (elemento[i].valor * (wmax / elemento[i].peso));
			wmax=0;
		}
		i++;
	}
	printf("El valor maximo de la mochila es: %.1f", valmax);
}