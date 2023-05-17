#include<stdio.h>
#include<stdlib.h>
void heapify(int a[],int n,int i);
void heapsort(int a[],int n);
int main(){
	int i;
	int a[]={9,3,7,1,5,4};
	int n=(sizeof(a)/sizeof(a[0]));
	heapsort(a,n);
	printf("sorted array\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
return 0;
}
void heapsort(int a[],int n){
	int i,temp;
	for(i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(i=n-1;i>=0;i--){
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapify(a,i,0);
	}
}
void heapify(int a[],int n,int i){
	int temp;
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left]>a[largest])
		largest=left;
	if(right<n && a[right]>a[largest])
		largest=right;
	if(largest!=i){
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		heapify(a,n,i);	
	}
}
