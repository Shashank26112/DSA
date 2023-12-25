#include<stdio.h>

int GCD(int m, int n)
{
	if(n==0) return m;
	return GCD(n,m%n);
}

int main()
{
	int m,n,gcd,lcm,temp;
	printf("\n Enter the m and n natural numbers\n");
	scanf("%d%d",&m,&n);
	if(m < n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	gcd = GCD(m,n);
	lcm = (m*n)/gcd;
	printf("\n The GCD of %d and %d is : %d\n",m,n,gcd);
	printf("\n The LCM of %d and %d is : %d\n",m,n,lcm);
	return;
}
