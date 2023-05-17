#include<stdio.h>
void heapsort(int a[],int n);
void heapify(int a[],int i,int n);
int main(){
	int a[20];
	int n,i;	
	printf("enter no.of elements \n");
	scanf("%d",&n);
	printf("enter elemnts in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	printf("array after sorting\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
void heapsort(int a[],int n){
	int i,temp;
	for(i=(n/2)-1;i>=0;i--)
		heapify(a,i,n);
	for(i=n-1;i>=0;i--){
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapify(a,0,i);
	}
}
void heapify(int a[],int i,int n){
	int l=i,temp;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left]>a[l])
		l=left;
	if(right<n && a[right]>a[l])
		l=right;
	if(i!=l){
		temp=a[i];
		a[i]=a[l];
		a[l]=temp;
		heapify(a,i,n);
	}
}
