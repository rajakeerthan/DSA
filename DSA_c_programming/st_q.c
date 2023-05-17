#include<stdio.h>
#include<stdlib.h>
#define max 50
int st1[max],st2[max];
int top1=-1;
int top2=-1;
void push1(int );
int pop1();
void push2(int );
int pop2();
void display1();
void enq();
int deq();
int front=-1;
int rear=-1;
int main(){
	int n,data;
	while(1){
		printf("\n1.enqueue\n2.dequq\n3.display\n4.exit\n5.sort\nenter  n value\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data\n");
			scanf("%d",&data);
			enq(data);break;
			case 2:deq();break;
			case 3:display1();break;
			case 4:exit(0);
			//case 5:dup();break;
		}
	}

return 0;
}
void enq(int data){
	push1(data);
	front=0;rear++;
}
int deq(){
	int m;
	while(top1!=-1){
		m=pop1();
		push2(m);
	}
	m=pop1();
	front++;
	while(top2!=-1){
		m=pop2();
		push1(m);
	}
	return m;

}
void push2(int data){
	if(top2>=max-1)
		printf("overflow\n");
	else{
		
		st2[++top2]=data;
	}
}
int pop2(){
	if(top2==-1)
		printf("underflow\n");
	else{
		//printf("%d deleted\n",st2[top]);
		return st2[top2--];
	}
}
void push1(int data){
	
	if(top1>=max-1)
		printf("overflow\n");
	else{
		st1[++top1]=data;
	}
}
int pop1(){
	if(top1==-1)
		printf("underflow\n");
	else{
		return st1[top1--];
	}
}
void display1(){
	int i;
	for(i=front;i<=rear;i++)
		printf("%d",st1[i]);
}
