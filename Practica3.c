#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int peso;
	int valor;
} mochila;

int conv_binario(int n); 

int main()
{
	int i, pesoMax, max, n;
	n = 5;
	pesoMax = 15;
	
	//printf("Elementos: %i", n);
	
	mochila elemento[n];
	
	printf("Ingresar elementos de la mochila\n");
	
	for(i = 0;i < n; i++)
	{
		printf("Peso %i: ", i+1);
		scanf("%i", &elemento[i].peso);
		printf("Valor %i: ", i+1);
		scanf("%i", &elemento[i].valor);
	}
	
	printf("Peso maximo de la mochila: %i\n", pesoMax);
	
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
	printf("El valor maximo de la mochila es: %i\n\n", max);
	
	conv_binario(max);
}

int conv_binario(int n)
{
	//int n,
	int i, bin; 
	//int binario[tam],
	int nBits;
	//n = 79;
		
		
	printf("Binario: \n");
	int j=0;
	while(j <= n)
	//for(int j = 1 ; j <= n; j++)
	{
		printf("%d: ", j);
		
		nBits = sizeof(j)*2;
		//j++; 
		
		
			for(i = 0; i < nBits; i++)
			{
				bin = j>>(nBits - i - 1)&1;
				printf("%d", bin);
			}
			printf("\n");	
			j++;	
	}
}