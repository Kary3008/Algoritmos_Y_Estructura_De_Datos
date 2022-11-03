#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **matriz, i, j, nfilas, ncols;
	nfilas = 5;
	ncols = 10;
	
	matriz = (int **) calloc(nfilas, sizeof(int *));
	for(i=0; i<nfilas; ++i)
		matriz[i] = (int *) calloc(ncols, sizeof(int));
		
	for(i=0; i<nfilas; ++i)
		for(j=0; j<ncols;++j)
			matriz[i][j] = i+j;
			
	for(i=0; i<nfilas; ++i){
	
		for(j=0; j<ncols;++j)
			printf("%d ", matriz[i][j]);
			
		printf("\n");
		
}
	return 0; 
}