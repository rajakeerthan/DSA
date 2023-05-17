#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head=NULL;
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
void display(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d-->",root->data);
	display(root->left);
	display(root->right);
}
void search(struct node *root,int x){
	if(root==NULL){
		printf("element not found\n");
		return;
	}
	if(root->data==x){
		printf("element found\n");
	}
	search(root->left,x);
	search(root->right,x);
}
int main(){
	int n,data;
	while(1){
		printf("\nchoose\n1.insert\n2.display\n3.search\n,4.delete\n5.exit\n");
		scanf("%d",&n);
		switch(n){
				case 1:
					head=create();
					break;
				case 2:display(head);break;
				case 3:
					printf("enter data to search\n");
					scanf("%d",&data);
					search(head,data);
					break;
				/*case 4:
					printf("enter data to delete\n");
					scanf("%d",&data);
					delete(head,data);
					break;*/
				case 5:exit(0);break;
		}
	}
return 0;
}
