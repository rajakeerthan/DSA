#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int l,int h,int n);
void mergesort(int a[],int l,int h,int m,int n);
int main(){
	int n,i,a[50];
	printf("enter number of elements in the \n");
	scanf("%d",&n);
	printf("enter elemnts\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge(a,0,n-1,n);
	printf("sorted array\n");
	for(i=0;i<n;i++)
		printf("%d",a[i]);
return 0;
}
void merge(int a[],int l,int h,int n){
	int mid;
	if(l<h){
		mid=(l+h)/2;
		merge(a,l,mid,n);
		merge(a,mid+1,h,n);
		mergesort(a,l,h,mid,n);
	}
}
void mergesort(int a[],int l,int h,int m,int n){
	int b,i=l;
	int c[50];
	int k=l;
	int j=m+1;
	while(i<=m && j<=h){
		if(a[i]<a[j]){
			c[k]=a[i];
			k++;
			i++;
		}
		else{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=m){
		c[k]=a[i];
			k++;
			i++;
	}
	while(j<=h){
		c[k]=a[j];
			k++;
			j++;
	}
	for(i=l;i<k;i++){
		a[i]=c[i];
	}
	/*for(b=0;b<n;b++){
		printf("%d",a[b]);
	}	
	printf("\n");*/
}

