#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void push(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	if(head==NULL){
		head=nn;	
	}
	else{
		nn->next=head;
		head=nn;
	}
}
void pop(){
	if(head==NULL){
		printf("empty\n");
	}
	else{
		head=head->next;
	}
}
void display(){
	struct node *temp;
	if(head==NULL){
		printf("empty\n");
	}
	else{
		temp=head;
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
int main(){
	int n;
	while(1){
		printf("1.push\n2.pop\n,3.Display\n");
		scanf("%d",&n);
		switch(n){
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
		}
	}
return 0;
}
