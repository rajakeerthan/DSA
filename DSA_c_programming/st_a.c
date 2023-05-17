#include<stdio.h>
#include<stdlib.h>
#define max 10
int a[max];
int top=-1;
void push();
void pop();
void display();
int main(){
	int n;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\nenter  n value\n");
		scanf("%d",&n);
		switch(n){
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
			case 4:exit(0);
		}
	}
return 0;
}
void push(){
	int data;
	if(top>=max-1)
		printf("overflow\n");
	else{
		printf("enter data\n");
		scanf("%d",&data);
		a[++top]=data;
	}
}
void pop(){
	if(top==-1)
		printf("underflow\n");
	else{
		printf("%d deleted\n",a[top]);
		top--;
	}
}
void display(){
	int i;
	for(i=top;i>=0;i--)
		printf("%d",a[i]);
}
