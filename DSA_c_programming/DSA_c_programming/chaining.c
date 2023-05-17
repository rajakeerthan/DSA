#include<stdio.h>
#include<stdlib.h>
#define size 10
struct pair{
	int key;
	int value;
	struct pair *next;
};
struct pair *hashtable[size];
void null(){
	int i;
	for(i=0;i<size;i++){
		hashtable[i]=NULL;
	}
}
void create(){
	int data,i,n,j;
	printf("number of elemnt s to add\n");
	scanf("%d",&n);
	for(j=0;j<n;j++){
		printf("enter data\n");
		scanf("%d",&data);
		struct pair *newpair;
		newpair=(struct pair *)malloc(sizeof(struct pair));
		newpair->value=data;
		newpair->next=NULL;
		newpair->key=data%size;
		if(hashtable[data%size]==NULL){
			hashtable[data%size]=newpair;
		}
		else{
			struct pair *temp;
			temp=hashtable[data%size];
			while(temp->next!=NULL){
				//printf("%d,%d",hashtable[size],hashtable[
				temp=temp->next;
			}
			temp->next=newpair;
		}
	}
}
void search(){
	int i,search,m=0;
	printf("enter element to search\n");
	scanf("%d",&search);
	for(i=0;i<size;i++){
		struct pair *temp;
		temp=hashtable[i];
		//printf("key-%d\t",i);
		while(temp!=NULL){
			if(temp->value==search){
					printf("element founded at %d key\n",i);			
					m=1;
			}
			temp=temp->next;
		}
		//printf("NULL\n");
}		if(m==0){
			printf("elemnt not found\n");
		}
}
void print(){
	int i;
	for(i=0;i<size;i++){
		struct pair *temp;
		temp=hashtable[i];
		printf("key-%d\t",i);
		while(temp!=NULL){
			printf("%d\t",temp->value);
			temp=temp->next;
		}
		printf("NULL\n");
}}
int main(){
	int n;
	null();
	while(1){
		printf("choose\n");
		printf("1.create\n,2.print\n3.exit\n4.search\n");
		scanf("%d",&n);
		switch(n){
			case 1:create();break;
			case 2:print();break;
			case 3:exit(0);break;
			case 4:search();break;
		}	
	}
return 0;
}
