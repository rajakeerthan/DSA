#include<stdio.h>
#include<stdlib.h>
void quicksort(int [],int ,int,int );

int main(){
	int n,i,k;
	int a[20];
	printf("enter no.of elements in the array\n");
	scanf("%d",&n);
	printf("enter elements in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1,n);
	printf("elements after sorting\n");
	for(k=0;k<n;k++){
		printf("%d\t",a[k]);
	}
	printf("\n");
return 0;
}
void quicksort(int a[],int low,int high,int n){
	int k;
	if(low<high){
		int temp;
		int i=low;
		int j=high;
		int pivot=low;
		while(i<j){
			while(i<high && a[i]<=a[pivot])
				i++;
			while(j>low && a[j]>=a[pivot])
				j--;
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		for(k=0;k<n;k++){
			printf("%d\t",a[k]);
		}
		printf("\n");
		quicksort(a,low,j-1,n);
		quicksort(a,j+1,high,n);
	}
}
