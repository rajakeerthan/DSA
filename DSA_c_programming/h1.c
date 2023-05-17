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
	int key,value;
	printf("enter actual data to be strored\n");
	scanf("%d",&key);
	value=hash_function(key);
	if(hashtable[value]==-1){
		hashtable[value]=key;
	}
	else{
		printf("collision taking place,no place for %d\n",key);
	} 
	
}
void search(){
	int s,ref;
	printf("enter key to serach\n");
	scanf("%d",&s);
	ref=s%MAX;
	if(s==hashtable[ref]){
		printf("element found\n");
	}
	else{
		printf("element not found\n");	
	}
}
void delete(){
	int d,ref;
	printf("enter key to delte\n");
	scanf("%d",&d);
	ref=d%MAX;
	if(d==hashtable[ref]){
		hashtable[ref]=-1;
		printf("element delted\n");
	}
	else{
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
