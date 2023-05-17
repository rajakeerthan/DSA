#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head=NULL;
struct node *insert(struct node *root,int data){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=data;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL){
		root=nn;
		head=nn;
	}
	else if(data<=root->data && root->left==NULL)
		root->left=nn;
	else if(data>root->data && root->right==NULL)
		root->right=nn;
	else if(data<root->data)
		insert(root->left,data);
	else
		insert(root->right,data);
}
void display(struct node *root){
	if(root==NULL)
		return ;
	else{
		printf("%d",root->data);
		display(root->left);
		display(root->right);
	}
}
void search(struct node *root,int data){
	int m=0;
	if(root==NULL)
		printf("element not found\n");
	else if(root->data==data){
		printf("element found\n");
		m=1;
	}
	else if(data<=root->data)
		search(root->left,data);
	else
		search(root->right,data);
}
struct node *min(struct node *root){
	struct node *temp;
	temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}
struct node *delete(struct node *root,int data){
	if(root==NULL){
		printf("enter element not ound\n");
		exit(0);
	}
	if(root->data==data){
		if(root->left==NULL && root->right==NULL){
			root=NULL;
		}
		else if(root->left==NULL){
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		else{
			struct node* temp = min(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
		return root;
			
	}
	else if(root->data<data){
		root->right=delete(root->right,data);
	}
	else if(root->data>data){
		root->left=delete(root->left,data);
	}
	else{
		printf("element not found to delete\n");
	}
}
int main(){
	int n,data;
	while(1){
		printf("enter your choice \n1.create\n2.display\n3.exit\n4.searcj\n,5.delete\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data\n");
				scanf("%d",&data);
				insert(head,data);break;
			case 2:
				display(head);break;
			case 3:exit(0);break;
			case 4:printf("enter data to search\n");
				scanf("%d",&data);
				search(head,data);break;
			case 5:printf("enter data\n");
				scanf("%d",&data);
				delete(head,data);
		}
	}
return 0;
}
