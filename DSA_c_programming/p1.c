#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX][MAX];
int visited[MAX];
void dfs(int v,int n){
	int i;
	visited[v]=1;
	for(i=0;i<n;i++){
		if(a[v][i]==1 && visited[i]==0){
			printf("%c",i+65);
			
			dfs(i,n);
		}
		
	}
	
}
int main(){
	int n,i,j,k;
	int m;
	printf("enter no.of vetices\n");
	scanf("%d",&n);
	printf("enter adjacency matrix corresponding to the graph\n");
	for(i=0;i<n;i++){
		visited[i]=0;
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter starting vertex number\n");
	scanf("%d",&m);
	printf("%c",m+65-1);
	dfs(m,n);
return 0;
}
