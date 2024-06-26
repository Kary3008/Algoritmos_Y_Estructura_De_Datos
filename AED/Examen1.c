#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Huffman {
    char caracter;
    int frecuencia;
    char code[256];
    struct Huffman* izq;
    struct Huffman* der;
} Huffman;

typedef struct nodoLista {
    Huffman* nodo;
    struct nodoLista* ant;
    struct nodoLista* sig;
} nodoLista;
nodoLista* dividir(nodoLista* n);
nodoLista* unir(nodoLista* izq, nodoLista* der);

nodoLista* ordenar(nodoLista* n) {
    if (n == NULL || n->sig == NULL) {
        return n;
    }

    nodoLista* m = dividir(n);
    nodoLista* m_izq = ordenar(n);
    nodoLista* m_der = ordenar(m);

    return unir(m_izq, m_der);
}

nodoLista* dividir(nodoLista* n) {
    nodoLista* rap = n;
    nodoLista* lento = n;

    while (rap->sig != n && rap->sig->sig != n) {
        rap = rap->sig->sig;
        lento = lento->sig;
    }

    nodoLista* m = lento->sig;
    lento->sig = n; 
    m->ant = n;

    return m;
}

nodoLista* unir(nodoLista* izq, nodoLista* der) {
    nodoLista* tmp= (nodoLista*) malloc(sizeof(nodoLista));
    nodoLista* actual = tmp;

    while (izq != der && der->sig != izq) {
        if (izq->nodo->frecuencia <= der->nodo->frecuencia) {
            actual->sig = izq;
            izq->ant = actual;
            izq = izq->sig;
        } else {
            actual->sig = der;
            der->ant = actual;
            der = der->sig;
        }
        actual = actual->sig;
    }

    actual->sig = (der == izq) ? der : izq;
    actual->sig->ant = actual;

    return tmp->sig;
}
void codificar(nodoLista* n, char* input_text, char* output_file) {
    FILE* abrirArchivo = fopen(output_file, "w");
    nodoLista* actual=n;

    while (*input_text != '\0') {
    	//char cod_actual[256] = "";
        while (actual->nodo->caracter != *input_text) {
            actual = actual->sig;
        }
		//strcpy(cod_actual, actual->nodo->code);
		//fwrite(cod_actual, sizeof(char), strlen(cod_actual), abrirArchivo);
        fwrite(actual->nodo->code, sizeof(char), strlen(actual->nodo->code), abrirArchivo);
        input_text++;
    }

    fclose(abrirArchivo);
}

void decodificar(Huffman* raiz, char* input_file, char* output_file) {
    FILE* entrada = fopen(input_file, "r");
    FILE* salida = fopen(output_file, "w");
    Huffman* actual = raiz;

    char code;
    while (fread(&code, sizeof(char), 1, entrada) > 0) {
        if (code == '0') {
            actual = actual->izq;
        } else {
            actual = actual->der;
        }

        if (actual->izq == NULL && actual->der == NULL) {
            fwrite(&actual->caracter, sizeof(char), 1, salida);
            actual = raiz;
        }
    }

    fclose(entrada);
    fclose(salida);
}

void imprimir(nodoLista* n)
{
	nodoLista* actual = n;
	
	if(n == NULL)
	{
		printf("La lista esta vacia.\n");
		return;
	}
	
	do
	{
		printf("Caracter: %c\n", actual->nodo->caracter);
		printf("Frecuencia: %d\n", actual->nodo->frecuencia);
		printf("Codigo: %s\n", actual->nodo->code);
		printf("\n");
		actual = actual->sig;
	} while(actual != n);
}

int main() {
    FILE* entradaA = fopen("caracter.txt", "r");
    char caracter_actual;
    int frecuencias[256] = {0};

    // Leer el archivo de texto y contar las frecuencias de cada símbolo
    while (fread(&caracter_actual, sizeof(char), 1, entradaA) > 0) {
        frecuencias[(int) caracter_actual]++;
    }

    // Construir los nodos del árbol de Huffman y la lista circular doblemente enlazada
    nodoLista* n = NULL;
    for (int i = 0; i < 256; i++) {
        if (frecuencias[i] > 0) 
		{
            Huffman* nodo = (Huffman*) malloc(sizeof(Huffman));
            nodo->caracter = (char)i;
            nodo->frecuencia = frecuencias[i];
            nodo->izq = NULL;
            nodo->der = NULL;
            nodoLista* nuevoNodo = (nodoLista*) malloc(sizeof(nodoLista));
            nuevoNodo->ant = NULL;
            nuevoNodo->sig = NULL;
            
            if(n == NULL)
            {
            	n = nuevoNodo;
            	n->sig = n;
            	n->ant = n;
			}
			else
			{
				nuevoNodo->sig = n->sig;
				n->sig->ant = nuevoNodo;
				n->sig = nuevoNodo;
				nuevoNodo->ant = n;
			}
		}
		
		codificar(n, "z",entradaA);
		decodificar(n, entradaA, entradaA);
		
		imprimir(n);
	}
}