#include<stdio.h>
void quicksort(int a[],int low,int high)
{
	int s;	
	if(low<=high)
	{	
		s = partition(a,low,high);
		quicksort(a,low,s-1);
		quicksort(a,s+1,high);
	}
}

int partition(int a[], int low,int high)
{
	int pivot,i,j,temp;
	pivot = a[low];
	i=low+1;
	j=high;
	
	while (i<=j)
	{
		while(a[i] <= pivot && i<=high)
			i++;
		while(a[j] > pivot)
			j--;
		if(i<=j)
		{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		}
	}
	temp = a[j];
	a[j] = a[low];
	a[low] = temp;
	return j;
}

int main()
{
	int a[20],n,i;
	printf("\n Enter the size of array\n");
	scanf("%d",&n);
	printf("\n Enter the elements to array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	printf("\n The sorted elements of array\n");
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
	printf("\n");
	return;
}
