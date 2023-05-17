#include<stdio.h>
#include<stdlib.h>
#define n 4
int a[n][n];
int k[n];
void null(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j]=0;
		}
	}
}
void insertion(){
	int i;
	printf("enter the %d no.of nodes\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&k[i]);
	}
}
void insert(int i,int j){
	a[i-1][j-1]=1;
	a[j-1][i-1]=1;
}
void print(){
	int i,j;
	printf("adjacency matrix representation\n");
	for(i=0;i<n;i++){
		printf("%d-",k[i]);
		for(j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int m,k;
	insertion();
	null();
	printf("enter edge between which node and which node like 1st and 2nd or 2nd and 4...so on\n");
	scanf("%d %d",&m,&k);
	insert(m,k);
	insert(1,2);
	insert(3,2);
	insert(2,1);
	insert(3,4);
	print();
return 0;
}
