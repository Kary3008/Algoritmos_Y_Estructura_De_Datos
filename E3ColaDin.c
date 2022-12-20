#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 20
#define CProductos 35
 
typedef struct producto{
    char nombre[maxSize];
    int cant_Pro;
}producto;
 
typedef struct nodo{
    struct producto cliente;
    struct nodo *sgte;
}nodo;
 
typedef struct cola{
    struct nodo *delante;
    struct nodo *atras ;
}cola;
 
void encolar(struct cola *q, struct producto valor);
struct producto desencolar(struct cola *q);
void muestraCola(struct cola q);
void muestraColaMas18(struct cola q);
int is_full(struct cola q);
void vaciaCola(struct cola *q);
void menu();
 
int main(){
 
    struct cola q;
    q.delante = NULL;
    q.atras = NULL;
    struct producto dato;
    struct producto x ;
    int op;
 
    do{
        menu();  
        scanf("%d", &op);
 
        switch(op){
 
            case 1:
                printf("\nNombre del cliente: "); 
                scanf("%s", &dato.nombre);
                printf("Cantidad de Productos: "); 
                scanf("%d", &dato.cant_Pro);
                encolar(&q, dato);
                printf("\nCliente: %s", dato.nombre);
                printf("\nCantidad de Productos: %d", dato.cant_Pro);
                break;
 
            case 2:
                x = desencolar(&q);
                printf("\nNombre %s desencolado...\n\n", x.nombre);
                break;
 
            case 3:
                printf("\n\n MOSTRANDO COLA\n\n");
                if(q.delante != NULL) 
                    muestraCola(q);
                else  printf( "\n\n\tCola vacia...!\n");
                break;
 
            case 4:
                printf( "\n\n MOSTRANDO COLA >= 18\n\n");
                if(q.delante != NULL) 
                    muestraColaMas18(q);
                else  printf( "\n\n\tCola vacia...!\n");
                break;
 
 
            case 5:
                vaciaCola( &q );
                printf("\n\nHecho...\n\n");
                break;
 
            case 6:
                printf("VER PRODUCTOS\n");
                if(q.delante != NULL) 
                    is_full(q);
                else  printf( "\n\n\tCola vacia...!\n");
                break;
 
            default:
                printf("\nOpcion no valida\n");
                break;
        }
        printf("\n\n");
 
    }while(op != 7);
 
    vaciaCola(&q);
 
    return 0;
}

void encolar(struct cola *q, struct producto valor){
 
     struct nodo *aux = malloc(sizeof(struct nodo));
     aux->cliente = valor;
     aux->sgte = NULL;
 
     if(q->delante == NULL)
        q->delante = aux;
     else
        (q->atras)->sgte = aux;
 
     q->atras = aux;
}
 
struct producto desencolar(struct cola *q){
 
     struct producto nom ;
     struct nodo *aux ;
 
     aux = q->delante;
     nom = aux->cliente;
     q->delante = (q->delante)->sgte;
 
     free(aux);
 
     return nom;
}
 
void muestraCola(struct cola q){
 
     struct nodo *aux;
 
     aux = q.delante;
 
     while(aux != NULL){
        printf("Cliente: %s \n", aux->cliente.nombre);
        printf("Productos: %i \n\n", aux->cliente.cant_Pro);
        aux = aux->sgte;
     }
     printf("Fin de la cola\n");
}
 
void muestraColaMas18(struct cola q){
 
     struct nodo *aux;
 
     aux = q.delante;
 
     while(aux != NULL){
        if(aux->cliente.cant_Pro <= CProductos)
            printf("%s -> ", aux->cliente.nombre);
        aux = aux->sgte;
     }
     printf("Fin de la cola\n");
}

int is_full(struct cola q)
{
	struct nodo *aux;
     aux = q.delante;
     int a = CProductos;
     while(aux != NULL){
        if(aux->cliente.cant_Pro <= CProductos)
        {
        	a = a - aux->cliente.cant_Pro;
	            printf("%s -> ", aux->cliente.nombre);
	            printf("%i -> ", aux->cliente.cant_Pro);
	            printf("%d \n", a);
		}
            //printf("%s -> ", aux->cliente.nombre);
        aux = aux->sgte;
        
     }
     printf("Fin de la cola\n");
}
 
void vaciaCola(struct cola *q){
 
     struct nodo *aux;
 
     while(q->delante != NULL){
            aux = q->delante;
            q->delante = aux->sgte;
 
            free(aux);
     }
     q->delante = NULL;
     q->atras   = NULL;
}

void menu(){
 
    printf( "\n           COLA" );
    printf( "\n ==========================\n" );
    printf( " 1. ENCOLAR                  \n" );
    printf( " 2. DESENCOLAR               \n" );
    printf( " 3. MOSTRAR COLA             \n" );
    printf( " 4. MOSTRAR COLA >= 18       \n" );
    printf( " 5. VACIAR COLA              \n" );
    printf( " 6. PRODUCTOS                   \n" );
    printf( "\n OPCION: " );
 
}
