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

NODE insert_pos(int item,NODE first,int pos)
{
	NODE cur,temp;
	int i;
	temp=getnode();
	temp->info = item;
	cur=first;
	if(pos == 1)
	{
		temp->link = first;
		return temp;
	}
	else
	{
		for(i=1;i<pos-1 && cur!=NULL;i++)
			cur = cur->link;
		if(cur!=NULL)
		{
			temp->link = cur->link;
			cur->link = temp;
			return first;
		}
		else
		{
			printf("\n wrong position\n");
			return first;
		}
	}
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

NODE delete_rear(NODE first)
{
	NODE cur,prev=NULL;
	if(first == NULL)
	{
		printf("\n List is Empty\n");
		return first;
	}
	if(first->link == NULL)
	{
		cur = first;
		first = NULL;
		printf("\n Element deleted %d\n",cur->info);
		free(cur);
		return first;
	}
	cur = first;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link = NULL;
	printf("\n the Deleted element in List is %d\n",cur->info);
	free(cur);
	return first;
}

NODE delete_pos(NODE first,int pos)
{
	NODE cur,prev=NULL;
	int i;
	if(first == NULL)
	{
		printf("\n List is Empty\n");
		return first;
	}
	cur = first;
	if(pos == 1)
	{
		cur = first->link;
		printf("\n Element deleted is %d\n",first->info);
		free(first);
		return cur;
	}
	else
	{
		for(i=1;i<pos && cur!=NULL;i++)
		{
			prev = cur;
			cur = cur->link;
		}
		if(cur!=NULL)
		{
			prev->link = cur->link;
			printf("\n the element deleted is %d\n",cur->info);
			free(cur);
			return first;
		}
		else
		{
			printf("\n Wrong choice\n");
			return first;
		}
	} // Main else
}
	
int main()
{
	int ch,item,pos;
	NODE first=NULL;
	while(1)
	{
		printf("\n********Single Linked List****\n");
		printf("\n 1. Insert_front\n");
		printf("\n 2. Insert_position\n");
		printf("\n 3. Display\n");
		printf("\n 4. Delete_rear\n");
		printf("\n 5. Delete_Position\n");
		printf("\n 6. EXIT\n");
		printf("\n Enter your choice:::");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("\n Enter element to list:::");
				scanf("%d",&item);
				first = insert_front(item,first);
				break;
			case 2: printf("\n Enter element to list:::");
				scanf("%d",&item);
				printf("\n Enter position to insert element::");
				scanf("%d",&pos);
				first = insert_pos(item,first,pos);
			case 3: display(first);
				break;
			case 4: first = delete_rear(first);
				break;
			case 5: printf("\n Enter position to insert element::");
				scanf("%d",&pos);
				first = delete_pos(first,pos);
				break;
			case 6: exit(0);
				break;
			default: printf("\n Wrong Choice\n");
		}
	}
	return;
}
