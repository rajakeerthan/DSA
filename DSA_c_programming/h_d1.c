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
int hash1(int key){
	return (key%max);
}
int hash2(int key){
	int value= (7-(key%7));
	return value;
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
		int m=value,i=0;
		while(hashtable[m]!=-1){
			m=(hash1(key)+i*hash2(key))%max;	
			i++;
		}
		hashtable[m]=key;
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
		int j=0,m=value;
		while(hashtable[m]!=-1){
			if(hashtable[m]==key){
				printf("element found -deleted\n");
				hashtable[m]=-1;
				f=1;
				break;
			}
			m=(hash1(key)+j*hash2(key)%max);
			j++;
		}
	}
	if(f==0)
		printf("elemnt not found\n");
}
