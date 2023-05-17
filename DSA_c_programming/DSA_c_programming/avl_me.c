#include<stdio.h>
#include<stdlib.h>
struct avlnode{
	int data;
	int height;
	struct node *left;
	struct node *right;
};
//typedef struct avlnode *node;
struct avlnode *head=NULL;
struct avlnode *insert(struct avlnode *root,int data){
		struct avlnode *nn;
		nn=(struct avlnode *)malloc(sizeof(struct avlnode));
		nn->data=data;
		nn->left=NULL;
		nn->right=NULL;
		nn->height=0;
}
int main(){
	int n,value;
	while(1){
		printf("choose\n1.insert\n2.duspla\n3.exit\n");
		switch(n){
			case 1:printf("enter value\n");
				scanf("%d",&value);
				insert(root,value);break;
			case 2:display(root);break;
			case 3:exit(0);break;
		}
	}
return 0;
}
void display(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d-->",root->data);
	display(root->left);
	display(root->right);
}

