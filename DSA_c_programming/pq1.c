#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int prior;
	struct node *next;
};
struct node *front;
void enqueue(){
	struct node *nn,*temp;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	printf("enter priority of the new node\n");
	scanf("%d",&nn->prior);
	temp=front;
	if(front==NULL || nn->prior<front->prior)
		front=nn;
	else 
		temp=top;
		while(temp!=NULL){
			if(temp->prior>=nn->prior){
				nn->next=temp->next;
				temp->next=nn;}
			temp=temp->next;
		}
	}
}
void dequeue(){
	if(top==NULL)
		printf("empty\n");
	else{
		top=top->next;
	}
}
void display(){
	struct node *temp;
	if(top==NULL)
		printf("empty\n");
	else{
		temp=top;
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
int main(){
	int n;
	while(1){
		printf("choos\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:enqueue();break;
			case 2:dequeue();break;	
			case 3:display();break;
			case 4:exit(0);break;
		}
	}
return 0;
}
