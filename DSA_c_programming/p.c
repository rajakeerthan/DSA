#include<stdio.h>
#include<stdlib.h>
#define size 10
 int hashtable[10];
int null(){
	int i;
	for(i=0;i<size;i++){
		hashtable[i]=-1;
	}
}
int create(){
	int k,m;
	printf("enter key to add\n");
	scanf("%d",&k);
	m=k%size;
	hashtable[m]=k;
}
int display(){
	int k,i;
	printf("keys\tdata\n");
	for(i=0;i<size;i++){
		printf("%d\t %d\n",i,hashtable[i]);
	}
}
int main(){
	null();
	int n;
	while(1){
		printf("enter your choice\n");
		scanf("%d",&n);
		switch(n){
			case 1:create();break;
			case 2:display();break;
			case 3:exit(0);break;
		}
	}
return 0;
}
