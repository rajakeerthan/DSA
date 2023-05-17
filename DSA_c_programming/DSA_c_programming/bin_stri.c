#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
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
	else if(data<root->data && root->left==NULL){
			root->left=nn;
	}
	else if(data>root->data && root->right==NULL){
			root->right=nn;
	}
	else if(data<root->data){
		insert(root->left,data);
	}
	else{
		insert(root->right,data);
	}
}
void pre_print(struct node *root){
	if(root==NULL){
		return;
	}
	
	pre_print(root->left);
	printf("%d\t",root->data);
	pre_print(root->right);
}
int main(){
//null();
	int n,x;
	while(1){
		printf("choose\n1.insert\n2.print\n3.exit\n4.search\n5.delete\n");
		scanf("%d",&n);
		switch(n){
			case 1:	printf("enter data to insert -1 to exit\n");
				scanf("%d",&x);
				insert(head,x);break;
			case 2:pre_print(head);break;
			case 3:exit(0);break;
			//case 4:printf("enter data to search\n");
	//scanf("%d",&x);search(root,x);break;
			case 5:delete();break;
		}
	}
return 0;
}
