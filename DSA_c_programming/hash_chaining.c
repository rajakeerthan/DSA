#include<stdio.h>
#include<stdlib.h>
struct pair{
	int value;
	int key;
	struct pair *next;
};
int size=10;
struct pair *hashtable[10];
int hashfunction(int key){
	return key%size;
}
void null(){
	int i;
	for(i=0;i<size;i++){
		hashtable[i]=NULL;
	}
}
void insert(){
	int n,val;
		struct pair *temp;
	printf("enter new key to store\n");
	scanf("%d",&n);
	struct pair *nn;
	nn=(struct pair *)malloc(sizeof(struct pair));
	nn->key=n;
	val=hashfunction(n);
	nn->value=val;
	if(hashtable[val]==NULL)
		hashtable[val]=nn;
	else{
		temp=hashtable[val];
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nn;
	}
}
void print(){
	int i;
	struct pair *temp;
	printf("value\t keys\n");
	for(i=0;i<size;i++){
		if(hashtable[i]==NULL)
			continue;
		else{
			temp=hashtable[i];
			printf("%d\t",temp->value);
			while(temp!=NULL){
				printf("%d\t",temp->key);
				temp=temp->next;
			}
			printf("\n");
		}
	}
}
void search(){
	int s,k,m;
	struct pair *temp;
	printf("enter elemnt to earch\n");
	scanf("%d",&s);
	k=s%size;
	temp=hashtable[k];
	while(temp!=NULL){
		if(temp->key==s){
				printf("elemnt found\n");
				m=1;
		}
		temp=temp->next;
	}
	if(m!=1)
		printf("elemnt not found\n");
}
void delete(){
	int s,k,m;
	struct pair *temp1,*temp2;
	printf("enter elemnt to delete\n");
	scanf("%d",&s);
	k=s%size;
	temp1=hashtable[k];
	if(temp1==NULL){
		printf("element not found\n");
		return ;
	}
	if(hashtable[k]->next==NULL && hashtable[k]->key==s){
		hashtable[k]=NULL;m=1;
		printf("delted succefully\n");
	}
	else if(hashtable[k]->next==NULL){
		printf("elemnt not found to delete\n");
	}
	else{
		temp2=hashtable[k]->next;
		if(temp1->key==s){
			hashtable[k]=hashtable[k]->next;
			//free(temp1);
			
			printf("delted succefully\n");
			m=1;
		}
		else{
			
			while(temp1->next!=NULL){
				if(temp2->key==s){
						temp1->next=temp2->next;
						printf("elemnt deleted\n");
						m=1;
						return ;
				}
				temp1=temp1->next;
				temp2=temp2->next;
			}
			if(m!=1)
				printf("elemnt not found to delete\n");
		}
	}
}
int main(){
	null();
	int n;
	while(1){
		printf("choose\n1.insert\n2.print\n3.exit\n4.search\n5.delete\n");
		scanf("%d",&n);
		switch(n){
			case 1:insert();break;
			case 2:print();break;
			case 3:exit(0);break;
			case 4:search();break;
			case 5:delete();break;
		}
	}
return 0;
}
