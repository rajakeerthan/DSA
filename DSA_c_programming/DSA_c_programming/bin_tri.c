#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root;
struct node *insert();
struct node *insert(){
	int x;
	struct node *nn;
	printf("enter data to insert -1 to exit\n");
	scanf("%d",&x);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=x;
	if(x==-1){	
		return 0;
	}
	if(root==NULL){
		root=nn;
	}
	printf("enter left child of %d\n",x);
	nn->left=insert();
	printf("enter right child of %d\n",x);
	nn->right=insert();
	return nn;
}
void print(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d",root->data);
	print(root->left);
	print(root->right);
}
void print(struct node *root,int key){
	if(root==NULL){
		printf("tree is empty\n");
		return;
	}ss
	if(root->data==key){
		printf("element found\n");
		return ;
	}
		search(root->left);
	search(root->right);
}
int main(){
//null();
	int n,x;
	while(1){
		printf("choose\n1.insert\n2.print\n3.exit\n4.search\n5.delete\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				root=insert();break;
			case 2:print(root);break;
			case 3:exit(0);break;
			case 4:printf("enter data to search\n");
	scanf("%d",&x);search(root,x);break;
			//case 5:delete();break;
		}
	}
return 0;
}
