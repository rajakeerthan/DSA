#include<stdio.h>
#include<stdlib.h>
#define max 10
int st1[max],st2[max],st3[max];
int top1=-1;
int top2=-1;
int top3=-1;
void push1(int );
int pop1();
void push2(int );
int pop2();
void push3(int );
int pop3();
void display1();
void dup();
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
			case 3:display1();break;
			case 4:exit(0);
			case 5:dup();break;
		}
	}

return 0;
}
void dup(){
	int x,y,z,m;
	while(top1!=0){
		x=pop1();
		push2(x);	
		while(top1!=-1){
			y=pop1();
			if(st2[top2]==y){
				printf("deleted\n");
			}
			else{
				push3(y);
			}
		}
		while(top3!=-1){
			z=pop3();
			push1(z);
		}
	}
	while(top2!=-1){
			z=pop2();
			push1(z);
		}
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
void push3(int data){
	if(top3>=max-1)
		printf("overflow\n");
	else{
		st3[++top3]=data;
	}
}
int pop3(){
	if(top3==-1)
		printf("underflow\n");
	else{
		
		return st3[top3--];
	}
}
void display1(){
	int i;
	for(i=top1;i>=0;i--)
		printf("%d",st1[i]);
}
