#include<stdio.h>
#include<stdlib.h>
#define max 5
int a[max];
int front=-1,rear=-1;
void enqueue();
void dequeue();
void display();
int main(){
	int n;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\nenter  n value\n");
		scanf("%d",&n);
		switch(n){
			case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			case 4:exit(0);
		}
	}
return 0;
}
void enqueue(){
	int data;
	printf("enter data\n");
		scanf("%d",&data);
	if((rear+1)%max==front)
		printf("overflow\n");
	else if(front==-1 && rear==-1){
		front=0;
		rear=0;
		a[rear]=data;	
	}	
	else{
		rear=(rear+1)%max;
		a[rear]=data;
	}
}
void dequeue(){
	if(front==-1 && rear==-1)
		printf("underflow\n");
	else if(front==rear)
		front=rear=-1;
	else{
		printf("%d deleted\n",a[front]);
		front=(front+1)%max;
	}
}
void display(){
	int i;
	i=front;
	if(front==-1){
		printf("empty\n");
	}
	while(i!=rear){
		printf("%d",a[i]);
		i=(i+1)%max;
	}
}
