#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int peso;
	int valor;
} mochila;

int main()
{
	int n, i, pesoMax, max;
	n = 5;
	
/*	printf("Elementos: %i", n);*/
	
	mochila elemento[n];
	
	printf("Ingresar elementos de la mochila\n");
	
	for(i = 0;i < n; i++)
	{
		printf("Peso %i: ", i+1);
		scanf("%i", &elemento[i].peso);
		printf("Valor %i: ", i+1);
		scanf("%i", &elemento[i].valor);
	}
	
	printf("Peso maximo de la mochila: ");
	scanf("%i", &pesoMax);
	
	i = 0;
	while(pesoMax > 0)
	{
		if(pesoMax > elemento[i].peso)
		{
			pesoMax = pesoMax - elemento[i].peso;
			max = max + elemento[i].valor;
		}
		else
		{
			max = max + (elemento[i].valor * (pesoMax / elemento[i].peso));
			pesoMax = 0;
		}
		i++;
	}
	printf("El valor maximo de la mochila es: %i", max);
}