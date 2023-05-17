#include<stdio.h>
#include<stdlib.h>
#define max 10
int a[max][max],visited[max];
int main(){
	int n,i,j;
	printf("enter n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		visited[i]=0;
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs(0,n);
}
dfs(int v,int n){
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==1 && visited[j]==0){
				printf("%c",j+65);
				visited[j]=1;
				dfs(i,n);
			}
		}
	}
}
