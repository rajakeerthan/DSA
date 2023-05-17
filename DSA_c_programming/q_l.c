#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void enq();
void deq();
void display();
int main(){
	int n;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\nenter  n value\n");
		scanf("%d",&n);
		switch(n){
			case 1:enq();break;
			case 2:deq();break;
			case 3:display();break;
			case 4:exit(0);
		}
	}
return 0;
}
struct node *top=NULL;
void enq(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	if(top==NULL)
		top=nn;
	else{
		struct node *temp=top;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=nn;
	}
}
void deq(){
	if(top==NULL)
		printf("underflow\n");
	else
		top=top->next;
}
void display(){
	struct node *temp=top;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
}

