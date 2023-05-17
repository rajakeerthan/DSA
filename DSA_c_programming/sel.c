#include<stdio.h>
void sel(int a[],int n);

int main(){
	int a[20];
	int n,i;	
	printf("enter no.of elements \n");
	scanf("%d",&n);
	printf("enter elemnts in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sel(a,n);
	printf("array after sorting\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
void sel(int a[],int n){
	int i,j,temp,b,min;
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(a[min]>a[j]){
				min=j;
			}
		}
		if(min!=i){
				temp=a[min];
				a[min]=a[i];
				a[i]=temp;
		}
		for(b=0;b<n;b++)
			printf("%d\t",a[b]);
		printf("\n");
	}
	
} 
