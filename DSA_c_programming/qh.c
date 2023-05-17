#include<stdio.h>
#include<stdlib.h>
#define size 10
int hashtable[size];
void null(){
	int i;
	for(i=0;i<size;i++){
		hashtable[i]=-1;
	}
}

void insert(){
	int key,value;
	printf("enter key\n");
	scanf("%d",&key);
	value=(key%size);
	if(hashtable[value]==-1)
		hashtable[value]=key;
	else{
		int m=value,i=0;
		while(hashtable[m]!=-1){
			m=(m+i*i)%size;
			i=(i+1)%size;
		}
		hashtable[m]=key;
	}
}
void display(){
	int i;
	printf("balues\tkeys\n");
	for(i=0;i<size;i++){
		printf("%d\t%d\n",i,hashtable[i]);
	}
}
int main(){
	null();
	int n;
	while(1){
		printf("enter choice\n");
		scanf("%d",&n);
		switch(n){
			case 1:insert();break;
			case 2:display();break;
			case 3:exit(0);break;
		}
	}
return 0;
} 
