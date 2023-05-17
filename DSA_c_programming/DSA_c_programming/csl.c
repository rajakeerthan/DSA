#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
void createnode_tail(){
	int n,i;
	printf("enter no.of nodes u want to add\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	struct node *new_node,*temp;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("enter new node data\n");
	scanf("%d",&new_node->data);
	if(head==NULL)
		head=tail=new_node;
	else{
		 tail->next=new_node;
		 new_node->next=head;
		tail=new_node;
		}
	}
}
void insert_pos(){
	int pos,i;
	printf("enter at which psition u want to insert\n");
	scanf("%d",&pos);
	if(pos==1){
		createnode_tail();
	}
	else{
	struct node *new_node,*temp=head;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("enter new_node data\n");
	scanf("%d",&new_node->data);
	for(i=1;i<pos-1;i++){
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	}
}
void del_head(){
	int *k;
	if(head==NULL)
		printf("list is empty\n");
	else{
		head=head->next;
		tail->next=head;
		
	}
}
void del_head(){
	int *k;
	if(head==NULL)
		printf("list is empty\n");
	else{
		head=head->next;
		tail->next=head;
		
	}
}
void createnode_head(){
	int n,i;
	printf("enter no.of nodes u want to add\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	struct node *new_node,*temp;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("enter new node data\n");
	scanf("%d",&new_node->data);
	if(head==NULL)
		head=tail=new_node;
	else{
		 tail->next=new_node;
		 new_node->next=head;
		head=new_node;
		}
	}
}
void printlist(){
	struct node *temp=head;
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		do{
		printf("%d",temp->data);
		temp=temp->next;
		}while(temp!=head);
	}
	printf("\n");
}
void count(){
	int count=0;
	struct node *temp=head;
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		do{
		count++;
		temp=temp->next;
		}while(temp!=head);
	}
	printf("total no.of nodes are %d\n",count);
}
int main(){
	createnode_tail();
	createnode_head();
	printlist();
	//insert_pos();
	
	del_head();
	printlist();
return 0;
}
