#include <stdlib.h>
#define maxSize 10 //definir constante, elementos que tendrá la pila

typedef struct pila 
{
	int indice;
	int total;
	int datos[maxSize]; //arreglo de datos
}Pila;
int is_empty(Pila pila);
 /* PILA *CREAR( )
 1. Apartar espacio para la Pila.
 2. Inicializar los atributos.
 3. Retornar la referencia a la Pila.
 */
Pila *crear()
{
	Pila * p;
	p = (Pila *)malloc(sizeof(Pila)); //casting a Pila (Pila *)
	p->indice=0; //su índice va a valer 0
	p->total=0; //se maneja con flecha para tipo apuntador
	return p;
}

int is_empty(Pila pila) //verifica si la pila está vacía
{
	if(pila.total==0)
		return 1;
	else
		return 0;
}

int is_full(Pila pila)
{
	if(pila.total==maxSize) //cuando el total coincide con el máximo de elementos
	//es porque la pila está llena.
	return 1;
	else 
	return 0;
}

int push(Pila *pila, int dato) //recibimos un apuntador para que la pila original sea modificada
{
	if(pila->total<maxSize) //preguntar si no está llena, para insertar un elemento
	{
		pila->datos[pila->indice]=dato; //pila en su atributo datos, dónde indica el indice donde quiero guardar el dato que me acabam de enviar en ese paramentro(dato)
		pila->indice++; //una vez insertado el valor, el índice se desplaza al siguiente.
		pila->total++; //y cuando insertamos, el total se incrementa.
		return 1; //en caso de que sí, avisa que si se pudo insertar
		
	}
	else  //en caso contrario no inserta un elemento
		return 0;
}

int pop(Pila *pila)
{
	int aux;
	if(pila->total > 0) //si la pila es mayor a cero es porque tiene elementos que eliminar
	{
		aux = pila->datos[pila->indice-1]; //guarda el dato e indice en el auxiliar
		pila->indice--; //se decrementa el índice
		pila->total--; //se decrementa el total
		return aux;
	}
	else
		return -1;
}