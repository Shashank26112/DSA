#include<stdio.h>
#include<stdlib.h>
void push(int*,int);
void pop(int*,int);
void display(int*,int);
int top=-1;
int main()
{
	int *s,n,ch;
	printf("\n Enter the size of the Stack: ");
	scanf("%d",&n);
	s = (int*) malloc(n*sizeof(int));
	while(1)
	{
		printf("\n########Stack Operations######\n");
		printf("\n 1. PUSH Operation\n");
		printf("\n 2. POP Operation\n");
		printf("\n 3. Display Operation\n");
		printf("\n 4. Exit \n");
		printf("\n Enter your choice::  ");
		scanf("%d",&ch);
		switch(ch)
		{

			case 1: push(s,n);
				break;
			case 2: pop(s,n);
				break;
			case 3: display(s,n);
				break;
			case 4: exit(0);
				break;
			default: printf("\n Entered Wrong Choice!!!!\n");
		} //End of switch
	} // End of while
	return;
}// End of Main

void push(int s[],int n)
{
	if(top==(n-1))
	{
		printf("\n The Stack is FULL!!!\n");
		return;
	}
	printf("\n Enter the Element to Stack:: ");
	scanf("%d",&s[++top]);
	return;
}
void pop(int s[],int n)
{
	if(top==-1)
	{
		printf("\n The Stack is Empty!!!\n");
		return;
	}
	printf("\n The Element deleted from Stack is: %d\n", s[top--]);
	return;
}
void display(int s[],int n)
{
	int i;	
	if(top==-1)
	{
		printf("\n The Stack is Empty!!!\n");
		return;
	}
	printf("\n The Elements in Stack are::\n");
	for(i=top;i>-1;i--)
		printf("%d\n",s[i]);
	return;
}

