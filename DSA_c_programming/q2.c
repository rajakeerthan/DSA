#include<stdio.h>
#define MAX 20
front=rear=-1;
int a[max];
void enqueue(){
	int data;
	printf("enter data\n");
	scanf("%d",&data);
	a[++top]=data;
}
void dequeue(){
	if(top==-1){
		printf("empty\n");
	else
		top--;
}
void display(){
	int i;
	if(top==-1){
		printf("empty\n");
	}
	else{
		for(i=0;i<=top;i++){
			printf("%d",a[i]);
	}
}
int main(){
	int n;
	while(1){
		printf("choos\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:enqueue();break;
			case 2:dequeue();break;	
			case 3:display();break;
			case 4:exit(0);break;
		}
	}
return 0;
}
