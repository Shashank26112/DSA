#include<stdio.h> 
#include<stdlib.h>

struct node
{
int info;
struct node *llink, *rlink;
};
typedef struct node *NODE;

NODE insert_beginning(NODE head); 
NODE insert_rear(NODE head); 
void display(NODE head);
NODE delete_front(NODE head);
NODE delete_rear(NODE head);
NODE getnode();

int main()
{
	NODE head;
	int ch;
	head=getnode();
	head->llink=head;
	head->rlink=head; 
	while(1)
	{
		printf("\n 1.Insert Beginning"); 
		printf("\n 2.Insert End");
 		printf("\n 3.Display");
		printf("\n 4.Delete_front");
		printf("\n 5.Delete_rear"); 
		printf("\n 6.exit");
		printf("\n Enter your choice: "); 
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:head=insert_beginning(head); 
			break;
			case 2:head=insert_rear(head); 
			break;
			case 3:display(head);
			break;
			case 4:head=delete_front(head);
			break;
			case 5:head=delete_rear(head);
			break;
			case 6:exit(0); 
			break;
			default:printf("\n Enter correct choice.\n");
		}
	}
}
NODE getnode()
{
return((struct node*) malloc(sizeof(struct node*)));
}

NODE insert_beginning(NODE head)
{
	NODE newnode, cur; 
	newnode=getnode();
	printf("\n Enter the new element: "); 
	scanf("%d",&newnode->info); 
	cur = head->rlink;
	head->rlink = newnode; 
	newnode->rlink=cur;
	newnode->llink=head; 
        cur->llink=newnode; 
	return(head);
}

NODE insert_rear(NODE head)
{
	NODE temp, cur; 
	temp=getnode();
	printf("\n Enter the element: "); 
	scanf("%d",&temp->info); 
	cur=head->llink;
	head->llink=temp;
	temp->rlink=head;
	temp->llink=cur;
	cur->rlink=temp;
	return head;
}

void display(NODE head)
{
	NODE temp; 
	if(head->llink==head)
	{
		printf("\n List is empty.\n"); 
		return;
	}
	temp=head->rlink;
	printf("\n List is: \n"); 
	while(temp != head)
	{
		printf("%d->",temp->info); 
		temp=temp->rlink;
	}
	printf("NULL\n");
}

NODE delete_front(NODE head)
{
	NODE cur, next;
	if(head->rlink == head)
	{
		printf("\n List Empty\n");
		return head;
	}
	cur = head->rlink;
	next = cur->rlink;
	head->rlink = next;
	next->llink = head;
	printf("\n deleted node is %d\n",cur->info);
	free(cur);
	return head;
}

NODE delete_rear(NODE head)
{
	NODE cur, prev;
	if(head->rlink == head)
	{
		printf("\n List Empty\n");
		return head;
	}
	cur = head->llink;
	prev = cur->llink;
	head->llink = prev;
	prev->rlink = head;
	printf("\n deleted node is %d\n",cur->info);
	free(cur);
	return head;
}
