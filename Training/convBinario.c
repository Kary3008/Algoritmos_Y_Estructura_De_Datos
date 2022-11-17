//Decimal a binario

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char *binario(unsigned int n);
//char *binario(unsigned int n);

int main()
{
	/*int n = 79, bin[10], binario;
	int i;
	
//	printf("Ingrese un numero decimal: ");
	//scanf("%i", &n);
	
	i = 0;
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
		
	//for(i = 1; i <= n; i++)
	//	printf("%i\n", binario);
	
	*/
	
	/*int max;
	max = 79;
	printf("%s", binario(max));
	return 0;*/
	
	//printf("%s", binario(79));
	
	int n, i, bin;
	n = 79;
		
		
	printf("Binario: \n");
	int nBits = sizeof(n)*8;
	for(i = 0; i < nBits; i++)
	{
		bin = n>>(nBits - i - 1)&1;
		printf("%d", bin);
	}
	printf("\n");
	
	//for(i = 0; i <= n; i++)
	//	printf("%d\n", bin);
		
	return 0;
	
	
}

/*char *binario(unsigned n)
{
	char *b = calloc((sizeof(unsigned int) *8)+1, 1);
	unsigned int uno = 1;
	unsigned int temp;
	int i = 0;
	
	while (n)
	{
		temp = n & uno;
		if(temp)
		{
			b[i++] = '1';
		}
		else
		{
			b[i++] = '0';
		}
		n = n >> 1;
	//	b[i--];
	}
	return b;
}*/
/*
char *binario(unsigned int n)
{
	static char b[33];
	int i = 0;
	do
	{
		b[i++] = (n & 1) ? '1' : '0';
		n = n >> 1;
		
	}
	while (n);
	b[i] = 0;
	//b[i--];
	return b;
}*/