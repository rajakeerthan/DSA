#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *create();
void display(struct node *);
struct node *root;
int main(){
	root=create();
	display(root);
return 0;
}
struct  node *create(){
	int x;
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data -1 to exit\n");
	scanf("%d",&x);
	if(x==-1){
		return 0;
	}
	nn->data=x;
	printf("enter left child o %d",x);
	nn->left=create();
	printf("enter right child of %d",x);
	nn->right=create();
	return nn; 
}

void display( struct node *temp){
	if(temp==NULL){
		return ;
	}
	printf("%d",temp->data);
	display(root->left);
	display(root->right);
}
	
