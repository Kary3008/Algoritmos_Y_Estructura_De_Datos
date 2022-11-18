//Decimal a binario

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 5

//char *binario(unsigned int n);
//char *binario(unsigned int n);
//int binario(int num);

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
		}*/

		
	//for(i = 1; i <= n; i++)
	//	printf("%i\n", binario);
	
	
	/*int max;
	max = 79;
	printf("%s", binario(max));
	return 0;*/
	
	//printf("%s", binario(79));
	
	
	//OPCION 1
	int n, i, bin; 
	int binario[tam], num, nBits;
	n = 79;
		
		
	printf("Binario: \n");
	int j=0;
	while(j <= n)
	//for(int j = 1 ; j <= n; j++)
	{
		printf("%d: \n", j);
		
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
		//j++;
	//}
	//for(int j = 0 ; j <= n; j++)
	//	printf("%d\n", n);
	
	//printf("%d", binario(79));
		
	return 0;
	
	
}

/*int binario(int num)
{
//	int bin;
	for(int j=0; j<num; j++)
		printf("%d\n", bin);
	//	return bin;
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