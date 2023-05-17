#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head=NULL;
struct node *insert(struct node *root,int x){
	int x;
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	
	nn->data=x;
	nn->left=NULL;
	nn->right=NULL;
	if(x==-1){
		return 0;
	}
	else if(head==NULL){
		head=nn;
		root=nn;
	}
	printf("enter left child of %d",x);
	root->left=insert(root->left,int x);
	printf("enter right child of %d",x);
	insert(root->right);
	return root;
	
}
struct node *delete(struct node *root,int x){
}
void display(struct node *root){
	//struct node *temp;
	if(root==NULL)
		return ;
	printf("%d",root->data);
	display(root->left);
	display(root->right);
}

int main(){
	int n,data;
	while(1){
		printf("\nchoose\n1.insert\n2.display\n3.search\n,4.delete\n5.exit\n");
		scanf("%d",&n);
		switch(n){
				case 1:printf("enter data to insert -1 t0 exit\n");
	scanf("%d",&x);
					
					insert(head);
					break;
				case 2:display(head);break;
				case 3:
					printf("enter data to search\n");
					scanf("%d",&data);
					search(head,data);
					break;
				case 4:
					printf("enter data to delete\n");
					scanf("%d",&data);
					delete(head,data);
					break;
				case 5:exit(0);break;
		}
	}
return 0;
}
