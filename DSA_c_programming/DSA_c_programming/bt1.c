#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root=NULL;
struct node *create();
void display();
int main(){
	int k;
	while(1){
		printf("\nchoose\n1.create\n2.display\n3.exit\n");
		scanf("%d",&k);
		switch(k){
			case 1:root=create();break;
			case 2:display(root);break;
			case 3:exit(0);
		}
	}
}
struct node *create(){
	int x;
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter x -1 to exit\n");
	scanf("%d",&x);
	if(x==-1)
		return 0;
	nn->data=x;
	printf("enter left child %d",x);
	nn->left=create();
	printf("enter right child of %d",x);
	nn->right=create();
	return nn;
}
void display(struct node *temp){
	if(temp==NULL)
		return ;
	printf("%d",temp->data);
	display(temp->left);
	display(temp->right);
}
