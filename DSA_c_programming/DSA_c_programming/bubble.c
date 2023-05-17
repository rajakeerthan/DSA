#include<stdio.h>
int a[10];
void select(){
	int i,j,k,temp;
	for(i=9;i>=0;i--){
		for(j=0;j<i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		for(k=0;k<10;k++){
			printf("%d  ",a[k]);
		}
		printf("\n");
	}
				
}
int main(){
	int k;
	printf("enter 10 elements to insert\n");
	for(k=0;k<10;k++){
		scanf("%d",&a[k]);
	}
	for(k=0;k<10;k++){
		printf("%d  ",a[k]);
	}
	printf("\n");
	select();
return 0;
}
