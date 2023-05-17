#include<stdio.h>
#include<stdlib.h>

#define max 10
int q[max];
//int p[20];
int f=-1;
int r=-1;
void deq();
void display();
void enq();
int main(){
	int n;
	while(1){
		printf("choose\n1.enq\n2.deq\n3.exit\n4.display\n");
		scanf("%d",&n);
		switch(n){
			case 1:enq();break;
			case 2:deq();break;	
			case 4:display();break;
			case 3:exit(0);
		}
	}
return 0;
}
/*int element;
	printf("enter elemnt");
	scanf("%d",&element);
	if(((rear+1)%MAX)==front)
	{
		printf("queue over fl0w\n");
		return ;
	}
	else if(front ==-1)
		front=rear=0;
	else
	{
		rear=((rear+1)%MAX);
	}
	cqueue[rear]=element;*/
void enq(){
	int data;
	printf("enter data\n");
	scanf("%d",&data);
	if(f==0 && r==max-1){
		printf("overflow\n");
		return ;
	}
	else if(f==-1){
		f=0;
		r=0;
		q[r]=data;
	}
	else{
		r=(r+1)%max;
		q[r]=data;
	}
}
void deq(){
	if(f==-1)
		printf("underflow\n");
	else if(f==r){
		f=-1;
		r=-1;
	}
	else{
		f=(f+1)%max;
	}
}
void display(){
	int i;
	if(f==-1)
	{
		printf("queue is empty\n");
		return;
	}
	for(i=f;i!=r;i=(i+1)%max)
	{
		printf("%d\t",q[i]);
	}
	printf("%d\t",q[i]);
	printf("\n");
}
