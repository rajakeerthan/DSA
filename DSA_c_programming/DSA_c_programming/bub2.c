#include<stdio.h>
void bub(int a[],int n);

int main(){
	int a[20];
	int n,i;	
	printf("enter no.of elements \n");
	scanf("%d",&n);
	printf("enter elemnts in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bub(a,n);
	printf("array after sorting\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
void bub(int a[],int n){
	int i,j,temp,b;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
		for(b=0;b<n;b++)
			printf("%d\t",a[b]);
		printf("\n");
	}
	
} 
