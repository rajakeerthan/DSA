#include<stdio.h>
#include<stdlib.h>
void binary(int b[20],int l,int h,int x);
int a[20];
int main(){
	int n,i,search;
	printf("enter no.of elements\n");
	scanf("%d",&n);
	printf("enter elemnts\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter elem to search\n");
	scanf("%d",&search);
	binary(a,0,n-1,search);
	//for(i=0;i<n;i++){
		//printf("%d",a[i]);
}
void binary(int b[20],int l,int h,int x){
	int mid;
	mid=(l+h)/2;
	while(l<h){
		mid=(l+h)/2;
		if(x==a[mid]){
			printf("element found\n");
			break;
		}
		else if(x>a[mid])
			l=mid+1;
		else
			h=mid-1;
	}
}
