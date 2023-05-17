#include<stdio.h>
#include<stdlib.h>
struct node{
	int p;
	int data;
	struct node *next;
};
struct node *front=NULL;
void deq();
void enq();
void display(struct node *root);
int main(){
	int n;
	while(1){
		printf("choose\n1.enq\n2.deq\n3.exit\n4.display\n");
		scanf("%d",&n);
		switch(n){
			case 1:enq();break;
			case 2:deq();break;	
			case 4:display(front);break;
			case 3:exit(0);
		}
	}
return 0;
}
void enq(){
		int data,prior;
		printf("enter data and priority\n");
		scanf("%d",&data);
		scanf("%d",&prior);
		struct node *nn;
		nn=(struct node *)malloc(sizeof(struct node));
		nn->data=data;
		nn->p=prior;
		nn->next=NULL;
		if(front==NULL || front->p<=prior){
			nn->next=front;
			front=nn;
		}
		else{
			struct node *temp=front;
			while(temp->next->p>=prior && temp->next!=NULL){
					temp=temp->next;
			}
			nn->next=temp->next;
			temp->next=nn;
		}
}
void deq(){
	if(front==NULL)
		printf("empty\n");
	else{
		front=front->next;
	}
}
void display(struct node *root){
	//struct node *temp=root;
	while(root!=NULL){
		printf("data=%d\tprior=%d\n",root->data,root->p);	
		root=root->next;
	}
}
