#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
};
struct node *head=NULL;
int main(){
	int k,x;
	while(1){
		printf("\nchoose\n1.create\n2.display\n3.exit\n4.search\n5.delete\n");
		scanf("%d",&k);
		switch(k){
			case 1:printf("enter data to insert\n");
				scanf("%d",&x);
				create(head,x);break;
			case 2:display(head);break;
			case 3:exit(0);
			case 4:printf("enter element to search\n");
				scanf("%d",&x);	
				search(head,x);
			case 5:printf("enter element to delete\n");
				scanf("%d",&x);
				delete(head,x);
		}
	}
}
struct node *min(struct node *root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}
void insert(struct node *root,int x){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));	
	nn->data=x;
	if(root==NULL){
		root=nn;
	}
	else if(root->left==NULL){
		root->left=nn;
	}
	else if(root->right==NULL){
		root->right=nn;
	}
	else if(x<=root->data){
		insert(root->left,x);
	}
	else{
		insert(root->right,x);
	}
}
struct node *delete(int x){
	if(root==NULL)
		return ;
	else if(x==root->data){
		if(root->left==NULL && root->right==NULL){
			root=NULL;
		}
		else if(root->right==NULL){
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		else if(root->left==NULL){
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else{
			struct node *ptr;
			ptr=min(root->right);
			root->data=ptr->data;
			root->right=delete(root->right,x);
			
		}
		
	}
	else if(x<=root->data){
		delete(root->left,x);
	}
	else{
		delete(root->right,x);
	}
}
void display(struct node *temp){
	if(temp==NULL){
		return ;
	}
	printf("%d",temp->data);
	display(root->left);
	display(root->right);
}


