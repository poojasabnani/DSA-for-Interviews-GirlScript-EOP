/* Program of doubly linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
};

/*Traverse the list or display every element in the list */
void display(struct node *head)
{
	struct node *p;
	if(head==NULL)
	{
		printf("List is empty\n\n");
		return;
	}
	p=head;
	printf("List is :\t");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n\n");
}/*End of display() */

/*Insert new node at the beginning of the list */
struct node *insert_at_beginning(struct node *head, int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=head;
	if(head)
		head->prev=temp;
	head=temp;
	return head;
}/*End of insert_at_beg( )*/

/*Insert new node at the end of the list*/
struct node *insert_at_end(struct node *head,int data)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=head;
	if(p)
	{
		while(p->next!=NULL)
			p=p->next;

		p->next=temp;
		temp->next=NULL;
		temp->prev=p;
	}
	else
		head=temp;
	return head;
}/*End of insert_at_end( )*/

/*Insert new node after the given node in a list*/
struct node *insert_after_given_node(struct node *head,int data,int item)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=head;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			temp->prev=p;
			temp->next=p->next;
			if(p->next!=NULL) 
				p->next->prev=temp;
			p->next=temp;
			return head;	
		}
		p=p->next;
	}
	printf("%d not present in the list\n\n",item);
	return head;
}/*End of insert_after_given_node()*/

/* Deleting node from the list*/
struct node *del(struct node *head,int data)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return head;
	}
	if(head->next==NULL)	/*only one node in the list*/
	{
		if(head->info==data) 
		{
			temp=head;
			head=NULL;
			free(temp);
			return head;
		}
		else
		{
			printf("Element %d not found\n",data);
			return head;
		}
	}
	/*Deletion of first node*/
	if(head->info==data)
	{
		temp=head;
		head=head->next;  
		head->prev=NULL;
		free(temp);
		return head;
	}

	/*Deletion in between*/
	temp=head->next;
	while(temp->next!=NULL )
	{
		if(temp->info==data)     
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			return head;
		}
		temp=temp->next;
	}

	/*Deletion of last node*/
	if(temp->info==data)
	{
		temp->prev->next=NULL;
		free(temp);
		return head;
	}
	printf("Element %d not found\n",data);
	return head;
}/*End of del()*/

/*Revering the element in a linked list*/
struct node *reverse(struct node *head)
{
	struct node *p1,*p2;
	p1=head;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev; 
	}
	head=p1;
	printf("List reversed\n");
	return head;
}/*End of reverse()*/

int main()
{
	int choice,data,item;
	struct node *head=NULL;
	while(1)
	{
		printf("1.Display\n");
		printf("2.Insert new node at the beginning\n");
		printf("3.Insert new node at the end\n");
		printf("4.Insert new node after the given element\n");
		printf("5.Delete\n");
		printf("6.Reverse\n");
		printf("7.Quit\n");
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
			printf("\n");
			break;
		 case 3: 
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			head=insert_at_end(head,data);
			printf("\n");
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			head=insert_after_given_node(head,data,item);
			printf("\n");
			break;
		 case 5:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			head=del(head,data);
			printf("\n");
	   		break;
		 case 6:
		 	head=reverse(head);
		 	printf("After Reversing the elements are\n");
		 	display(head);
			break;
		 case 7:
			exit(1);
		 default:
			printf("Wrong choice\n");
	}/*End of switch*/
   }/*End of while*/
   return 0;
}/*End of main()*/