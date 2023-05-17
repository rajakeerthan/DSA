#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
void insert_at_head(){
	int new,n,i=0;
	printf("enter no.of elemts you wanted to insert in the list\n");
	scanf("%d",&n);
	while(i<n){
	struct node *new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("enter new node data to insert at head\n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	if(head==NULL){
		head=new_node;
		tail=new_node;
	}
	else{
		new_node->next=head;
		head=new_node;
	}
	i++;
	}
	
}
void insert_at_tail(){
	int new,n,i=0;
	printf("enter no.of elemts you wanted to insert in the list\n");
	scanf("%d",&n);
	while(i<n){
	struct node *new_node,*temp;
	new_node=(struct node 	*)malloc(sizeof(struct node));
	printf("enter new node data to insert at tail\n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	if(head==NULL){
		head=new_node;
		tail=new_node;
	}
	else{
		tail->next=new_node;
		new_node->next=NULL;
		tail=new_node;
		/*temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;*/
	}
	i++;
	}
}
void delete_at_head(){
	int element;
	int new,n,i=0;
	printf("enter no.of elemts you wanted to delete in the list\n");
	scanf("%d",&n);
	while(i<n){
	if(head==NULL)
		printf("invalid selection\n there is no items in the list\n");
	else{
		element=head->data;
		head=head->next;
		printf("succssfully deleted head node and the data value is %d\n",element);
	} 
	i++;
	}
		
}
void delete_at_tail(){
	struct node *temp=head;
	int element;
	int new,n,i=0;
	printf("enter no.of elemts you wanted to delete in the list\n");
	scanf("%d",&n);
	while(i<n){
	if(head==NULL){
		printf("invalid selection\n there is no items in the list\n");
	}
	else{
		element=tail->data;
		while(temp!=NULL){
			temp=temp->next;
		}
		tail=temp;
	}
	printf("succssfully deleted tail node and the data value is %d\n",element);
	i++;
	}
				
}
void printlist(){
	struct node *ptr=head;
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		while(ptr!=NULL){
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
	printf("\n");
}
void count(){
	struct node *ptr=head;
	int count=0;
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		while(ptr!=NULL){
			count++;
			ptr=ptr->next;
		}
	}
	printf("there were %d no.of nodes in the list\n",count);
	//return count;
}
void delete_at_pos(){
	int pos,i=1,c;
	struct node *ptr=head,*new_node;
	printf("enter at which position u want to insert the data\n");
	scanf("%d",&pos);
	
	for(i=1;i<pos-1;i++)
	{
		ptr=ptr->next;
	}
	ptr->next=ptr->next->next;
}
void insert_at_pos(){
	int pos,i=1,c;
	struct node *ptr=head,*new_node;
	printf("enter at which position u want to insert the data\n");
	scanf("%d",&pos);
	printf("enter data to be inserted\n");
	scanf("%d",&new_node->data);
	
	
	for(i=1;i<pos-1;i++)
	{
		ptr=ptr->next;
	}
	new_node->next=ptr->next;
	ptr->next=new_node;
}
int main(){
	int i;
	while(1){
	printf("choose your option\n");
	printf("1.create at list by inserting at head\n2. create at list by inserting at tail\n3.delete a node at head\n4.dalete a node at tail\n5.print list\n6.to know the no.of elemnts in the list\n7.exit\n8.inert at a position\n9.delete at pos\n");
	scanf("%d",&i);
	
	switch(i){
		case 1:insert_at_head();break;
		case 2:insert_at_tail();break;
		case 3:delete_at_head();break;
		case 4:delete_at_tail();break;
		case 5:printlist();break;
		case 6:count();break;
		case 7:exit(1);break;
		case 8:insert_at_pos();break;
		case 9:delete_at_pos();break;
			
	}}
return 0;
}
