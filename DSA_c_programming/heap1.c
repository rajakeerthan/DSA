#include<stdio.h>
#include<stdlib.h>
void heapsort(int a[],int n);
void heapify(int a[],int i,int n);
int main(){
	int a[]={9,5,1,7,3,4,7};
	int i,n=(sizeof(a)/sizeof(a[0]));
	heapsort(a,n);
	printf("array\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
return 0;
}
void heapsort(int a[],int n){
	int i,temp;
	for(i=(n/2)-1;i>=0;i--){
		heapify(a,i,n);
	}
	for(i=n-1;i>=0;i--){
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapify(a,0,i);
	}
}
void heapify(int a[],int i,int n){
	int l=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left]>a[l])
		l=left;
	if(right<n && a[right]>a[l])
		l=right;
	if(l!=i){
		int temp=a[l];
		a[l]=a[i];
		a[i]=temp;
		heapify(a,i,n);
	}
}
