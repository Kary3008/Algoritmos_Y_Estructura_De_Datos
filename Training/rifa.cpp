#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define max 10

using namespace std;

void generar_arreglo(int A[max]);
void generar_B(int B[1]);
void escribir_arreglo(int A[max]);
void escribir_B(int B[1]);
int mayor_arreglo(int A[max]);

int main()
{
	int A[max], f;
	int B[1], i;
	
	generar_arreglo(A);
	generar_B(B);
	escribir_arreglo(A);
	escribir_B(B);
	
	mayor_arreglo(A);
	{
		int opcion;
		do
		{
			cout<<endl;
			cout<<"Si desea generar otro arreglo pulse 1: "<<endl;
			cout<<"Si desea salir pulse 2: "<<endl;
			cin>>opcion;
			
			switch(opcion)
			{
				case 1: 
					generar_arreglo(A);
					escribir_arreglo(A);
					generar_B(B);
					escribir_B(B);
					cout<<"Nuevo arreglo"<<endl;
					break;
				case 2:
					cout<<"Fin programa"<<endl;
					break;
			}
		} while(opcion != 2 );
	}
	return 0;
}

void generar_arreglo(int A[max])
{
	int n;
	srand(time(NULL));
		for(int i = 0; i<max; i++)
			A[i]= 3+rand()%(7);
}

void generar_B(int B[1])
{
	int n;
	srand(time(NULL));
	B[0] = 1+rand()%(9);
}

void escribir_arreglo(int A[max])
{
	for(int i=0; i<max; i++)
	{
		cout<<setw(7)<<A[i];
	}
	cout<<endl;
}

void escribir_B(int B[1])
{
	cout<<"El numero ganador es: "<<B[0]<<endl;
}

int mayor_arreglo(int A[max])
{
	int mayor_A=A[0];
	for(int i=0; i<max;i++)
		if(mayor_A<A[i])
			mayor_A=A[i];
			cout<<"El mayor numero es: "<<mayor_A<<endl;
	return mayor_A;
}