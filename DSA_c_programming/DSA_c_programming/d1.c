#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
void ins_head(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	if(head==NULL){
		head=nn;	
	}
	else{
		nn->next=head;
		head->prev=nn;
		head=nn;
	}
}
void ins_end(){
	struct node *nn,*temp;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	if(head==NULL){
		head=nn;	
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=nn;
		nn->prev=temp;
	}
}
void del_end(){
	struct node *temp=head;
	if(head==NULL){
		printf("empty\n");
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->prev->next=NULL;
	}
}
void del_head(){
	struct node *temp=head;
	if(head==NULL){
		printf("empty\n");
	}
	else{
		head=head->next;
	}
}
void ins_pos(){
	struct node *nn,*temp1,*temp2;
	int pos,i=1;
	printf("enter pos\n");
	scanf("%d",&pos);
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	if(pos==1){
		nn->next=head;
		head=nn;	
	}
	else{
		temp1=head;
		temp2=head->next;
		while(i<pos-1){
			
			temp1=temp1->next;
			temp2=temp2->next;
			i++;
		}
		nn->next=temp2;
		temp2->prev=nn;
		nn->prev=temp1;
		temp1->next=nn;
	}
}
void del_pos(){
	struct node *nn,*temp1,*temp2;
	int pos,i=1;
	printf("enter pos\n");
	scanf("%d",&pos);
	if(pos==1){
		head=head->next;
	}
	else{
		temp1=head;
		temp2=head->next;
		while(i<pos-1){
			temp1=temp1->next;
			temp2=temp2->next;
			i++;
		}
		temp1->next=temp2->next;
		temp2->next->prev=temp1;
	}
}
void display(){
	struct node *temp;
	if(head==NULL){
		printf("empty\n");
	}
	else{
		temp=head;
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
int main(){
	int n;
	while(1){
		printf("choose your choice\n");
		printf("1.insert head\n 2.insert head\n 3.del end\n 4.del head\n 5.del pos\n 6.ins pos\n7.display\n");
		scanf("%d",&n);
		switch(n){
			case 1:ins_head();break;
			case 2:ins_end();break;
			case 3:del_end();break;
			case 4:del_head();break;
			case 5:del_pos();break;
			case 6:ins_pos();break;
			case 7:display();break;
			default:printf("invaid input\n");break;
		}
	}
return 0;
}
