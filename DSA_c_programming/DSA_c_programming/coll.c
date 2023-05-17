#include<stdio.h>
#include<stdlib.h>
#define max 10
void null();
void insert();
void display();
void search();
void delete();
struct node{
	int data;
	struct node *next;
};
struct node *hashtable[10];
void null(){
	int i=0;
	for(i=0;i<10;i++)
		hashtable[i]=NULL;
	
}
int main(){
	null();
	int n;
	while(1){
		printf("\nchoose\n1.insert value\n2.dispaly\n3.delete\n4.exit\n5.search\n");
		scanf("%d",&n);
		switch(n){
			case 1:insert();break;
			case 2:display();break;
			case 3:delete();break;
			case 4:exit(0);
			case 5:search();break;
		}
	}
return 0;
}
void insert(){
	int key,j;
	int value;
	printf("enter key\n");
	scanf("%d",&key);
	value=key%max;
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=key;
	if(hashtable[value]==NULL){
		hashtable[value]=nn;
	}
	else{
		struct node *temp;
		temp=hashtable[value];
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nn;
	}	
}
void delete(){
	int search;
	printf("enter  key to search\n");
	scanf("%d",&search);
	int val=search%max,m=0;
	struct node *temp=hashtable[val];
	if(temp==NULL)
		printf("element not found\n");
	else if(temp->next==NULL && temp->data==search)
			temp=NULL;
	else if(temp->data==search){
			free(temp);
			hashtable[val]=temp->next;
			m=1;printf("found\n");
	}
	else{
		struct node *temp2;
		temp2=temp->next;
		while(temp2!=NULL){
			if(temp2->data==search){
				printf("found\n");
				temp->next=temp2->next;
				m=1;
			}
			temp=temp->next;
			temp2=temp2->next;
		}	
	}
	if(m==0)
		printf("not found\n");
}
void search(){
	int search;
	printf("enter  key to search\n");
	scanf("%d",&search);
	int val=search%max,m=0;
	struct node *temp=hashtable[val];
	while(temp!=NULL){
		if(temp->data==search){
			printf("found\n");
			m=1;
		}
		temp=temp->next;
	}
	if(m==0)
		printf("not found\n");
}
void display(){
	struct node *temp;
	int i;
	for(i=0;i<max;i++){
		temp=hashtable[i];
		printf("%d\t",i);
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
