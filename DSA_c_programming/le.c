#include<stdio.h>
#include<stdlib.h>
#define size 40
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head=NULL;
struct node *dequeue(struct node **,int *);
void enqueue(struct node **,struct node *,int *);
void levelorder(struct node *root){
	int front=0,rear=0;
	struct node **queue=(struct node **)malloc(sizeof(struct node *)*size);
	
	struct node *temp=root;
	
	while(temp!=NULL){
		printf("%d-->",temp->data);
		if(temp->left!=NULL)
			enqueue(queue,temp->left,&rear);
		if(temp->right!=NULL)
			enqueue(queue,temp->right,&rear);
		temp=dequeue(queue,&front);
	}
}
void enqueue(struct node **q,struct node *ptr,int *rear){
	q[*rear]=ptr;
	(*rear)++;
}
struct node *dequeue(struct node **q,int *front){
	(*front)++;
	return q[*front-1];
}
void print(struct node *root){

	if(root==NULL)
		return ;
	printf("%d-->",root->data);
	print(root->left);
	print(root->right);
}
struct node *create(){
		int x;
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data -1 to exit\n");
	scanf("%d",&x);
	if(x==-1)
		return 0;
	nn->data=x;
	printf("left child of %d",x);
	nn->left=create();
	printf("right child of %d",x);
	nn->right=create();
	return nn;
}
int main(){
	head=create();
	print(head);
	printf("\nleveorder:\n");
	levelorder(head);
return 0;
}

