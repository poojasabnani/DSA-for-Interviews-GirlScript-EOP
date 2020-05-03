## Various types of Linked List and their implementations

Program to implement Singly Linked List in C

```c
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

```
Demo program to show implementation of singly Linked List in C++

```c
#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int val) : data(val),next(nullptr) { }
    ~node() {
        if(next != nullptr)
            delete next;
    }
};
class List {
    node* head;
    node* findHelper(int val){
        node* temp = head;
        while(temp != nullptr){
            if(temp->data == val){
                break;
            }
            temp = temp->next;
        }
        return temp;
    }
public:
    List(){
        head = nullptr;
    }
    friend void reverse(List);
    void insert(int val){
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }
    void remove(int val){
        node* findNode = findHelper(val);
        if(findNode == nullptr){ // this will handle both cases 1. if LL is empty and 2. node not present
            cout<<"Node not found\n";
            return;
        }
        if(findNode == head){ // special case
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        node* oneNodePrev = head;
        while(oneNodePrev->next != findNode){
            oneNodePrev = oneNodePrev->next;
        }
        // now we have access to node previous to the target
        // now modify the links
        oneNodePrev->next = findNode->next;
        delete findNode;
    }
    void display(){
        node* temp = head;
        if(isEmpty()){
            cout<<"list is empty!\n";
            return;
        }
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    bool isEmpty(){
        if(head == nullptr)
            return true;
        return false;
    }
    bool find(int val){
        node* findNode = findHelper(val);
        if(findNode != nullptr)
            return true;
        return false;
    }

};
void reverse(List l){
    //
}
void fun(){
    List l;
    l.insert(32);
    l.insert(321);
    l.insert(32);
    l.insert(321);
    l.insert(32);
    l.insert(321);
    l.display();
}

int main(){
    List mlist;
    fun();
    mlist.insert(45);
    mlist.insert(31);
    mlist.display();
    mlist.remove(421);
    mlist.display();
    mlist.remove(31);
    mlist.display();
    mlist.remove(45);
    mlist.display();
}
```

Program to implement Doubly Linked List in C

```c
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
```

Program to implement Circular Linked List in C

```c

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

```

