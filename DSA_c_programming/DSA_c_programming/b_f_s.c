#include<stdio.h>
#include<stdlib.h>
#define max 10
int visited[max]={0};
int a[max][max];
void bfs(int adj[][max],int visited[],int start,int n){
	int queue[max],rear=-1,front=-1,i;
	queue[++rear]=start;
	visited[start]=1;
	while(rear!=front){
		start=queue[++front];
		if(start!=n){
			printf("%c\t",start+65);
			for(i=0;i<max;i++){		
				if(adj[start][i]==1 && visited[i]==0){
					queue[++rear]=i;
					visited[i]=1;
				}
			}
		}
	}
}
int main(){
	int n,i,j;
	printf("enter no.o vertices in the graph\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		visited[i]=0;
		for(j=0;j<n;j++){
			printf("enter the element in row %d and colomn %d:\n",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	bfs(a,visited,0,n);
return 0;
}
