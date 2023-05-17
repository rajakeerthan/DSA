#include<stdio.h>
#include<stdlib.h>
struct avlnode{
	int data;
	int height;
	struct node *left;
	struct node *right;
};
typedef struct avlnode *node;
node root=NULL;
int height(node t){
		return (t==NULL)?0:t->height;}
		
int isempty(){
	return (root==NULL)?1:0;
}
int max(int x,int y){
	return (x>y)?x:y;
}
node createnode(int value){
	node temp=NULL;
	temp=(node)malloc(sizeof(struct avlnode));
	temp->data=value;
	temp->height=0;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int getheightbalance(node t){
	return (t==NULL)?0:(height(t->left)-height(t->right)) 
}
node insert(node t,int value){
	
	if(t==NULL){
		return createnode(value);
	}
	else if(value<t->data){
		t->left=insert(t->left,value);
	}
	else if(value>t->data){
		t->tight=insert(t->right,value);
	}
	else return t;
	t->height=max(height(t->left),height(t->right)) + 1;
	int balance=getbalance(t);
	if(balance>1&& value<t->left->data)
		return rightrotate(t);
	if(balance<-1&& value>t->right->data)
		return leftrotate(t);
	if(balance>1 && value>t->left->data){
		t->left=leftrotate(t->left);
		return rightrotate(t);
	}
	if(balance<-1 && value<t->right->data){
		t->right=rightrotate(t->right);
		return leftrotate(t);
	}
	return t;
}
node leftrotate(node k){
	node y=k->right;
	node t2=y->left;
	y->left=k;
	k->right=t2;
	k->height=max(height(k->left),height(k->right)) + 1;
	y-<height=max(height(y->left),height(y->right)) + 1;
	return y;
}
node rightrotate(node k){
	node y=k->left;
	node t2=y->right;
	
	y->right=k;
	k->left=t2;
	k->height=max(height(k->left),height(k->right)) + 1;
	y-<height=max(height(y->left),height(y->right)) + 1;
	return y;
}
void display(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d-->",root->data);
	display(root->left);
	display(root->right);
}
void main(){
	root=insert(root,4);
	root=insert(root,5);
	root=insert(root,6);
	root=insert(root,7);
	root=insert(root,9);
	root=insert(root,19);
	root=insert(root,13);
	root=insert(root,12);
	root=insert(root,14);
	root=insert(root,17);
	root=insert(root,2);
	root=insert(root,1);
	display(root);
}
