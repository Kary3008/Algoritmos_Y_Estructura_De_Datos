#include <stdio.h>

int main()
{
	int num = 0;
	printf("Este programa lee un numero de 3 digitos e imprime si es capicuo: ");
	scanf("%i", &num);
	
	if((num % 10) == (num /10000))
		printf("El numero es capicuo.");
	else
		printf("El numero no es capicuo");
		
	return 0;

}