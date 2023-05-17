#include<stdio.h>
#include<stdlib.h>
#define max 10
struct node{
	int data;
	struct node *next;
};
struct node *hashtable[max];
void null(){
	int i;
	for(i=0;i<max;i++){
		hashtable[i]=NULL;
	}
}
void create(){
	int key,value;
	printf("enter key\n");
	scanf("%d",&key);
	value=key%max;
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=key;
	nn->next=NULL;
	if(hashtable[value]==NULL){
		hashtable[value]=nn;
	}
	else{
		struct node *temp;
		temp=hashtable[value];
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=nn;
	}
}
void display(){
	int i;
	struct node *temp;
	for(i=0;i<max;i++){
		temp=hashtable[i];
		printf("%d\t",i);
		if(temp==NULL)
			printf("null");
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
		
	}
	
}
void search(){
	int data,x=0,v;
	printf("enter data to search\n");
	scanf("%d",&data);
	struct node *temp;
	v=data%max;
		if(hashtable[v]!=NULL){
			temp=hashtable[v];
			while(temp!=NULL){
				if(temp->data==data){
					printf("element found\n");
					x=1;
				}
				temp=temp->next;
			}
		}
	if(x==0){
		printf("element found\n");
	}
}
void delete(){
	int data,x=0,v;
	printf("enter data to deleted\n");
	scanf("%d",&data);
	struct node *temp,*temp1;
	v=data%max;
		if(hashtable[v]!=NULL){
			temp=hashtable[v];
			if(hashtable[v]->data==data ){
				if(hashtable[v]->next==NULL){
					hashtable[v]=NULL;
					printf("element deleted succesfully\n");
				}
				else{
					hashtable[v]=hashtable[v]->next;
					printf("element deletd\n");
							x=1;
				}
			}
			else{
				temp1=hashtable[v]->next;
				while(temp1!=NULL){
					if(temp1->data==data){
						if(temp1->next==NULL){
							temp->next=NULL;
							printf("element deletd\n");
							x=1;
						}
						else{
							temp->next=temp1->next;
							printf("element deletd\n");
							x=1;
						}
					}
					temp1=temp1->next;
					temp=temp->next;
				}
			}
		}
	if(x==0){
		printf("element found\n");
	}
}
int main(){
	null();
	int n;
	while(1){
		printf("choose\n,1.create\n2.display\n3.exit\n4.search\n5.delete\n");
		scanf("%d",&n);
		switch(n){
			case 1:create();break;
			case 2:display();break;
			case 3:exit(0);break; 
			case 4:search();break;
			case 5:delete();break;
		}
	}
return 0;
}
