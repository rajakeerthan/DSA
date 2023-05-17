#include<stdio.h>
#include<stdlib.h>
#define size 50
struct node{
	struct node *left;
	int data;
	struct node *right;
};
struct node  *min(struct node *);
struct node *insert(struct node *root,int x);
struct node *head=NULL;
struct node *create(struct node*,int);
void search(struct node *,int );
struct node *delete(struct node*,int);
void display();
void level(struct node *root);
struct node *dequeue(struct node **,int *);
void enq(struct node *,struct node **,int *);
int main(){
	int k,x,h;
	while(1){
		printf("\nchoose\n1.create\n2.display\n3.exit\n4.search\n5.delete\n");
		scanf("%d",&k);
		switch(k){
			case 1:printf("enter data to insert\n");
				scanf("%d",&x);
				insert(head,x);break;
			case 2:display(head);break;
			case 3:exit(0);
			/*case 4:printf("enter element to search\n");
				scanf("%d",&x);	
				search(head,x);
			case 5:printf("enter element to delete\n");
				scanf("%d",&x);
				delete(head,x);*/
			case 6:level(head);break;
			case 7:h=height(head);printf("heoght=%d",h);break;
		}
	}
}
int height(struct node *root){
	if(root==NULL)
		return 0;
	else{
		int lheight=height(root->left);
		int rheight=height(root->right);
		if(lheight>rheight)
			return (lheight+1);
		else
			return (rheight+1);
	}
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
void level(struct node *root){
	int f=0,r=0;
	struct node **q;
	q=(struct node **)malloc(sizeof(struct node *)*size);
	if(root==NULL)
		return ;
	struct node *temp=root;
	while(temp!=NULL){
			printf("%d",temp->data);
			if(temp->left!=NULL)
				enq(temp->left,q,&r);
			if(temp->right!=NULL)
				enq(temp->right,q,&r);
			temp=dequeue(q,&f);
	}
}
void enq(struct node *nn,struct node **q,int *r){
	q[*r]=nn;
	(*r)++;
}
struct node *dequeue(struct node **q,int *f){
	(*f)++;
	return q[(*f)-1];
}
