#include<stdio.h>
void merge(int a[],int l,int h,int n);
void mergesort(int a[],int l,int h,int m,int n);
int main(){
	int a[20];
	int n,i;	
	printf("enter no.of elements \n");
	scanf("%d",&n);
	printf("enter elemnts in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	merge(a,0,n-1,n);
	printf("array after sorting\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
void merge(int a[],int l,int h,int n){
	int m;
	if(l<h){
		m=(l+h)/2;
		merge(a,l,m,n);
		merge(a,m+1,h,n);
		mergesort(a,l,h,m,n);
	}
}
void mergesort(int a[],int l,int h,int m,int n){
	int i=l,b;
	int j=m+1;
	int k=l;
	int c[50];
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
	for(b=0;b<n;b++)
		printf("%d\t",a[b]);
	printf("\n");
}
