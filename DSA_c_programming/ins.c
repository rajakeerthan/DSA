#include<stdio.h>
#include<stdlib.h>
void insertion(int );
int a[20];
int main(){
	int n,i;
	printf("enter no.of elements in the array\n");
	scanf("%d",&n);
	printf("enter elements in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	insertion(n);
}
void insertion(int n){
	int i,j,temp,k;
	for(i=0;i<n;i++){
		j=i;
		while(j>0 && a[j-1]>a[j]){
			temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
			j--;
		}	
		for(k=0;k<n;k++){
			printf("%d\t",a[k]);
		}
		printf("\n");
	}
	
}
