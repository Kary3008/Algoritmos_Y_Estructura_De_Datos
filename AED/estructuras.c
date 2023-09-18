#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Estructuras y uniones estáticas y dinámicas

//ABSTRACCIÓN:
//Extraer de características generales de grupos o elementos.
typedef float decimal; //cualquier valor flotante lo va a reconocer como decimal
typedef struct{ //typeder redefinir cualquier tipo de dato
	char forma[20];
	char color[20];
	decimal radio;
	decimal volumen;
	//float radio;
	//float volumen;
}Pelota;

void main()
{
	Pelota miPelota;
	//APUNTADOR A ESTRUCTURA
	Pelota* p=&miPelota; //envía solo una dirección de memoria. 
	Pelota* pelotas = calloc(10,sizeof(Pelota));
	if(pelotas == NULL)
	{
		puts("Se termino la memoria");
		exit(1);
	}
	strcpy(pelotas[4].color,"azul");//guardarlo en la posición 5
	strcpy(pelotas[2].color,"rosita");//guardarlo en la posición 5
	(*p).radio = 2.4; //tipo estructura apuntador (. ) //eliminar que es un apuntador (->)se usa cuando la variable del lado izq sea un apuntador
	//miPelota.color[0] = 'a'; //forma 1
	strcpy(p->color, "rojo");
	printf("Las caracteristicas de mi pelota son:  \ncolor->%s\n",miPelota.color);
	printf("Radio->%1.3f\n", miPelota.radio);
	printf("El color de la quinta pelota es: %s", pelotas[4].color);
	printf("\nEl color de la tercera pelota es: %s", pelotas[2].color);
	free(pelotas);
}
