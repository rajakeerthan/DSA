#include<stdio.h>
#include<stdlib.h>
#define  max 10
int stack[10];
int top=-1;
void push(){
	int element;
	printf("enter element to add into the stack\n");
	scanf("%d",&element);
	if(top>max-1){
		printf("stack overflow\n");
	}
	else{
		stack[++top]=element;
	}
}
void pop(){
	if(top<0){
		printf("stack underflow\n");
	}
	else{
		top--;
	}
}
void display(){
	int i;
	for(i=0;i<=top;i++){
		printf("%d",stack[i]);
	}
}
int main(){
	int i;
	
	while(1){
		printf("choose you option\n");
	printf("1.push\t2.pop\t3.pop");
	scanf("%d",&i);
		switch(i){
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
		}
	}
return 0;
}
