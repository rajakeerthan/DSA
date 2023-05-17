#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[],int l,int h,int n);
int main(){
	int n,i,a[50];
	printf("enter number of elements in the \n");
	scanf("%d",&n);
	printf("enter elemnts\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1,n);
	printf("sorted array\n");
	for(i=0;i<n;i++)
		printf("%d",a[i]);
return 0;
}
void quicksort(int a[],int l,int h,int n){
	int i,j,pivot,temp,b;
	if(l<h){
		i=l;
		pivot=l;
		j=h;
		while(i<j){
			while(a[i]<=a[pivot] && i<h){
				i++;
			}
			while(a[j]>=a[pivot] && j>l){
				j--;
			}
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[j];
		a[j]=a[pivot];
		a[pivot]=temp;
			for(b=0;b<n;b++){
				printf("%d",a[b]);
			}	
			printf("\n");
		quicksort(a,l,j-1,n);
		quicksort(a,j+1,h,n);
	}
	
}
