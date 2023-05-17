#include<stdio.h>
#include<stdlib.h>
int size=10;

/*struct pair *head=NULL;*/
int hashtable[10];
int hashfunction(int key){
	return key%size;
}
void null(){
	int i;
	for(i=0;i<size;i++)
		hashtable[i]=-1;
}
void search(){
	int s,k;
	printf("enter elemnt to earch\n");
	scanf("%d",&s);
	k=s%size;
	if(hashtable[k]==s)
		printf("elemnt found\n");
	else
		printf("elemnt not found\n");
}
void delete(){
	int s,k;
	printf("enter elemnt to delete\n");
	scanf("%d",&s);
	k=s%size;
	if(hashtable[k]==s){
		hashtable[k]=-1;
		printf("elemnt deleted succefully\n");
	}
	else
		printf("elemnt not found to delete\n");
}
void insert(){
	int x,key,value,i;
	printf("enter new key to be stored\n");
	scanf("%d",&x);
	i=hashfunction(x);
	value=i;
	key=x;
	if(hashtable[value]==-1)
		hashtable[value]=key;
	else
		printf("%d is already filled\n",value);
}
void print(){
	int i;
	printf("value\t keys\n");	
	for(i=0;i<size;i++){
		if(hashtable[i]==-1)
			printf("%d\t noelement\n",i);
		else{
			printf("%d\t%d\n",i,hashtable[i]);
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
