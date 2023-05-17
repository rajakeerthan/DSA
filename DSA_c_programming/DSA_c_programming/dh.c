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
int hashfunction(int key){
	return (7-(key%size));
}
void insert(){
	int key,value;
	printf("enter key\n");
	scanf("%d",&key);
	value=(key%size);
	if(hashtable[value]==-1)
		hashtable[value]=key;
	else{
		int m=value,i=0,l;
		l=hashfunction(key);
		while(hashtable[m]!=-1){
			m=((key%size)+l*i)%size;
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
void search(){
	int element,s,t,i=1,r=0;
	printf("element to search\n");
	scanf("%d",&element);
	s=element%size;
	t=s;
	do{
		if(hashtable[t]==element){
				printf("element found\n");
				r=1;
		}
		t=(t+i)%size;
		i=(i+1)%size;
	}while(s!=t);
	if(r==0)
		printf("elemnt not found\n");
}
void delete(){
	int element,s,t,i=1,r=0;
	printf("element to search\n");
	scanf("%d",&element);
	s=element%size;
	t=s;
	do{
		if(hashtable[t]==element){
				
				hashtable[t]=-1;
				r=1;
				printf("element deletd \n");
		}
		t=(t+i)%size;
		i=(i+1)%size;
	}while(s!=t);
	if(r==0)
		printf("elemnt not found\n");
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
			case 4:search();break;
			case 5:delete();break;
		}
	}
return 0;
} 
