#include<stdio.h>
#include<stdlib.h>
#define max 10
int st1[max],st2[max],st3[max];
int top1=-1;
int front1=-1;
int rear1=-1;
int front2=-1;
int rear2=-1;
void push1(int );
int pop1();
void enq1(int );
void enq2(int );
int deq1();
int deq2();
void display();
int main(){
	int n,data;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\n5.sort\nenter  n value\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data\n");
			scanf("%d",&data);
			push1(data);break;
			case 2:pop1();break;
			case 3:display();break;
			case 4:exit(0);
			//case 5:dup();break;
		}
	}

return 0;
}
void push1(int data){
	enq1(data);
}
int pop1(){
	int i,m;
	for(i=front1;i<=rear1;i++){
		m=deq1();
		enq2(m);
	}
	deq2();
	for(i=front2;i<=rear2;i++){
		m=deq2();
		enq1(m);
	}
}
void enq1(int data){
	if(front1==-1 && rear1==-1){
		front1=0;
		rear1=0;
		st1[rear1]=data;
		//printf("overflow\n");
	}
	else{
		st1[++rear1]=data;
	}
}
int deq1(){
	if(front1==rear1){
		front1=rear1=-1;
	}
	else{
		front1++;
		return st1[front1-1];
	}
}
int deq2(){
	if(front2==rear2){
		front2=rear2=-1;
	}
	else{
		front2++;
		return st2[front2-1];
	}
}
void enq2(int data){
	//int data;
	if(front2==-1 && rear2==-1){
		front2=0;
		rear2=0;
		st2[rear2]=data;
		//printf("overflow\n");
	}
	else{
		st2[++rear2]=data;
	}
}
void display(){
	int i;
	for(i=rear1;i>=front1;i--){
		printf("%d",st1[i]);
	}
}
