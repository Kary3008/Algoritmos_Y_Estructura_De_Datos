#include <stdlib.h>
#include <stdio.h>
//#include <string.h>

int main()
{
	int key;
	int a[] = {2, 6, 1, 10, 5, 2};
	int tam = sizeof(a);
	int tam1 = sizeof(a[0]);
	int longt = (tam / tam1);
	//auto size_of_vec = a.size();
	//int j = 1;
	for(int j = 0 ; j <longt ; j++)
	{
		key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
	printf("%d\n", a);
}
