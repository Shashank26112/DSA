#include<stdio.h>
#include<math.h>
#include<string.h>
int compute(int op1,int op2,char symbol)
{
	switch(symbol)
	{
		case '+': return op1+op2;
		case '-': return op1-op2;
		case '*': return op1*op2;
		case '/': return op1/op2;
		case '%': return op1%op2;
	}
	return;
}

int main()
{
	double s[20],op1,op2,res;
	int top,i;
	char postfix[15],symbol;
	top=-1;
	printf("\n Enter the postfix expression::\n");
	scanf("%s",postfix);
	for(i=0;i<strlen(postfix);i++)
	{
		symbol = postfix[i];
		if(isdigit(symbol))
		{
			s[++top]=symbol-'0';
		}
		else
		{
			op2 = s[top--];
			op1 = s[top--];
			res = compute(op1,op2,symbol);
			s[++top] = res;
		}
	} // end of for
	res = s[top];
	printf("\n The Result of postfix expr::: %lf\n",res);
	return;
}
