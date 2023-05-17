#include<stdio.h>
#include<stdlib.h>
#define max 10
void push1(int );
void push2(int );
void enqueue(int );
void dequeue();
int pop1();
int pop2();
void display();
int main(){
	int n,data;
	while(1){
		printf("enter n 1.enqueue 2.dequeue 3.exit 4.display\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data\n");scanf("%d",&data);enqueue(data);break;
			case 2:dequeue(data);break;
			case 3:exit(0);break;	
			case 4:display();break;
		}
	}
}
int count=0;
int stack1[max];
int stack2[max];
int top1=-1,top2=-1;
void push1(int data){
	stack1[++top1]=data;
}
void push2(int data){
	stack2[++top2]=data;
}
void enqueue(int x){
	push1(x);
	count++;
}
void dequeue(){
	int i,a,b;
	if(top1==-1 && top2==-1){
		printf("overflow\n");
	}
	else{
		for(i=0;i<count;i++){
			a=pop1();
			push2(a);
		}
		b=pop2();
		printf("%d is deleted\n",b);
		count--;
		for(i=0;i<count;i++){
			a=pop2();
			push1(a);
		}
	}
	
}
int pop1(){
	return stack1[top1--];
}
int pop2(){
	return stack2[top2--];
}
void display(){
	int i;
	for(i=0;i<=top1;i++){
		printf("%d",stack1[i]);
	}
}
