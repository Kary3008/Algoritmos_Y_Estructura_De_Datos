#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxCad 50

int cadenaNombre(char nombres[][MaxCad], int n)
{
	int i, max = 0, imax = 0;
	
	for(i = 0; i < n; i++)
		printf("%s | ", nombres[i]);
		
	for (i=0; i<n; i++)
		if(strlen(nombres[i])>max)
		{
			max = strlen(nombres[i]);
			imax = i;
		}
	printf("\n%s", nombres[imax]);
	return max;
}

int main()
{
	char nombres[6][MaxCad] = 
	{
		"Kary", "Diego", "Alan", "Oscar", "Jos", "Alonso"
	};

	printf("\nLongitud del nombre mas largo: %d\n", cadenaNombre(nombres, 6));
	
	return 0;
}