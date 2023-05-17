#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX];
int top=-1;
void push(){
	int data;
	printf("enter data\n");
	scanf("%d",&data);
	if(top>MAX-1)
		printf("stack overflow\n");
	else{
		a[++top]=data;
	}
}
void pop(){
	int temp;
	if(top==-1){
		printf("stack underflow\n");
	}
	else{
		temp=a[top--];
	}
}
void display(){
	int i;
	if(top==-1){
		printf(" empty stack\n");
	}
	else{
		for(i=0;i<=top;i++){
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
