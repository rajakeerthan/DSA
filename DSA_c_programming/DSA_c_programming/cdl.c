#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
void createnode_tail(){
		int n,i;
		printf("enter no.of nodes you want to add\n");
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			struct node *new_node,*temp;	
			new_node=(struct node *)malloc(sizeof(struct node));
			printf("enter new node data\n");
			scanf("%d",&new_node->data);
			if(head==NULL){
				head=new_node;
				tail=new_node;
			}
			else{
				tail->next=new_node;
				new_node->next=head;
				tail=new_node;
			}
	}
}
void createnode_head(){
		int n,i;
		printf("enter no.of nodes you want to add\n");
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			struct node *new_node,*temp;	
			new_node=(struct node *)malloc(sizeof(struct node));
			printf("enter new node data\n");
			scanf("%d",&new_node->data);
			if(head==NULL){
				head=new_node;
				tail=new_node;
			}
			else{
				tail->next=new_node;
				new_node->prev=tail;
				new_node->next=head;
				head->prev=new_node;
				head=new_node;
			}
	}
}
void insert_pos(){
	int pos,i;
		printf("enter at which position you want to add\n");
		scanf("%d",&pos);
		
			struct node *new_node,*temp=head;	
			new_node=(struct node *)malloc(sizeof(struct node));
			printf("enter new node data\n");
			scanf("%d",&new_node->data);
			for(i=1;i<pos-1;i++){
				temp=temp->next;
			}
			temp->next->prev=new_node;
			new_node->next=temp->next;
			temp->next=new_node;
}
void delete_head(){
	struct node *temp=head;
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		head=head->next;
		head->prev=tail;
		tail->next=head;
		
	}
}
void delete_tail(){
	struct node *temp=head;
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		tail=tail->prev;
		tail->next=head;
		head->prev=tail;
	}
}
void delete_pos(){
		int i,pos;
		printf("enter at which position you want to add\n");
		scanf("%d",&pos);
		struct node *temp=head;
		for(i=1;i<pos-1;i++){
			temp=temp->next;
		}
		
}
void printlist(){
	struct node *ptr=head;
	if(head==NULL){
		printf("list is empty\n");
	}	
	else{
		do{
			printf("%d",ptr->data);
			ptr=ptr->next;
		}while(ptr!=head);
		printf("\n");
	}
}
int main(){
	createnode_tail();
	createnode_head();
	printlist();
	delete_head();
	printlist();
	delete_tail();
	insert_pos();
	printlist();
return 0;
}
