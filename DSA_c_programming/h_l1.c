#include<stdio.h>
#include<stdlib.h>
#define max 10
void insert();
void display();
void delete();
int hashtable[10];
void null(){
	int i;
	for(i=0;i<max;i++){
		hashtable[i]=-1;
	}
}
int main(){
	null();
	int n;
	while(1){
		printf("\nchoose\n1.insert value\n2.dispaly\n3.delete\n4.exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:insert();break;
			case 2:display();break;
			case 3:delete();break;
			case 4:exit(0);
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
	if(hashtable[value]==-1){
		hashtable[value]=key;
	}
	else{
		j=0;
		while(hashtable[(j+key)%max]!=-1)
				j++;
		hashtable[(j+key)%max]=key;
	}	
}
void display(){
	int i;
	for(i=0;i<max;i++){
		printf("%d-->%d\n",i,hashtable[i]);
	}
}
void delete(){
	int key,f=0,j;
	int value;
	printf("enter key to search\n");
	scanf("%d",&key);
	value=key%max;
	if(hashtable[value]==key){
		printf("element found at %d -deleted\n",value);
		hashtable[value]=-1;
		f=1;
	}
	else{
		j=0;
		while(hashtable[(key+j)%max]!=-1){
			if(hashtable[(key+j)%max]==key){
				printf("element found -deleted\n");
				hashtable[(key+j)%max]=-1;
				f=1;
				break;
			}
			j++;
		}
	}
	if(f==0)
		printf("elemnt not found\n");
}
