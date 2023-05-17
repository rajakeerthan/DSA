#include<stdio.h>
#include<stdlib.h>
#define max 10
int a[max][max];
int visited[max];
void dfs(int v,int n){
	int i;
	visited[v]=1;
	for(i=0;i<n;i++){
		if(a[v][i]==1 && visited[i]==0){
			printf("%c\t",i+65);
			visited[i]=1;
			dfs(i,n);
		}
	}
			
}
int main(){
	int n,i,j;
	printf("enter no.of vertices in the graph\n");
	scanf("%d",&n);
	printf("enter adjacency matrix coressponding to graph\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}	
	printf("%c",65);
	dfs(0,n);
return 0;
}
