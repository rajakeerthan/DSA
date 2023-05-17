#include<stdio.h>
#include<stdlib.h>
#define max 20
int q1[max],q2[max];
void enq1(int );
void enq2(int );
int deq1();
int deq2();
void push();
void pop();
int k=0;
void display();
void display1();
int f1=-1,f2=-1;
int r1=-1,r2=-1;
int main(){
	int n;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\n5.display2\nenter  n value\n");
		scanf("%d",&n);
		switch(n){
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
			case 5:display1();break;
			case 4:exit(0);
		}
	}
return 0;
}
void push(){
	int data;
	printf("enter data \n");
	scanf("%d",&data);
	enq1(data);
	k++;
}
void pop(){
	int i,m,n;
	for(i=f1;i<r1;i++){
		m=deq1();
		enq2(m);
	}
	deq1();
	k--;
	for(i=f2;i<=r2;i++){
		n=deq2();
		enq1(n);
	}
	
}
void enq1(int x){
	if(f1==-1){
		f1=0;
		r1=0;
		q1[r1]=x;
	}
	else{
		q1[++r1]=x;
	}
}
void enq2(int x){
	if(f2==-1){
		f2=0;
		r2=0;
		q2[r2]=x;
	}
	else{
		q2[++r2]=x;
	}
}
int deq1(){
	if(f1==-1)
		printf("underflow\n");
	else if(r1==f1)
		f1=r1=-1;
	else{
		f1++;
		return q1[f1-1];
	}
}
int deq2(){
	if(f2==-1)
		printf("underflow\n");
	if(r2==f2)
		f2=r2=-1;
	else{
		f2++;
		return q2[f2-1];
	}
}
void display(){
	int i;
	for(i=f1;i<=r1;i++)
		printf("%d",q1[i]);
}
void display1(){
	int i;
	for(i=f2;i<=r2;i++)
		printf("%d",q2[i]);
}
