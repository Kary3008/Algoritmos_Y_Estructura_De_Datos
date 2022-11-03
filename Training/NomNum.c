#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxCad 5

int main()
{
	char* arr[0][MaxCad] = 
	{
		{1,"Kary"},
	{2,"Diego"},
	{3,"Alan"},
	{4,"Anya"},
	{5,"Oscar"}
	};
	printf("Cadena de nombres\n");
	/*arr[0]={1,"Kary"};
	arr[1]={2,"Diego"};
	arr[2]={3,"Alan"};
	arr[3]={4,"Anya"};
	arr[4]={5,"Oscar"};*/
	
	for(int i=0; i<1; i++)
	{
		for(int j=0; j<MaxCad; j++){
		
		printf("%i %c\n", arr[i][j]);
		}
	}
	//printf("\nEl elegido: %s ", arr[3][]);
	return 0;
}
