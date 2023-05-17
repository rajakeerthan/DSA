#include<stdio.h>
#include<stdlib.h>
#define max 10
int visited[max]={0};
int a[max][max];
void dfs(int,int);
int main(){
	int n,i,j;
	printf("enter no.of vertices\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix of the graph\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("enter the element in row %d and colomn %d:\n",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	dfs(0,n);
	return 0;
}
void dfs(int v,int n){
	visited[v]=1;
	int i;
	for(i=0;i<n;i++){
		if(a[v][i] && !visited[i]){
			printf("\n%c----->%c\n",v+65,i+65);
			dfs(i,n);
		}
	}
}
