/*P3.3 Program of circular linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

/*Insert new node at the beginning of the list */
struct node *insert_at_beg(struct node *head,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	if(head)
	{
		temp->link=head->link;
		head->link=temp;
	}
	else
	{
		head=temp;
		head->link=head;
	}
	return head;
}/*End of insert_at_beg( )*/

/*Insert new node at the end of the list*/
struct node *insert_at_end(struct node *head,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	if(head)
	{
		temp->link=head->link;
		head->link=temp;
		head=temp;
	}
	else
	{
		head=temp;
		head->link=head;
	}
	return head;
}/*End of insert_at_end( )*/

/*Insert new node after the given node in a list*/
struct node *insert_after_given_node(struct node *head,int data,int item)
{
	struct node *temp,*p;
	p=head->link;
	do
	{
		if(p->info==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data;
			temp->link=p->link;
			p->link=temp;
			if(p==head)
				head=temp;
			return head;
		}
		p=p->link;
	}while(p!=head->link);
	printf("%d not present in the list\n",item);
	return head;
}/*End of insert_after_given_node()*/

/* Deleting node from the list*/
struct node *del(struct node *head,int data)
{
	struct node *temp,*p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return head;
	}
	/*Deletion of only node*/
	if(head->link==head && head->info==data)  
	{
		temp=head;
		head=NULL;
		free(temp);
		return head;
	}
	/*Deletion of first node*/
	if(head->link->info==data)    
	{
		temp=head->link;
		head->link=temp->link;
		free(temp);
		return head;
	}
	/*Deletion in between*/
	p=head->link;
	while(p->link!=head)
	{
		if(p->link->info==data)     
		{
			temp=p->link;
			p->link=temp->link;
			free(temp);
			return head;
		}
		p=p->link;
	}
	/*Deletion of head node*/
	if(head->info==data)    
	{
		temp=head;
		p->link=head->link;
		head=p;
		free(temp);
		return head;
	}
	printf("Element %d not found\n",data);
	return head;
}/*End of del( )*/

/*Traverse the list or display every element in the list */
void display(struct node *head)
{
	struct node *p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=head->link;
	do 
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=head->link);
	printf("\n");
}/*End of display( )*/

int main( )
{
	int choice,data,item;
	struct node	*head=NULL;
	
	while(1)
	{
		printf("1.Display\n");
		printf("2.Insert new node at the beginning\n");
		printf("3.Insert new node at the end\n");
		printf("4.Insert new node after the given element\n");
		printf("5.Delete\n");
		printf("6.Quit\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			display(head);
			break;
		 case 2:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			head=insert_at_beg(head,data);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			head=insert_at_end(head,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			head=insert_after_given_node(head,data,item);
			break;
		 case 5:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			head=del(head,data);
			break;
		 case 6:
		 	exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
	return 0;
}/*End of main( )*/
