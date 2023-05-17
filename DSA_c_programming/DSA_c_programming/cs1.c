#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
void ins_head(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	if(head==NULL){
		head=nn;
		tail=nn;	
	}
	else{
		nn->next=head;
		head=nn;
		tail->next=head;
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
		/*temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=nn;*/
		tail->next=nn;
		nn->next=head;
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
		temp->next=NULL;
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
	struct node *nn,*temp;
	int pos,i=0;
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
		temp=head;
		while(i<pos-1){
			i++;
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
}
void del_pos(){
	struct node *nn,*temp;
	int pos,i=0;
	printf("enter pos\n");
	scanf("%d",&pos);
	if(pos==1){
		head=head->next;
	}
	else{
		temp=head;
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		temp->next=temp->next->next;
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
