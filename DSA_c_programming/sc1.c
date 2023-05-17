#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert(){
	struct node *nn,*temp;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	if(head==NULL){
		head==nn;
	}
	else{
		temp=head;
		while(temp->next!=NULL)
			temo=temp->next;
		temp->next=nn;
		nn->next=head;
	}
}
void del(){
	struct node *temp;
	if(head==NULL){
		printf("emty\n");
	}
	else{
		head=head->next;
		
	}
}
void insert_pos(){
}
void del_pos(){
}
int main(){
return 0;
}
