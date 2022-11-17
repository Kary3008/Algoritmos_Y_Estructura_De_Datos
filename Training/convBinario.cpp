//Decimal a binario

#include <stdio.h>

int main(void)
{
	int n, bin[100];
	int i = 0;
	
	printf("Ingrese un número decimal: ");
	scanf("%i", &n);
	
	while(n != 0)
	{
		bin[i] = n%2;
		n = n/2;
		i++;
	}
	i--;
	printf("Binario: ");
	
	while(i >= 0)
	{
		printf("%i", bin[i]);
		i--;
	}
	
	
}