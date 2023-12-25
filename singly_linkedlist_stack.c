#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
	return ((struct node*) malloc(sizeof(struct node*)));
}

NODE insert_front(int item,NODE first)
{
	NODE temp;
	temp = getnode();
	temp->info = item;
	temp->link = first;
	return temp;
}

void display(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("\n List is Empty\n");
		return;
	}
	temp=first;
	printf("\n the elements of the List are\n");
	while(temp!=NULL)
	{
		printf("%d--->",temp->info);
		temp=temp->link;
	}
	printf("NULL\n");
}

NODE delete_front(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("\n List is Empty\n");
		return first;
	}
	temp=first;
	temp=temp->link;
	printf("\n the Deleted element in List is %d\n",first->info);
	free(first);
	return temp;
}
	
int main()
{
	int ch,item;
	NODE first=NULL;
	while(1)
	{
		printf("\n********Singal Linked List****\n");
		printf("\n 1. Insert_front\n");
		printf("\n 2. Display\n");
		printf("\n 3. Delete\n");
		printf("\n 4. EXIT\n");
		printf("\n Enter your choice:::");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("\n Enter element to list:::");
				scanf("%d",&item);
				first = insert_front(item,first);
				break;
			case 2: display(first);
				break;
			case 3: first = delete_front(first);
				break;
			case 4: exit(0);
				break;
			default: printf("\n Wrong Choice\n");
		}
	}
	return;
}
