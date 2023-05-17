#include<stdio.h>
#include<stdlib.h>
void bubble(int );
int a[20];
int main(){
	int n,i;
	printf("enter no.of elements in the array\n");
	scanf("%d",&n);
	printf("enter elements in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bubble(n);
}
void bubble(int n){
	int i,j,temp,k,b;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		for(k=0;k<n;k++){
			printf("%d\t",a[k]);
		}
		printf("\n");
	}
	
}
