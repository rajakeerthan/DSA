#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int count=0;
struct node *head=NULL;
struct node *create(struct node *root,int x){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=x;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL){
		root=nn;
		head=nn;
	}
	else if(root->data<x && root->right==NULL){
		root->right=nn;
	}
	else if(root->data>=x && root->left==NULL){
		root->left=nn;
	}
	else if(root->data<x)
		create(root->right,x);
	else
		create(root->left,x);
}
void display(struct node *root){
	if(root==NULL){
		return ;
	}
	printf("%d",root->data);
	display(root->left);
	display(root->right);
}
void counts(struct node *root){
	if(root==NULL){
		return ;
	}
	count++;
	counts(root->left);
	counts(root->right);
	
}
int main(){
	int n,data;
	while(1){
		printf("choose\n1.create\n2.display\n3.exit\n4.count\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data to insert\n");
				scanf("%d",&data);
				create(head,data);break;
			case 2:display(head);break;
			case 3:exit(0);break;
			case 4:counts(head);
				printf("count=%d",count);break;
		}
	}
return 0;
}
