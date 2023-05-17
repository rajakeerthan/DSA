#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int c=0;
struct node *insert(struct node *,int );
struct node *delete(struct node *,int );
void display(struct node *);
struct node *min(struct node *root){
	struct node *temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}
struct node *head=NULL;
int main(){
	int k,x,h;
	while(1){
		printf("\nchoose\n1.create\n2.display\n3.exit\n4.search\n5.delete\n,6.height\n7.node count\n");
		scanf("%d",&k);
		switch(k){
			case 1:printf("enter data to insert\n");
				scanf("%d",&x);
				insert(head,x);break;
			case 2:display(head);break;
			case 3:exit(0);
			//case 4:printf("enter element to search\n");
				//scanf("%d",&x);	
				//search(head,x);
			case 5:printf("enter element to delete\n");
				scanf("%d",&x);
				delete(head,x);
			case 6:h=height(head);printf("height=%d\n",h);break;
			case 7:count(head);printf("count=%d\n",c);break;
		}
	}
}
int height(struct node *root){
	if(root==NULL)
		return 0;
	else{
		int lh=height(root->left);
		int rh=height(root->right);
		if(lh>rh)
			return lh+1;
		else
			return rh+1;
	}
}

int count(struct node *root){
	if(root!=NULL){
		count(root->left);
		c++;
		count(root->right);
	}
	return c;
}
struct node *delete(struct node *root,int x){
	if(root==NULL)
		printf("not found\n");	
	if(root->data==x){
			if(root->left==NULL && root->right==NULL)
					root=NULL;
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
				struct node *temp;
				temp=min(root->right);
				root->data=temp->data;
				root->right=delete(root->right,temp->data);
			}
			return root;
		}
	else if(x<root->data)
			delete(root->left,x);
	else 
		delete(root->right,x);
}
struct node *insert(struct node *root,int x){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=x;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL){
		head=nn;
		root=nn;
	}
	else if(root->data>=nn->data && root->left==NULL)
			root->left=nn;
	else if(root->data<=nn->data && root->right==NULL)
			root->right=nn;
	else if(root->data<=nn->data)
			insert(root->right,x);
	else 
		insert(root->left,x);
}
void display(struct node *temp){
	if(temp==NULL)
		return ;
	printf("%d",temp->data);
	display(temp->left);
	display(temp->right);
}
