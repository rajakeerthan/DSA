#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node{
	int data;
	struct node *left;
	struct node *right;
};
void enqueue(struct node **q,struct node *root,int *rear);
struct node *dequeue(struct node **q,int *front);
struct node *head=NULL;
void levelorder(struct node *root){
	int front=0,rear=0;
	struct node **q;
	q=(struct node **)malloc(sizeof(struct node *) * size);
	if(root==NULL)
		return ;
	struct node *temp;
	temp=root;
	while(temp!=NULL){
			printf("%d",temp->data);
			if(temp->left!=NULL)
				enqueue(q,temp->left,&rear);
			if(temp->right!=NULL)
				enqueue(q,temp->right,&rear);
		temp=dequeue(q,&front);
	}	
}
/*void level(struct node *root){
	int f=0,r=0;
	struct node **q;
	q=(struct node **)malloc(sizeof(struct node *) * size);
	if(root==NULL)
		return ;
	struct node *temp=root;
	while(temp!=NULL){
		printf("%d",temp->data);
		if(temp->left!=NULL)
			enqueue(q,temp->left,&r);
		if(temp->right!=NULL)
			enqueue(q,temp->right,&r);
		temp=dequeue(q,&f);
	}
}*/
void enqueue(struct node **q,struct node *root,int *rear){
	q[(*rear)]=root;
	(*rear)++;
}
struct node *dequeue(struct node **q,int *front){
	(*front)++;
	return q[(*front)-1];
}
struct node *create(struct node *root,int data){
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
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
		create(root->left,data);
	}
	else{
		create(root->right,data);
	}
}
void display(struct node *root){
	if(root==NULL)
		return ;
	printf("%d-->",root->data);
	display(root->left);
	display(root->right);
	
}
struct node *min(struct node *root){
	struct node *temp=root;
	while(temp->left=NULL){
		temp=temp->left;
	} 
	return temp;
}
struct node *delete(struct node *root,int x){
	struct node *temp;
	if(root==NULL){
		printf("not found \n");
		return 0;
	}
	else if(root->data==x){
			if(root->left==NULL && root->right==NULL){
				root=NULL;
			}
			else if(root->left==NULL){
				root=root->right;
			}
			else if(root->right==NULL){
				root=root->left;
			}
			else{
				temp=min(root->right);
				root->data=temp->data;
				root->right=delete(root->right,temp->data);
			}
	}
	else if(x<root->data){
		root->left=delete(root->left,x);
	}
	else{
		root->right=delete(root->right,x);
	}
}
void search(struct node *root,int key){
	if(root==NULL)
		return ;
	if(root->data==key){
		printf("element found\n");
		return ;
	}
	else if(key<root->data){
		search(root->left,key);
	}
	else
		search(root->right,key);
	
}
int main(){
	int n,x;	
	
	while(1){
		printf("enter  navlue\n 1.create\n,2.display\n3.exit\n4.search\n5.delete\n6.level_order\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data to be inserted\n");
				scanf("%d",&x);
				create(head,x);break;
			case 2:display(head);break;
			case 3:exit(0);break;
			case 4:printf("enter data to search\n");
				scanf("%d",&x);
				search(head,x);
			case 5:printf("enter data to delte\n");
				scanf("%d",&x);
				delete(head,x);
			case 6:levelorder(head);
		}
	}
return 0;
}
