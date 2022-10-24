#include<stdio.h>
void main(void)
{
	int i;
	//Ascendente
	printf("FORMA ASCENDENTE\n");
	for(i=0;i<=10;i++) //i = 1 + 1
	{
		printf("%i.\n", i);
	}
	//Descendente
	printf("\nFORMA DESCENDENTE\n");
	for(i=10;i>=1;i--) //i = 1 + 1
	{
		printf("%i.\n", i);
	}
	//TEXTO
	printf("\nPLANA\n");
	for(i=0;i<=20;i++) //i = 1 + 1
	{
		printf("No debo llegar tarde.\n");
	}
}
