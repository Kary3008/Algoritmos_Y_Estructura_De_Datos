#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxCad 20

int cadenaNombre(char nombres[][MaxCad], int n);

int main()
{
	char nombres[30][MaxCad] = 
	{
		"Kary", "Diego", "Alan", "Oscar", "SA" , "Jos", "Alonso", "SA", "SA", 
		"Ana Maria", "SA", "SA", "SA", "SA", "Alfredo", "Mariel", "SA", 
		"Omar", "SA", "Katy", "Natalia", "Sofia", "SA", "Sandra", "SA", 
		"Sarita", "Danna Paola", "SA", "Angel", "Kevin"
	};
	
	cadenaNombre(nombres, 30);
	
	return 0;
}

int cadenaNombre(char nombres[][MaxCad], int n)
{
	int i; // max = 0, imax = 0;
	
	for(i = 0; i < n; i++)
		printf("%s | ", nombres[i]);
		
	/*for (i=0; i<n; i++)
		if(strlen(nombres[i])>max)
		{
			max = strlen(nombres[i]);
			imax = i;
		}
	printf("\n%s", nombres[imax]);
	return max;*/
}
