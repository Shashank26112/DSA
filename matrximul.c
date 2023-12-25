#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10][10],b[10][10],m,n,p,q,i,j,k;
	static int c[10][10];
	printf("\n Enter the size of Matrix A\n");
	scanf("%d%d",&m,&n);
	printf("\n Enter the elements to Matrix A\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("\n Enter the size of Matrix B\n");
	scanf("%d%d",&p,&q);
	printf("\n Enter the elements to Matrix B\n");
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&b[i][j]);
   if(n==p)
   {
	for(i=0;i<m;i++)
		for(j=0;j<q;j++)
			for(k=0;k<n;k++)
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
    }
    else
    {
	printf("\n Matrix multiplication is not possible\n");
	exit(0);
     }
	printf("\n the multiplication of Matrix A & B is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return;
}



