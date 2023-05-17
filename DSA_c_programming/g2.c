#include<stdio.h>
#include<stdlib.h>
#define max 10
int a[max][max];
int visited[max];
void bfs(int start,int n){
	int i,front=-1,rear=-1,queue[max];
	queue[++rear]=start;
	visited[start]=1;
	while(front!=rear){
			start=queue[++front];
			if(start!=n){
				printf("%c",start+65);
				for(i=0;i<n;i++){
						if(a[start][i]==1 && visited[i]==0){
							queue[++rear]=i;
							visited[i]=1;
						} 
				}
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
	//printf("%c",65);
	bfs(0,n);
return 0;
}
