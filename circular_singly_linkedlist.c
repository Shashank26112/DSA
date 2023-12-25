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

NODE insert_rear(int item,NODE last)
{
	NODE temp;
	temp = getnode();
	temp->info = item;
	if(last==NULL)
	{
		temp->link=temp;
		return temp;
	}
	temp->link = last->link;
	last->link = temp;
	return temp;
}


void display(NODE last)
{
	NODE temp;
	if(last == NULL)
	{
		printf("\n List is Empty\n");
		return;
	}
	temp=last->link;
	printf("\n the elements of the List are\n");
	while(temp!=last)
	{
		printf("%d--->",temp->info);
		temp=temp->link;
	}
	printf("%d--->",temp->info);
	printf("NULL\n");
}

NODE delete_front(NODE last)
{
	NODE first,cur;
	if(last == NULL)
	{
		printf("\n List is Empty\n");
		return last;
	}
	if(last->link == last)
	{
		cur = last;
		last = NULL;
		printf("\n Element deleted %d\n",cur->info);
		free(cur);
		return last;
	}
	first = last->link;
	last->link = first->link;
	printf("\n the Deleted element in List is %d\n",first->info);
	free(first);
	return last;
}


int main()
{
	int ch,item;
	NODE last=NULL;
	while(1)
	{
		printf("\n********Circular-Single Linked List****\n");
		printf("\n 1. Insert_rear\n");
		printf("\n 2. Display\n");
		printf("\n 3. Delete_front\n");
		printf("\n 4. EXIT\n");
		printf("\n Enter your choice:::");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("\n Enter element to list:::");
				scanf("%d",&item);
				last = insert_rear(item,last);
				break;
			case 2: display(last);
				break;
			case 3: last = delete_front(last);
				break;
			case 4: exit(0);
				break;
			default: printf("\n Wrong Choice\n");
		}
	}
	return;
}
