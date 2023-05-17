#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int hashtable[MAX];
int hash_function(int key){
	int value;
	value=key%MAX;
	return value;
}
void null(){
	int i;
	for(i=0;i<MAX;i++){
		hashtable[i]=-1;
	}
}
void display(){
	int i;
	for(i=0;i<MAX;i++){
		printf("%d\t%d\n",i,hashtable[i]);
	}
}
void create(){
	int key,value,k,i;
	printf("enter actual data to be strored\n");
	scanf("%d",&key);
	value=hash_function(key);
	if(hashtable[value]==-1){
		hashtable[value]=key;
	}
	else{
		i=0;
		k=value;
		while(hashtable[k]!=-1){
				k=(value+i*i)%MAX;
				i=(i+1)%MAX;
		}
		hashtable[k]=key;
	} 
}
void search(){
	int s,ref,x=0,i=0,v;
	printf("enter key to serach\n");
	scanf("%d",&s);
	ref=s%MAX;
	v=ref;
	if(s==hashtable[ref]){
		printf("element found\n");
		x=1;
	}
	else{
		while(hashtable[ref]!=-1){
			if(s==hashtable[ref]){
				printf("element found\n");
				x=1;
				break;
			}
			ref=(v+i*i)%MAX;
			i++;
		}
	}
	if(x==0){
		printf("element not found\n");
	}
}
void delete(){
	int s,ref,x=0,i=0,v;
	printf("enter key to serach\n");
	scanf("%d",&s);
	ref=s%MAX;
	v=ref;
	if(s==hashtable[ref]){
		hashtable[ref]=-1;
		printf("element delted\n");
		x=1;
	}
	else{
		while(hashtable[ref]!=-1){
			if(s==hashtable[ref]){
				hashtable[ref]=-1;
				printf("element delted\n");
				x=1;
				break;
			}
			ref=(v+i*i)%MAX;
			i++;
		}
	}
	if(x==0){
		printf("element not found\n");
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
