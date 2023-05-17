#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
void ins_head(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("entr data\n");
	scanf("%d",&nn->data);
	if(head==NULL){
		head=nn;
		tail=nn;
		tail->next=head;
		head->prev=tail;
	}
	else{
		nn->next=head;	
		head->prev=tail;
		tail->next=nn;
		nn->prev=tail;
		head=nn;
	}
}
void ins_end(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("entr data\n");
	scanf("%d",&nn->data);
	if(head==NULL){
		head=nn;
		tail=nn;
		tail->next=head;
		head->prev=tail;
	}
	else{
		nn->next=head;	
		head->prev=tail;
		tail->next=nn;
		nn->prev=tail;
		tail=nn;
	}
}
void del_head(){
	struct node *temp;
	if(head==NULL){
		printf("underflow\n");
	}
	else{
		head=head->next;
		tail->next=head;
		head->prev=tail;
		
	}
}
void del_end(){
	struct node *temp;
	if(head==NULL){
		printf("underflow\n");
	}
	else{
		tail=tail->prev;
		tail->next=head;
		head->prev=tail;
		
		
	}
}
void del_pos(){
	int pos,i=1;
	printf("enter pos\n");
	scanf("%d",&pos);
	struct node *nn,*temp;
	
	if(pos==1 || pos==0){
		del_head();
	}
	else{
		temp=head;
		while(i<pos-1){
			temp=temp->next;
			pos++;
		}
		temp->next->next->prev=temp;
		temp->next=temp->next->next;
	}
}
void ins_pos(){
	int pos,i=1;
	printf("enter pos\n");
	scanf("%d",&pos);
	struct node *nn,*temp;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("entr data\n");
	scanf("%d",&nn->data);
	if(pos==1 || pos==0){
		ins_head();
	}
	else{
		temp=head;
		while(i<pos-1){
			temp=temp->next;
			pos++;
		}
		nn->next=temp->next;
		tail->next->prev=nn;
		temp->next=nn;
		nn->prev=temp;
	}
}
void display(){
	struct node *temp;
	if(head==NULL){
		printf("underflow\n");
	}
	else{
		temp=head;
		do{
			printf("%d",temp->data);
			temp=temp->next;
		}while(temp!=head);
	}
}

int main(){
	int n;
	while(1){
		printf("choose\n1.insert head\n2.insert end\n3.insert pos\n4.del head\n5.del_end\n6.del_pos\n7.display\n8.exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:ins_head();break;
			case 2:ins_end();break;
			case 3:ins_pos();break;
			case 4:del_head();break;	
			case 5:del_end();break;
			case 6:del_pos();break;
			case 7:display();break;
			case 8:exit(0);break;
		}
	}
return 0;
}
