#include<stdio.h>
void quick(int a[],int l,int h,int n);

int main(){
	int a[20];
	int n,i;	
	printf("enter no.of elements \n");
	scanf("%d",&n);
	printf("enter elemnts in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quick(a,0,n-1,n);
	printf("array after sorting\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
void quick(int a[],int l,int h,int n){
	int i,j,pivot,temp,b;
	if(l<h){
		i=l;
		pivot=l;
		j=h;
		while(i<j){
			while(a[i]<a[pivot] && i<h)
				i++;
			while(a[j]>a[pivot] && j>l)
				j--;
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		for(b=0;b<n;b++)
			printf("%d\t",a[b]);
		printf("\n");
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		
		quick(a,l,j-1,n);
		quick(a,j+1,h,n);
	}
}
