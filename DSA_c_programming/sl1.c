 #include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void display();
void del_beg();
void del_end();
void del_pos();
void insert_pos();
void insert_end();
void insert_beg();
void count();
void duplicate(struct node*);
void del_value();
int main(){
	int n;
	while(1){
		printf("\n1:insert_beg()\n2.insert_end\n3:insert_pos()\n4:del_beg()\n 5:del_end\n	6:del_pos\n7:display()\n8:exit\n9.count no.of nodes\n10.del value\n11.duplicate\n enter your choice\n");
		scanf("%d",&n);
		switch(n){
			case 1:insert_beg();break;
			case 2:insert_end();break;
			case 3:insert_pos();break;
			case 4:del_beg();break;
			case 5:del_end();break;	
			case 6:del_pos();break;
			case 7:display();break;
			case 8:exit(0);
			case 9:count();break;
			case 10:del_value();break;
			case 11:duplicate(head);break;
		}
	}
return 0;
}
void duplicate(struct node *root){
	struct node *temp1=root,*temp2;
	while(temp1->next!=NULL){
		temp2=temp1->next;
		if(temp1->data==temp2->data)
			temp1->next=temp2->next;
		while(temp2->next!=NULL){
			
			if(temp1->data==temp2->next->data){
				temp2->next=temp2->next->next;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}
void count(){
	int count=0;
	struct node *temp;
	if(head==NULL)
		printf("count=0\n");
	else{
		temp=head;
		while(temp!=NULL){
			count++;
			temp=temp->next;
		}
	}
	printf("count=%d",count);
}
void del_value(){
	int value;
	struct node *temp1,*temp2;
	printf("enter value\n");
	scanf("%d",&value);
	if(head==NULL)
		printf("underflow\n");
	else if(head->data==value)
		head=head->next;
	else{
		temp1=head;
		temp2=head->next;
		while(temp1->next!=NULL){
	
			if(temp2->data==value){
				if(temp2->next==NULL){
					temp1->next=NULL;
					break;
				}
				else{
					temp1->next=temp2->next;

					break;
				}
			}
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
}
void del_beg(){
	if(head==NULL)
		printf("underflow\n");
	else
		head=head->next;
}
void del_end(){
	struct node *temp,*temp2;
	if(head==NULL)
		printf("underflow\n");
	else if(head->next==NULL){
		head=NULL;
		printf("deleted\n");
	}
	else{
		temp=head;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		temp->next=NULL;
	}
		
		
}
void del_pos(){
	struct node *temp;
	printf("enter position to delete\n");
	int pos;
	scanf("%d",&pos);
	if(pos==0 || pos==1){
		head=head->next;
	}
	else{
		temp=head;
		int i=1;
		while(i<pos-1 && temp->next!=NULL){
			temp=temp->next;
			i++;
		}
		if(temp->next==NULL)
			printf("there is no element found at %d\n",pos);
		else
			temp->next=temp->next->next;
		
	}
}
void insert_beg(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter nn->data\n");
	scanf("%d",&nn->data);
	nn->next=NULL;
	if(head==NULL)
		head=nn;
	else{
		nn->next=head;
		head=nn;
	}
}
void insert_end(){
	struct node *nn,*temp;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter nn->data\n");
	scanf("%d",&nn->data);
	nn->next=NULL;
	if(head==NULL)
		head=nn;
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=nn;
		nn->next=NULL;
	}
}
void insert_pos(){
	struct node *nn,*temp;
	printf("enter position to insert\n");
	int pos,i;
	scanf("%d",&pos);
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter nn->data\n");
	scanf("%d",&nn->data);
	nn->next=NULL;
	if(pos==0 || pos==1){
		nn->next=head;
		head=nn;
	}
	else{
		temp=head;
		for(i=1;i<pos-1;i++){
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
		
	}
}
void display(){
	struct node *temp;
	if(head==NULL)
		printf("empty\n");
	else{
		temp=head;
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
