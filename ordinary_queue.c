#include<stdio.h>
#include<stdlib.h>

int rear=-1,front=0;
void insert(int q[],int n)
{
	if(rear==(n-1))
	{
		printf("\n Queue Full!!!!!\n");
		return;
	}
	printf("\n Enter the Queue Element:: ");
	scanf("%d",&q[++rear]);
}
void delete(int q[])
{
	if(front > rear)
	{
		printf("\n Queue Empty!!!!!\n");
		return;
	}
	if(front == rear)
	{
		printf("\n The Element deleted from queue is %d\n",q[front]);
		front=0;
		rear=-1;
		return;
	}
	printf("\n The Element deleted from queue is %d\n",q[front++]);
}
void display(int q[])
{
	int i;	
	if(front > rear)
	{
		printf("\n Queue Empty!!!!!\n");
		return;
	}
	printf("\n The Elements in Queue are\n");
	for(i=front;i<=rear;i++)
		printf("%d\t",q[i]);
	printf("\n");
}
int main()
{
	int q[20],n,ch;
	printf("\n Enter the size of Queue:: ");
	scanf("%d",&n);
	while(1)
	{
		printf("\n******Queue********\n");
		printf("\n 1. Insert\n");
		printf("\n 2. Delete\n");
		printf("\n 3. Display\n");
		printf("\n 4. Exit\n");
		printf("\n Enter Your choice ::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(q,n);
				break;
			case 2: delete(q);
				break;
			case 3: display(q);
				break;
			case 4: exit(0);
				break;
			default: printf("\n Wrong choice!!!!!\n");
		}
	}
	return;
}
