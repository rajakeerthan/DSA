#include<stdio.h>
#include<stdio.h>
#define max 10
int a[max];
int top=-1;
int search(int first,int last,int s){
	int mid,top;
	while(first<=last){
		mid=(first+last)/2;
		if(a[mid]==s){
			return mid;
		}
		else if(a[mid]>s){
				last=mid-1;
		}
		else{
			first=mid+1;
		}
	}
}
int add(){
	int element,i;
	for(i=0;i<9;i++){
	
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
	int k,l;
	add();
	printf("enter elemnt to search\n");
	scanf("%d",&k);
	l=search(0,9,k);
	printf("elemnt found at %d",l);
return 0;
}
