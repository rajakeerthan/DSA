#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head=NULL;
void enqueue(struct node **q,int *f,struct node *nn);
struct node *dequeue(struct node **q,int *r);
struct node *create(struct node *root,int data){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=data;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL){
		root=nn;
		head=nn;
	}
	else if(data<root->data && root->left==NULL)
		root->left=nn;
	else if(data>=root->data && root->right==NULL)
		root->right=nn;
	else if(data<root->data)
		create(root->left,data);
	else
		create(root->right,data);
}
void level(struct node *root){
	int f=0,r=0;
	struct node **q;
	q=(struct node **)malloc(sizeof(struct node *) * size);
	if(root==NULL)
		return ;
	struct node *temp=root;
	while(temp!=NULL){
		printf("%d",temp->data);
		if(temp->left!=NULL)
			enqueue(q,&r,temp->left);
		if(temp->right!=NULL)
			enqueue(q,&r,temp->right);
		temp=dequeue(q,&f);
	}
}
/*void levelorder(struct node *root){
	int front=0,rear=0;
	struct node** queue=(struct node **)malloc(sizeof(struct node *) * size);
	if(root==NULL)
		return;
	struct node *temp=root;
	while(temp!=NULL){
		printf("%d",temp->data);
		if(temp->left!=NULL){
			enqueue(queue,&rear,temp->left);
		}
		if(temp->right!=NULL){
			enqueue(queue,&rear,temp->right);
		}
		temp=dequeue(queue,&front);
	}
	
}*/
void enqueue(struct node** q,int *r,struct node *nn){
	q[*r]=nn;
	(*r)++;
}
struct node *dequeue(struct node** q,int *f){
	(*f)++;
	return q[(*f)-1];
}
/*void enqueue(struct node** queue,int *rear,struct node *ptr){
		queue[*rear]=ptr;
		(*rear)++;
}
struct node* dequeue(struct node** queue,int *front){
	(*front)++;
	return queue[*front -1];
}*/
void display(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d-->",root->data);
	display(root->left);
	display(root->right);
}
int main(){
	int n,x,key;
	while(1){
		printf("choose\n1.insert\n2.display\n3.exit\n4.level display\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter new node data\n");
				scanf("%d",&x);
				create(head,x);break;
			case 2:
				display(head);break;
			case 3:	exit(0);break;
			case 4:
				level(head);break;
		}
	}
return 0;
}
