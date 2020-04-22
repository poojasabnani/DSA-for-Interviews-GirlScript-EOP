/* P3.1 Program for a single linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

/*Traverse the list or display every element in the list */
void display(struct node *head)
{
	struct node *p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=head;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}/*End of display() */

/* Count number of elements in a list*/
void count(struct node *head)
{
	struct node *p;
	int cnt=0;
	p=head;
	while(p!=NULL)
	{
		p=p->link;
		cnt++;
	}
	printf("Number of elements are %d\n", cnt);
}/*End of count() */

/*Search an element in the given list */
void search(struct node *head,int item)
{
	struct node *p=head;
	int pos=1;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			printf("Item %d found at position %d\n",item,pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("Item %d not found in list\n",item);
}/*End of search()*/

/*Insert new node at the beginning of the list */
struct node *insert_at_beg(struct node *head,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=head;
	head=temp;
	return head;
}/*End of insert_at_beg()*/

/*Insert new node at the end of the list*/
struct node *insert_at_end(struct node *head,int data)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=NULL;
	p=head;
	if(p)
	{
		while(p->link!=NULL)
			p=p->link;
		p->link=temp;
	}
	else
		head=temp;
	return head;
}/*End of insert_at_end()*/

/*Insert new node after the given node in a list*/
struct node *insert_after_given_node(struct node *head,int data,int item)
{
	struct node *temp,*p;
	p=head;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data;
			temp->link=p->link;
			p->link=temp;
			return head;
		}
		p=p->link;
	}
	printf("%d not present in the list\n",item);
	return head;
}/*End of insert_after_given_node()*/

/*Insert new node at the given position*/
struct node *insert_at_pos(struct node *head,int data,int pos)
{
	struct node *temp,*p;
	int i;

	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	if(pos==1)
	{
		temp->link=head; 
		head=temp;
		return head;
	}
	p=head;
	for(i=1; i<pos-1 && p!=NULL; i++)
		p=p->link;
	if(p==NULL)
		printf("There are less than %d elements\n",pos);
	else
	{
		temp->link=p->link;
		p->link=temp;
	}	
	return head;
}/*End of insert_at_pos()*/

/* Deleting node from the list*/
struct node *del(struct node *head,int data)
{
	struct node *temp,*p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return head;
	}
	/*Deletion of first node*/
	if(head->info==data)
	{
		temp=head;
		head=head->link;  
		free(temp);
		return head;
	}
	/*Deletion in between or at the end*/
	p=head;
	while(p->link!=NULL)
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
	printf("Element %d not found\n",data);
	return head;
}/*End of del()*/

/*Revering the element in a linked list*/
struct node *reverse(struct node *head)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
   	ptr=head;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head=prev;
	return head;
}/*End of reverse()*/



int main()
{
	struct node *head=NULL;	
	int choice,data,item,pos;
		
	while(1)
	{
		printf("1.Display\n");
		printf("2.Count list\n");
		printf("3.Search element\n");
		printf("4.Insert new node at the beginning\n");
		printf("5.Insert new node at the end\n");
		printf("6.Insert new node after the given node\n");
		printf("7.Insert new node at the given position\n");
		printf("8.Delete node\n");
		printf("9.Reverse list\n");
		printf("10.Quit\n\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
		 
		 case 1:
			display(head);
			break;
		 case 2:
			count(head);
			break;
		 case 3:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			search(head,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			head=insert_at_beg(head,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			head=insert_at_end(head,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			head=insert_after_given_node(head,data,item);
			break;
		 
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert : ");
			scanf("%d",&pos);
			head = insert_at_pos(head,data,pos);
			break;
		 case 8:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			head=del(head, data);	
			break;
		 case 9:
			head=reverse(head);
			break;
		 case 10:
			 exit(1);
		 default:
			 printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/
