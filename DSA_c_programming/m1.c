#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	nn->next=NULL;
	if(top==NULL)
		top=nn;
	else{
		nn->next=top;
		top=nn;
	}
}
void pop(){
	struct node *temp=top;
	if(top==NULL){
		printf("stack underflow\n");
	}
	else{
		temp=top;
		top=top->next;
		free(temp);
	}
}
void display(){
	struct node *temp=top;
	if(top==NULL){
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
			push();break;
		case 2:
			pop();break;
		case 4:
			display();break;
		default:
			printf("invalid input\n");break;
		}
	}
return 0;
}
