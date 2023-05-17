#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node{
	int data;
	struct node *left;
	struct node *right;
};
void enqueue(struct node**, int* ,struct node*);
struct node *dequeue(struct node**,int *);
struct node *head=NULL;
void levelorder(struct node *root){
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
	
}
void enqueue(struct node** queue,int *rear,struct node *ptr){
		queue[*rear]=ptr;
		(*rear)++;
}
/*void enqueue(struct node** queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}*/
struct node* dequeue(struct node** queue,int *front){
	(*front)++;
	return queue[*front -1];
}
/*struct node* dequeue(struct node** queue, int* front)
{
    (*front)++;
    return queue[*front - 1];
}*/
struct node *create(){
	int x;
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data -1 to exit\n");
	scanf("%d",&x);
	if(x==-1)
		return 0;
	nn->data=x;
	printf("enter left chile node of %d\n",x);
	nn->left=create();
	printf("enter right childe of %d\n",x);
	nn->right=create();
	return nn;
}
void print(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d",root->data);
	print(root->left);
	print(root->right);
}
int main(){
	head=create();
	print(head);
	printf("\n");
	printf("levelorder:\n");
	levelorder(head);
return 0;
}
