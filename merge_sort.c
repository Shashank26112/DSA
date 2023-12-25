#include<stdio.h>

void merge_sort(int a[20], int low, int high); 
void sort(int a[20], int low, int mid, int high);

int main()
{
	int n,a[20],i;
	printf("\n Enter size of array: "); 
	scanf("%d",&n);
	printf("\n Enter the array:\n"); 
	for(i=0;i<n;i++)
		scanf("%d",&a[i]); 
	merge_sort(a,0,n-1);
	printf("\nSorted array is: "); 
	for (i = 0; i < n; i++)
		printf("%d ", a[i]); 
	return 0;
}

void merge_sort(int a[20], int low, int high)
{
	int mid; 
	if(low<high)
	{
		mid=(low+high)/2; 
		merge_sort(a, low, mid); 
		merge_sort(a, mid+1,high); 
		sort(a, low, mid, high);
	}
}

void sort(int a[20], int low, int mid, int high)
{
	int i,j,k,c[20]; 
	i=low; j=mid+1; k=low;
	while(i<=mid && j<=high)
	{
		if(a[i] < a[j])
		{
			c[k]=a[i]; 
			k++;
			i++;
		}
		else
		{
			c[k]=a[j]; 
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		c[k]=a[i]; 
		k++;
		i++;
	}	
	while(j<=high)
	{
		c[k]=a[j]; 
		k++;
		j++;
	}
	for(i=low;i<k;i++)
		a[i]=c[i];
}
