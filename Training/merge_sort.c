#include <stdio.h>

void merge_sort(int a[], int length); //llevará la matriz, así como su longitud.
void merge_sort_recursion(int a[], int left, int right); //lleva el paso recursivo del algoritmo, donde se divide continuamente la matriz no ordenada en porciones más pequeñas.
void merge_sorted_arrays(int a[], int left, int mid, int right); //fusionará las dos porciones ordenadas de la matriz.

int main()
{
  // array y length
  int array[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
  int length = 10;
  //imprime matriz desordenada
  printf("Matriz Desordenada");
  for(int i = 0; i < length; i++)
  {
      printf("%i | ", array[i]);
  }
  printf("\n\n");
  //imprime cada elemento de la matriz ordenada.
  printf("Matriz Ordenada por Merge_Sort");
  merge_sort(array, length);
  for (int i = 0; i < length; i++)
    printf("%d | ", array[i]);

  return 0;
}

/*Se proporciona la matriz y su longitud.*/
void merge_sort(int a[], int length)
{
  //se clasifica toda la matriz -> (a[], left, right)
  merge_sort_recursion(a, 0, length - 1);
}

/*dividiendo la parte de la matriz entre l...r en el medio y llamándose
a sí misma en cada parte, antes de aplicar la función para combinar las
partes ordenadas de la matriz.
*/
void merge_sort_recursion(int a[], int left, int right)
{
  //la recursión se detiene cuando left es mayor o igual que right, mientras ejecuta lo siguiente
  if (left < right)
  {
    //encontramos el punto medio entre left y right.
    int mid = left + (right - left) / 2;

    //llamamos a la función en porciones más pequeñas de la matriz en la parte izquierda.
    merge_sort_recursion(a, left, mid);
    //luego llamamos a la recursión de ordenación por fusión en la parte derecha.
    merge_sort_recursion(a, mid + 1, right);

    //ambas partes de la matriz se han ordenado, ahora se necesita fusionar las partes ordendadas
    merge_sorted_arrays(a, left, mid, right);
  }
}

//fusiona las dos porciones ordenadas entre los índices (l ... m) y (m + 1 ... r)
void merge_sorted_arrays(int a[], int left, int mid, int right)
{
  //calcula la longitud, tanto de la izq. como de la der.
  int left_length = mid - left + 1; //long left.
  int right_length = right - mid; //long right.

  //se crea submatrices temporales para copiar las porciones de la matriz a.
  int temp_left[left_length];
  int temp_right[right_length];

  // usamos un índice/contador para los 3 arrays temp_left, temp_right, matriz A.
  int i, j, k;

  // copiamos la porción left_length dentro de temp_left array
  for (int i = 0; i < left_length; i++)
    //copia desde el índice l hasta llegar a i que es menor que left_length
    temp_left[i] = a[left + i];

  // copiamos la porción right_length dentro de temp_right array
  for (int i = 0; i < right_length; i++)
    //empieza desde (m + 1) y de así en adelante con i hasta right_length
    temp_right[i] = a[mid + 1 + i];

  /*fusiona las dos porciones ordenadas de la matriz a entre los índices l ... m y m + 1 ... r

  Use i para moverse a través de los índices de temp_left, j para moverse a
  través de los índices de temp_right y k para moverse a través de la parte de
  la matriz a de l ... r.
  Colocamos la matriz más pequeña de las dos en la matriz A (usando i, j, k para
  movernos por las matrices). Cuando agotamos elementos en temp_left o temp_right,
  los elementos restantes de la otra matriz se copiarán en la matriz A.*/
  for (i = 0, j = 0, k = left; k <= right; k++)
  {
    /*siempre que no hayamos llegado al final de la matriz temp_left con
    nuestra variable i, si el siguiente elemento de la matriz left_temp es
    más pequeño O si hemos llegado al final de la matriz temp_right,
    almacene el siguiente elemento de temp_left en el siguiente elemento
    en la matriz A*/

    //PRUEBA DE ESCRITORIO
      /*             i i+1
         temp_left:  4, 9, 12
                     j j+1
         temp_right: 5, 8, 14
                     k k+1
                  a: 4, 5,
      */
    if ((i < left_length) && //si i no es menor que la longitud izq
        (j >= right_length || temp_left[i] <= temp_right[j]))
        //si j es mayor o igual que la lomgitud derecha
        //verifica si entre la matriz izq y derecha es menor o igual sino se
        //ejecuta el else
    {
      a[k] = temp_left[i]; //el índice right se guarda en
      i++;
    }
    /*de lo contrario, si el siguiente elemento en temp_right que el siguiente
    elemento en temp_left O hemos llegado al final de temp_left, almacene el
    siguiente elemento de la matriz temp_right en el siguiente elemento de la
    matriz a*/
    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }
}


/* Example visualization of the merge sort algorithm:

          [38, 27, 43, 3, 9, 82, 10]
                     /   \
       [38, 27, 43, 3]   [9, 82, 10]
        /         |         |      \
   [38, 27]    [43, 3]   [9, 82]   [10]
    /   |      /    |    /    \      |
 [38]  [27]  [43]  [3]  [9]   [82]  [10]
    \  /       \   /     \     /     |
   [27, 38]    [3, 43]   [9, 82]    [10]
       \         /          \        /
     [3, 27, 38, 43]        [9, 10, 82]
           \                  /
          [3, 9, 10, 27, 38, 43, 82]

 The array is first broken up into progressively smaller unsorted portions of
 the array, and once we have "sub-arrays" of 1 element they are by definition
 sorted arrays.  From here the "sorted arrays" are merged together until we
 arrive at the complete sorted array.
*/
