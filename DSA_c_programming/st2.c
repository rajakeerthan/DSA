#include<stdio.h>
#define max 10
int top=-1;
int a[max];
void push(){
	printf("enter elemnt in th array\n");
	scanf("%d",&a[++top]);
}
void pop(){
	if(top==-1)
		printf("empty\n");
	else
		printf("%d",a[top--]);
}
void display(){
	int i=0;
	if(top==-1)
		printf("empty\n");
	else{
		for(i=0;i<=top;i++){
			printf("%d",a[i]);
		}
	}
}
int main(){
	while(1){
		int n;
		printf("choose\n");
		printf("1.push\n2.pop\n3.display\n");
		scanf("%d",&n);
		switch(n){
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
		}
	}
return 0;
}
