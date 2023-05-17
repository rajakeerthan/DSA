#include<stdio.h>
int a[10];
void select(){
	int i,j,k,temp;
	for(i=0;i<10;i++){
		for(j=i;j<10;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
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
