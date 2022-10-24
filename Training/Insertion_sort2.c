#include <stdio.h>
void insertion_sort(int a[], int length);

int main()
{
    int a[] = {5, 2, 4, 6, 1, 3};
    for(int i = 0; i < 6; i++)
    {
        printf("%i | ", a[i]);
    }
    printf("\n\n");
    insertion_sort(a,6);
    for(int i = 0; i < 6; i++)
    {
        printf("a[%i] = %i\n", i, a[i]);
    }

}

void insertion_sort(int a[], int length)
{
    for(int j=1; j<=length - 1; j++)
    {
        int key = a[j];
        int i = j - 1;
        while(i>=0 && a[i]>key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1]= key;
    }
}
