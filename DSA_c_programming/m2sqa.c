#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX];
int front=-1;
int rear=-1;
void enqueue(){
	int data;
	printf("enter data\n");
	scanf("%d",&data);
	if(front==0 & rear==MAX-1)
		printf("queue overflow\n");
	else if(front==-1&rear==-1){
			front=rear=0;
			a[rear]=data;}
	else{
		rear=(rear+1)%MAX;
		a[rear]=data;
	}
}
void dequeue(){
	int temp;
	if(front==-1){
		
		printf("underflow underflow\n");
	}
	else{
		temp=a[front];
		if(front=rear)
			front=rear=-1;
		
		front=(front+1)%MAX;
	}
}
void display(){
	int i;
	if(front==-1){
		printf("empty queue\n");
	}
	else{
		for(i=0;i<=rear;i++){
			printf("%d",a[i]);
		}
		
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
		case 4:
			display();break;
		default:
			printf("invalid input\n");break;
		}
	}
return 0;
}
