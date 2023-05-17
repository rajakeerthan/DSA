#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head;
struct node *insert(struct node *root,int x){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=x;
	//nn->left=NULL;
	//nn->right=NULL;
	if(root==NULL){
		root=nn;
		head=nn;
	}
	else if(x<root->data && root->left==NULL){
		root->left=nn;
	} 
	else if(x>root->data && root->right==NULL){
		root->right=nn;
	} 
	else if(x<root->data){
		insert(root->left,x);
	}
	else{
		insert(root->right,x);
	}
}
void print(struct node *ptr){
	if(ptr==NULL){
		
		return;
	}
	printf("%d-->",ptr->data);
	print(ptr->left);
	print(ptr->right);
}
void search(struct node *ptr,int key){
	int k=0;
	if(ptr==NULL){
		printf("empty\n");
	}
	if(ptr->data==key){
		printf("element found\n");
		return;
	}
	else if(key<ptr->data)
		search(ptr->left,key);
	else
		search(ptr->right,key);
	//if(k==0)
	//	printf("elemnt not found\n");
}
struct node *min(struct node *root){
	struct node *current=root;
	while(current->left!=NULL)
		current=current->left;
	return current;
}
struct node *delete(struct node *root,int x){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(root==NULL)
		return 0;
	else if(root->data==x){
		if(root->left==NULL && root->right==NULL)
			root=NULL;
		else if(root->left==NULL){
				temp=root->right;
				free(root);
				return temp;
		}
		else if(root->right==NULL){
				temp=root->left;
				free(root);
				return temp;
		}
		else{
			struct node *ptr=min(root->right);
			root->data=ptr->data;
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
int main(){
//null();
	int n,x;
	while(1){
		printf("choose\n1.insert\n2.print\n3.exit\n4.search\n5.delete\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter data to insert\n");
			scanf("%d",&x);
				insert(head,x);break;
			case 2:print(head);break;
			case 3:exit(0);break;
			case 4:printf("enter data to search\n");
			scanf("%d",&x);
			search(head,x);break;
			case 5:printf("enter data to insert\n");
			scanf("%d",&x);
				delete(head,x);break;
		}
	}
return 0;
}
