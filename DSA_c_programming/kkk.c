#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int c=0;
struct node *insert(struct node *,int );
void display(struct node *);
struct node *deq(struct node **q,int *f);
void enq(struct node **q,struct node *nn,int *r);
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
			/*case 5:printf("enter element to delete\n");
				scanf("%d",&x);
				delete(head,x);
			case 6:h=height(head);printf("height=%d\n",h);break;
			case 7:count(head);printf("count=%d\n",c);break;*/
		}
	}
}
/*void level(struct node *root){
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
}*/
void display(struct node *root){
	struct node **q,*temp=root;
	q=(struct node **)malloc(sizeof(struct node *)*size);
	int f=0,r=0;
	if(root==NULL)	
		return ;
	while(temp!=NULL){
		printf("%d",temp->data);
		if(temp->left!=NULL){
			enq(q,temp->left,&r);
		}
		if(temp->right!=NULL){
			enq(q,temp->right,&r);
		}
		temp=deq(q,&f);
	}
	
}
void enq(struct node **q,struct node *nn,int *r){
	q[(*r)]=nn;
	(*r)++;
}
struct node *deq(struct node **q,int *f){
	(*f)++;
	return q[(*f)-1];
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
