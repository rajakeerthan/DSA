#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void fun(struct node *start){
	if(start==NULL)
		return ;
	printf("%d",start->data);
	if(start->next!=NULL)
		fun(start->next->next);
	printf("%d",start->data);
}
void insert_tail(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&nn->data);
	if(head==NULL){
		head=tail=nn;
	}
	else{
		tail->next=nn;
		tail=nn;
	}
}

void display(){
	int count=0;
	struct node *temp=head;
	if(head==NULL){
		printf("empty\n");
	}
	else{
		while(temp->next!=NULL){
			printf("%d",temp->data);
			temp=temp->next;
			count++;
		}
	}
	printf("n.of elemnts=%d",count);
}
int main(){
	int i;
	for(i=0;i<6;i++)
		insert_tail();
	display();
	fun(head);
return 0;
}	
