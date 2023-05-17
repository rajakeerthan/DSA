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
struct node *min(struct node *root){
	struct node *temp;
	temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	printf("min=%d",temp->data);
	return temp;
}
struct node *delete(struct node *root,int x){
		struct node *temp;
		if(root==NULL){
			printf("no\n");
		}
		else if(root->data==x){
			printf("found\n");
			if(root->left==NULL && root->right==NULL)
				root=NULL;
			else if(root->left==NULL){
				struct node *temp2=root->right;
				free(root);	
				return temp2;
			}
			else if(root->right==NULL){
				struct node *temp1= root->left;
			free(root);
			return temp1;
				/*struct node *ptr=root->left;
				free(root);
				return ptr;*/
			}
			else{
				struct node* temp = min(root->right);
		root->data = temp->data;
		root->right = delete(root->right, temp->data);
				/*temp=min(root->right);
				root->data=temp->data;
				root->right=delete(root->right,temp->data);*/
			}
			return root;
		}
		else if(root->data<x){
			root->right=delete(root->right,x);
		}
		else
			root->left=delete(root->left,x);
}
void display(struct node *root){
	if(root==NULL){
		return ;
	}
	printf("%d",root->data);
	display(root->left);
	display(root->right);
}
void search(struct node *root,int x){
	int m;
	if(root==NULL){
		return ;
	}
	else if(root->data==x){
		printf("element found\n");
		return ;
	}
	else if(root->data>=x)
		search(root->left,x);
	else
		search(root->right,x);
}
int main(){
	int n,data;
	while(1){
		printf("choose\n1.create\n2.display\n3.exit\n4.search\n5.delete\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data to insert\n");
				scanf("%d",&data);
				create(head,data);break;
			case 2:display(head);break;
			case 3:exit(0);break;
			case 4:printf("enter data to insert\n");
				scanf("%d",&data);
				search(head,data);break;
			case 5:printf("enter data to insert\n");
				scanf("%d",&data);
				delete(head,data);break;
		}
	}
return 0;
}
