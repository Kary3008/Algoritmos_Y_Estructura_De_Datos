#include <stdio.h>
void binary_search(int a[], int x, int low, int high);

int main()
{
	int n, i, x;
	
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int array[n];
	
	printf("Enter the elements in a sorted manner: \n");
	for(i=0; i<n; i++)
		scanf("%d", &array[i]);
	printf("Enter the value to find: ");
	scanf("%d", &x);
	
	int low=0;
	int high= n-1;
	
	binary_search(array,x,low,high);
	
	return 0;
}

void binary_search(int a[], int x, int low, int high)
{
	int mid;
	
	mid = (low + high) /2;
	
	while(low<=high)
	{
		if(a[mid]<x)
			low= mid +1;
		else if(a[mid]==x)
		{
			printf("%d found at the location %d", x, mid+1);
			break;
		}
		else 
		high=mid -1;
		mid = (low + high)/2;
	}
	if(low>high)
	printf("%d is not present in the array, ", x);
}