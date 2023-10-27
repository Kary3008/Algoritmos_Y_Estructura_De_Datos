#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void main()
{
	FILE* archivoIndices=fopen("archivoIndices.txt","r");
	FILE* archivoLibros=fopen("archivoLibros.txt","r");
	
	if(archivoLibros == NULL || archivoIndices == NULL)
	{
		puts("Archivos no encontrados");
		exit(1);
	}
	
	int indice, i, posIni, posFin, indiceLibros=1;
	char linea[4]={0};
	char valor[3]={'\0'};
	char libros[11][100];
	char lineaLibro[50];
	char itemBuscado[50] = "Divergente\n";
	bool exito = false;
	
	
	int arregloIndices[256];
	while(!feof(archivoIndices))
	{
		fgets(linea, 4, archivoIndices);
		for(indice = 0; indice < strlen(linea); indice++)
		{
			valor[indice]=linea[indice+1];
		}
		arregloIndices[(int)linea[0]]=atoi(valor);
	}
	
	while(!feof(archivoLibros))
	{
		fgets(libros[indiceLibros],100,archivoLibros);
		indiceLibros++;
	}
	
	i = (int)itemBuscado[0];
	if(arregloIndices[i]>0)
	{
		posIni = arregloIndices[i];
		do{
			i++;
		} while(arregloIndices[i]==0);
		
		posFin = i;
		
		for(i=posIni; i<posFin; i++)
		{
			printf("Comparando item %s  y %s", itemBuscado, libros[i]);
			if(strcmp(itemBuscado,libros[i])==0)
			{
				exito = true;
			}
		}
		
	}
	else
	{
		exito=false;
	}
	
	fclose(archivoIndices);
	fclose(archivoLibros);
	 
	
}