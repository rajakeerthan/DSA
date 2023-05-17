#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int prior;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enq();
void deq();
void display();
int main(){
	int n;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\nenter  n value\n");
		scanf("%d",&n);
		switch(n){
			case 1:enq();break;
			case 2:deq();break;
			case 3:display();break;
			case 4:exit(0);
		}
	}
return 0;
}
void enq(){
	struct node *nn,*temp=front;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter element in the new node----");
	scanf("%d",&nn->data);
	printf("enter priority of the new node------\n");
	scanf("%d",&nn->prior);
	nn->next=NULL;
	if(front== NULL || nn->prior < front->prior)
	{
		nn->next=front;
		front=nn;
	}
	else
	{
		while(temp->next!=NULL && temp->next->prior <= nn->prior)
		{
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
}
/*void enq(){
	int data,prior;
	printf("enter data and prior\n");
	scanf("%d",&data);
	scanf("%d",&prior);
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=data;
	nn->prior=prior;
	nn->next=NULL;
	if(front==NULL || front->prior > prior)
	{
		nn->next=front;
		front=nn;
	}
	else{
		struct node *temp=front;
		while(temp->next->prior > prior || temp->next!=NULL){
				temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
}*/
void deq(){
	if(front==NULL)
		printf("underflow\n");
	else{
		front=front->next;
	}
}
/*void display(){
	struct node *temp=front;
	while(temp!=NULL){
		printf("%d--->%d",temp->data,temp->prior);
	}
	
	
}*/
void display()
{
	struct node *temp=front;
	if(temp==NULL){
		printf("queue is empty\n");
		return;
	}
	while(temp!=NULL){
		printf("\n%d--%d",temp->data,temp->prior);
		temp=temp->next;
	}
	printf("\n");
}
