#include<stdio.h>
#include<stdlib.h>
#define size 10
struct pair{
	int key;
	int value;
	//struct pair *next;
};
struct pair *hashtable[size];
void null(){
	int i;
	for(i=0;i<size;i++){
		hashtable[i]=NULL;
	}
}
int hash(int n){
	float k;
	k=(size*(n*0.618033))%size;
	int 
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
		newpair->value=data%size;
		newpair->key=data;
		if(hashtable[data%size]==NULL){
			hashtable[data%size]=newpair;
		}
		else{
			int k;
			k=data%size;
			struct pair *temp;
			temp=hashtable[k];
			int i=0,m=k;
			while(temp!=NULL){
				//printf("%d,%d",hashtable[size],hashtable[ss
				k=(m+(i*i))%size;
				i++;
				temp=hashtable[k];
			}
			hashtable[k]=newpair;
		}
	}
}
void print(){
	int i;
	for(i=0;i<size;i++){
		struct pair *temp;
		temp=hashtable[i];
		if(temp==NULL){
			printf("key-%d\t",i);
			printf("no element\n");
		}
		else{
			printf("key-%d\t",i);
			printf("value-%d\n",temp->key);
		}
}}
void search(){
	
	int i,search,m=0,temp;
	printf("enter element to search\n");
	scanf("%d",&search);
	
	for(i=0;i<size;i++){
		struct pair *temp;
		
		if(hashtable[i]==NULL){
			continue;
		}
		else if(hashtable[i]->value==search){
			printf(" element found at %d \n",i);
			m=1;
		}
	}
	if(m==0)
		printf("elemnt not found\n");
		
}
int main(){
	int n;
	null();
	while(1){
		printf("choose\n");
		printf("1.create\n,2.print\n3.exit\n4.search");
		scanf("%d",&n);
		switch(n){
			case 1:create();break;
			case 2:print();break;
			case 3:exit(0);break;
			case 4:search();break;
		}	
	}
return 0;
}s
