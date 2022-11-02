#include <stdio.h>
#include <stdlib.h>
void indexedSearch(int arr[], int n, int key);
void seqSearch(int arr[], int start, int end , int key);

int main()
{
	//int arr[]={1,3,4,6,9,10,15,19,25,29,60,90,100};
	//int n = sizeof(arr)/sizeof(arr[0]);
	int arr[100];
	int n;
	int key, i;
	
	printf("How many elements you want in array: ");
	scanf("%d", &n);
	
	printf("Enter array elements\n");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
		
	printf("Array elements are below\n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
		
	printf("\nEnter the key which you want to search: ");
	scanf("%d", &key);
	
	/*printf("How many elements you want in array: ");
	scanf("%d", &n);
	
	printf("Array elements are below\n");
	for(i = 0; i < n; i++)
		scanf("%d ", arr[i]);
		
	printf("\nEnter the key which you want to search: ");
	scanf("%d", &key);*/
	
	indexedSearch(arr, n, key);
	//seqSearch(arr, 0, n-1, key);
}

void indexedSearch(int arr[], int n, int key)
{
	int index[20], i;
	int j = 0, x = 0, start, end, bs;
	printf("enter block size: ");
	scanf("%d", &bs);
	
	for(i=0; i<n; i=i+bs)
		index[x++]=i;
		
	if(key<arr[index[0]] || key>arr[index[x-1]])
	{
		printf("key is not found in array");
		exit(0);
	}
	else
	{
		for(i=1; i<=x; i++)
			if(key<=arr[index[i]])
			{
				start=index[i-1];
				end= start+bs;
				break; 
			}
	}
	seqSearch(arr, start, end, key);
}

void seqSearch(int arr[], int start, int end , int key)
{
	int i, flag = 0;
	for(i = start; i <= end; i++)
	{
		if(key == arr[i])
		{			
			flag=1;
			break;
		}
	}
	if(flag == 1)
		printf("key is found at position number %d", i + 1); //i+1
	else
	printf("Key is not found in array");
}

