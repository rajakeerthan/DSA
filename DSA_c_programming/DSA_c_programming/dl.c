#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
void insert_at_head(){
	int i,n;
	printf("enter no.of elements u want to insert at head\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		struct node *new_node,*temp;
		new_node=(struct node *)malloc(sizeof(struct node));
		printf("enter new node data\n");
		scanf("%d",&new_node->data);
		new_node->next=NULL;
		new_node->prev=NULL;
		if(head==NULL){
			head=new_node;
			head->prev=NULL;
		}
		else{
			temp=head;
			new_node->next=temp;
			temp->prev=new_node;
			head=new_node;	
		}
		
	}	
}
void insert_at_tail(){
	int i,n;
	printf("enter no.of elements u want to insert at tail\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		struct node *new_node,*temp;
		new_node=(struct node *)malloc(sizeof(struct node));
		printf("enter new node data\n");
		scanf("%d",&new_node->data);
		new_node->next=NULL;
		new_node->prev=NULL;
		if(head==NULL){
			head=new_node;
			head->prev=NULL;
		}
		else{
			temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=new_node;
			new_node->prev=temp;
			tail=new_node;
		}
		
	}	
		
}
void insert_at_pos(){
	int i=1,pos;
	struct node *ptr=head,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("enter new-node data\n");
	scanf("%d",&new_node->data);
	printf("enetr at which position u want to insert node\n");
	scanf("%d",&pos);
	for(i=1;i<pos-1;i++)
	{
		ptr=ptr->next;
	}
	ptr->next->prev=new_node;
	new_node->prev=ptr;
	new_node->next=ptr;
	
}
void delete_at_pos(){
	int i=1,pos;
	struct node *temp1=head,*temp2;
	temp2=head->next;
	printf("enetr at which position u want to delete node\n");
	scanf("%d",&pos);
	for(i=1;i<pos-1;i++)
	{
		temp1=temp1->next;
		temp2=temp2->next;
	}
	temp1->next->prev=temp2;
	temp2->next=temp1->next;
}
void delete_at_head(){
	int i,n;
	printf("enter no.of elemnts u want to delete at head\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(head==NULL){
			printf("list is empty\n");
			break;
		}
		else{
			head=head->next;
			//head->next->prev=NULL;
		}
	}
}
void delete_at_tail(){
	int i,n;
	struct node *temp;
	printf("enter no.of elemnts u want to delete at tail\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(head==NULL){
			printf("list is empty\n");
			break;
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			//temp=temp->prev;
			temp->prev->next=NULL;
			//printf("deleted successfully\n");
		}
	}
}
void printlist(){
	struct node *ptr=head;
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		printf("the list is\n");
		while(ptr!=NULL){
			printf("%d",ptr->data);
			ptr=ptr->next;
		}
	}
	printf("\n");	
}
void printlist_rev(){
	struct node *ptr=head,*temp;
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		printf("the list in revrese order\n");
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		tail=ptr;
		temp=tail;
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->prev;
		}
	}
	printf("\n");	
}
void count(){
	int count=0;
	struct node *ptr=head;
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		while(ptr!=NULL){
			count++;
			ptr=ptr->next;
		}
	}
	printf("total no.of nodes int he list are %d\n",count);	
}
int main(){
	int i,n;
	while(1){
	printf("1.insert at head\n2.insert at tail\n,3.insert at a position\n4.delete at a position\n5.delete at head\n6.delete at tail\n7.print list\n8.reverse print the list\n9.count the no.of nodes in the  list\n10.exit\n");
	printf("choose your option\n");
	scanf("%d",&n);
	switch(n){
		case 1:insert_at_head();break;
		case 2:insert_at_tail();break;
		case 3:insert_at_pos();break;
		case 4:delete_at_pos();break;
		case 5: delete_at_head();break;
		case 6:delete_at_tail();break;
		case 7:printlist();break;
		case 8:printlist_rev();break;
		case 9:count();break;
		case 10:exit(1);break;
	}
	}
return 0;
}
