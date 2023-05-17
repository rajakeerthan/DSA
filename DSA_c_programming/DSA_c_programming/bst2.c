#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;	
	struct node *right;
};
int c=0;
struct node *head=NULL;
void display(struct node *root);
int count(struct node *root);
int height(struct node *root);
void search(struct node *root,int data);
struct node *min(struct node *root);
struct node *delete(struct node *root,int data);
struct node *insert(struct node *root,int data);
int main(){
	int n,data,h,c;
	while(1){
		printf("enter n\n1.insert\n2.search\n3.delete\n4.display\n5.height\n6.count\n7.exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data to insert\n");scanf("%d",&data);insert(head,data);break;
			case 2:printf("enter data to search\n");scanf("%d",&data);search(head,data);break;
			case 3:printf("enter data to delete\n");scanf("%d",&data);delete(head,data);break;
			case 4:display(head);break;
			case 5:h=height(head);printf("height=%d\n",h);break;
			case 6:c=count(head);printf("count=%d\n",c);break;
			case 7:exit(0);
		}
	}
return 0;
}
struct node *insert(struct node *root,int data){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=data;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL){
		head=nn;
		root=nn;
	}
	else if(data<=root->data && root->left==NULL)
			root->left=nn;
	else if(data>root->data && root->right==NULL)
			root->right=nn;
	else if(data<=root->data){
		insert(root->left,data);
	}
	else{
		insert(root->right,data);
	}
}
struct node *delete(struct node *root,int data){
	if(root==NULL)
		return 0;
	else if(root->data==data){
		if(root->left==NULL && root->right==NULL)
			root=NULL;
		else if(root->left==NULL){
			struct node *temp1=root->right;
			free(root);
			return temp1;
		}
		else if(root->right==NULL){
			struct node *temp2=root->left;		
			free(root);
			return temp2;
		}
		else{
			struct node *temp=min(root->right);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
		return root;				
			
	}
	else if(data<=root->data){
		root->left=delete(root->left,data);
	}
	else 
		root->right=delete(root->right,data);
	
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
}s
/*int height(struct node *root){
	if(root==NULL)
		return 0;
	else{
		int lh=height(root->left);
		int rh=height(root->right);
		if(lh>rh)
			return (lh+1);
		else
			return (rh+1);
	}
}

int count(struct node *root){
	if(root!=NULL){
		count(root->left);
		c++;
		count(root->right);
	}
	return c;
}*/
void search(struct node *root,int data){
	if(root==NULL){
		return ;
	}
	else if(root->data==data){
		printf("found\n");
		return ;
	}
	else if(data<root->data){
		search(root->left,data);
	}
	else{
		search(root->right,data);
	}

}

struct node *min(struct node *root){
	while(root->left!=NULL)
		root=root->left;	
	
	return root;
}
void display(struct node *root){
	if(root==NULL)
		return ;
	printf("%d",root->data);
	display(root->left);
	display(root->right);
}
