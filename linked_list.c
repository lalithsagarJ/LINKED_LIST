#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
NODE start=NULL;
NODE getnode()
{
 	NODE new_node;
	new_node=(NODE)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("no memory \n");
		exit(0);
	}
	else
		return new_node;
}
NODE create_list(NODE);
NODE display(NODE);
NODE insert_beg(NODE);
NODE insert_end(NODE);
NODE insert_at_position(NODE);
NODE delete_beg(NODE);
NODE delete_end(NODE);
NODE delete_at_position(NODE);
NODE traverse(NODE);

int main()
{
	int option;
	do
	{
		printf("\n      options     ");
		printf("\n1.create list");
		printf("\n2.display");
		printf("\n3.insert at beginning");
		printf("\n4.insert at end");
		printf("\n5.insert at position");
		printf("\n6.delete at beginning");
		printf("\n7.delete at end");
		printf("\n8.delete at position");
		printf("\n9.traverse");
		printf("\n0.exit");
		printf("\nenter your choice :");
		scanf("%d",&option);
	
	switch(option)
	{
		case 1:start=create_list(start);
			printf("\nthe linked list is created ");
			break;
		case 2:start=display(start);
			break;
		case 3:start=insert_beg(start);
			break;
		case 4:start=insert_end(start);
			break;
		case 5:start=insert_at_position(start);
			break;
		case 6:start=delete_beg(start);
			break;
		case 7:start=delete_end(start);
			break;
		case 8:start=delete_at_position(start);
			break;
		case 9:start=traverse(start);
			break;
		case 0:exit(0);
			break;
	}
	}while(option!=0);
	return 0;
}

NODE create_list(NODE start)
{
	NODE new_node,ptr;
	int n;
	printf("\nenter -1 to exit (or)");
	printf("\nenter a number :");
	scanf("%d",&n);
	while(n!=-1)
	{
		new_node=getnode();
		new_node->data=n;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("\nenter the data:");
		scanf("%d",&n);
	}
	return start;
}

NODE display(NODE start)
{
	NODE ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

NODE insert_beg(NODE start)
{
	NODE new_node;
	int n;
	printf("\nenter the data :");
	scanf("%d",&n);
	new_node=getnode();
	new_node->data=n;
	new_node->next=start;
	start=new_node;
	return start;
}

NODE insert_end(NODE start)
{
	NODE ptr,new_node;
	int n;
	printf("\nenter the data:");
	scanf("%d",&n);
	new_node=getnode();
	new_node->data=n;
	new_node->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	return start;
}

NODE insert_at_position(NODE start)
{
	int n,p;
	NODE new_node;
	new_node=getnode();
	printf("\nenter a number:");
	scanf("%d",&n);
	printf("\nenter the position:");
	scanf("%d",&p);
	new_node->data=n;
	int c=1;
	if(p==1)
	{
		new_node->next=start;
		start=new_node;
	}
	else
	{
		NODE ptr=start;
		while(c<p-1)
		{
			ptr=ptr->next;
			c++;
		}
		new_node->next=ptr->next;
		ptr->next=new_node;
	}	
	return start;
}

NODE delete_beg(NODE start)
{
	NODE temp=start;
	if(start==NULL)
		printf("\nlist is empty ");
	else
	{
		start=start->next;
		free(temp);
	}
	return start;
}

NODE delete_at_position(NODE start)
{
	NODE ptr,preptr;
	int c,p;
	printf("\nenter the position to be deleted ");
	scanf("%d",&p);
	if(start==NULL)
		printf("\nlist is  empty ");
	else
	{
		if(p==1)
		{
			preptr=NULL;
			ptr=start;
		}
		else
		{
			preptr=start;
			ptr=start->next;
			c=2;
			while(c!=p)
			{
				preptr=ptr;
				ptr=ptr->next;
				c++;
			}
			if(preptr==NULL)
				start=ptr->next;
			else
				preptr->next=ptr->next;
			free(ptr);
		}
	}
	return start;
}

NODE delete_end(NODE start)
{
	NODE ptr,preptr;
	if(start==NULL)
	{
		printf("\nlist is empty ");
	}
	else
	{
		if(start->next==NULL)
		{
			ptr=start;
			start=NULL;
		}
		else
		{
			preptr=start;
			ptr=start->next;
			while(ptr->next!=NULL)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			preptr->next=NULL;
			free(ptr);
		}
	}
	return start;
}

NODE traverse(NODE start)
{
	NODE ptr;
	if(start==NULL)
		printf("\nno elements in list");
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
	return start;
}
