#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int minimum=1000;
int maximum=0;
struct node *head=NULL;
struct node *insert(struct node *,int );
void display(struct node *);
void search(struct node*,int );
int max(struct node*);
int min(struct node*);
struct node * minValueNode(struct node* node)
{
struct node* current = node;
while (current->left != NULL)
current = current->left;
return current;
}
struct node *delete(struct node *,int );
struct node *delete(struct node *root,int key){
	//int temp;
	struct node *ptr;
	if(root==NULL){
		printf("not found\n");
	}
	if(root->data==key){
		if(root->left == NULL && root->right == NULL)
				root=NULL;
		else if (root->left == NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		else{
		struct node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = delete(root->right, temp->data);
		}
		return root;
	}
	else if(root->data<key){
		root->right=delete(root->right,key);
		}
	else{
		root->left=delete(root->left,key);
	}
}
struct node *insert(struct node *root,int data){
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL){
		root=nn;
		head=nn;
	}
	else if(root->data<data && root->right==NULL){
		root->right=nn;
	}
	else if(root->data>=data && root->left==NULL){
		root->left=nn;
	}
	else if(root->data<data){
		insert(root->right,data);
	}
	else{
		insert(root->left,data);
	}
}
int max(struct node *root){
		//int maximum=0;
		if(root==NULL){
			printf("max=%d\n",maximum);
			return maximum;
		}
		else if(maximum<root->data){
			maximum=root->data;
		}
		max(root->right);
		
	
}
int min(struct node *root){
		if(root==NULL){
			printf("min=%d\n",minimum);
			return minimum;
		}
		else if(minimum>root->data){
			minimum=root->data;
		}
		min(root->left);
	
}
void search(struct node *root,int key){
	if(root==NULL){
		printf("not found\n");
	}
	else if(root->data==key){
		printf("element found\n");
	}
	else if(root->data<key){
		search(root->right,key);
		}
	else{
		search(root->left,key);
	}
}
void display(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d-->",root->data);
	display(root->left);
	display(root->right);
}
int main(){
	int n,x,key;
	while(1){
		printf("choose\n1.insert\n2.display\n3.exit\n4.search\n5.delete\n6.max number \n7.minimum number\n");
		scanf("%d",&n);
		switch(n){
			case 1:printf("enter new node data\n");
				scanf("%d",&x);
				insert(head,x);break;
			case 2:
				display(head);break;
			case 3:	exit(0);break;
			case 4:printf("enter new node data\n");
				scanf("%d",&key);
				search(head,key);break;
			case 5:printf("enter  data to be deleted\n");
				scanf("%d",&x);
				delete(head,x);break;
			case 6:max(head);break;
			case 7:min(head);break;
		}
	}
return 0;
}
