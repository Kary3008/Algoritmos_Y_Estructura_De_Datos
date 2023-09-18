#include <stdio.h>

struct Dato{
	int valor;
	char caracter;
};

union Data{
	int valor;
	char caracter;
};

void main()
{
	struct Dato dato;
	union Data data;
	dato.valor = 64;
	data.valor = 64;
	//printf("Tam Dato-->%d\n", sizeof(dato));
	//printf("Tam Data-->%d\n", sizeof(data));
	printf("tam entero-->%d\n",sizeof(dato.valor));
	printf("tam char-->%d\n",sizeof(dato.caracter));
	printf("Tam Dato-->%d\n", sizeof(struct Dato));
	printf("Tam Data-->%d\n", sizeof(union Data));
	printf("Información Dato: valor=%d, caracter=%c\n", dato.valor, dato.caracter);
	printf("Información Data: valor=%d, caracter=%c", data.valor, data.caracter);
}