#include<stdio.h>
#define max 10
int a[max];
int top=-1;
int search(int s){
	int i=0;
	while(i<top){	
		if(a[i]==s){
			printf("key found at %d",i+1);
			break;
		}
		i++;
	}
}
int add(){
	int element,i;
	for(i=0;i<10;i++){
	
		printf("enter elemnt \n");
		scanf("%d",&element);
		if(top>max-1){
			printf("overflow\n");
		}
		else{
			a[++top]=element;
		}
	}
}
int main(){
	int k;
	add();
	printf("enter elemnt to search\n");
	scanf("%d",&k);
	search(k);
return 0;
}
