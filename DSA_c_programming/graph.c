#include<stdio.h>
#include<stdlib.h>
#define n 4
int a[n][n];
void null(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j]=0;
		}
	}
}
void insert(int i,int j){
	a[i-1][j-1]=1;
	a[j-1][i-1]=1;
}
void print(){
	int i,j;
	for(i=0;i<n;i++){
		printf("%d\t",i+1);
		for(j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
int main(){
	null();
	insert(1,2);
	insert(3,2);
	insert(2,1);
	insert(3,4);
	print();
return 0;
}
