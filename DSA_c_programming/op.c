#include<stdio.h>
#include<stdlib.h>
#define size 10
struct pair{
	int key;
	int data;
	struct pair *next;
};
struct pair *hashtable[size];
void null(){
	int i;
	for(i=0;i<size;i++)
		hashtable[i]=NULL;
}
void insert(){
	int key,m;
	struct pair *temp,*nn;
	printf("enter key\n");
	scanf("%d",&key);
	m=key%size;
	nn=(struct pair *)malloc(sizeof(struct pair));
	nn->key=key;
	nn->data=m;
	nn->next=NULL;
	if(hashtable[m]==NULL)
		hashtable[m]=nn;
	else{
		temp=hashtable[m];
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nn;
	}
	
}
void display(){
	struct pair *temp;
	int i;
	for(i=0;i<size;i++){
		if(hashtable[i]==NULL)
			continue;
		else{
			printf("%d\t",hashtable[i]->data);
			temp=hashtable[i];
			while(temp!=NULL){
				printf("%d\t",temp->key);
				temp=temp->next;
			}
			printf("\n");
		}
	}
}
void search(){
	int s,i,k=0;
	struct pair *temp;
	printf("enter element to search\n");
	scanf("%d",&s);
	for(i=0;i<size;i++){
		if(hashtable[i]==NULL)
			continue;
		else{
			temp=hashtable[i];
			while(temp!=NULL){
				if(s==temp->key){
					printf("element found\n");
					k=1;
					return ;
				}
				temp=temp->next;
			}
		}
	}
	if(k==0)
		printf("element found\n");
}
void delete(){
	int s,i,k=0;
	struct pair *temp;
	printf("enter element to search\n");
	scanf("%d",&s);
	for(i=0;i<size;i++){
		if(hashtable[i]==NULL)
			continue;
		else{
			temp=hashtable[i];
			if(temp->next==NULL && hashtable[i]->key==s){
				hashtable[i]=NULL;
			}
			while(temp!=NULL){
				if(s==temp->key){
					printf("element found\n");
					if(temp->next==NULL)
						temp=NULL;
					else if(temp->next->next==NULL){
						temp->next=NULL;
					}
					else{
						temp1=hashtable[i];
						temp2=hashtabe[i]->next;
					}
				}
				temp=temp->next;
			}
		}
	}
}
int main(){
	null();
	int n;
	while(1){
		printf("choose\n1.insert\n2.display\n.exit\n4.search\n5.delete\n");
		scanf("%d",&n);
		switch(n){
			case 1:insert();break;
			case 2:display();break;
			case 3:exit(0);break;
			case 4:search();break;
			case 5:delete();break;
		}
	}
return 0;
}
