#include<stdio.h>
int main()
{
	int a[10],n,i,sume,sumo;
	printf("\n Enter the size of array\n");
	scanf("%d",&n);
	printf("\n Enter the elements to array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sume=0;
	sumo=0;	
	for(i=0;i<n;i++)
	{
		if(a[i] > 0)
		{
			if(a[i]%2==0)
			{
				sume=sume+a[i];
			}
			else
			{
			sumo=sumo+a[i];
			}
		}
	}
	printf("\n The sum of even numbers in array is %d\n",sume);
	printf("\n The sum of odd numbers in array is %d\n",sumo);
	return;
}
