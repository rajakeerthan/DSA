#include<stdio.h>
void ins(int a[],int n);

int main(){
	int a[20];
	int n,i;	
	printf("enter no.of elements \n");
	scanf("%d",&n);
	printf("enter elemnts in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	ins(a,n);
	printf("array after sorting\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
void ins(int a[],int n){
	int i,temp,j,b;
	for(i=0;i<n;i++){
		j=i;
		while(j>0 && a[j-1]>a[j]){
			temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
			j--;
		}
		for(b=0;b<n;b++)
			printf("%d\t",a[b]);
		printf("\n");
	}
	
	
}
