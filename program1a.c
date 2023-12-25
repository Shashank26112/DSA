#include<stdio.h>
int main()
{
	int a[10],n,i,j,flag;
	printf("\nEnter the Size of Array: ");
	scanf("%d",&n);
	printf("\n Enter the Elements to Array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n The Prime Numbers in Array are:\n");
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=2;j<a[i];j++)
		{
			if(a[i]%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("%d\n",a[i]);
	}
	return;
}
