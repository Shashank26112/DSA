#include<stdio.h>
int main()
{
	int n,a[10],max,min,i;
	printf("Eneter the n value:\n");
	scanf("%d",&n);
	printf("\n Enter the values for array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	min=a[0];
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(max < a[i])
			max=a[i];
		if(min > a[i])
			min=a[i];
	}
	printf("\n The largest value is : %d and smallest value is : %d\n",max,min);
	return;
}
