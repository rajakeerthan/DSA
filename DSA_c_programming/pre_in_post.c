#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
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
void display_in_order(struct node *root){
	if(root==NULL){
		return ;
	}
	
	display_in_order(root->left);
	printf("%d",root->data);
	display_in_order(root->right);
}
void display_pre_order(struct node *root){
	if(root==NULL){
		return ;
	}
	printf("%d",root->data);
	display_pre_order(root->left);
	display_pre_order(root->right);
}
void display_post_order(struct node *root){
	if(root==NULL){
		return ;
	}
	
	display_post_order(root->left);
	display_post_order(root->right);
	printf("%d",root->data);
}
int main(){
	int n,data;
	while(1){
		printf("choose\n1.create\n2.display in order\n3.exit\n4.pre order\n5.post order\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data to insert\n");
				scanf("%d",&data);
				create(head,data);break;
			case 2:printf("in order\n");display_in_order(head);break;
			case 3:exit(0);break;
			case 4:printf("pre order\n");display_pre_order(head);break;
			case 5:printf("post order\n");display_post_order(head);break;
		}
	}
return 0;
}
