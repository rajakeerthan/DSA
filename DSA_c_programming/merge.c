#include<stdio.h>
#include<stdlib.h>
void merge(int [],int ,int,int );
void mergesort(int [],int ,int ,int ,int );
int main(){
	int n,i,k;
	int a[20];
	printf("enter no.of elements in the array\n");
	scanf("%d",&n);
	printf("enter elements in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	merge(a,0,n-1,n);
	printf("elements after sorting\n");
	for(k=0;k<n;k++){
		printf("%d\t",a[k]);
	}
	printf("\n");
return 0;
}
void merge(int a[],int l,int h,int n){
	if(l<h){
		int mid=(l+h)/2;
		merge(a,l,mid,n);
		merge(a,mid+1,h,n);
		mergesort(a,l,h,mid,n);
	}
}
void mergesort(int a[],int l,int h,int m,int n){
	int i=l;
	int j=m+1;
	int c[20];
	int k=l;
	while(i<=m && j<=h){
		if(a[i]<a[j]){
			c[k]=a[i];
			i++;
			k++;
		}
		else{
			c[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=m){
			c[k]=a[i];
			i++;
			k++;
	}
	while(j<=h){
		c[k]=a[j];
			j++;
			k++;
	}
	for(i=l;i<k;i++)
		a[i]=c[i];
	/*for(i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");*/
	
}
