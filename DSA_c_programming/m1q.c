#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *front=NULL;
void enqueue(){
	struct node *nn,*temp;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	nn->next=NULL;
	temp=front;
	if(front==NULL)
		front=nn;
	else{
		if(temp->next!=	NULL){
			temp=temp->next;
		}
		temp->next=nn;
		nn->next=NULL;
	
	}
}
void dequeue(){
	struct node *temp=front;
	if(front==NULL){
		printf("queue underflow underflow\n");
	}
	else{
		temp=front;
		front=front->next;
		free(temp);
	}
}
void display(){
	struct node *temp=front;
	if(front==NULL){
		printf("stack underflow\n");
	}
	else{
		while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;}
		
	}
}
int main(){
	int n;
	while(1){
	printf("select 1. push\n or 2.pop\n 3.display\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			enqueue();break;
		case 2:
			dequeue();break;
		case 3:
			display();break;
		default:
			printf("invalid input\n");break;
		}
	}
return 0;
}
